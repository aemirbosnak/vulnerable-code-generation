//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 1024

void die(const char *error) {
    fprintf(stderr, "Fatal Error: %s\n", error);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        die("Invalid arguments, please provide IP address and port number");
    }

    char *server_address = argv[1];
    int server_port = atoi(argv[2]);

    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("Failed to create socket");
    }

    // Set up server socket address
    struct sockaddr_in server_sockaddr;
    memset(&server_sockaddr, 0, sizeof(server_sockaddr));
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_addr.s_addr = inet_addr(server_address);
    server_sockaddr.sin_port = htons(server_port);

    // Connect to server
    if (connect(sock, (struct sockaddr*) &server_sockaddr, sizeof(server_sockaddr)) < 0) {
        die("Failed to connect to server");
    }

    printf("Connected to server at %s:%d\n", server_address, server_port);

    // Send message to server
    char message[] = "Hello, server!";
    if (send(sock, message, strlen(message), 0) < 0) {
        die("Failed to send message to server");
    }

    printf("Sent message to server: %s\n", message);

    // Receive message from server
    char buffer[MAX_BUFFER_SIZE] = {0};
    int bytes_recv = recv(sock, buffer, MAX_BUFFER_SIZE, 0);
    if (bytes_recv < 0) {
        die("Failed to receive message from server");
    }

    printf("Received message from server: %s\n", buffer);

    // Close socket
    if (close(sock) < 0) {
        die("Failed to close socket");
    }

    printf("Disconnected from server\n");

    return 0;
}