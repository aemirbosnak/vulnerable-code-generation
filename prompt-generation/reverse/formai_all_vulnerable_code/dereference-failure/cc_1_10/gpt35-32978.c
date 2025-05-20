//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function for handling errors
void handleError(char *errorMessage) {
    perror(errorMessage);
    exit(1);
}

// Function for reading data from the socket
int readFromSocket(int socket, char *buffer, int size) {
    int bytesReceived = recv(socket, buffer, size, 0);
    if (bytesReceived < 0) {
        handleError("Error receiving data from socket");
    }
    return bytesReceived;
}

// Function for writing data to the socket
void writeToSocket(int socket, char *buffer, int size) {
    int bytesSent = send(socket, buffer, size, 0);
    if (bytesSent < 0) {
        handleError("Error sending data to socket");
    }
}

int main(int argc, char *argv[]) {
    int controlSocket, dataSocket, port, bytesReceived;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    char *host, *username, *password, *filename, *command, *argument;
    struct sockaddr_in serverAddress;

    // Check if correct number of arguments provided
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <host> <port> <username> <password> <filename>", argv[0]);
        exit(1);
    }

    // Get input arguments
    host = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];
    filename = argv[5];

    // Create control socket
    if ((controlSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handleError("Error creating control socket");
    }

    // Set server address
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = inet_addr(host);
    serverAddress.sin_port = htons(port);

    // Connect to server
    if (connect(controlSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        handleError("Error connecting to server");
    }

    // Read welcome message from server
    bytesReceived = readFromSocket(controlSocket, buffer, BUFFER_SIZE);
    printf("%.*s", bytesReceived, buffer);

    // Send login information to server
    sprintf(response, "USER %s\r\n", username);
    writeToSocket(controlSocket, response, strlen(response));

    bytesReceived = readFromSocket(controlSocket, buffer, BUFFER_SIZE);
    if (buffer[0] == '5') {
        handleError("Error logging in to server");
    }

    sprintf(response, "PASS %s\r\n", password);
    writeToSocket(controlSocket, response, strlen(response));

    bytesReceived = readFromSocket(controlSocket, buffer, BUFFER_SIZE);
    if (buffer[0] == '5') {
        handleError("Error logging in to server");
    }

    // Send command to retrieve file
    sprintf(response, "RETR %s\r\n", filename);
    writeToSocket(controlSocket, response, strlen(response));

    bytesReceived = readFromSocket(controlSocket, buffer, BUFFER_SIZE);

    if (buffer[0] == '5') {
        handleError("Error retrieving file from server");
    }

    // Set up data socket
    if ((dataSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handleError("Error creating data socket");
    }

    if (connect(dataSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        handleError("Error connecting to server");
    }

    // Read file data from data socket and save to file
    FILE *file = fopen(filename, "w");
    int totalBytesReceived = 0;
    while ((bytesReceived = readFromSocket(dataSocket, buffer, BUFFER_SIZE)) > 0) {
        totalBytesReceived += bytesReceived;
        fwrite(buffer, sizeof(char), bytesReceived, file);
    }
    fclose(file);

    // Print success message and exit program
    printf("File transfer complete. %d bytes received.\n", totalBytesReceived);
    close(controlSocket);
    close(dataSocket);
    exit(0);
}