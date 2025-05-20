//FormAI DATASET v1.0 Category: Email Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 4096

void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int client_socket, err;
    struct sockaddr_in server_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];

    if (argc < 2) {
        error("Usage: ./client email");
    }

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        error("Error creating client socket");
    }

    // Get server host by name
    server = gethostbyname(SERVER_ADDRESS);
    if (server == NULL) {
        error("Error getting server host by name");
    }

    // Set server address
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    // Connect to server
    err = connect(client_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (err < 0) {
        error("Error connecting to server");
    }

    // Send email to server
    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "To: %s\nSubject: Test Email\n\nHello World!\n", argv[1]);
    err = write(client_socket, buffer, strlen(buffer));
    if (err < 0) {
        error("Error writing to server");
    }

    // Wait for response from server
    bzero(buffer, BUF_SIZE);
    err = read(client_socket, buffer, BUF_SIZE - 1);
    if (err < 0) {
        error("Error reading from server");
    }

    // Print response from server
    printf("%s\n", buffer);

    // Close client socket
    close(client_socket);

    return 0;
}