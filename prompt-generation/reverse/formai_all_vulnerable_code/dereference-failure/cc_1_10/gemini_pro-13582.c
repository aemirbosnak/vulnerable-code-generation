//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 8192

int start_test(const char *host, int port) {
    struct sockaddr_in addr;
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &addr.sin_addr) != 1) {
        perror("inet_pton");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return -1;
    }

    return sock;
}

void test_speed(int sock) {
    char buf[BUF_SIZE];
    struct timeval start, end;
    double elapsed;
    int bytes_recv = 0;

    gettimeofday(&start, NULL);
    while (1) {
        int bytes = recv(sock, buf, BUF_SIZE, 0);
        if (bytes == -1) {
            perror("recv");
            return;
        } else if (bytes == 0) {
            break;
        }

        bytes_recv += bytes;
    }
    gettimeofday(&end, NULL);

    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    double speed = (bytes_recv / elapsed) * 8 / 1024 / 1024;
    printf("Speed: %.2f Mbps\n", speed);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    int sock = start_test(argv[1], atoi(argv[2]));
    if (sock == -1) {
        return 1;
    }

    test_speed(sock);
    close(sock);

    return 0;
}