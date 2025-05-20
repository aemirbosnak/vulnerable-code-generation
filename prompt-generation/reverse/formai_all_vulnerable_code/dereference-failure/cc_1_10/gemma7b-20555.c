//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 4096

typedef struct ProxyClient {
    int clientfd;
    char buffer[MAX_BUFFER_SIZE];
    struct ProxyClient* next;
} ProxyClient;

ProxyClient* proxy_client_insert(ProxyClient* head, int clientfd) {
    ProxyClient* new_client = malloc(sizeof(ProxyClient));
    new_client->clientfd = clientfd;
    strcpy(new_client->buffer, "");
    new_client->next = NULL;

    if (head == NULL) {
        return new_client;
    }

    head->next = new_client;
    return new_client;
}

void proxy_client_remove(ProxyClient* head, int clientfd) {
    ProxyClient* prev = NULL;
    ProxyClient* current = head;

    while (current) {
        if (current->clientfd == clientfd) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }

    return;
}

int main() {
    int listenfd, clientfd;
    struct sockaddr_in sock_addr;
    ProxyClient* head = NULL;

    listenfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    bind(listenfd, (struct sockaddr*)&sock_addr, sizeof(sock_addr));

    while (1) {
        clientfd = accept(listenfd, NULL, NULL);
        proxy_client_insert(head, clientfd);

        printf("Client connected: %d\n", clientfd);
    }

    return 0;
}