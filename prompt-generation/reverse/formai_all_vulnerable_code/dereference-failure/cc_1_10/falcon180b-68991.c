//Falcon-180B DATASET v1.0 Category: Firewall ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

struct client {
    int sock;
    char *name;
    struct sockaddr_in address;
};

void *handle_client(void *arg) {
    struct client *client = (struct client *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Client %s sent message: %s\n", client->name, buffer);
    }

    close(client->sock);
    free(client->name);
    free(client);
}

void accept_connections(int server_sock) {
    struct sockaddr_in client_address;
    socklen_t client_size = sizeof(client_address);

    while (1) {
        struct client *client = (struct client *) malloc(sizeof(struct client));

        if (client == NULL) {
            printf("Error: Out of memory\n");
            exit(1);
        }

        client->sock = accept(server_sock, (struct sockaddr *) &client_address, &client_size);

        if (client->sock == -1) {
            printf("Error: Accept failed\n");
            exit(1);
        }

        inet_ntop(AF_INET, &client_address.sin_addr, client->name, INET_ADDRSTRLEN);

        printf("Client %s connected\n", client->name);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, client);
    }
}

int main() {
    int server_sock;
    struct sockaddr_in server_address;

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(8080);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Socket failed\n");
        exit(1);
    }

    if (bind(server_sock, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        printf("Error: Bind failed\n");
        exit(1);
    }

    if (listen(server_sock, MAX_CLIENTS) == -1) {
        printf("Error: Listen failed\n");
        exit(1);
    }

    printf("Server started on port 8080\n");

    accept_connections(server_sock);

    return 0;
}