//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define PORT 80
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int client_socket, n;
    struct sockaddr_in server_address;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc < 2) {
        printf("Error: Please provide the website URL.\n");
        return 1;
    }

    // Get the server name from the input URL
    char *server_name = strtok(argv[1], "/");
    server = gethostbyname(server_name);

    if (server == NULL) {
        printf("Error: No such host found.\n");
        return 1;
    }

    // Create a socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        printf("Error: Could not create socket.\n");
        return 1;
    }

    // Connect to the server
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(PORT);

    if (connect(client_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error: Could not establish connection.\n");
        return 1;
    }

    // Send the HTTP request
    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", server_name);

    if (send(client_socket, request, strlen(request), 0) < 0) {
        printf("Error: Could not send request.\n");
        return 1;
    }

    // Receive the server response
    bzero(buffer, BUFFER_SIZE);
    while ((n = recv(client_socket, buffer, BUFFER_SIZE - 1, 0)) > 0) {
        printf("%s", buffer);
        bzero(buffer, BUFFER_SIZE);
    }

    if (n < 0) {
        printf("Error: Could not receive response.\n");
        return 1;
    }

    // Close the socket
    close(client_socket);

    return 0;
}