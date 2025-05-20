//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <unistd.h>
#define BUF_SIZE 1024
#define COMMAND_SIZE 100

void retrieveFile(int clientSocket, char* fileName) {
    FILE *fp = fopen(fileName, "wb");
    if(fp == NULL) {
        printf("Failed to create file %s.\n", fileName);
        return;
    }
    char buffer[BUF_SIZE];
    int bytesRead = 0;
    while((bytesRead = recv(clientSocket, buffer, BUF_SIZE, 0)) > 0) {
        fwrite(buffer, 1, bytesRead, fp);
    }
    printf("File %s downloaded successfully!\n", fileName);
    fclose(fp);
}

void sendFile(int clientSocket,char* fileName) {
    FILE *fp = fopen(fileName, "rb");
    if(fp == NULL) {
        printf("Failed to open file %s.\n", fileName);
        return;
    }
    char buffer[BUF_SIZE];
    int bytesRead = 0;
    while((bytesRead = fread(buffer,1, BUF_SIZE, fp)) > 0) {
        send(clientSocket, buffer, bytesRead, 0);
    }
    printf("File %s uploaded successfully!\n", fileName);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if(argc < 3) {
        printf("Usage: %s [FTP server IP address] [FTP server port number]\n", argv[0]);
        return 1;
    }
    int clientSocket;
    struct sockaddr_in serverAddress;
    char buffer[BUF_SIZE];
    char command[COMMAND_SIZE];
    char fileName[COMMAND_SIZE];
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serverAddress.sin_addr);
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress))) {
        printf("Failed to connect to server.\n");
        return 1;
    }
    printf("Connected to FTP server at %s:%s\n", argv[1], argv[2]);
    while(1) {
        printf("Enter command (GET/SEND/QUIT): ");
        scanf("%s", command);
        if(!strcmp(command, "QUIT")) {
            send(clientSocket, "QUIT", strlen("QUIT"), 0);
            printf("Closing connection.\n");
            close(clientSocket);
            break;
        }
        printf("Enter file name: ");
        scanf("%s", fileName);
        if(!strcmp(command, "GET")) {
            send(clientSocket, "GET", strlen("GET"), 0);
            send(clientSocket, fileName, strlen(fileName), 0);
            retrieveFile(clientSocket, fileName);
        } else if(!strcmp(command, "SEND")) {
            send(clientSocket, "SEND", strlen("SEND"), 0);
            send(clientSocket, fileName, strlen(fileName), 0);
            sendFile(clientSocket, fileName);
        } else {
            printf("Unknown command.\n");
        }
    }
    return 0;
}