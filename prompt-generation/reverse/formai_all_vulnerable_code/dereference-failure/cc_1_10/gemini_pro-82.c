//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

typedef struct {
    int fd;
    char ip[16];
} client_t;

typedef struct {
    pthread_mutex_t mutex;
    int num_clients;
    client_t clients[10];
} server_t;

server_t server;

void *handle_client(void *arg) {
    client_t *client = (client_t *)arg;
    char buffer[1024];
    int n;

    while ((n = read(client->fd, buffer, sizeof(buffer))) > 0) {
        pthread_mutex_lock(&server.mutex);

        // Broadcast the message to all other clients
        for (int i = 0; i < server.num_clients; i++) {
            if (server.clients[i].fd != client->fd) {
                write(server.clients[i].fd, buffer, n);
            }
        }

        pthread_mutex_unlock(&server.mutex);
    }

    pthread_mutex_lock(&server.mutex);

    // Remove the client from the list of clients
    for (int i = 0; i < server.num_clients; i++) {
        if (server.clients[i].fd == client->fd) {
            server.clients[i] = server.clients[server.num_clients - 1];
            server.num_clients--;
            break;
        }
    }

    pthread_mutex_unlock(&server.mutex);

    close(client->fd);
    free(client);

    return NULL;
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(sockfd, 5);

    pthread_mutex_init(&server.mutex, NULL);
    server.num_clients = 0;

    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("accept");
            exit(1);
        }

        pthread_mutex_lock(&server.mutex);

        // Add the client to the list of clients
        server.clients[server.num_clients].fd = newsockfd;
        strcpy(server.clients[server.num_clients].ip, inet_ntoa(cli_addr.sin_addr));
        server.num_clients++;

        pthread_mutex_unlock(&server.mutex);

        pthread_t thread;
        pthread_create(&thread, NULL, handle_client, &server.clients[server.num_clients - 1]);
    }

    close(sockfd);

    return 0;
}