//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

// Our very own HTTP server!
int main() {
    // Let's set up our server socket.
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // We'll be listening on all available interfaces, on port 8080.
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind our server socket to the address.
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // We're ready to listen for incoming connections. We'll allow up to 10 connections to queue up.
    if (listen(server_socket, 10) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Let's keep our server running until the user decides to stop it.
    while (1) {
        // We'll wait for a client to connect to our server.
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr *) &client_address, &client_address_length);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // We've got a client connected! Let's print out their IP address and port.
        char client_ip_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_address.sin_addr, client_ip_address, INET_ADDRSTRLEN);
        printf("Client connected from %s:%d\n", client_ip_address, ntohs(client_address.sin_port));

        // Let's read the request from the client.
        char request[1024];
        memset(request, 0, sizeof(request));
        int bytes_received = recv(client_socket, request, sizeof(request), 0);
        if (bytes_received < 0) {
            perror("recv");
            close(client_socket);
            continue;
        }

        // We've got the request! Let's parse it out.
        char *method = strtok(request, " ");
        char *path = strtok(NULL, " ");
        char *version = strtok(NULL, "\r\n");

        // We'll just handle GET requests for now.
        if (strcmp(method, "GET") != 0) {
            char *response = "HTTP/1.1 405 Method Not Allowed\r\n\r\n";
            send(client_socket, response, strlen(response), 0);
            close(client_socket);
            continue;
        }

        // We'll just serve a simple HTML page for now.
        char *html_page = "<html><body><h1>Hello, world!</h1></body></html>";
        char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %d\r\n\r\n%s";
        char content_length[16];
        sprintf(content_length, "%d", strlen(html_page));
        response = realloc(response, strlen(response) + strlen(content_length) + strlen(html_page) + 1);
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: %s\r\n\r\n%s", content_length, html_page);

        // Send the response to the client.
        send(client_socket, response, strlen(response), 0);

        // We're all done with this client. Close the connection.
        close(client_socket);
    }

    // Close the server socket.
    close(server_socket);

    return EXIT_SUCCESS;
}