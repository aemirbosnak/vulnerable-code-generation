//Gemma-7B DATASET v1.0 Category: Simple HTTP Proxy ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct ProxyClient {
    char* hostname;
    int port;
    int sockfd;
    struct ProxyClient* next;
} ProxyClient;

ProxyClient* proxy_client_insert(char* hostname, int port, ProxyClient* head) {
    ProxyClient* new_client = malloc(sizeof(ProxyClient));
    new_client->hostname = strdup(hostname);
    new_client->port = port;
    new_client->sockfd = -1;
    new_client->next = NULL;

    if (head == NULL) {
        head = new_client;
    } else {
        head->next = new_client;
    }

    return head;
}

void proxy_client_remove(ProxyClient* client, ProxyClient* head) {
    if (client == NULL) {
        return;
    }

    if (client->next == NULL) {
        head = NULL;
    } else {
        ProxyClient* prev = NULL;
        ProxyClient* current = head;

        while (current) {
            if (current == client) {
                if (prev) {
                    prev->next = client->next;
                } else {
                    head = client->next;
                }
                free(client);
                return;
            }

            prev = current;
            current = current->next;
        }
    }
}

int main() {
    ProxyClient* head = NULL;

    // Insert some clients
    proxy_client_insert("localhost", 8080, head);
    proxy_client_insert("192.168.1.10", 8080, head);

    // Remove a client
    proxy_client_remove(head->next, head);

    // Print the remaining clients
    ProxyClient* current = head;
    while (current) {
        printf("hostname: %s, port: %d\n", current->hostname, current->port);
        current = current->next;
    }

    return 0;
}