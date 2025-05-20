//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXSIZE 1024

void ftp_download(char filename[], int sockfd) {
    char buffer[MAXSIZE];
    int n;

    FILE *file = fopen(filename, "wb");

    while ((n = recv(sockfd, buffer, MAXSIZE, 0)) > 0) {
        fwrite(buffer, sizeof(char), n, file);
    }

    fclose(file);

    return;
}

void ftp_upload(char filename[], int sockfd){
    char buffer[MAXSIZE];
    int n;

    FILE *file = fopen(filename, "rb");

    while ((n = fread(buffer, sizeof(char), MAXSIZE, file)) > 0) {
        send(sockfd, buffer, n, 0);
    }

    fclose(file);

    return;
}

int main(int argc, char *argv[]){
    if (argc < 4) {
        printf("Usage: %s <ip> <port> <filename> [option: upload/download]\n", argv[0]);
        exit(1);
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);
    char *filename = argv[3];
    char *option;

    if (argc == 5) {
        option = argv[4];
    } else {
        option = "download";
    }

    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: failed to create socket.");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: failed to connect to server.");
        exit(1);
    }

    if (strcmp(option, "upload") == 0) {
        printf("Uploading file %s...\n", filename);
        ftp_upload(filename, sockfd);
        printf("File uploaded successfully.\n");
    } else {
        printf("Downloading file %s...\n", filename);
        ftp_download(filename, sockfd);
        printf("File downloaded successfully.\n");
    }

    close(sockfd);

    return 0;  
}