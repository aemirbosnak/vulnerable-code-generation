//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80
#define MAX_REQS 10

int ping(char* ip, int timeout) {
    int sockfd, n, total_sent = 0, total_recv = 0, send_len = 0, recv_len = 0;
    struct sockaddr_in addr;
    char buffer[4096];

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip);
    addr.sin_port = htons(PORT);

    send_len = sendto(sockfd, "ping ", strlen("ping "), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (send_len < 0) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    recv_len = recv(sockfd, buffer, sizeof(buffer), 0);
    if (recv_len < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    total_sent += send_len;
    total_recv += recv_len;

    close(sockfd);
    return (recv_len - send_len);
}

int ping_test(char* ip[], int timeout) {
    int i, j, success = 0;
    int total_sent = 0, total_recv = 0;

    for (i = 0; i < MAX_REQS; i++) {
        total_sent += ping(ip[i], timeout);
    }

    for (i = 0; i < MAX_REQS; i++) {
        for (j = 0; j < MAX_REQS; j++) {
            if (i!= j) {
                success += (ping(ip[j], timeout) == 0);
            }
        }
    }

    return success;
}

int main(int argc, char* argv[]) {
    char* ip[MAX_REQS];
    int i, j, timeout = 1;

    for (i = 1; i < argc; i++) {
        ip[i-1] = argv[i];
    }

    if (argc > 1) {
        timeout = atoi(argv[argc-1]);
    }

    printf("Testing %d IPs...\n", MAX_REQS);
    ping_test(ip, timeout);
    printf("Test complete!\n");

    return 0;
}