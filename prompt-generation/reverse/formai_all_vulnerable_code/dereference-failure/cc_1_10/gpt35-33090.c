//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>

#define BUFFER_SIZE 4096
#define PORT 80

int main(int argc, char *argv[]) {
    int client_fd, bytes_received;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_address;
    struct hostent *server;

    // Creates a socket to connect to the server
    client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd < 0) {
        perror("Socket creation error");
        exit(1);
    }
    // Extracts the hostname from the input arguments
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }
    // Fills the server_address struct with the server details
    memset((char *) &server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy((char *) &server_address.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    server_address.sin_port = htons(PORT);
    // Establishes a connection to the server
    if (connect(client_fd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Connection error");
        exit(1);
    }
    // Sends the HTTP GET request to the server
    char *request = "GET / HTTP/1.1\r\nHost: ";
    send(client_fd, request, strlen(request), 0);
    send(client_fd, argv[1], strlen(argv[1]), 0);
    send(client_fd, "\r\n\r\n", 4, 0);
    // Receives the server response and prints it to the console
    bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
    while (bytes_received > 0) {
        printf("%.*s", bytes_received, buffer);
        bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
    }
    // Closes the socket and exits
    close(client_fd);
    return 0;
}