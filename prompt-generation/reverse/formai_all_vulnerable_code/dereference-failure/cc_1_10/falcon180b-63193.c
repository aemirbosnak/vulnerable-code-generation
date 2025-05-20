//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client {
    int sock;
    char ip[INET_ADDRSTRLEN];
    char name[20];
};

void *handle_client(void *arg) {
    struct client *client = (struct client *) arg;
    char buffer[BUFFER_SIZE];

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            close(client->sock);
            printf("Client disconnected: %s\n", client->ip);
            pthread_exit(NULL);
        }

        buffer[bytes_received] = '\0';
        printf("Message from client %s: %s\n", client->name, buffer);

        send(client->sock, buffer, strlen(buffer), 0);
    }
}

int main() {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    pthread_t thread_id;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_sock, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        if ((client_sock = accept(server_sock, (struct sockaddr *) &client_addr, sizeof(client_addr))) == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        inet_ntop(AF_INET, &client_addr.sin_addr, client_addr.sin_addr.s_addr? : "127.0.0.1", client_addr.sin_addr.s_addr? : "127.0.0.1");

        struct client *new_client = (struct client *) malloc(sizeof(struct client));
        strcpy(new_client->ip, inet_ntoa(client_addr.sin_addr));
        strcpy(new_client->name, "Client");
        new_client->sock = client_sock;

        if (pthread_create(&thread_id, NULL, handle_client, (void *) new_client)!= 0) {
            printf("Error creating thread\n");
            close(client_sock);
        }
    }

    return 0;
}