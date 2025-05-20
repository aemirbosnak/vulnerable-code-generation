//GPT-4o-mini DATASET v1.0 Category: Firewall ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10
#define TRUE 1
#define FALSE 0

// Structure to hold a client and its state
typedef struct {
    int socket;
    struct sockaddr_in address;
    int addr_len;
    int is_blocked;
} client_t;

// Function prototypes
void init_server(struct sockaddr_in *server_addr, int *server_fd);
client_t *accept_client(int server_fd);
void handle_client_message(client_t *client);
void block_client(client_t *client);
void unblock_client(client_t *client);
void close_client_connection(client_t *client);

int main() {
    // Server setup
    struct sockaddr_in server_addr;
    int server_fd;
    client_t *clients[MAX_CLIENTS];

    init_server(&server_addr, &server_fd);

    while (TRUE) {
        printf("Waiting for connections...\n");
        client_t *client = accept_client(server_fd);
        
        if (client) {
            clients[client->socket % MAX_CLIENTS] = client; // Store client in cyclic manner
            printf("Client connected from %s:%d\n", inet_ntoa(client->address.sin_addr), ntohs(client->address.sin_port));
            
            while (TRUE) {
                handle_client_message(client);
            }
        }
    }

    // Cleaning up (never reached)
    close(server_fd);
    return 0;
}

// Initialize the server by setting the address and creating a socket
void init_server(struct sockaddr_in *server_addr, int *server_fd) {
    *server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (*server_fd == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    server_addr->sin_family = AF_INET;
    server_addr->sin_addr.s_addr = INADDR_ANY;
    server_addr->sin_port = htons(PORT);
    
    if (bind(*server_fd, (struct sockaddr*)server_addr, sizeof(*server_addr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    if (listen(*server_fd, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    printf("Server initialized on port %d\n", PORT);
}

// Accept a client connection
client_t *accept_client(int server_fd) {
    client_t *client = malloc(sizeof(client_t));
    client->addr_len = sizeof(client->address);
    client->socket = accept(server_fd, (struct sockaddr*)&client->address, (socklen_t*)&client->addr_len);
    
    if (client->socket < 0) {
        perror("Accept failed");
        free(client);
        return NULL;
    }
    client->is_blocked = FALSE;
    return client;
}

// Handle a single message from the client
void handle_client_message(client_t *client) {
    char buffer[BUFFER_SIZE];
    int read_size = recv(client->socket, buffer, sizeof(buffer), 0);
    
    if (read_size <= 0) {
        printf("Client disconnected or error occurred.\n");
        close_client_connection(client);
        return;
    }
    
    buffer[read_size] = '\0'; // Null terminate the buffer
    printf("Received from client: %s\n", buffer);
    
    if (strcmp(buffer, "block") == 0) {
        block_client(client);
    } else if (strcmp(buffer, "unblock") == 0) {
        unblock_client(client);
    } else {
        if (client->is_blocked) {
            printf("Client is blocked! Message ignored.\n");
        } else {
            // Echo back the message
            send(client->socket, buffer, read_size, 0);
        }
    }
}

// Block the client
void block_client(client_t *client) {
    client->is_blocked = TRUE;
    printf("Client %d is now blocked.\n", client->socket);
}

// Unblock the client
void unblock_client(client_t *client) {
    client->is_blocked = FALSE;
    printf("Client %d is now unblocked.\n", client->socket);
}

// Close the connection with the client
void close_client_connection(client_t *client) {
    printf("Closing connection with client %d.\n", client->socket);
    close(client->socket);
    free(client);
}