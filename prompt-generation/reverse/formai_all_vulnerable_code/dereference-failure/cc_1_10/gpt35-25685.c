//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int connect_to_server(char *server_address, int port);
void send_file(int sockfd, char *file_path);
void recv_file(int sockfd, char *file_path);

int main(int argc, char **argv) {
    if (argc != 5) {
        printf("Usage: ./ftpclient <server_address> <port> <command> <filename>\n");
        return 1;
    }

    char *server_address = argv[1];
    int port = atoi(argv[2]);
    char *command = argv[3];
    char *file_path = argv[4];

    int sockfd = connect_to_server(server_address, port);

    if (strcmp(command, "PUT") == 0) {
        send_file(sockfd, file_path);
    } else if (strcmp(command, "GET") == 0) {
        recv_file(sockfd, file_path);
    } else {
        printf("Invalid command\n");
        return 1;
    }

    close(sockfd);
    return 0;
}

int connect_to_server(char *server_address, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_aton(server_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Connection error");
        exit(1);
    }

    return sockfd;
}

void send_file(int sockfd, char *file_path) {
    FILE *fp = fopen(file_path, "rb");
    char buffer[BUFFER_SIZE];

    if (fp == NULL) {
        printf("File not found\n");
        return;
    }

    printf("Sending file %s...\n", file_path);

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        send(sockfd, buffer, sizeof(buffer), 0);
    }

    printf("File sent successfully\n");
    fclose(fp);
}

void recv_file(int sockfd, char *file_path) {
    FILE *fp = fopen(file_path, "wb");
    char buffer[BUFFER_SIZE];
    int bytes_received;

    if (fp == NULL) {
        printf("Unable to create file %s", file_path);
        return;
    }

    printf("Retrieving file %s...\n", file_path);

    while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, fp);
    }

    printf("File %s retrieved successfully\n", file_path);
    fclose(fp);
}