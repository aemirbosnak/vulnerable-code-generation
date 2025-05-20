//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char **argv)
{
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &addr.sin_addr);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    struct timespec start, end;
    double elapsed;

    char buf[1024];
    memset(buf, 0, sizeof(buf));
    strcpy(buf, "PING");

    int addr_len = sizeof(addr);

    int sent = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&addr, addr_len);
    if (sent < 0) {
        perror("sendto");
        close(sockfd);
        return 1;
    }

    clock_gettime(CLOCK_MONOTONIC, &start);

    int recv_len = recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, &addr_len);
    if (recv_len < 0) {
        perror("recvfrom");
        close(sockfd);
        return 1;
    }

    clock_gettime(CLOCK_MONOTONIC, &end);

    elapsed = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_nsec - start.tv_nsec) / 1000000.0;

    printf("Ping: %s (%s): bytes=%d time=%0.3fms\n", argv[1], inet_ntoa(addr.sin_addr), recv_len, elapsed);

    close(sockfd);

    return 0;
}