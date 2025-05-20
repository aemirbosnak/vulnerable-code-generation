//LLAMA2-13B DATASET v1.0 Category: Client Server Application ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to represent a client connection
struct client_conn {
    int sock;    // Socket descriptor
    char *name;  // Client name
};

// Function to create a new client connection
struct client_conn *new_client_conn(int sock) {
    struct client_conn *conn = malloc(sizeof(struct client_conn));
    conn->sock = sock;
    conn->name = malloc(100);
    return conn;
}

// Function to free a client connection
void free_client_conn(struct client_conn *conn) {
    free(conn->name);
    close(conn->sock);
    free(conn);
}

// Function to handle incoming client connections
void handle_client_connection(int sock) {
    struct client_conn *conn = new_client_conn(sock);

    // Read client name from socket
    read(sock, conn->name, 100);

    // Print welcome message to client
    printf("Welcome, %s! Please enter a command: ", conn->name);

    // Wait for client input
    char buff[1024];
    read(sock, buff, 1024);

    // Handle client input
    if (strcmp(buff, "help") == 0) {
        printf("Available commands:\n");
        printf("  help         Display this message and exit\n");
        printf("  exit        Exit the program\n");
        printf("  echo <text>  Echo back the text\n");
    } else if (strcmp(buff, "echo") == 0) {
        char *text = malloc(100);
        read(sock, text, 100);
        printf("You said: %s\n", text);
        free(text);
    } else {
        printf("Invalid command. Please enter a valid command.\n");
    }

    // Free client connection
    free_client_conn(conn);
}

// Function to start the server
int start_server(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(port),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(sock, 3) < 0) {
        perror("listen failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", port);

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        handle_client_connection(client_sock);
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    start_server(port);

    return 0;
}