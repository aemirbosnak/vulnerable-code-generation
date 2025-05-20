//FormAI DATASET v1.0 Category: Browser Plugin ; Style: multiplayer
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define PORT 8080

typedef struct {
    int fd;
    struct sockaddr_in address;
    pthread_t thread;
} client_t;

static client_t *clients[MAX_CLIENTS];
static int num_clients = 0;

static void *handle_client(void *arg) {
    client_t *client = (client_t*) arg;
    char buffer[1024];
    ssize_t bytes_read;

    while ((bytes_read = read(client->fd, buffer, 1024))) {
        if (bytes_read == -1) {
            printf("Error reading from client %s\n", inet_ntoa(client->address.sin_addr));
            break;
        }

        buffer[bytes_read] = '\0';
        printf("Received %ld bytes from client %s: %s\n", bytes_read, inet_ntoa(client->address.sin_addr), buffer);

        // handle player input here

        // send game state to all clients
        for (int i = 0; i < num_clients; i++) {
            if (clients[i] != NULL && clients[i]->fd != client->fd) {
                write(clients[i]->fd, buffer, bytes_read);
            }
        }
    }

    return NULL;
}

static void add_client(int fd, struct sockaddr_in address) {
    client_t *client = (client_t*) malloc(sizeof(client_t));

    client->fd = fd;
    client->address = address;

    pthread_create(&client->thread, NULL, handle_client, (void*) client);
    clients[num_clients++] = client;
}

int main() {
    struct sockaddr_in address;
    int sock_fd, opt = 1, client_fd;
    ssize_t bytes_read;
    socklen_t addrlen = sizeof(address);
    char buffer[1024];

    memset(clients, 0, sizeof(clients));

    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return EXIT_FAILURE;
    }

    if (setsockopt(sock_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(sock_fd, (const struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("bind failed");
        return EXIT_FAILURE;
    }

    if (listen(sock_fd, 3) < 0) {
        perror("listen");
        return EXIT_FAILURE;
    }

    while (true) {
        if ((client_fd = accept(sock_fd, (struct sockaddr*) &address, &addrlen)) < 0) {
            perror("accept");
            continue;
        }

        printf("Client connected from %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));

        if (num_clients == MAX_CLIENTS) {
            printf("Maximum number of clients reached\n");
            continue;
        }

        add_client(client_fd, address);

        // send game state to new client
        for (int i = 0; i < num_clients - 1; i++) {
            if (clients[i] != NULL) {
                write(client_fd, buffer, bytes_read);
            }
        }
    }

    return EXIT_SUCCESS;
}