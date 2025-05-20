//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct config {
    int sock;
    char host[256];
    int port;
};

void init_config(struct config *cfg) {
    cfg->sock = socket(AF_INET, SOCK_STREAM, 0);
    cfg->host[0] = '\0';
    cfg->port = PORT;
}

void set_host(struct config *cfg, char *host) {
    strcpy(cfg->host, host);
}

void set_port(struct config *cfg, int port) {
    cfg->port = port;
}

int main(int argc, char *argv[]) {
    struct config cfg;

    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    init_config(&cfg);

    set_host(&cfg, argv[1]);
    set_port(&cfg, atoi(argv[2]));

    if (connect(cfg.sock, (struct sockaddr *)&cfg.host, sizeof(cfg.host)) < 0) {
        perror("connect failed");
        return 1;
    }

    printf("Connected to %s on port %d\n", cfg.host, cfg.port);

    char buffer[1024];
    recv(cfg.sock, buffer, 1024, 0);
    printf("Received message: %s\n", buffer);

    char message[] = "Hello, client!";
    send(cfg.sock, message, strlen(message), 0);

    recv(cfg.sock, buffer, 1024, 0);
    printf("Received response: %s\n", buffer);

    close(cfg.sock);

    return 0;
}