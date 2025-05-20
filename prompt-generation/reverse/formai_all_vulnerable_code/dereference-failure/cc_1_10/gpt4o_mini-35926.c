//GPT-4o-mini DATASET v1.0 Category: TCP/IP Programming ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Server function
void run_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        handle_error("socket failed");
    }

    // Attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        handle_error("setsockopt");
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        handle_error("bind failed");
    }

    // Start listening for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        handle_error("listen");
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        // Accept a new connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            handle_error("accept");
        }

        printf("New connection accepted\n");

        // Read the message from client
        int read_size = read(new_socket, buffer, BUFFER_SIZE);
        if (read_size < 0) {
            handle_error("read");
        }
        
        printf("Client: %s\n", buffer);

        // Echo the message back to the client
        send(new_socket, buffer, read_size, 0);
        printf("Echoed back to client: %s\n", buffer);

        // Close the connection
        close(new_socket);
    }

    // Close the server socket (unreachable code)
    close(server_fd);
}

// Client function
void run_client(const char *server_ip) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char message[BUFFER_SIZE] = "Hello from client";
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        handle_error("Invalid address / Address not supported");
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handle_error("Connection failed");
    }

    // Send message to server
    send(sock, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    // Read the echoed message from server
    int read_size = read(sock, buffer, BUFFER_SIZE);
    if (read_size < 0) {
        handle_error("read");
    }
    
    printf("Received from server: %s\n", buffer);

    // Close the socket
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <server_ip|server>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        run_server();
    } else {
        run_client(argv[1]);
    }

    return 0;
}