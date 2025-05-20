//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAXSIZE 1024 // Maximum buffer size

void download(int sockfd, char *filename) {
    char buffer[MAXSIZE];
    memset(buffer, 0, MAXSIZE);
    FILE *fp = fopen(filename, "wb"); // Open file for writing in binary mode
    if (fp == NULL) {
        printf("Error: Could not open %s for writing\n", filename);
        return;
    }
    printf("Downloading file %s\n", filename);
    while (1) {
        ssize_t bytesReceived = recv(sockfd, buffer, MAXSIZE, 0);
        if (bytesReceived < 0) {
            printf("Error: File transfer failed\n");
            fclose(fp);
            return;
        } else if (bytesReceived == 0) {
            break;
        }
        fwrite(buffer, 1, bytesReceived, fp);
        memset(buffer, 0, MAXSIZE);
    }
    printf("Download complete\n");
    fclose(fp);
}

void startTCPConnection(int sockfd, char *ipAddress, int port) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a TCP socket
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        return;
    }
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET; // Set the address family type
    serverAddr.sin_port = htons(port); // Set the server port
    serverAddr.sin_addr.s_addr = inet_addr(ipAddress); // Convert IP address to binary format
    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) { // Connect to server
        printf("Error: Connection failed\n");
        return;
    }
    printf("Connected to server\n");
}

void upload(int sockfd, char *filename) {
    char buffer[MAXSIZE];
    memset(buffer, 0, MAXSIZE);
    FILE *fp = fopen(filename, "rb"); // Open file for reading in binary mode
    if (fp == NULL) {
        printf("Error: Could not open %s for reading\n", filename);
        return;
    }
    printf("Uploading file %s\n", filename);
    while (1) {
        ssize_t bytesRead = fread(buffer, 1, MAXSIZE, fp);
        if (bytesRead == 0) {
            break;
        }
        ssize_t bytesSent = send(sockfd, buffer, bytesRead, 0);
        if (bytesSent < bytesRead) {
            printf("Error: File transfer failed\n");
            fclose(fp);
            return;
        }
        memset(buffer, 0, MAXSIZE);
    }
    printf("Upload complete\n");
    fclose(fp);
}

int main(int argc, char *argv[]) {
    int sockfd;
    char ipAddress[MAXSIZE], command[MAXSIZE], filename[MAXSIZE];
    int port;
    if (argc != 3) { // Check if argument count is correct
        printf("Usage: ./ftpclient [IP Address] [Port Number]\n");
        return 0;
    }
    strcpy(ipAddress, argv[1]);
    port = atoi(argv[2]);
    startTCPConnection(sockfd, ipAddress, port); // Start TCP connection
    while (1) {
        printf("Enter a command (get/put/quit): ");
        fgets(command, MAXSIZE, stdin);
        command[strlen(command) - 1] = 0; // Remove newline character
        if (strcmp(command, "quit") == 0) { // Exit program
            break;
        }
        printf("Enter filename: ");
        fgets(filename, MAXSIZE, stdin);
        filename[strlen(filename) - 1] = 0; // Remove newline character
        if (strcmp(command, "get") == 0) { // Download file
            send(sockfd, command, strlen(command), 0);
            download(sockfd, filename);
        } else if (strcmp(command, "put") == 0) { // Upload file
            send(sockfd, command, strlen(command), 0);
            upload(sockfd, filename);
        } else {
            printf("Error: Invalid command\n");
        }
    }
    close(sockfd);
    printf("Disconnected from server\n");
    return 0;
}