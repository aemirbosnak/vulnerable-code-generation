//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Server port number
#define SERVER_PORT 5000

// Maximum number of clients
#define MAX_CLIENTS 10

// Maximum message length
#define MAX_MSG_LEN 1024

// Create a socket
int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    return sock;
}

// Bind the socket to an address and port
void bind_socket(int sock, int port) {
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);
    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }
}

// Listen for incoming connections
void listen_for_connections(int sock) {
    if (listen(sock, MAX_CLIENTS) == -1) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }
}

// Accept an incoming connection
int accept_connection(int sock) {
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    int new_sock = accept(sock, (struct sockaddr *)&addr, &addr_len);
    if (new_sock == -1) {
        perror("Failed to accept connection");
        exit(EXIT_FAILURE);
    }
    return new_sock;
}

// Send a message to a client
void send_message(int sock, char *msg) {
    int len = strlen(msg);
    if (send(sock, msg, len, 0) == -1) {
        perror("Failed to send message");
        exit(EXIT_FAILURE);
    }
}

// Receive a message from a client
int receive_message(int sock, char *msg) {
    int len = recv(sock, msg, MAX_MSG_LEN, 0);
    if (len == -1) {
        perror("Failed to receive message");
        exit(EXIT_FAILURE);
    }
    return len;
}

// Main server loop
void server_loop(int sock) {
    while (1) {
        // Accept an incoming connection
        int new_sock = accept_connection(sock);

        // Receive a message from the client
        char msg[MAX_MSG_LEN];
        int len = receive_message(new_sock, msg);

        // Process the message
        printf("Received message: %s\n", msg);

        // Send a response to the client
        char response[] = "Hello from the server!";
        send_message(new_sock, response);

        // Close the client connection
        close(new_sock);
    }
}

// Main client loop
void client_loop(char *ip, int port) {
    // Create a socket
    int sock = create_socket();

    // Connect to the server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(port);
    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Failed to connect to server");
        exit(EXIT_FAILURE);
    }

    // Send a message to the server
    char msg[] = "Hello from the client!";
    send_message(sock, msg);

    // Receive a response from the server
    char response[MAX_MSG_LEN];
    int len = receive_message(sock, response);

    // Print the response
    printf("Received response: %s\n", response);

    // Close the connection
    close(sock);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the user specified the server IP and port
    if (argc != 3) {
        printf("Usage: %s [server IP] [server port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Start the server or client based on the first argument
    if (strcmp(argv[1], "server") == 0) {
        // Create a server socket
        int sock = create_socket();

        // Bind the socket to the specified port
        bind_socket(sock, SERVER_PORT);

        // Listen for incoming connections
        listen_for_connections(sock);

        // Run the server loop
        server_loop(sock);
    } else if (strcmp(argv[1], "client") == 0) {
        // Start the client loop
        client_loop(argv[2], SERVER_PORT);
    } else {
        printf("Invalid argument: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    return 0;
}