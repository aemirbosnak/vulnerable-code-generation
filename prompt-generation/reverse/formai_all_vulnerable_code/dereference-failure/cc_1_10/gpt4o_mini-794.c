//GPT-4o-mini DATASET v1.0 Category: Client Server Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <errno.h>

#define PORT 8080
#define BUFFER_SIZE 256

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

// Server code
void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        handle_error("socket failed");
    }

    // Forcefully attaching socket to the port
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        handle_error("setsockopt");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Binding the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        handle_error("bind failed");
    }

    // Listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        handle_error("listen");
    }

    printf("Server is listening on port %d\n", PORT);

    // Accepting incoming connections
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
        handle_error("accept");
    }

    // Reading from the client
    read(new_socket, buffer, BUFFER_SIZE);
    printf("Received from client: %s\n", buffer);

    // Sending response back to the client
    const char *response = "Message received!";
    send(new_socket, response, strlen(response), 0);
    printf("Response sent to client\n");

    // Close sockets
    close(new_socket);
    close(server_fd);
}

// Client code
void start_client(const char *server_ip) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // Creating socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation error");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
        handle_error("Invalid address/ Address not supported");
    }

    // Connecting to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handle_error("Connection failed");
    }

    // Sending message to the server
    const char *message = "Hello, Server!";
    send(sock, message, strlen(message), 0);
    printf("Message sent to server: %s\n", message);

    // Reading response from the server
    read(sock, buffer, BUFFER_SIZE);
    printf("Response from server: %s\n", buffer);

    // Close socket
    close(sock);
}

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server/client>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client("127.0.0.1");
    } else {
        fprintf(stderr, "Invalid argument. Use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}