//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define MAXSIZE 1024

void receiveFile(int sockfd, char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Failed to open file!\n");
        return;
    }

    char buffer[MAXSIZE] = {0};
    int bytesReceived = 0;
    while ((bytesReceived = recv(sockfd, buffer, MAXSIZE, 0)) > 0) {
        fwrite(buffer, 1, bytesReceived, file);
    }

    fclose(file);
}

int main(int argc, char const *argv[]) {
    int sockfd;
    struct sockaddr_in serverAddr;
    char buffer[MAXSIZE];

    if (argc != 4) {
        printf("Usage: %s <Server IP> <Port> <Filename>\n", argv[0]);
        return 0;
    }

    char* serverIP = (char*)argv[1];
    int port = atoi(argv[2]);
    char* filename = (char*)argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket!\n");
        return 0;
    }

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        printf("Failed to connect to server!\n");
        return 0;
    }

    send(sockfd, filename, strlen(filename), 0);

    int filesize;
    recv(sockfd, &filesize, sizeof(int), 0);
    if (filesize == -1) {
        printf("File not found on server!\n");
        return 0;
    }

    printf("File size: %d bytes\n", filesize);

    printf("Receiving file...\n");
    receiveFile(sockfd, filename);
    printf("File received successfully!\n");

    close(sockfd);
    return 0;
}