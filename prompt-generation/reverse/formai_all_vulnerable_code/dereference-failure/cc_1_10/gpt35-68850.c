//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int ftpConnect(char *serverAddress, int portNumber, char *username, char *password);
void ftpList(int ftpSocket, char *path);
void ftpDownload(int ftpSocket, char *remoteFilePath, char *localFilePath);

int main(int argc, char *argv[]) {

    if (argc != 5) {
        printf("Usage: %s  <server address> <port number> <username> <password>\n", argv[0]);
        return 1;
    }

    int ftpSocket = ftpConnect(argv[1], atoi(argv[2]), argv[3], argv[4]);

    char command[BUFFER_SIZE];
    char path[BUFFER_SIZE];
    char remoteFilePath[BUFFER_SIZE];
    char localFilePath[BUFFER_SIZE];

    printf("Enter command: ");
    fgets(command, BUFFER_SIZE, stdin);

    char *token = strtok(command, "\n");

    while (strcmp(token, "quit") != 0) {
        if (strcmp(token, "ls") == 0) {
            printf("Enter path: ");
            fgets(path, BUFFER_SIZE, stdin);
            ftpList(ftpSocket, path);
        } else if (strcmp(token, "get") == 0) {
            printf("Enter remote file path: ");
            fgets(remoteFilePath, BUFFER_SIZE, stdin);
            printf("Enter local file path: ");
            fgets(localFilePath, BUFFER_SIZE, stdin);

            ftpDownload(ftpSocket, remoteFilePath, localFilePath);
        }

        printf("Enter command: ");
        fgets(command, BUFFER_SIZE, stdin);
        token = strtok(command, "\n");
    }

    if (ftpSocket != -1) {
        close(ftpSocket);
    }

    return 0;
}

int ftpConnect(char *serverAddress, int portNumber, char *username, char *password) {
    int ftpSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (ftpSocket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return -1;
    }

    struct sockaddr_in serverAddr;

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(portNumber);
    serverAddr.sin_addr.s_addr = inet_addr(serverAddress);

    if (connect(ftpSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return -1;
    }

    char response[BUFFER_SIZE];

    if (read(ftpSocket , response, BUFFER_SIZE) == -1) {
        printf("Error receiving server response: %s\n", strerror(errno));
        return -1;
    }

    printf("%s\n", response);

    if (write(ftpSocket, "USER ", strlen("USER ")) == -1) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return -1;
    }

    if (write(ftpSocket, username, strlen(username)) == -1) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return -1;
    }

    if (write(ftpSocket, "\r\n", strlen("\r\n")) == -1) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return -1;
    }

    if (read(ftpSocket, response, BUFFER_SIZE) == -1) {
        printf("Error receiving server response: %s\n", strerror(errno));
        return -1;
    }

    printf("%s\n", response);

    if (write(ftpSocket, "PASS ", strlen("PASS ")) == -1) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return -1;
    }

    if (write(ftpSocket, password, strlen(password)) == -1) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return -1;
    }

    if (write(ftpSocket, "\r\n", strlen("\r\n")) == -1) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return -1;
    }

    if (read(ftpSocket, response, BUFFER_SIZE) == -1) {
        printf("Error receiving server response: %s\n", strerror(errno));
        return -1;
    }

    printf("%s\n", response);

    return ftpSocket;
}

void ftpList(int ftpSocket, char *path) {
    char message[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    sprintf(message, "LIST %s\r\n", path);

    if (write(ftpSocket, message, strlen(message)) == -1) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return;
    }

    if (read(ftpSocket, response, BUFFER_SIZE) == -1) {
        printf("Error receiving server response: %s\n", strerror(errno));
        return;
    }

    printf("%s", response);
}

void ftpDownload(int ftpSocket, char *remoteFilePath, char *localFilePath) {
    char message[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    sprintf(message, "RETR %s\r\n", remoteFilePath);

    if (write(ftpSocket, message, strlen(message)) == -1) {
        printf("Error sending message to server: %s\n", strerror(errno));
        return;
    }

    FILE *fp = fopen(localFilePath, "w");

    if (fp == NULL) {
        printf("Error creating local file: %s\n", strerror(errno));
        return;
    }

    int bytesRead;
    char buffer[BUFFER_SIZE];

    while ((bytesRead = read(ftpSocket , buffer, BUFFER_SIZE)) > 0) {
        if (fwrite(buffer, 1, bytesRead, fp) < bytesRead) {
            printf("Error writing to local file: %s\n", strerror(errno));
            fclose(fp);
            return;
        }
    }

    if (bytesRead == -1) {
        printf("Error receiving server response: %s\n", strerror(errno));
        fclose(fp);
        return;
    }

    fclose(fp);

    if (read(ftpSocket, response, BUFFER_SIZE) == -1) {
        printf("Error receiving server response: %s\n", strerror(errno));
        return;
    }

    printf("%s\n", response);
}