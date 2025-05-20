//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    char ip[16];
    int port;
} client_t;

void *handle_client(void *arg);

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "0.0.0.0", &server_addr.sin_addr);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 10);

    printf("Server started on port 12345\n");

    while (TRUE) {
        client_t *client = malloc(sizeof(client_t));
        memset(client, 0, sizeof(client_t));

        client->socket = accept(server_socket, NULL, NULL);
        inet_ntop(AF_INET, &(((struct sockaddr_in*) malloc(sizeof(struct sockaddr_in)))->sin_addr), client->ip, 16);
        client->port = ntohs(((struct sockaddr_in*) malloc(sizeof(struct sockaddr_in)))->sin_port);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, client);
    }

    return 0;
}

void *handle_client(void *arg) {
    client_t *client = arg;
    char buffer[BUFFER_SIZE];

    while (TRUE) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->socket, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Received message from %s:%d - %s\n", client->ip, client->port, buffer);
    }

    close(client->socket);
    free(client);

    return NULL;
}