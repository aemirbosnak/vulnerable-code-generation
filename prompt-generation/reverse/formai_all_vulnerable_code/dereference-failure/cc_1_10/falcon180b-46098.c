//Falcon-180B DATASET v1.0 Category: Chat server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

struct client_data {
    int sock;
    char name[20];
};

void *handle_client(void *arg) {
    struct client_data *client = (struct client_data *) arg;
    char buffer[BUFFER_SIZE];
    while (TRUE) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client->sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        send(client->sock, buffer, strlen(buffer), 0);
    }
    close(client->sock);
    free(client);
    return NULL;
}

int main() {
    int server_sock, client_sock, addrlen;
    struct sockaddr_in server_addr, client_addr;
    int opt = TRUE;
    setsockopt(server_sock, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt));

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding to port %d\n", PORT);
        exit(1);
    }

    if (listen(server_sock, BACKLOG) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (TRUE) {
        addrlen = sizeof(client_addr);
        client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &addrlen);
        if (client_sock < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }
        struct client_data *client = (struct client_data *) malloc(sizeof(struct client_data));
        client->sock = client_sock;
        inet_ntop(AF_INET, &client_addr.sin_addr, client->name, 20);
        printf("New client connected: %s\n", client->name);
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, client);
    }

    return 0;
}