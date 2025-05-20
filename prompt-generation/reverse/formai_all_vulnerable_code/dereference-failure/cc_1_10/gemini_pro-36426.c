//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: ultraprecise
#define _POSIX_C_SOURCE 200809L
#include <arpa/inet.h>
#include <err.h>
#include <netdb.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct {
    int fd;
    char *host;
    char *port;
    const char *username;
    const char *password;
    char buffer[BUFSIZ];
    size_t buffer_len;
} pop3_client_t;

static int pop3_client_init(pop3_client_t *client, const char *host, const char *port, const char *username, const char *password) {
    client->host = strdup(host);
    client->port = strdup(port);
    client->username = username;
    client->password = password;
    client->fd = -1;
    return 0;
}

static void pop3_client_free(pop3_client_t *client) {
    free(client->host);
    free(client->port);
    if (client->fd != -1) close(client->fd);
}

static int pop3_client_connect(pop3_client_t *client) {
    struct addrinfo hints = {
        .ai_family = AF_UNSPEC,
        .ai_socktype = SOCK_STREAM,
    };
    struct addrinfo *result;
    if (getaddrinfo(client->host, client->port, &hints, &result) != 0) err(1, "getaddrinfo");
    for (struct addrinfo *rp = result; rp != NULL; rp = rp->ai_next) {
        client->fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (client->fd == -1) continue;
        if (connect(client->fd, rp->ai_addr, rp->ai_addrlen) != -1) break;
        close(client->fd);
    }
    if (client->fd == -1) err(1, "connect");
    freeaddrinfo(result);
    return 0;
}

static int pop3_client_send_command(pop3_client_t *client, const char *command) {
    if (send(client->fd, command, strlen(command), 0) == -1) err(1, "send");
    return 0;
}

static int pop3_client_receive_response(pop3_client_t *client) {
    client->buffer_len = 0;
    while (true) {
        ssize_t n = recv(client->fd, client->buffer + client->buffer_len, BUFSIZ - client->buffer_len - 1, 0);
        if (n == -1) err(1, "recv");
        if (n == 0) break;
        client->buffer_len += n;
        if (client->buffer_len >= 2 && client->buffer[client->buffer_len - 2] == '\r' && client->buffer[client->buffer_len - 1] == '\n') break;
    }
    client->buffer[client->buffer_len] = '\0';
    return 0;
}

static int pop3_client_login(pop3_client_t *client) {
    pop3_client_send_command(client, "USER ");
    pop3_client_send_command(client, client->username);
    pop3_client_send_command(client, "\r\n");
    pop3_client_receive_response(client);
    pop3_client_send_command(client, "PASS ");
    pop3_client_send_command(client, client->password);
    pop3_client_send_command(client, "\r\n");
    pop3_client_receive_response(client);
    return 0;
}

static int pop3_client_fetch(pop3_client_t *client) {
    pop3_client_send_command(client, "LIST\r\n");
    pop3_client_receive_response(client);
    char *line = strtok(client->buffer, "\r\n");
    while (line != NULL) {
        if (line[0] >= '1' && line[0] <= '9') {
            char *space = strchr(line, ' ');
            if (space != NULL) {
                printf("%s\n", space + 1);
            }
        }
        line = strtok(NULL, "\r\n");
    }
    return 0;
}

static int pop3_client_quit(pop3_client_t *client) {
    pop3_client_send_command(client, "QUIT\r\n");
    pop3_client_receive_response(client);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 5) errx(1, "Usage: %s <host> <port> <username> <password>", argv[0]);
    pop3_client_t client;
    if (pop3_client_init(&client, argv[1], argv[2], argv[3], argv[4]) != 0) errx(1, "pop3_client_init");
    if (pop3_client_connect(&client) != 0) errx(1, "pop3_client_connect");
    if (pop3_client_login(&client) != 0) errx(1, "pop3_client_login");
    if (pop3_client_fetch(&client) != 0) errx(1, "pop3_client_fetch");
    if (pop3_client_quit(&client) != 0) errx(1, "pop3_client_quit");
    pop3_client_free(&client);
    return 0;
}