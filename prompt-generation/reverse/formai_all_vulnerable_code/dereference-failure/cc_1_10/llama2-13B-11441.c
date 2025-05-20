//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct genius_socket {
    int sock;
    char *ip;
    int port;
};

void genius_socket_init(struct genius_socket *s) {
    s->sock = socket(AF_INET, SOCK_STREAM, 0);
    s->ip = malloc(INET_ADDRSTRLEN);
    s->port = PORT;
}

void genius_socket_destroy(struct genius_socket *s) {
    close(s->sock);
    free(s->ip);
}

int genius_socket_connect(struct genius_socket *s, char *ip, int port) {
    memset(&s->ip, 0, INET_ADDRSTRLEN);
    inet_pton(AF_INET, ip, &s->ip);
    s->port = port;
    return connect(s->sock, (struct sockaddr *)&s->ip, sizeof(s->ip));
}

int genius_socket_send(struct genius_socket *s, char *data, int len) {
    return send(s->sock, data, len, 0);
}

int genius_socket_recv(struct genius_socket *s, char *data, int len) {
    return recv(s->sock, data, len, 0);
}

int main() {
    struct genius_socket s;
    char *ip = "127.0.0.1";
    int port = 8080;

    genius_socket_init(&s);
    if (genius_socket_connect(&s, ip, port) < 0) {
        perror("connect failed");
        return 1;
    }

    char message[] = "Hello, world!";
    if (genius_socket_send(&s, message, sizeof(message)) < 0) {
        perror("send failed");
        return 1;
    }

    char buffer[1024];
    int len = genius_socket_recv(&s, buffer, sizeof(buffer));
    if (len < 0) {
        perror("recv failed");
        return 1;
    }

    printf("%s\n", buffer);

    genius_socket_destroy(&s);
    return 0;
}