//LLAMA2-13B DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define PORT 8080

// Structure to hold information about incoming connections
typedef struct {
    int sock; // Socket descriptor
    struct sockaddr_in client_addr; // Client IP address and port
    char client_name[100]; // Client name (e.g. "John's Computer")
} connection_t;

// Function to handle incoming connections
void handle_connection(connection_t *conn) {
    // Accept the connection and get the client IP address and port
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    getpeername(conn->sock, (struct sockaddr *)&client_addr, &client_len);

    // Print a friendly message to the console
    printf("New connection from %s (%d.%d.%d.%d:%d)\n",
           inet_ntoa(client_addr.sin_addr),
           ntohs(client_addr.sin_port),
           client_addr.sin_family);

    // Check if the client is asking for a directory listing
    if (strcmp(conn->client_name, " directory listing") == 0) {
        // Send a directory listing to the client
        char dir_listing[] = "Welcome to my firewall! Here are the files and directories in my home directory:\n";
        send(conn->sock, dir_listing, strlen(dir_listing), 0);
    } else {
        // If the client is asking for something else, deny the request
        close(conn->sock);
        printf("Access denied: %s is not allowed\n", conn->client_name);
    }
}

// Function to create a listening socket
int create_listening_socket(void) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Set up the listening socket address
    struct sockaddr_in listen_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sock, 5) < 0) {
        perror("listen failed");
        exit(1);
    }

    return sock;
}

int main(void) {
    // Create a listening socket
    int sock = create_listening_socket();
    if (sock < 0) {
        perror("create_listening_socket failed");
        exit(1);
    }

    // Loop forever to handle incoming connections
    while (1) {
        // Wait for an incoming connection
        connection_t *conn = (connection_t *)malloc(sizeof(connection_t));
        socklen_t client_len = sizeof(struct sockaddr_in);
        accept(sock, (struct sockaddr *)&conn->client_addr, &client_len);

        // Handle the incoming connection
        handle_connection(conn);

        // Free memory for the connection structure
        free(conn);
    }

    return 0;
}