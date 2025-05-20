//GEMINI-pro DATASET v1.0 Category: Networking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client_data {
    int sockfd;
    struct sockaddr_in addr;
    char name[32];
};

void *handle_client(void *arg) {
    struct client_data *client = (struct client_data *)arg;
    char buffer[BUFFER_SIZE];
    int n;

    // Receive client name
    n = recv(client->sockfd, client->name, sizeof(client->name), 0);
    if (n <= 0) {
        perror("recv");
        close(client->sockfd);
        free(client);
        pthread_exit(NULL);
    }

    // Send welcome message
    sprintf(buffer, "Welcome, %s!\n", client->name);
    n = send(client->sockfd, buffer, strlen(buffer), 0);
    if (n <= 0) {
        perror("send");
        close(client->sockfd);
        free(client);
        pthread_exit(NULL);
    }

    // Handle client messages
    while ((n = recv(client->sockfd, buffer, sizeof(buffer), 0)) > 0) {
        // Broadcast message to all other clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (i != client->sockfd) {
                send(i, buffer, n, 0);
            }
        }
    }

    // Client disconnected
    printf("%s disconnected.\n", client->name);
    close(client->sockfd);
    free(client);
    pthread_exit(NULL);
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in addr;
    socklen_t addrlen;
    pthread_t threads[MAX_CLIENTS];

    // Create server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    // Bind server socket to address
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Start listening for connections
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        // Accept new connection
        newsockfd = accept(sockfd, (struct sockaddr *)&addr, &addrlen);
        if (newsockfd < 0) {
            perror("accept");
            continue;
        }

        // Create a new client thread
        struct client_data *client = malloc(sizeof(struct client_data));
        client->sockfd = newsockfd;
        client->addr = addr;
        if (pthread_create(&threads[newsockfd], NULL, handle_client, (void *)client) != 0) {
            perror("pthread_create");
            close(newsockfd);
            free(client);
        }
    }

    // Close server socket
    close(sockfd);

    return EXIT_SUCCESS;
}