//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>

#define SIZE 1024
#define TRUE 1
#define FALSE 0
#define TIMEOUT 5

int main(int argc, char *argv[]) {
    int sock, ret, len, i;
    struct sockaddr_in addr;
    char send_buf[SIZE], recv_buf[SIZE];
    fd_set read_fds;
    struct timeval tv;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket error\n");
        exit(1);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(7);

    if (argc > 1) {
        inet_pton(AF_INET, argv[1], &addr.sin_addr);
    } else {
        inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);
    }

    ret = connect(sock, (struct sockaddr *)&addr, sizeof(addr));
    if (ret == -1) {
        printf("connect error\n");
        exit(1);
    }

    FD_ZERO(&read_fds);
    FD_SET(sock, &read_fds);

    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    ret = select(sock + 1, &read_fds, NULL, NULL, &tv);
    if (ret == -1) {
        printf("select error\n");
        exit(1);
    }

    if (FD_ISSET(sock, &read_fds)) {
        len = recv(sock, recv_buf, SIZE, 0);
        if (len <= 0) {
            printf("recv error\n");
            exit(1);
        }

        recv_buf[len] = '\0';
        printf("ping response: %s\n", recv_buf);
    } else {
        printf("no response\n");
    }

    close(sock);
    return 0;
}