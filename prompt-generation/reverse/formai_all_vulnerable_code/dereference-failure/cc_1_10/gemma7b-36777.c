//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/stat.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ProxyClient {
    char *hostname;
    int port;
    int sockfd;
    struct ProxyClient *next;
} ProxyClient;

ProxyClient *insertClient(ProxyClient *head, char *hostname, int port) {
    ProxyClient *newClient = malloc(sizeof(ProxyClient));
    newClient->hostname = strdup(hostname);
    newClient->port = port;
    newClient->sockfd = -1;
    newClient->next = NULL;

    if (head == NULL) {
        head = newClient;
    } else {
        ProxyClient *iter = head;
        while (iter->next) {
            iter = iter->next;
        }
        iter->next = newClient;
    }

    return head;
}

void handleClient(ProxyClient *client) {
    int sockfd = socket(AF_INET, SOCK_STREAM, htons(80));
    client->sockfd = sockfd;

    char buffer[MAX_BUFFER_SIZE];
    int readBytes = read(sockfd, buffer, MAX_BUFFER_SIZE);
    buffer[readBytes] = '\0';

    printf("Client: %s:%d sent: %s\n", client->hostname, client->port, buffer);

    write(sockfd, buffer, readBytes);
    close(sockfd);
}

int main() {
    ProxyClient *clients = NULL;

    // Listen for client connections
    int listenfd = socket(AF_INET, SOCK_STREAM, htons(80));
    bind(listenfd, NULL, 0);

    while (1) {
        int connfd = accept(listenfd, NULL, NULL);
        insertClient(clients, "localhost", 8080);
        handleClient(clients);
        close(connfd);
    }

    return 0;
}