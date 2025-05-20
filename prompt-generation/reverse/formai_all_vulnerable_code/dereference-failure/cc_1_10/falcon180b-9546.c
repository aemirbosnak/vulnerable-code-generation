//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

typedef struct {
    int sock;
    struct sockaddr_in addr;
} client_t;

void *thread_func(void *arg) {
    client_t *client = (client_t *) arg;
    char buffer[1024];
    while (TRUE) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client->sock, buffer, sizeof(buffer), 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Client %s:%d sent message: %s\n", inet_ntoa(client->addr.sin_addr), ntohs(client->addr.sin_port), buffer);
        send(client->sock, buffer, strlen(buffer), 0);
    }
    close(client->sock);
    free(client);
    return NULL;
}

int main() {
    int listen_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    int addr_len;
    int client_count = 0;

    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_sock, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    while (TRUE) {
        addr_len = sizeof(client_addr);
        client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &addr_len);
        if (client_sock == -1) {
            perror("accept");
            exit(1);
        }

        client_count++;
        printf("Client %s:%d connected\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        client_t *client = (client_t *) malloc(sizeof(client_t));
        client->sock = client_sock;
        memcpy(&client->addr, &client_addr, sizeof(client_addr));

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, thread_func, (void *) client);
    }

    close(listen_sock);
    return 0;
}