//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

// Function to send a SYN packet to the specified host and port
int send_syn(int sockfd, const char *host, const int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &addr.sin_addr);
    int len = sizeof(addr);
    int rc = sendto(sockfd, &len, sizeof(len), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (rc < 0) {
        perror("sendto");
        exit(1);
    }
    return rc;
}

// Function to receive a SYN-ACK packet from the specified host and port
int recv_synack(int sockfd, const char *host, const int port) {
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &addr.sin_addr);
    int len = sizeof(addr);
    int rc = recvfrom(sockfd, &len, sizeof(len), 0, (struct sockaddr *)&addr, (socklen_t *)&len);
    if (rc < 0) {
        perror("recvfrom");
        exit(1);
    }
    return rc;
}

// Function to measure the round-trip time (RTT) between the local host and the specified host
double measure_rtt(const char *host, const int port) {
    struct timeval start, end;
    double rtt;
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    int rc = send_syn(sockfd, host, port);
    if (rc < 0) {
        perror("send_syn");
        exit(1);
    }
    int recv_len = 0;
    rc = recv_synack(sockfd, host, port);
    if (rc < 0) {
        perror("recv_synack");
        exit(1);
    }
    recv_len = ntohs(*(int *)recv_synack(sockfd, host, port));
    gettimeofday(&start, NULL);
    rc = recvfrom(sockfd, &recv_len, sizeof(recv_len), 0, NULL, NULL);
    if (rc < 0) {
        perror("recvfrom");
        exit(1);
    }
    gettimeofday(&end, NULL);
    rtt = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) * 1e-6;
    close(sockfd);
    return rtt;
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }
    const char *host = argv[1];
    const int port = atoi(argv[2]);
    double rtt = measure_rtt(host, port);
    printf("Round-trip time (RTT) to %s:%d: %f ms\n", host, port, rtt);
    return 0;
}