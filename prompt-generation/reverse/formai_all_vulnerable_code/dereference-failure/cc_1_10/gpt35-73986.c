//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Usage: %s <ip_address> <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int client_socket;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];
    memset(&server_address, 0, sizeof(server_address));

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(client_socket < 0) {
        printf("Could not create client socket. Exiting.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    server_address.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to server
    if(connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Could not connect to server: %s:%s. Exiting.\n", argv[1], argv[2]);
        exit(EXIT_FAILURE);
    }

    // Receive welcome message from server
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("Server Response: %s\n", buffer);
    memset(buffer, 0, BUFFER_SIZE);

    // Send username to server
    printf("Username: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);

    // Receive response from server and check if username is valid
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    if(strncmp(buffer, "331", 3) != 0) {
        printf("Invalid username. Exiting.\n");
        close(client_socket);
        exit(EXIT_FAILURE);
    }
    memset(buffer, 0, BUFFER_SIZE);

    // Send password to server
    printf("Password: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    send(client_socket, buffer, strlen(buffer), 0);
    memset(buffer, 0, BUFFER_SIZE);

    // Receive response from server and check if password is valid
    recv(client_socket, buffer, BUFFER_SIZE, 0);
    if(strncmp(buffer, "230", 3) != 0) {
        printf("Invalid password. Exiting.\n");
        close(client_socket);
        exit(EXIT_FAILURE);
    }
    memset(buffer, 0, BUFFER_SIZE);

    // Login successful
    printf("Login Successful!\n");

    // Wait for user input
    while(1) {
        printf("> ");
        fgets(buffer, BUFFER_SIZE, stdin);

        // Send user command to server
        send(client_socket, buffer, strlen(buffer), 0);

        // Receive response from server
        recv(client_socket, buffer, BUFFER_SIZE, 0);

        // Print server response
        printf("%s", buffer);

        memset(buffer, 0, BUFFER_SIZE);
    }

    // Close client socket
    close(client_socket);

    return 0;
}