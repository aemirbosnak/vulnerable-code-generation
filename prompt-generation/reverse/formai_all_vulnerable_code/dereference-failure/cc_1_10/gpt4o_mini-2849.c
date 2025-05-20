//GPT-4o-mini DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void uploadFile(int sockfd, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        error("Cannot open file to upload");
    }

    char buffer[BUFFER_SIZE];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, fp)) > 0) {
        if (send(sockfd, buffer, bytesRead, 0) < 0) {
            error("Cannot send file");
        }
    }

    fclose(fp);
    printf("File %s uploaded successfully!\n", filename);
}

void downloadFile(int sockfd, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("Cannot open file to download");
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesReceived;
    while ((bytesReceived = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytesReceived, fp);
    }

    fclose(fp);
    printf("File %s downloaded successfully!\n", filename);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <port> <upload/download> <filename>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    int port = atoi(argv[2]);
    const char *action = argv[3];
    const char *filename = argv[4];

    int sockfd;
    struct sockaddr_in serverAddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &serverAddr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        error("Connection failed");
    }

    if (strcmp(action, "upload") == 0) {
        uploadFile(sockfd, filename);
    } else if (strcmp(action, "download") == 0) {
        downloadFile(sockfd, filename);
    } else {
        fprintf(stderr, "Unknown action: %s. Use 'upload' or 'download'.\n", action);
        close(sockfd);
        exit(1);
    }

    close(sockfd);
    return 0;
}