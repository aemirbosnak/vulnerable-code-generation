//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/time.h>

#define MAX_PKTS 1000
#define PKT_SIZE 1024

int main(int argc, char **argv)
{
    int sockfd, n, i;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[PKT_SIZE];
    struct timeval start, end;
    double rtt, avg_rtt = 0.0;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    for (i = 0; i < MAX_PKTS; i++) {
        gettimeofday(&start, NULL);
        n = sendto(sockfd, buffer, PKT_SIZE, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        if (n < 0) {
            perror("sendto");
            exit(1);
        }

        n = recvfrom(sockfd, buffer, PKT_SIZE, 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            exit(1);
        }

        gettimeofday(&end, NULL);
        rtt = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
        avg_rtt += rtt;

        printf("Packet %d: RTT = %.2f ms\n", i + 1, rtt);
    }

    avg_rtt /= MAX_PKTS;
    printf("Average RTT: %.2f ms\n", avg_rtt);

    close(sockfd);
    return 0;
}