//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <signal.h>

#define MAX_CONNECTIONS 10
#define MAX_THREADS 10
#define QUEUE_SIZE 10

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    int addrlen;
} client_t;

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    int addrlen;
    int num_conns;
    pthread_t threads[MAX_THREADS];
    pthread_mutex_t lock;
} server_t;

void *handle_client(void *args) {
    client_t *client = (client_t *)args;
    char buffer[1024];
    int n;

    while ((n = recv(client->sockfd, buffer, sizeof(buffer), 0)) > 0) {
        // Process data from client
        printf("Received %d bytes from client %s:%d\n", n, inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port));
        // Send data back to client
        send(client->sockfd, buffer, n, 0);
    }

    // Client has disconnected
    printf("Client %s:%d disconnected\n", inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port));
    close(client->sockfd);
    free(client);

    return NULL;
}

void *accept_clients(void *args) {
    server_t *server = (server_t *)args;
    client_t *client;
    pthread_t thread;

    while (1) {
        client = malloc(sizeof(client_t));
        client->addrlen = sizeof(client->addr);
        client->sockfd = accept(server->sockfd, (struct sockaddr *)&client->addr, &client->addrlen);
        if (client->sockfd < 0) {
            perror("accept() failed");
            continue;
        }

        pthread_mutex_lock(&server->lock);
        if (server->num_conns >= MAX_CONNECTIONS) {
            // Too many connections
            close(client->sockfd);
            free(client);
            pthread_mutex_unlock(&server->lock);
            continue;
        }

        server->num_conns++;
        pthread_mutex_unlock(&server->lock);

        // Create thread to handle client
        pthread_create(&thread, NULL, handle_client, (void *)client);
        pthread_detach(thread);
    }

    return NULL;
}

int main(int argc, char *argv[]) {
    server_t server;
    pthread_t thread;
    struct sockaddr_in addr;

    // Create server socket
    server.sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server.sockfd < 0) {
        perror("socket() failed");
        exit(1);
    }

    // Set server address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(atoi(argv[1]));

    // Bind server socket to address
    if (bind(server.sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind() failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server.sockfd, QUEUE_SIZE) < 0) {
        perror("listen() failed");
        exit(1);
    }

    // Initialize server
    server.addr = addr;
    server.addrlen = sizeof(addr);
    server.num_conns = 0;
    pthread_mutex_init(&server.lock, NULL);

    // Create thread to accept connections
    pthread_create(&thread, NULL, accept_clients, (void *)&server);
    pthread_detach(thread);

    // Main loop
    while (1) {
        // Perform QoS monitoring here
        // ...

        sleep(1);
    }

    // Cleanup
    close(server.sockfd);
    pthread_mutex_destroy(&server.lock);

    return 0;
}