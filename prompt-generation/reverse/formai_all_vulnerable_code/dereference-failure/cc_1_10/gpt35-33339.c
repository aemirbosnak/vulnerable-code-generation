//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: ftpclient <FTP server IP address> <Port>\n");
        exit(EXIT_FAILURE);
    }

    // Declare variables
    int clientSocket;
    struct sockaddr_in serverAddress;
    char command[BUFFER_SIZE] = {0};
    char response[BUFFER_SIZE] = {0};
    char buffer[BUFFER_SIZE] = {0};

    // Create socket
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Error: Failed to create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Set server information
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serverAddress.sin_addr) != 1) {
        perror("Error: Invalid IP Address.\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == -1) {
        perror("Error: Failed to connect to server.\n");
        exit(EXIT_FAILURE);
    }

    // Receive welcome message from server
    fflush(stdout);
    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Response: %s\n", buffer);

    // Login to server
    printf("Username: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    sprintf(command, "USER %s\r\n", buffer);
    send(clientSocket, command, strlen(command), 0);
    fflush(stdout);
    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Response: %s\n", buffer);

    printf("Password: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    sprintf(command, "PASS %s\r\n", buffer);
    send(clientSocket, command, strlen(command), 0);
    fflush(stdout);
    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Response: %s\n", buffer);

    // Enter passive mode
    sprintf(command, "PASV\r\n");
    send(clientSocket, command, strlen(command), 0);
    fflush(stdout);
    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Response: %s\n", buffer);

    // Retrieve file list
    sprintf(command, "LIST\r\n");
    send(clientSocket, command, strlen(command), 0);
    fflush(stdout);
    memset(buffer, 0, BUFFER_SIZE);
    recv(clientSocket, buffer, BUFFER_SIZE, 0);
    printf("Response: %s\n", buffer);

    // Close socket
    close(clientSocket);
    return EXIT_SUCCESS;
}