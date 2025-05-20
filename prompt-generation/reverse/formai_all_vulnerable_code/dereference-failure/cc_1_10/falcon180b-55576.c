//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_CLIENTS 100
#define QOS_PORT 8080

struct client {
    int sock;
    struct sockaddr_in addr;
    char name[50];
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(int sender_sock, char* message) {
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].sock!= sender_sock) {
            send(clients[i].sock, message, strlen(message), 0);
        }
    }
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
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(QOS_PORT);

    if (bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_sock, 3) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server listening on port %d\n", QOS_PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_len);

        if (client_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        strcpy(clients[num_clients].name, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].sock = client_sock;
        clients[num_clients].addr = client_addr;
        num_clients++;

        printf("Client connected: %s\n", clients[num_clients-1].name);

        char welcome_msg[100];
        sprintf(welcome_msg, "Welcome to the QoS server, %s!\n", clients[num_clients-1].name);
        send(client_sock, welcome_msg, strlen(welcome_msg), 0);
    }

    return 0;
}