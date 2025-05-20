//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFLEN 1024
#define TRUE 1
#define FALSE 0
#define TIMEOUT 5000 // 5 seconds

void die(const char *s) {
    perror(s);
    exit(EXIT_FAILURE);
}

int ping(const char *hostname, int count, int interval) {
    int sock, ret, len;
    struct sockaddr_in addr;
    char buf[BUFLEN];
    struct timeval timeout;
    fd_set fds;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        die("socket");
    }

    if (inet_pton(AF_INET, hostname, &addr.sin_addr) <= 0) {
        die("inet_pton");
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(7); // Echo port

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        die("connect");
    }

    for (int i = 0; i < count; i++) {
        FD_ZERO(&fds);
        FD_SET(sock, &fds);

        timeout.tv_sec = interval / 1000;
        timeout.tv_usec = (interval % 1000) * 1000;

        ret = select(sock + 1, NULL, &fds, NULL, &timeout);

        if (ret == -1) {
            die("select");
        } else if (ret > 0) {
            if (FD_ISSET(sock, &fds)) {
                len = recv(sock, buf, BUFLEN, 0);

                if (len <= 0) {
                    die("recv");
                }

                buf[len] = '\0';
                printf("%s", buf);
            }
        } else {
            printf("Timeout\n");
        }

        usleep(interval * 1000);
    }

    close(sock);
    return TRUE;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s hostname count interval\n", argv[0]);
        return FALSE;
    }

    char *hostname = argv[1];
    int count = atoi(argv[2]);
    int interval = atoi(argv[3]);

    ping(hostname, count, interval);

    return 0;
}