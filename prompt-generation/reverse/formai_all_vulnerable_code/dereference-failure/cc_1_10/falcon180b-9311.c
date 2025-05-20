//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define MAX_REQUEST_SIZE 1024

struct client {
    int socket;
    char ip[16];
    int port;
};

void *handle_client(void *arg) {
    struct client *client = (struct client *) arg;
    char request[MAX_REQUEST_SIZE];
    int bytes_received = 0;

    while (1) {
        bytes_received = recv(client->socket, request, MAX_REQUEST_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        if (strstr(request, "GET /")) {
            char response[1024];
            sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\nHello, World!", strlen(response));
            send(client->socket, response, strlen(response), 0);
        }
    }

    close(client->socket);
    free(client);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    bind(server_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));
    listen(server_socket, MAX_CLIENTS);

    pthread_t thread_id;

    while (1) {
        struct client *client = (struct client *) malloc(sizeof(struct client));
        client->socket = accept(server_socket, NULL, NULL);

        inet_ntop(AF_INET, &((struct sockaddr_in *) &server_addr)->sin_addr, client->ip, 16);
        client->port = ntohs(((struct sockaddr_in *) &server_addr)->sin_port);

        pthread_create(&thread_id, NULL, handle_client, client);
    }

    return 0;
}