//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    printf("Socket created.\n");

    // Set up server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    printf("Connected to server.\n");

    // Send data to server
    strcpy(buffer, "Hello, World!");
    send(client_socket, buffer, strlen(buffer), 0);

    printf("Data sent to server.\n");

    // Receive data from server
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving data from server: %s\n", strerror(errno));
        return 1;
    }

    printf("Data received from server: %s\n", buffer);

    // Close socket
    if (close(client_socket) == -1) {
        printf("Error closing socket: %s\n", strerror(errno));
        return 1;
    }

    printf("Socket closed.\n");

    return 0;
}