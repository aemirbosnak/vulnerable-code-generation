//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXSIZE 1024

void receiveFile(int socket, char *filename);
void sendFile(int socket, char *filename);

int main(int argc, char *argv[]) {
    // Ensure correct usage
    if (argc != 4) {
        printf("Usage: %s <server_address> <port> <filename>\n", argv[0]);
        return 1;
    }

    // Parse arguments
    char *serverAddress = argv[1];
    int port = atoi(argv[2]);
    char *filename = argv[3];

    struct sockaddr_in server;
    int socketFD;

    // Create socket
    if ((socketFD = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        return 1;
    }

    // Fill server address information
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, serverAddress, &server.sin_addr) <= 0) {
        perror("invalid address");
        return 1;
    }

    // Connect to server
    if (connect(socketFD, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connection failed");
        return 1;
    }

    // Send command to server (retrieve or store file)
    char command[MAXSIZE];
    sprintf(command, "RETR %s", filename);
    if (send(socketFD, command, strlen(command), 0) < 0) {
        perror("send failed");
        return 1;
    }

    printf("Waiting for server response...\n");

    // Receive response from server
    char buffer[MAXSIZE];
    memset(buffer, 0, MAXSIZE);
    if (recv(socketFD, buffer, MAXSIZE, 0) < 0) {
        perror("recv failed");
        return 1;
    }

    // Check if file found or error
    if (strncmp(buffer, "550", 3) == 0) {
        printf("Error: File not found on server\n");
        return 1;
    } else if (strncmp(buffer, "150", 3) != 0) {
        printf("Error: Unexpected response from server (%s)\n", buffer);
        return 1;
    }

    printf("Starting file transfer...\n");

    // Get filename without path
    char *p = strrchr(filename, '/');
    if (p == NULL) {
        p = filename;
    } else {
        p++;
    }

    // Receive file from server
    receiveFile(socketFD, p);
    printf("File transfer completed successfully\n");

    // Close socket and exit
    close(socketFD);
    return 0;
}

void receiveFile(int socket, char *filename) {
    FILE *f = fopen(filename, "wb");
    if (f == NULL) {
        perror("file error");
        exit(1);
    }

    char buffer[MAXSIZE];

    while (1) {
        memset(buffer, 0, MAXSIZE);
        int n = recv(socket, buffer, MAXSIZE, 0);
        fwrite(buffer, sizeof(char), n, f);
        if (n < MAXSIZE) {
            break;
        }
    }

    fclose(f);
}

void sendFile(int socket, char *filename) {
    FILE *f = fopen(filename, "rb");
    if (f == NULL) {
        perror("file error");
        exit(1);
    }

    char buffer[MAXSIZE];

    while (1) {
        int n = fread(buffer, sizeof(char), MAXSIZE, f);
        if (n == 0) {
            break;
        }
        send(socket, buffer, n, 0);
    }

    fclose(f);
}