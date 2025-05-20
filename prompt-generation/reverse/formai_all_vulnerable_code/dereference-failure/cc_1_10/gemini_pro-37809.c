//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define MAX_BUF_SIZE 1024

// Client structure
typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    pthread_t thread;
} client_t;

// Global variables
client_t clients[MAX_CLIENTS];
int num_clients = 0;
pthread_mutex_t clients_lock = PTHREAD_MUTEX_INITIALIZER;

// Function to handle client connections
void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;

    // Receive data from client
    char buf[MAX_BUF_SIZE];
    int nbytes;
    while ((nbytes = recv(client->sockfd, buf, MAX_BUF_SIZE, 0)) > 0) {
        // Process data from client

        // Send data back to client
        send(client->sockfd, buf, nbytes, 0);
    }

    // Close client connection
    close(client->sockfd);

    // Remove client from list of active clients
    pthread_mutex_lock(&clients_lock);
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].sockfd == client->sockfd) {
            clients[i] = clients[num_clients - 1];
            num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&clients_lock);

    // Free client struct
    free(client);

    return NULL;
}

int main() {
    // Create server socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind socket to address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(12345);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections in a loop
    while (1) {
        // Accept incoming connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Add client to list of active clients
        pthread_mutex_lock(&clients_lock);
        if (num_clients < MAX_CLIENTS) {
            client_t *client = malloc(sizeof(client_t));
            client->sockfd = client_sockfd;
            client->addr = client_addr;
            clients[num_clients++] = *client;

            // Create thread to handle client connection
            pthread_create(&client->thread, NULL, handle_client, client);
        } else {
            // Too many clients connected, send error message and close connection
            char *err_msg = "Too many clients connected.\n";
            send(client_sockfd, err_msg, strlen(err_msg), 0);
            close(client_sockfd);
        }
        pthread_mutex_unlock(&clients_lock);
    }

    // Close server socket
    close(sockfd);

    return 0;
}