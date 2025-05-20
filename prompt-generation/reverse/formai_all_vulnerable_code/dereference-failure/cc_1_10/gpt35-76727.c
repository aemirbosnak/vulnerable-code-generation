//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void ftp_get(int sockfd, char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not create file\n");
        return;
    }
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (strncmp(buffer, "FAIL", 4) == 0) {
        printf("Error: File not found on server\n");
        return;
    }
    while (1) {
        ssize_t num_bytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (num_bytes <= 0) {
            break;
        }
        fwrite(buffer, sizeof(char), num_bytes, file);
    }
    fclose(file);
    printf("Successfully downloaded file: %s\n", filename);
}

void ftp_put(int sockfd, char *filename) {
    char buffer[BUFFER_SIZE];
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file\n");
        return;
    }
    send(sockfd, filename, strlen(filename) + 1, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (strncmp(buffer, "FAIL", 4) == 0) {
        printf("Error: File already exists on server\n");
        return;
    }
    while (1) {
        ssize_t num_bytes = fread(buffer, sizeof(char), BUFFER_SIZE, file);
        if (num_bytes <= 0) {
            break;
        }
        send(sockfd, buffer, num_bytes, 0);
    }
    fclose(file);
    printf("Successfully uploaded file: %s\n", filename);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <server IP address> <command> <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *server_ip = argv[1];
    char *command = argv[2];
    char *filename = argv[3];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(21);
    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        exit(EXIT_FAILURE);
    }
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (strncmp(buffer, "READY", 5) != 0) {
        printf("Error: Invalid response from server\n");
        exit(EXIT_FAILURE);
    }
    if (strcmp(command, "get") == 0) {
        send(sockfd, command, strlen(command) + 1, 0);
        send(sockfd, filename, strlen(filename) + 1, 0);
        ftp_get(sockfd, filename);
    } else if (strcmp(command, "put") == 0) {
        send(sockfd, command, strlen(command) + 1, 0);
        send(sockfd, filename, strlen(filename) + 1, 0);
        char response[BUFFER_SIZE];
        recv(sockfd, response, BUFFER_SIZE, 0);
        if (strncmp(response, "READY", 5) != 0) {
            printf("Error: Invalid response from server\n");
            exit(EXIT_FAILURE);
        }
        ftp_put(sockfd, filename);
    } else {
        printf("Error: Invalid command\n");
        exit(EXIT_FAILURE);
    }
    close(sockfd);
    return 0;
}