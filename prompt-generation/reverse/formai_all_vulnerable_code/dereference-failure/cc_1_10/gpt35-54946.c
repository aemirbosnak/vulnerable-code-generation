//FormAI DATASET v1.0 Category: Socket programming ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFSIZE 1024
#define MAX_CLIENTS 50
#define DEFAULT_PORT 8888

// Client structure definition
typedef struct {
    int sockfd;
    struct sockaddr_in client_addr;
    char username[BUFSIZE];
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;
pthread_t threads[MAX_CLIENTS];

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[BUFSIZE];
    int bytes_received;

    while ((bytes_received = recv(client->sockfd, buffer, BUFSIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("[%s]: %s", client->username, buffer);

        // Broadcast message to all clients
        for (int i = 0; i < num_clients; i++) {
            if (clients[i].sockfd != client->sockfd) {
                send(clients[i].sockfd, client->username, strlen(client->username), 0);
                send(clients[i].sockfd, buffer, strlen(buffer), 0);
            }
        }
    }

    // Remove client from list
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].sockfd == client->sockfd) {
            printf("Client %s has disconnected.\n", client->username);
            close(client->sockfd);
            for (int j = i; j < num_clients - 1; j++) {
                clients[j] = clients[j+1];
            }
            num_clients--;
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    int server_sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    char ip_str[INET_ADDRSTRLEN];
    int port = DEFAULT_PORT;

    // Parse command line arguments
    if (argc > 1) {
        port = atoi(argv[1]);
    }

    // Create server socket
    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Bind server socket to address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sockfd, MAX_CLIENTS) < 0) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d.\n", port);

    // Accept connections and create client threads
    while (1) {
        socklen_t client_addrlen = sizeof(client_addr);

        if ((client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addrlen)) < 0) {
            perror("Failed to accept connection");
            exit(EXIT_FAILURE);
        }

        // Add client to list
        client_t client;
        client.sockfd = client_sockfd;
        client.client_addr = client_addr;
        sprintf(client.username, "Client #%d", num_clients+1);
        clients[num_clients] = client;
        num_clients++;

        // Print client connection information
        if (inet_ntop(AF_INET, &client_addr.sin_addr, ip_str, INET_ADDRSTRLEN) != NULL) {
            printf("Client connected from %s:%d.\n", ip_str, ntohs(client_addr.sin_port));
        }

        // Create client thread
        pthread_create(&threads[num_clients-1], NULL, handle_client, (void *)&clients[num_clients-1]);
    }

    // Close server socket
    close(server_sockfd);

    return 0;
}