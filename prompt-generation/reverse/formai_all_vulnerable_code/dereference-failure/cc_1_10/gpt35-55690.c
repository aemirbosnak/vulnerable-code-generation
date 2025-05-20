//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER 4096

int main(int argc, char *argv[]) {
    struct sockaddr_in server_address;
    char server_reply[MAX_BUFFER];
    int socket_descriptor;

    if(argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <server_port>\n", argv[0]);
        return 1;
    }

    // Create socket
    if((socket_descriptor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        perror("Error: Could not create socket");
        return 1;
    }

    // Set server address
    memset(&server_address, 0, sizeof(server_address));  // Clear structure
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if(connect(socket_descriptor, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Error: Could not connect to server");
        close(socket_descriptor);
        return 1;
    }

    // Receive welcome message
    if(recv(socket_descriptor, server_reply, MAX_BUFFER, 0) == -1) {
        perror("Error: Failed to receive welcome message");
        close(socket_descriptor);
        return 1;
    }

    // Print welcome message
    printf("Server says: %s\n\n", server_reply);

    // Send login command
    char login_command[MAX_BUFFER];
    printf("Please enter your username: ");
    fgets(login_command, MAX_BUFFER, stdin);
    login_command[strcspn(login_command, "\n")] = '\0';  // Remove trailing newline character
    strcat(login_command, " login\r\n");  // Append login command
    send(socket_descriptor, login_command, strlen(login_command), 0);

    // Receive login response
    if(recv(socket_descriptor, server_reply, MAX_BUFFER, 0) == -1) {
        perror("Error: Failed to receive login response");
        close(socket_descriptor);
        return 1;
    }

    // Print login response
    printf("Server says: %s\n", server_reply);

    // Send list command
    send(socket_descriptor, "LIST\r\n", 6, 0);

    // Receive list response
    if(recv(socket_descriptor, server_reply, MAX_BUFFER, 0) == -1) {
        perror("Error: Failed to receive list response");
        close(socket_descriptor);
        return 1;
    }

    // Print list response
    printf("Server says:\n%s\n", server_reply);

    // Close connection
    send(socket_descriptor, "QUIT\r\n", 6, 0);
    close(socket_descriptor);

    return 0;
}