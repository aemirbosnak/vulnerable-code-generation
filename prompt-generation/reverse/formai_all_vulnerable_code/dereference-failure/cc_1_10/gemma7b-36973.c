//Gemma-7B DATASET v1.0 Category: Chat server ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>

#define MAX_CLIENTS 10

typedef struct client_t {
    char name[256];
    int sockfd;
    struct client_t* next;
} client_t;

client_t* head = NULL;

void add_client(int sockfd, char* name) {
    client_t* new_client = (client_t*)malloc(sizeof(client_t));
    strcpy(new_client->name, name);
    new_client->sockfd = sockfd;
    new_client->next = head;
    head = new_client;
}

void remove_client(int sockfd) {
    client_t* prev = NULL;
    client_t* current = head;
    while (current) {
        if (current->sockfd == sockfd) {
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
}

int main() {
    int sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    int client_len;

    // Bind socket to port 8080
    sockfd = socket(AF_INET, SOCK_STREAM, htons(8080));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));

    // Listen for clients
    while (1) {
        // Accept client connection
        client_len = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);

        // Add client to list
        add_client(new_sockfd, "John Doe");

        // Send welcome message
        write(new_sockfd, "Welcome to the chat server, John Doe!", 43);
    }

    return 0;
}