//Falcon-180B DATASET v1.0 Category: Networking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send data to server
    char *message = "Hello, World!";
    bytes_received = send(sock, message, strlen(message), 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Error sending data: %s\n", strerror(errno));
        exit(1);
    }

    // Receive data from server
    bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
        exit(1);
    }

    printf("Received data: %s\n", buffer);

    // Close socket
    close(sock);

    return 0;
}