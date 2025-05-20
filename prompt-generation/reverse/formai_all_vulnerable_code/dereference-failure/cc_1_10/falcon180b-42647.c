//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket, bytes_received;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    char *message = "Hello, Server!";

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    // Connect to server
    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        exit(1);
    }

    // Send message to server
    bytes_received = send(client_socket, message, strlen(message), 0);
    if (bytes_received == -1) {
        printf("Error sending message: %s\n", strerror(errno));
        exit(1);
    }

    // Receive response from server
    bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        printf("Error receiving response: %s\n", strerror(errno));
        exit(1);
    }

    // Print response
    buffer[bytes_received] = '\0';
    printf("Response from server: %s\n", buffer);

    // Close socket
    close(client_socket);

    return 0;
}