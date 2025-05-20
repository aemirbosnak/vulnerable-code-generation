//FormAI DATASET v1.0 Category: Networking ; Style: decentralized
// A decentralized chat program using sockets in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFSIZE 1024
#define PORT 8080

// Struct to hold client information (username and socket)
typedef struct {
    char username[32];
    int sockid;
} client_t;

client_t clients[10]; // max of 10 clients
int num_clients = 0;

// Function to broadcast a message to all clients except sender
void broadcast(char *message, int sender_sockid) {
    int i;
    for (i = 0; i < num_clients; i++) {
        if (clients[i].sockid != sender_sockid) {
            write(clients[i].sockid, message, strlen(message));
        }
    }
}

// Function to handle connections (run in separate thread)
void *handle_connection(void *arg) {
    int sockid = *((int *) arg);
    char message[BUFSIZE];
    int len;

    // Get client's username
    read(sockid, clients[num_clients].username, sizeof(clients[num_clients].username));
    printf("%s has joined the chat\n", clients[num_clients].username);

    // Add client to list of clients and increment count
    clients[num_clients].sockid = sockid;
    num_clients++;

    // Start chat
    while ((len = read(sockid, message, BUFSIZE)) > 0) {
        message[len - 1] = '\0'; // remove newline character
        printf("%s: %s\n", clients[num_clients - 1].username, message);
        broadcast(message, sockid);
    }

    // Remove client from list of clients and close socket
    int i, remove_index = -1;
    for (i = 0; i < num_clients; i++) {
        if (clients[i].sockid == sockid) {
            remove_index = i;
            break;
        }
    }
    printf("%s has left the chat\n", clients[remove_index].username);
    num_clients--;
    for (i = remove_index; i < num_clients; i++) {
        clients[i] = clients[i+1];
    }
    close(sockid);
}

int main() {
    int server_sockid, new_sockid, len;
    struct sockaddr_in servaddr, cliaddr;

    // Create server socket
    if ((server_sockid = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating server socket");
        exit(1);
    }

    // Set server socket options
    int opt = 1;
    if (setsockopt(server_sockid, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("Error setting server socket options");
        exit(1);
    }

    // Bind server socket to IP address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    if (bind(server_sockid, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error binding server socket");
        exit(1);
    }

    // Listen for client connections
    if (listen(server_sockid, 10) < 0) {
        perror("Error listening for client connections");
        exit(1);
    }

    printf("Server waiting for clients to join...\n");

    // Loop to handle clients
    while (1) {
        // Accept new client connection
        len = sizeof(cliaddr);
        if ((new_sockid = accept(server_sockid, (struct sockaddr *)&cliaddr, &len)) < 0) {
            perror("Error accepting client connection");
            exit(1);
        }

        // Spawn new thread to handle client connection
        pthread_t tid;
        int *arg = malloc(sizeof(*arg));
        *arg = new_sockid;
        if (pthread_create(&tid, NULL, handle_connection, arg) < 0) {
            perror("Error creating thread to handle client connection");
            exit(1);
        }
        pthread_detach(tid);
    }

    return 0;
}