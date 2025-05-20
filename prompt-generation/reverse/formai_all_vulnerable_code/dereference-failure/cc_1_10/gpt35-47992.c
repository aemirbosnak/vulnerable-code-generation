//FormAI DATASET v1.0 Category: Client Server Application ; Style: Dennis Ritchie
// A simple client-server program in C
// Written in Dennis Ritchie Style

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_MSG_LEN 1024  // maximum message length

int main(int argc, char *argv[]) {
    int client_fd;  // file descriptor for the client
    struct sockaddr_in server_address;  // server address structure

    // Check for required arguments
    if (argc < 3) {
        printf("Usage: %s <server-IP> <port-number>\n", argv[0]);
        exit(1);
    }

    // Create a TCP socket for the client
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Failed to create a socket");
        exit(1);
    }

    // Initialize server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        perror("Failed to convert server IP address");
        exit(1);
    }

    // Connect to the server
    if (connect(client_fd, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("Failed to connect to the server");
        exit(1);
    }

    char message[MAX_MSG_LEN];  // buffer to hold messages

    // Read and send messages to the server until the user types "quit"
    while (1) {
        memset(message, 0, MAX_MSG_LEN);
        printf("Client: ");
        scanf("%[^\n]%*c", message);
        if (send(client_fd, message, strlen(message), 0) == -1) {
            perror("Failed to send message to the server");
            exit(1);
        }
        if (strcmp(message, "quit") == 0) {
            break;
        }
        memset(message, 0, MAX_MSG_LEN);
        if (recv(client_fd, message, MAX_MSG_LEN, 0) == -1) {
            perror("Failed to receive message from the server");
            exit(1);
        }
        printf("Server: %s\n", message);
    }

    // Close the socket and exit
    close(client_fd);
    return 0;
}