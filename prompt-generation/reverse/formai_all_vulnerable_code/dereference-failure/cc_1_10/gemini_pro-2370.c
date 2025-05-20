//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080
#define MAX_CLIENTS 10

typedef struct {
    int sockfd;
    char name[20];
    int x, y;
} client_t;

client_t clients[MAX_CLIENTS];
int num_clients = 0;

void broadcast(char *msg) {
    for (int i = 0; i < num_clients; i++) {
        send(clients[i].sockfd, msg, strlen(msg), 0);
    }
}

void *client_thread(void *arg) {
    client_t *client = (client_t *)arg;
    char buf[1024];
    int n;

    while (1) {
        n = recv(client->sockfd, buf, sizeof(buf), 0);
        if (n <= 0) {
            printf("Client %s disconnected.\n", client->name);
            close(client->sockfd);
            num_clients--;
            pthread_exit(NULL);
        }

        buf[n] = '\0';
        printf("Client %s: %s\n", client->name, buf);

        if (strncmp(buf, "move", 4) == 0) {
            int dx, dy;
            sscanf(buf, "move %d %d", &dx, &dy);
            client->x += dx;
            client->y += dy;
            char msg[100];
            sprintf(msg, "move %s %d %d", client->name, client->x, client->y);
            broadcast(msg);
        }
    }
}

int main() {
    int server_sockfd, new_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd == -1) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        return 1;
    }

    printf("Waiting for clients...\n");

    while (1) {
        client_addr_len = sizeof(client_addr);
        new_sockfd = accept(server_sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (new_sockfd == -1) {
            perror("accept");
            continue;
        }

        printf("Client %s connected.\n", inet_ntoa(client_addr.sin_addr));

        char msg[100];
        sprintf(msg, "Welcome to the RC Vehicle Simulation, %s!", inet_ntoa(client_addr.sin_addr));
        send(new_sockfd, msg, strlen(msg), 0);

        clients[num_clients].sockfd = new_sockfd;
        strcpy(clients[num_clients].name, inet_ntoa(client_addr.sin_addr));
        clients[num_clients].x = 0;
        clients[num_clients].y = 0;
        num_clients++;

        pthread_t thread;
        pthread_create(&thread, NULL, client_thread, &clients[num_clients - 1]);
    }

    return 0;
}