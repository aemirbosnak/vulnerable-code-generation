//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>

#ifndef NI_MAXHOST
#define NI_MAXHOST 1024
#endif

#define ICMP_ECHOREPLY 0
#define ICMP_ECHOREQUEST 8
#define ICMP_MAXLEN 65535

#define PORT_MAX 65535
#define TIMEOUT_MS 500

typedef struct {
    int fd;
    struct sockaddr_in addr;
    socklen_t addrlen;
    struct timeval timeout;
} ping_t;

static int ping_init(ping_t *ping, const char *host, int port) {
    struct addrinfo hints = {0};
    struct addrinfo *res = NULL;
    int err;

    ping->fd = -1;

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_RAW;
    hints.ai_protocol = IPPROTO_ICMP;

    err = getaddrinfo(host, NULL, &hints, &res);
    if (err) {
        perror("getaddrinfo");
        return -1;
    }

    ping->addr = *(struct sockaddr_in *)res->ai_addr;
    ping->addr.sin_port = htons(port);
    ping->addrlen = res->ai_addrlen;

    ping->timeout.tv_sec = TIMEOUT_MS / 1000;
    ping->timeout.tv_usec = (TIMEOUT_MS % 1000) * 1000;

    ping->fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (ping->fd == -1) {
        perror("socket");
        freeaddrinfo(res);
        return -1;
    }

    setsockopt(ping->fd, SOL_SOCKET, SO_RCVTIMEO, &ping->timeout, sizeof(ping->timeout));
    setsockopt(ping->fd, SOL_SOCKET, SO_SNDTIMEO, &ping->timeout, sizeof(ping->timeout));

    freeaddrinfo(res);

    return 0;
}

static void ping_fini(ping_t *ping) {
    if (ping->fd != -1) {
        close(ping->fd);
        ping->fd = -1;
    }
}

static int ping_send(ping_t *ping, const void *data, size_t datalen) {
    return sendto(ping->fd, data, datalen, 0, (struct sockaddr *)&ping->addr, ping->addrlen);
}

static int ping_recv(ping_t *ping, void *data, size_t datalen) {
    return recvfrom(ping->fd, data, datalen, 0, NULL, NULL);
}

static int ping_check(ping_t *ping) {
    char recvbuf[ICMP_MAXLEN];
    int recvdatalen;
    int i;

    recvdatalen = ping_recv(ping, recvbuf, sizeof(recvbuf));
    if (recvdatalen == -1) {
        return -1;
    }

    if (recvdatalen < sizeof(struct icmphdr)) {
        return -1;
    }

    struct icmphdr *icmphdr = (struct icmphdr *)recvbuf;
    if (icmphdr->type != ICMP_ECHOREPLY) {
        return -1;
    }

    for (i = 0; i < recvdatalen; i++) {
        if (recvbuf[i] != i) {
            return -1;
        }
    }

    return 0;
}


int main(int argc, char *argv[]) {
    ping_t ping;
    char host[NI_MAXHOST];
    int port;
    int i;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strncpy(host, argv[1], sizeof(host) - 1);
    host[sizeof(host) - 1] = '\0';

    port = atoi(argv[2]);
    if (port < 1 || port > PORT_MAX) {
        fprintf(stderr, "Invalid port: %d\n", port);
        return EXIT_FAILURE;
    }

    if (ping_init(&ping, host, port) == -1) {
        return EXIT_FAILURE;
    }

    //

    char data[ICMP_MAXLEN];
    for (i = 0; i < sizeof(data); i++) {
        data[i] = i;
    }

    printf("Scanning port %d on host %s...\n", port, host);
    fflush(stdout);

   //

    if (ping_send(&ping, data, sizeof(data)) == -1) {
        perror("sendto");
        ping_fini(&ping);
        return EXIT_FAILURE;
    }

    if (ping_check(&ping) == -1) {
        printf("Port %d is closed\n", port);
    } else {
        printf("Port %d is open\n", port);
    }

    ping_fini(&ping);

    return EXIT_SUCCESS;
}