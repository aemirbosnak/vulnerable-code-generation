//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: surprised
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Function to handle incoming connections
void handle_client(int client_socket, int server_socket, int client_ip, int client_port, char* url) {
    // Connect to the server
    int server_socket_fd = connect(server_socket, (struct sockaddr *)&client_ip, sizeof(struct sockaddr_in));
    if (server_socket_fd == -1) {
        printf("Failed to connect to server\n");
        return;
    }

    // Send the request
    send(client_socket, url, strlen(url), 0);

    // Receive the response
    char response[1024];
    int response_length = recv(server_socket_fd, response, sizeof(response), 0);
    if (response_length == -1) {
        printf("Failed to receive response from server\n");
        return;
    }

    // Send the response to the client
    send(client_socket, response, response_length, 0);

    // Close the connections
    close(server_socket_fd);
    close(client_socket);
}

int main() {
    // Create a server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        return 1;
    }

    // Set up the server socket address
    struct sockaddr_in server_socket_address;
    server_socket_address.sin_family = AF_INET;
    server_socket_address.sin_addr.s_addr = INADDR_ANY;
    server_socket_address.sin_port = htons(8000);

    // Bind the server socket to the address
    bind(server_socket, (struct sockaddr *)&server_socket_address, sizeof(struct sockaddr_in));

    // Listen for incoming connections
    listen(server_socket, 5);

    // Accept a connection from a client
    int client_socket = accept(server_socket, NULL, NULL);
    if (client_socket == -1) {
        perror("Failed to accept client connection");
        return 1;
    }

    // Get the client's IP address and port
    struct sockaddr_in client_socket_address;
    socklen_t client_socket_address_length = sizeof(struct sockaddr_in);
    getsockname(client_socket, (struct sockaddr *)&client_socket_address, &client_socket_address_length);

    // Extract the IP address and port from the client's address
    char client_ip[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &client_socket_address.sin_addr, client_ip, sizeof(client_ip));
    int client_port = ntohs(client_socket_address.sin_port);

    // Get the URL from the client
    char url[1024];
    int url_length = read(client_socket, url, sizeof(url));
    if (url_length == -1) {
        printf("Failed to read URL from client\n");
        return 1;
    }

    // Forward the request to the server
    handle_client(client_socket, server_socket, client_socket_address.sin_addr.s_addr, client_socket_address.sin_port, url);

    // Close the client socket
    close(client_socket);

    return 0;
}