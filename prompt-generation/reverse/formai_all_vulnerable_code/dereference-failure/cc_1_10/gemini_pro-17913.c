//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/time.h>

int main(int argc, char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <packets>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* host = argv[1];
    int port = atoi(argv[2]);
    int packets = atoi(argv[3]);

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    char* buf = malloc(1024);
    if (buf == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < packets; i++) {
        memset(buf, 0, 1024);
        sprintf(buf, "PING %d\n", i);
        int len = strlen(buf);

        struct timeval start, end;
        gettimeofday(&start, NULL);

        int sent = sendto(sock, buf, len, 0, (struct sockaddr*)&addr, sizeof(addr));
        if (sent < 0) {
            perror("sendto");
            continue;
        }

        int received = recvfrom(sock, buf, 1024, 0, NULL, NULL);
        if (received < 0) {
            perror("recvfrom");
            continue;
        }

        gettimeofday(&end, NULL);
        long long elapsed = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec);

        printf("PING %d: %lld ms\n", i, elapsed / 1000);
    }

    free(buf);
    close(sock);

    return 0;
}