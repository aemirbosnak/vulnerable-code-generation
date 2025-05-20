//LLAMA2-13B DATASET v1.0 Category: Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define MAX_MESSAGE_LEN 1024

struct client_t {
    int sock;
    char name[50];
    char message[MAX_MESSAGE_LEN];
};

void* client_thread(void* arg) {
    struct client_t* client = arg;
    char buffer[MAX_MESSAGE_LEN];
    int bytes_read;

    while (1) {
        bytes_read = read(client->sock, buffer, MAX_MESSAGE_LEN);
        if (bytes_read < 0) {
            perror("read");
            break;
        }
        printf("Received message from client: %s\n", buffer);
        // Handle the message here
    }

    return NULL;
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };

    if (bind(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", server_addr.sin_port);

    while (1) {
        int client_sock = accept(sock, NULL, NULL);
        if (client_sock < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        struct client_t* client = malloc(sizeof(struct client_t));
        client->sock = client_sock;
        client->name[0] = '\0';

        pthread_t thread;
        pthread_create(&thread, NULL, client_thread, client);

        printf("Client connected: %s\n", client->name);
    }

    return 0;
}