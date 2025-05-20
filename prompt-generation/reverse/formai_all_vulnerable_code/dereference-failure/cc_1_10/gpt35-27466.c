//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

/**
 * This function returns the IP address of a given domain name
 */
char* get_ip_address(char* host) {
    struct hostent* hent = gethostbyname(host);
    if (hent == NULL) {
        fprintf(stderr, "Error: Unable to resolve domain name %s\n", host);
        exit(EXIT_FAILURE);
    }

    int idx = 0;
    char* address = (char*)malloc(INET_ADDRSTRLEN);
    char** h_addr_list = hent->h_addr_list;
    while (h_addr_list[idx] != NULL) {
        strcpy(address, inet_ntoa(*(struct in_addr*)h_addr_list[idx]));
        ++idx;
    }

    return address;
}

/**
 * This function reads the HTTP request from the client
 * and forwards the request to the server
 */
void handle_client(int client_fd, char* server_ip, int server_port) {
    char buffer[MAX_BUFFER_SIZE];
    int bytes_read;

    // Clear the buffer
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read the HTTP request from the client
    bytes_read = read(client_fd, buffer, MAX_BUFFER_SIZE);
    if (bytes_read < 0) {
        fprintf(stderr, "Error: Failed to read from client socket\n");
        exit(EXIT_FAILURE);
    }

    // Display the HTTP request
    printf("--------------------START REQUEST--------------------\n");
    printf("%s", buffer);
    printf("---------------------END REQUEST---------------------\n");

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_address.sin_addr);

    if (connect(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: Failed to connect to server\n");
        exit(EXIT_FAILURE);
    }

    // Forward the HTTP request to the server
    if (write(server_fd, buffer, strlen(buffer)) < 0) {
        fprintf(stderr, "Error: Failed to write to server socket\n");
        exit(EXIT_FAILURE);
    }

    // Clear the buffer
    memset(buffer, 0, MAX_BUFFER_SIZE);

    // Read the HTTP response from the server
    bytes_read = read(server_fd, buffer, MAX_BUFFER_SIZE);
    if (bytes_read < 0) {
        fprintf(stderr, "Error: Failed to read from server socket\n");
        exit(EXIT_FAILURE);
    }

    // Display the HTTP response
    printf("-------------------START RESPONSE-------------------\n");
    printf("%s", buffer);
    printf("--------------------END RESPONSE--------------------\n");

    // Forward the HTTP response to the client
    if (write(client_fd, buffer, strlen(buffer)) < 0) {
        fprintf(stderr, "Error: Failed to write to client socket\n");
        exit(EXIT_FAILURE);
    }

    // Close the sockets
    close(server_fd);
    close(client_fd);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    char* server = argv[2];
    char* server_ip = get_ip_address(server);

    // Create the socket
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        fprintf(stderr, "Error: Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error: Failed to bind socket to port\n");
        exit(EXIT_FAILURE);
    }

    // Listen for connections
    if (listen(server_fd, 10) < 0) {
        fprintf(stderr, "Error: Failed to listen on socket\n");
        exit(EXIT_FAILURE);
    }

    printf("HTTP proxy server started on port %d\n", port);

    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        int client_fd = accept(server_fd, (struct sockaddr*)&client_address, &client_address_len);
        if (client_fd < 0) {
            fprintf(stderr, "Error: Failed to accept client connection\n");
            continue;
        }

        char client_ip[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &client_address.sin_addr, client_ip, sizeof(client_ip));

        printf("Received connection from client %s:%d\n", client_ip, ntohs(client_address.sin_port));

        // Spawn a new thread to handle the client request
        if (fork() == 0) {
            // Child process
            handle_client(client_fd, server_ip, 80);
            exit(EXIT_SUCCESS);
        } else {
            // Parent process
            close(client_fd);
        }
    }

    free(server_ip);
    close(server_fd);

    return 0;
}