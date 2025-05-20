//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to represent a server
typedef struct {
    int sock;
    socklen_t clnt_len;
    struct sockaddr_in client_addr;
} server_t;

// Function to create a server socket
server_t* create_server(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set address and port number
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Get the client address and port number
    socklen_t client_len = sizeof(struct sockaddr_in);
    struct sockaddr_in client_addr;
    int client_sock = accept(sock, (struct sockaddr*)&client_addr, &client_len);
    if (client_sock < 0) {
        perror("accept failed");
        exit(EXIT_FAILURE);
    }

    // Create a new server structure and return it
    server_t* server = malloc(sizeof(server_t));
    server->sock = sock;
    server->clnt_len = client_len;
    server->client_addr = client_addr;
    return server;
}

// Function to handle incoming client connections
void handle_client(server_t* server) {
    // Read data from the client
    char buffer[1024];
    int bytes_read = read(server->sock, buffer, 1024);
    if (bytes_read < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    // Print the received message
    printf("Received message from client: %s\n", buffer);

    // Send a response back to the client
    char* message = "Hello, client!";
    int bytes_written = write(server->sock, message, strlen(message));
    if (bytes_written < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int port = atoi(argv[1]);
    server_t* server = create_server(port);
    handle_client(server);

    return 0;
}