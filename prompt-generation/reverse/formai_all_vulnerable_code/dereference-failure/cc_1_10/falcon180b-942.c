//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/time.h>

#define MAX_HOSTS 100
#define TIMEOUT 1000 // milliseconds

struct host_info {
    char *host;
    int port;
    int sock;
};

int ping(struct host_info *host) {
    char buf[1024];
    struct timeval tv;
    fd_set fds;
    int ret, len;

    tv.tv_sec = TIMEOUT / 1000;
    tv.tv_usec = (TIMEOUT % 1000) * 1000;

    FD_ZERO(&fds);
    FD_SET(host->sock, &fds);

    ret = select(host->sock + 1, NULL, &fds, NULL, &tv);

    if (ret == 0) {
        printf("%s is not responding\n", host->host);
        return -1;
    } else if (ret == -1) {
        perror("select");
        return -1;
    }

    len = recv(host->sock, buf, sizeof(buf), 0);

    if (len <= 0) {
        printf("%s is not responding\n", host->host);
        return -1;
    }

    printf("%s is responding\n", host->host);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("%s is responding\n", host);

    return 0;
}