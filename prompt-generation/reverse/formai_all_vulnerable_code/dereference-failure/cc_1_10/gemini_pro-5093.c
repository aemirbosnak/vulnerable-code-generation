//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);
    char *host = argv[2];

    // Create a socket for listening for incoming connections.
    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to the specified port.
    struct sockaddr_in listen_addr;
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_port = htons(port);
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Start listening for incoming connections.
    if (listen(listen_sock, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Main loop: accept incoming connections and handle them.
    while (1) {
        // Accept an incoming connection.
        int client_sock = accept(listen_sock, NULL, NULL);
        if (client_sock == -1) {
            perror("accept");
            continue;
        }

        // Handle the connection.
        char buf[BUF_SIZE];
        int nbytes;

        // Read the request from the client.
        nbytes = read(client_sock, buf, BUF_SIZE);
        if (nbytes == -1) {
            perror("read");
            close(client_sock);
            continue;
        }

        // Parse the request.
        char *method = strtok(buf, " ");
        char *path = strtok(NULL, " ");
        char *http_version = strtok(NULL, "\r\n");

        // Check if the method is supported.
        if (strcmp(method, "GET") != 0) {
            // Send an error response.
            char error_response[] = "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n";
            write(client_sock, error_response, strlen(error_response));
            close(client_sock);
            continue;
        }

        // Check if the path is valid.
        if (strcmp(path, "/") != 0) {
            // Send an error response.
            char error_response[] = "HTTP/1.1 400 Bad Request\r\nContent-Length: 0\r\n\r\n";
            write(client_sock, error_response, strlen(error_response));
            close(client_sock);
            continue;
        }

        // Send a response.
        char response[] = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 12\r\n\r\nHello, world!";
        write(client_sock, response, strlen(response));

        // Close the connection.
        close(client_sock);
    }

    // Close the listening socket.
    close(listen_sock);

    return EXIT_SUCCESS;
}