//Falcon-180B DATASET v1.0 Category: Firewall ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define BACKLOG 10
#define NUM_THREADS 5

typedef struct {
    int sock;
    struct sockaddr_in addr;
} client_t;

void *handle_client(void *arg) {
    client_t *client = (client_t *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);
    }

    close(client->sock);
    free(client);
}

int main() {
    int server_sock, new_sock, addrlen;
    struct sockaddr_in server_addr, client_addr;
    pthread_t threads[NUM_THREADS];

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_sock, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server listening on port 8080...\n");

    while (1) {
        addrlen = sizeof(client_addr);
        if ((new_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addrlen)) == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        client_t *client = (client_t *) malloc(sizeof(client_t));
        memcpy(&client->addr, &client_addr, sizeof(client_addr));
        client->sock = new_sock;

        if (pthread_create(&threads[0], NULL, handle_client, client)!= 0) {
            printf("Error creating thread\n");
        }
    }

    return 0;
}