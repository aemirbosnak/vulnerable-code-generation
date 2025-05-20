//Falcon-180B DATASET v1.0 Category: Metadata Extractor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define PORT 8080
#define BACKLOG 10

struct client_data {
    int sock;
    struct sockaddr_in addr;
};

void *handle_client(void *arg) {
    struct client_data *client = (struct client_data *) arg;
    char buffer[1024];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client->sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Received: %s\n", buffer);
    }
    close(client->sock);
    free(client);
    return NULL;
}

int main() {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_sock, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &client_size);
        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        struct client_data *client = malloc(sizeof(struct client_data));
        client->sock = client_sock;
        client->addr = client_addr;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *) client);
    }

    return 0;
}