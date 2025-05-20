//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: irregular
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// Function to establish a TCP connection with the FTP server
int connectToServer(const char* serverIP, const char* serverPort) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        return -1;
    }

    // Convert server IP and port to network format
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(atoi(serverPort));
    if (inet_pton(AF_INET, serverIP, &serverAddress.sin_addr) <= 0) {
        perror("Invalid address/port");
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Connection error");
        return -1;
    }

    return sockfd;
}

// Function to send a command to the FTP server
void sendCommand(int sockfd, const char* command) {
    send(sockfd, command, strlen(command), 0);
}

// Function to receive the response from the FTP server
void receiveResponse(int sockfd, char* buffer, int maxBufferSize) {
    memset(buffer, 0, maxBufferSize);
    int bytesReceived = recv(sockfd, buffer, maxBufferSize - 1, 0);
    if (bytesReceived <= 0) {
        perror("Error receiving response");
        exit(1);
    }
    buffer[bytesReceived] = '\0';
}

// Main function to handle FTP commands
int main() {
    const char* serverIP = "ftp.example.com";
    const char* serverPort = "21";

    // Connect to the FTP server
    int sockfd = connectToServer(serverIP, serverPort);
    if (sockfd < 0) {
        printf("Failed to connect to server\n");
        return 1;
    }

    // Send commands and receive responses
    char command[256];
    memset(command, 0, sizeof(command));
    printf("Enter a command: ");
    fgets(command, sizeof(command), stdin);
    strcpy(command, command); // Remove newline character
    sendCommand(sockfd, command);

    char response[256];
    memset(response, 0, sizeof(response));
    receiveResponse(sockfd, response, sizeof(response));
    printf("Response: %s\n", response);

    // Close the connection
    close(sockfd);

    return 0;
}