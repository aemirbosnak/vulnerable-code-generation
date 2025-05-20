//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <time.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

struct client {
    int sock;
    char ip[20];
};

void *thread_func(void *arg) {
    struct client *client = (struct client *) arg;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("Client %s sent: %s\n", client->ip, buffer);
    }

    close(client->sock);
    free(client);
    return NULL;
}

int main() {
    int server_sock, client_sock, addrlen, new_sock;
    struct sockaddr_in server_addr, client_addr;
    struct client clients[MAX_CLIENTS];
    pthread_t threads[MAX_CLIENTS];

    memset(clients, 0, sizeof(clients));

    server_sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_sock, (struct sockaddr *) &server_addr, sizeof(server_addr));

    listen(server_sock, 3);

    while (1) {
        addrlen = sizeof(client_addr);
        new_sock = accept(server_sock, (struct sockaddr *) &client_addr, &addrlen);

        if (new_sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sock == 0) {
                clients[i].sock = new_sock;
                strcpy(clients[i].ip, inet_ntoa(client_addr.sin_addr));

                pthread_create(&threads[i], NULL, thread_func, (void *) &clients[i]);

                break;
            }
        }
    }

    close(server_sock);
    return 0;
}