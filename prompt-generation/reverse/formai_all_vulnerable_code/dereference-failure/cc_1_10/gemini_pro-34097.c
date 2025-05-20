//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

// Function to handle the client request
int handle_client_request(int client_socket, int server_socket) {
    // Buffer to store the client request
    char client_request[BUFFER_SIZE];

    // Receive the client request
    int bytes_received = recv(client_socket, client_request, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        perror("recv");
        return -1;
    }

    // Parse the client request
    char *host = NULL;
    char *path = NULL;
    if (sscanf(client_request, "GET %s %s", &path, &host) != 2) {
        printf("Invalid client request\n");
        return -1;
    }

    // Connect to the remote server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    struct hostent *remote_host = gethostbyname(host);
    if (remote_host == NULL) {
        printf("Invalid remote host\n");
        return -1;
    }

    memcpy(&server_addr.sin_addr, remote_host->h_addr_list[0], remote_host->h_length);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0) {
        perror("connect");
        return -1;
    }

    // Send the request to the server
    if (send(server_socket, client_request, bytes_received, 0) != bytes_received) {
        perror("send");
        return -1;
    }

    // Receive the response from the server
    char server_response[BUFFER_SIZE];
    int bytes_sent = 0;
    while ((bytes_sent = recv(server_socket, server_response, BUFFER_SIZE, 0)) > 0) {
        // Send the response to the client
        if (send(client_socket, server_response, bytes_sent, 0) != bytes_sent) {
            perror("send");
            return -1;
        }
    }

    if (bytes_sent < 0) {
        perror("recv");
        return -1;
    }

    return 0;
}

int main() {
    // Create a listening socket
    int listening_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listening_socket < 0) {
        perror("socket");
        return 1;
    }

    // Bind the listening socket to the IP address and port
    struct sockaddr_in listening_addr;
    memset(&listening_addr, 0, sizeof(listening_addr));
    listening_addr.sin_family = AF_INET;
    listening_addr.sin_port = htons(8080);
    listening_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listening_socket, (struct sockaddr *)&listening_addr, sizeof(listening_addr)) != 0) {
        perror("bind");
        return 1;
    }

    // Listen for client connections
    if (listen(listening_socket, 5) != 0) {
        perror("listen");
        return 1;
    }

    // Accept client connections
    while (1) {
        // Create a new socket for the client connection
        int client_socket = accept(listening_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }

        // Create a new socket for the server connection
        int server_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (server_socket < 0) {
            perror("socket");
            close(client_socket);
            continue;
        }

        // Handle the client request
        if (handle_client_request(client_socket, server_socket) < 0) {
            close(client_socket);
            close(server_socket);
            continue;
        }

        // Close the client and server sockets
        close(client_socket);
        close(server_socket);
    }

    // Close the listening socket
    close(listening_socket);

    return 0;
}