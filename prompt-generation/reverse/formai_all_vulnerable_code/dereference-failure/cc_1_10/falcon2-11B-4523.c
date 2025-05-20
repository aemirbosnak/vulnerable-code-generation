//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    // Extract the port number from the command line argument
    int port = atoi(argv[1]);

    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        return 1;
    }

    // Set up the server address structure
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // Bind the socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        return 1;
    }

    printf("Web server listening on port %d...\n", port);

    while (1) {
        // Accept a connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Read the HTTP request from the client
        char buffer[1024];
        if (read(client_socket, buffer, sizeof(buffer)) < 0) {
            perror("read");
            close(client_socket);
            continue;
        }

        // Handle the request
        if (strstr(buffer, "GET /")!= NULL) {
            printf("Received GET request for /!\n");
            // Send the response
            char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, World!</h1>";
            write(client_socket, response, sizeof(response));
            close(client_socket);
        } else {
            printf("Received invalid request: %s\n", buffer);
            close(client_socket);
        }
    }

    close(server_socket);
    return 0;
}