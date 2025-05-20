//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <target IP address> <timeout in seconds>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in dest;
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = 0;
    dest.sin_addr.s_addr = inet_addr(argv[1]);

    if (sendto(sock, "\x00\x00\x00\x00", 4, 0, (struct sockaddr *)&dest, sizeof(dest)) < 0) {
        perror("sendto");
        exit(1);
    }

    struct timeval timeout;
    timeout.tv_sec = atoi(argv[2]);
    timeout.tv_usec = 0;

    int n = recvfrom(sock, "", 1, 0, NULL, NULL);
    if (n > 0) {
        if (n == 4) {
            printf("Ping successful\n");
        } else {
            printf("Ping failed\n");
        }
    } else {
        perror("recvfrom");
        exit(1);
    }

    close(sock);
    return 0;
}