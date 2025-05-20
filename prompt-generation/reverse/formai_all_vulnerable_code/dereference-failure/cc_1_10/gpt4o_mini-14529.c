//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define PORT 21

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void *recv_response(void *arg) {
    int sock = *(int *)arg;
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0);
        if (bytes_received <= 0) {
            error("Failed to receive data from server");
        }
        printf("%s", buffer);
    }
}

void ftp_login(int sock, const char *username, const char *password) {
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "USER %s\r\n", username);
    send(sock, command, strlen(command), 0);
    sleep(1); // To allow server time to respond

    snprintf(command, sizeof(command), "PASS %s\r\n", password);
    send(sock, command, strlen(command), 0);
    sleep(1); // To allow server time to respond
}

void ftp_download(int sock, const char *filename) {
    char command[BUFFER_SIZE];
    snprintf(command, sizeof(command), "RETR %s\r\n", filename);
    
    send(sock, command, strlen(command), 0);
    sleep(1); // To allow server time to respond

    FILE *file = fopen(filename, "wb");
    if (!file) {
        error("Failed to open file for writing");
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_received;
    while ((bytes_received = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        fwrite(buffer, sizeof(char), bytes_received, file);
    }

    fclose(file);
    printf("Downloaded %s successfully.\n", filename);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("Error creating socket");
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    inet_pton(AF_INET, host, &server_address.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        error("Could not connect to server");
    }

    pthread_t response_thread;
    if (pthread_create(&response_thread, NULL, recv_response, &sock) != 0) {
        error("Failed to create response thread");
    }

    ftp_login(sock, username, password);

    char command[BUFFER_SIZE];
    while (1) {
        printf("FTP> ");
        if (!fgets(command, sizeof(command), stdin)) {
            break;
        }

        command[strcspn(command, "\n")] = 0; // Remove newline

        if (strncmp(command, "get ", 4) == 0) {
            ftp_download(sock, command + 4);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command\n");
        }
    }

    close(sock);
    return EXIT_SUCCESS;
}