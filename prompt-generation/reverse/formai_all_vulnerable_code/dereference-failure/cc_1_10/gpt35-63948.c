//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    // Check for required command line arguments
    if (argc != 3) {
        printf("Usage: ./tcp_client <server_ip_address> <port_number>\n");
        return 1;
    }

    char* server_address = argv[1];
    int port = atoi(argv[2]);

    // Create the socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_address, &server_addr.sin_addr);

    // Connect to the server
    int connect_status = connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (connect_status < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send a message to the server
    char* message = "Hello, server!";
    int send_status = send(client_socket, message, strlen(message), 0);
    if (send_status < 0) {
        printf("Error sending message to server\n");
        return 1;
    }

    // Receive a response from the server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int recv_status = recv(client_socket, buffer, BUFFER_SIZE, 0);
    if (recv_status < 0) {
        printf("Error receiving response from server\n");
        return 1;
    }
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(client_socket);

    return 0;
}