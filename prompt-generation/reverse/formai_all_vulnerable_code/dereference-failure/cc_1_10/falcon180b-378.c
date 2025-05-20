//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

struct client_data {
    int sock;
    char ip[20];
};

void *handle_client(void *arg) {
    struct client_data *client = arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Client %s sent: %s\n", client->ip, buffer);
    }

    close(client->sock);
    free(client);
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_sock, 10) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);

        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_size);

        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        char ip[20];
        inet_ntop(AF_INET, &client_addr.sin_addr, ip, 20);

        struct client_data *client = malloc(sizeof(struct client_data));
        client->sock = client_sock;
        strcpy(client->ip, ip);

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, client);
    }

    close(server_sock);
    return 0;
}