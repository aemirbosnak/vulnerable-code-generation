//Falcon-180B DATASET v1.0 Category: Music Library Management System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

struct client {
    int sock;
    char name[20];
    struct sockaddr_in addr;
};

struct message {
    char text[MAX_MSG_SIZE];
    int len;
};

struct client clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(int sender_sock, char* msg) {
    struct message message;
    strcpy(message.text, msg);
    message.len = strlen(message.text);

    for (int i = 0; i < num_clients; i++) {
        if (i == sender_sock)
            continue;

        send(clients[i].sock, &message, sizeof(message), 0);
    }
}

void handle_client(int sock) {
    char buffer[MAX_MSG_SIZE];
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int len = recv(sock, buffer, sizeof(buffer), 0);

        if (len <= 0) {
            close(sock);
            break;
        }

        buffer[len-1] = '\0';
        broadcast(sock, buffer);
    }
}

int main() {
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_sock, 10);

    printf("Server is running on port 8080\n");

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        int client_sock = accept(server_sock, (struct sockaddr*)&client_addr, &addr_size);

        if (num_clients >= MAX_CLIENTS) {
            send(client_sock, "Server is full\n", 16, 0);
            close(client_sock);
            continue;
        }

        strcpy(clients[num_clients].name, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].sock = client_sock;
        clients[num_clients].addr = client_addr;
        num_clients++;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, (void*)handle_client, (void*)&clients[num_clients-1]);
    }

    return 0;
}