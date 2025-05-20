//MISTRAL-7B DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
#define MAX_BUFFER 1024

typedef struct {
    int socket_desc, client_sock, c_addr_len;
    struct sockaddr_in server, client;
} server;

server *init_socket(int port) {
    server *s = (server *) malloc(1 * sizeof(server));
    int opt = 1;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    s->socket_desc = sock;

    bzero(&s->server, sizeof(s->server));
    s->server.sin_family = AF_INET;
    s->server.sin_addr.s_addr = INADDR_ANY;
    s->server.sin_port = htons(port);

    if (bind(s->socket_desc, (struct sockaddr *)&s->server, sizeof(s->server)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    listen(s->socket_desc, 3);
    printf("Listening on port %d...\n", port);

    return s;
}

void handle_client(server *s) {
    char buffer[MAX_BUFFER] = {0};
    ssize_t read_size;

    s->c_addr_len = sizeof(s->client);

    s->client_sock = accept(s->socket_desc, (struct sockaddr *)&s->client, &s->c_addr_len);

    if (s->client_sock < 0) {
        perror("Accept failed");
        return;
    }

    printf("Accepted connection from %s:%d\n",
           inet_ntoa(s->client.sin_addr), ntohs(s->client.sin_port));

    read_size = recv(s->client_sock, buffer, MAX_BUFFER, 0);
    printf("Received: %s\n", buffer);

    char *status = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nHello, client!";

    send(s->client_sock, status, strlen(status), 0);

    close(s->client_sock);
}

void loop(server *s) {
    int client_socket, addrlen;
    char buffer[MAX_BUFFER] = {0};

    for (;;) {
        addrlen = sizeof(struct sockaddr_in);
        client_socket = accept(s->socket_desc, (struct sockaddr *)&s->client, &addrlen);

        if (client_socket < 0) {
            perror("Failed to accept connection");
            continue;
        }

        printf("Connected: %s:%d\n",
               inet_ntoa(s->client.sin_addr), ntohs(s->client.sin_port));

        handle_client(s);
    }
}

int main() {
    server *s = init_socket(PORT);

    loop(s);

    return 0;
}