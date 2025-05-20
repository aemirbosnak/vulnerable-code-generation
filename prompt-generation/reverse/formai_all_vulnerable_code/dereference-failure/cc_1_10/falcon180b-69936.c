//Falcon-180B DATASET v1.0 Category: Networking ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int sock;
    char ip[20];
    int port;
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(int sender_sock, char *message) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].sock!= sender_sock) {
            send(clients[i].sock, message, strlen(message), 0);
        }
    }
}

int main(int argc, char *argv[]) {
    int server_sock, new_sock, addrlen, client_sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_sock, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %s\n", argv[1]);

    while (TRUE) {
        addrlen = sizeof(client_addr);
        new_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addrlen);

        if (new_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        strcpy(clients[num_clients].ip, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].port = ntohs(client_addr.sin_port);
        clients[num_clients].sock = new_sock;
        num_clients++;

        printf("Client connected: %s:%d\n", clients[num_clients - 1].ip, clients[num_clients - 1].port);

        for (int i = 0; i < num_clients - 1; i++) {
            send(clients[i].sock, clients[num_clients - 1].ip, strlen(clients[num_clients - 1].ip), 0);
            send(clients[i].sock, &clients[num_clients - 1].port, sizeof(clients[num_clients - 1].port), 0);
        }
    }

    return 0;
}