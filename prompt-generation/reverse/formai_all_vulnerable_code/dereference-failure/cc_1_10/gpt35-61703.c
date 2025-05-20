//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUFFER 1024

int main(int argc, char *argv[]) {
    // Check for valid command line arguments
    if (argc < 3) {
        printf("Usage: %s hostname port", argv[0]);
        return 0;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);
    int sock;
    struct sockaddr_in server;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket");
        return 1;
    }
    printf("Socket created\n");

    // Set server address
    server.sin_addr.s_addr = inet_addr(hostname);
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    // Connect to server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        perror("Connect failed");
        return 1;
    }
    printf("Connected\n");

    // Send IMAP request
    char *message = "a001 LOGIN username password\r\n";
    if (send(sock, message, strlen(message), 0) < 0) {
        puts("Send failed");
        return 1;
    }

    // Receive server response
    char buffer[MAX_BUFFER];
    memset(buffer, 0, MAX_BUFFER);
    if (recv(sock, buffer, MAX_BUFFER, 0) < 0) {
        puts("Receive failed");
        return 1;
    }

    printf("Server response: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}