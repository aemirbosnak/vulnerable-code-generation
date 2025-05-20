//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function to connect to FTP server
int connectToServer(char *ip, int port) {
    struct sockaddr_in server_addr;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error: Unable to create socket.");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if(inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        perror("Error: Invalid address.");
        exit(EXIT_FAILURE);
    }

    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error: Failed to connect to server.");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to receive response from server
void receiveResponse(int sockfd, char *buffer) {
    ssize_t numBytesReceived = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if(numBytesReceived < 0) {
        perror("Error: Failed to receive response.");
        exit(EXIT_FAILURE);
    }

    buffer[numBytesReceived] = '\0';
    printf("%s", buffer);
}

// Function to send command to server
void sendCommand(int sockfd, char *buffer) {
    ssize_t numBytesSent = send(sockfd, buffer, strlen(buffer), 0);
    if(numBytesSent < 0) {
        perror("Error: Failed to send command.");
        exit(EXIT_FAILURE);
    }
}

// Function to download file from FTP server
void downloadFile(char *ip, int port, char *username, char *password, char *remoteFile, char *localFile) {
    int sockfd = connectToServer(ip, port);
    char buffer[BUFFER_SIZE];

    receiveResponse(sockfd, buffer);
    sendCommand(sockfd, "USER ");
    sendCommand(sockfd, username);
    sendCommand(sockfd, "\r\n");
    receiveResponse(sockfd, buffer);

    sendCommand(sockfd, "PASS ");
    sendCommand(sockfd, password);
    sendCommand(sockfd, "\r\n");
    receiveResponse(sockfd, buffer);

    sendCommand(sockfd, "TYPE I\r\n");
    receiveResponse(sockfd, buffer);

    sendCommand(sockfd, "SIZE ");
    sendCommand(sockfd, remoteFile);
    sendCommand(sockfd, "\r\n");
    receiveResponse(sockfd, buffer);

    char *sizeString = strstr(buffer, " ");
    int fileSize = atoi(sizeString);

    sendCommand(sockfd, "RETR ");
    sendCommand(sockfd, remoteFile);
    sendCommand(sockfd, "\r\n");

    FILE *localFilePtr = fopen(localFile, "w");
    if(!localFilePtr) {
        perror("Error: Failed to create local file.");
        exit(EXIT_FAILURE);
    }

    char fileBuffer[BUFFER_SIZE];
    ssize_t numBytesReceived;
    int numBytesWritten = 0;
    while((numBytesReceived = recv(sockfd, fileBuffer, BUFFER_SIZE, 0)) > 0) {
        fwrite(fileBuffer, sizeof(char), numBytesReceived, localFilePtr);
        numBytesWritten += numBytesReceived;

        if(numBytesWritten >= fileSize)
            break;
    }

    fclose(localFilePtr);
    close(sockfd);
}

int main() {
    char ftpServer[] = "ftp.example.com";
    char username[] = "username";
    char password[] = "password";
    char remoteFile[] = "/example.txt";
    char localFile[] = "example.txt";

    int ftpPort = 21;
    downloadFile(ftpServer, ftpPort, username, password, remoteFile, localFile);

    printf("File downloaded successfully.\n");
    return 0;
}