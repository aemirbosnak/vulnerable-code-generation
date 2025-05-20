//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Custom datatypes and declarations
typedef struct {
    int sockfd;
    struct sockaddr_in serveraddr;
    socklen_t serveraddrlen;
    char *buffer;
    size_t bufferlen;
} socket_ctx_t;

// Custom functions
void init_socket_ctx(socket_ctx_t *ctx, char *ip, int port) {
    ctx->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (ctx->sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&ctx->serveraddr, 0, sizeof(ctx->serveraddr));
    ctx->serveraddr.sin_family = AF_INET;
    ctx->serveraddr.sin_port = htons(port);
    if (inet_aton(ip, &ctx->serveraddr.sin_addr) == 0) {
        perror("inet_aton");
        exit(1);
    }

    ctx->serveraddrlen = sizeof(ctx->serveraddr);
    ctx->buffer = NULL;
    ctx->bufferlen = 0;
}

void connect_socket(socket_ctx_t *ctx) {
    if (connect(ctx->sockfd, (struct sockaddr *)&ctx->serveraddr, ctx->serveraddrlen) < 0) {
        perror("connect");
        exit(1);
    }
}

void send_data(socket_ctx_t *ctx, char *data, size_t datalen) {
    if (send(ctx->sockfd, data, datalen, 0) < 0) {
        perror("send");
        exit(1);
    }
}

void recv_data(socket_ctx_t *ctx) {
    ctx->buffer = realloc(ctx->buffer, ctx->bufferlen + 1024);
    if (ctx->buffer == NULL) {
        perror("realloc");
        exit(1);
    }

    int n = recv(ctx->sockfd, ctx->buffer + ctx->bufferlen, 1024, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }

    ctx->bufferlen += n;
}

// Main program
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    socket_ctx_t ctx;
    init_socket_ctx(&ctx, argv[1], atoi(argv[2]));
    connect_socket(&ctx);

    // QoS monitoring logic
    while (1) {
        // Send a test packet to the server
        send_data(&ctx, "ping", 4);

        // Receive the response from the server
        recv_data(&ctx);

        // Parse the response to get QoS metrics (e.g., latency, jitter)
        // Display the QoS metrics on the console or store them for analysis

        // Sleep for a short period of time before sending the next test packet
        sleep(1);
    }

    close(ctx.sockfd);
    free(ctx.buffer);

    return 0;
}