//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client {
    int sock;
    char ip[16];
    int port;
};

void *handle_client(void *arg) {
    struct client *client = (struct client *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_read;

    while ((bytes_read = read(client->sock, buffer, BUFFER_SIZE)) > 0) {
        write(client->sock, buffer, bytes_read);
    }

    close(client->sock);
    free(client);
}

int main() {
    int server_sock, client_sock, new_sock;
    struct sockaddr_in server_addr, client_addr;
    pthread_t thread_id;
    struct client clients[MAX_CLIENTS];

    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_sock, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port 8080\n");

    while (1) {
        socklen_t addr_len;
        if ((client_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addr_len)) == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sock == -1) {
                clients[i].sock = client_sock;
                strcpy(clients[i].ip, inet_ntoa(client_addr.sin_addr));
                clients[i].port = ntohs(client_addr.sin_port);
                pthread_create(&thread_id, NULL, handle_client, &clients[i]);
                break;
            }
        }
    }

    return 0;
}