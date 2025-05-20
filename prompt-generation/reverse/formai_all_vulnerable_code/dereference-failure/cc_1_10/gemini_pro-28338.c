//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Function to handle client requests
void handle_client(int client_socket) {
    char buffer[1024];
    int bytes_received;

    // Receive the request from the client
    bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        perror("recv");
        return;
    }

    // Parse the request
    char *method = strtok(buffer, " ");
    char *path = strtok(NULL, " ");
    char *version = strtok(NULL, "\n");

    // Check if the method is supported
    if (strcmp(method, "GET") != 0) {
        // Send a 405 Method Not Allowed response
        send(client_socket, "HTTP/1.1 405 Method Not Allowed\r\n\r\n", strlen("HTTP/1.1 405 Method Not Allowed\r\n\r\n"), 0);
        close(client_socket);
        return;
    }

    // Check if the path is valid
    if (strcmp(path, "/") != 0) {
        // Send a 404 Not Found response
        send(client_socket, "HTTP/1.1 404 Not Found\r\n\r\n", strlen("HTTP/1.1 404 Not Found\r\n\r\n"), 0);
        close(client_socket);
        return;
    }

    // Send a 200 OK response
    send(client_socket, "HTTP/1.1 200 OK\r\n\r\n", strlen("HTTP/1.1 200 OK\r\n\r\n"), 0);

    // Send the response body
    send(client_socket, "Hello, world!", strlen("Hello, world!"), 0);

    // Close the connection
    close(client_socket);
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;

    // Create a server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return -1;
    }

    // Set the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);

    // Bind the server socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        return -1;
    }

    // Loop forever, accepting incoming connections and handling them
    while (1) {
        // Accept an incoming connection
        client_address_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Handle the client request in a separate thread
        #pragma omp parallel num_threads(4)
        {
            #pragma omp single
            {
                handle_client(client_socket);
            }
        }
    }

    // Close the server socket
    close(server_socket);

    return 0;
}