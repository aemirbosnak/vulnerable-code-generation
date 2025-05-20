//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: decentralized
// Building a decentralized FTP client program in C
// Author: your name

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_LENGTH 1024

// Define the FTP server info
char* serverIP = "localhost";
int serverPort = 21;

// Define the passive mode
int passiveMode = 0;

// Define the user credentials
char* username = "anonymous";
char* password = "guest";

// Define the socket info
int sockfd;
struct sockaddr_in serverAddr;
struct hostent* he;

// Helper function to send commands to the server
int sendCommand(const char* command) {
    char buffer[BUFFER_LENGTH];
    memset(buffer, 0, BUFFER_LENGTH);
    sprintf(buffer, "%s\r\n", command);
    printf("> %s\n", command);
    return send(sockfd, buffer, strlen(buffer), 0);
}

// Helper function to receive data from the server
int receiveResponse(char* buffer, int length) {
    memset(buffer, 0, length);
    int bytesReceived = recv(sockfd, buffer, length, 0);
    printf("< %s", buffer);
    return bytesReceived;
}

// Helper function to establish a connection with the FTP server
int establishConnection() {
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 0;
    }

    // Get the server information from the hostname
    he = gethostbyname(serverIP);
    if (he == NULL) {
        perror("Error resolving hostname");
        return 0;
    }

    // Set up the server address struct
    memset(&serverAddr, 0, sizeof(struct sockaddr_in));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(serverPort);
    memcpy(&serverAddr.sin_addr, he->h_addr_list[0], he->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*) &serverAddr, sizeof(serverAddr)) != 0) {
        perror("Error connecting to server");
        return 0;
    }

    // Receive the welcome message from the server
    char buffer[BUFFER_LENGTH];
    receiveResponse(buffer, BUFFER_LENGTH);

    // Send the username to the server
    sendCommand("USER anonymous");
    receiveResponse(buffer, BUFFER_LENGTH);

    // Send the password to the server
    sendCommand("PASS guest");
    receiveResponse(buffer, BUFFER_LENGTH);

    // Set the transfer mode to binary
    sendCommand("TYPE I");
    receiveResponse(buffer, BUFFER_LENGTH);

    return 1;
}

// Helper function to download a file from the server
int downloadFile(const char* fileName) {
    // Enter passive mode if it hasn't been established yet
    char buffer[BUFFER_LENGTH];
    if (!passiveMode) {
        sendCommand("PASV");
        receiveResponse(buffer, BUFFER_LENGTH);
        passiveMode = 1;
    }

    // Send the download command to the server
    char command[BUFFER_LENGTH];
    sprintf(command, "RETR %s", fileName);
    sendCommand(command);

    // Connect to the data port and receive the file
    struct sockaddr_in dataAddr;
    socklen_t dataAddrLen = sizeof(dataAddr);
    int datafd = accept(sockfd, (struct sockaddr*) &dataAddr, &dataAddrLen);
    if (datafd < 0) {
        perror("Error accepting data socket connection");
        return 0;
    }

    FILE* file = fopen(fileName, "wb");
    if (file == NULL) {
        perror("Error opening file for writing");
        return 0;
    }

    int bytesRead;
    do {
        bytesRead = read(datafd, buffer, BUFFER_LENGTH);
        fwrite(buffer, 1, bytesRead, file);
    } while (bytesRead > 0);

    fclose(file);
    close(datafd);

    receiveResponse(buffer, BUFFER_LENGTH);
    return 1;
}

// Main function
int main(int argc, char** argv) {
    // Establish connection with the FTP server
    if (!establishConnection()) {
        printf("Error establishing connection with server\n");
        return 1;
    }

    // Download a file from the server
    if (!downloadFile("example.txt")) {
        printf("Error downloading file\n");
        return 1;
    }

    printf("File downloaded successfully\n");
    return 0;
}