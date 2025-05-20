//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char* receive_response(int sockfd, char* buffer) {
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received == -1) {
        printf("Error receiving response from server.\n");
        exit(1);
    }
    buffer[bytes_received] = '\0';
    return buffer;
}

int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <server_address> <port> <username>\n", argv[0]);
        exit(1);
    }

    char* server_address = argv[1];
    int port = atoi(argv[2]);
    char* username = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    struct sockaddr_in server_address_info;
    server_address_info.sin_family = AF_INET;
    server_address_info.sin_port = htons(port);
    inet_pton(AF_INET, server_address, &server_address_info.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_address_info, sizeof(server_address_info)) != 0) {
        printf("Error connecting to server.\n");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    receive_response(sockfd, buffer);
    if (buffer[0] != '*') {
        printf("Error connecting to server.\n");
        exit(1);
    }

    // Log in to server with given username
    char login_command[BUFFER_SIZE];
    sprintf(login_command, "a001 LOGIN %s\r\n", username);
    send(sockfd, login_command, strlen(login_command), 0);
    receive_response(sockfd, buffer);
    if (strstr(buffer, "NO") != NULL) {
        printf("Error logging in to server.\n");
        exit(1);
    }

    // List all folders on the server
    char list_command[] = "a002 LIST \"\" *\r\n";
    send(sockfd, list_command, strlen(list_command), 0);
    receive_response(sockfd, buffer);
    printf("Folders on server:\n");
    char* folder = strtok(buffer, "\r\n");
    while (folder != NULL) {
        if (strstr(folder, "* LIST") != NULL) {
            char* name_start = strchr(folder, '"') + 1;
            char* name_end = strchr(name_start, '"');
            int length = (int)(name_end - name_start);
            char folder_name[length + 1];
            strncpy(folder_name, name_start, length);
            folder_name[length] = '\0';
            printf(" - %s\n", folder_name);
        }
        folder = strtok(NULL, "\r\n");
    }

    close(sockfd);
    return 0;
}