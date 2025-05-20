//Falcon-180B DATASET v1.0 Category: Chat server ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define PORT 8080
#define BACKLOG 10
#define MAX_CLIENTS 10
#define MAX_MSG_SIZE 1024

int clients[MAX_CLIENTS];
int num_clients = 0;
int server_socket;

void *handle_client(void *client_socket) {
    int client_id = *(int *) client_socket;
    char buffer[MAX_MSG_SIZE];

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        int bytes_received = recv(client_id, buffer, MAX_MSG_SIZE, 0);

        if (bytes_received <= 0) {
            close(client_id);
            int i;
            for (i = 0; i < num_clients; i++) {
                if (clients[i] == client_id) {
                    clients[i] = -1;
                    break;
                }
            }
            num_clients--;
            break;
        }

        printf("Client %d said: %s\n", client_id, buffer);
        send(client_id, buffer, strlen(buffer), 0);
    }

    pthread_exit(0);
}

int main() {
    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    while (num_clients >= MAX_CLIENTS) {
        printf("Server is full. Please try again later.\n");
        sleep(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, BACKLOG);

    printf("Chat server started on port %d\n", PORT);

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_id = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);

        if (client_id == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Client %d connected\n", client_id);
        clients[num_clients++] = client_id;

        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)&client_id);
    }

    close(server_socket);
    return 0;
}