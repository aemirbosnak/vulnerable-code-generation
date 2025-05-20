//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define TIMEOUT_SEC 2
#define TIMEOUT_USEC 0
#define PAYLOAD_SIZE 32

typedef struct {
    struct sockaddr_in addr;
    socklen_t addrlen;
    int sockfd;
    char payload[PAYLOAD_SIZE];
    time_t send_time;
    time_t recv_time;
    int recvlen;
} ping_context;

void cleanup(ping_context *ctx) {
    if (ctx->sockfd != -1) {
        close(ctx->sockfd);
    }
}

void alarm_handler(int signum) {
    printf("Timeout\n");
    exit(EXIT_SUCCESS);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    ping_context ctx;
    memset(&ctx, 0, sizeof(ping_context));
    ctx.addr.sin_family = AF_INET;
    ctx.addr.sin_port = htons(80);
    ctx.addr.sin_addr = *(struct in_addr *) host->h_addr;
    ctx.addrlen = sizeof(struct sockaddr_in);
    ctx.sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (ctx.sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < PAYLOAD_SIZE; i++) {
        ctx.payload[i] = 'a' + (i % 26);
    }

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_SEC;
    timeout.tv_usec = TIMEOUT_USEC;
    if (setsockopt(ctx.sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        cleanup(&ctx);
        return EXIT_FAILURE;
    }

    signal(SIGALRM, alarm_handler);
    alarm(TIMEOUT_SEC + 1);

    while (1) {
        ctx.send_time = time(NULL);
        if (sendto(ctx.sockfd, ctx.payload, PAYLOAD_SIZE, 0, (struct sockaddr *) &ctx.addr, ctx.addrlen) == -1) {
            perror("sendto");
            cleanup(&ctx);
            return EXIT_FAILURE;
        }

        ctx.recvlen = recvfrom(ctx.sockfd, ctx.payload, PAYLOAD_SIZE, 0, (struct sockaddr *) &ctx.addr, &ctx.addrlen);
        ctx.recv_time = time(NULL);

        if (ctx.recvlen == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                continue;
            } else {
                perror("recvfrom");
                cleanup(&ctx);
                return EXIT_FAILURE;
            }
        } else if (ctx.recvlen != PAYLOAD_SIZE) {
            fprintf(stderr, "Invalid payload size: %d\n", ctx.recvlen);
            continue;
        } else if (memcmp(ctx.payload, "pong", 4) != 0) {
            fprintf(stderr, "Invalid payload: %.*s\n", ctx.recvlen, ctx.payload);
            continue;
        }

        long long delay = (ctx.recv_time - ctx.send_time) * 1000 + (ctx.recv_time - ctx.send_time) / 1000;
        printf("%lld ms\n", delay);
        break;
    }

    cleanup(&ctx);

    return EXIT_SUCCESS;
}