//FormAI DATASET v1.0 Category: Network Ping Test ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define BUF_SIZE 1024
#define MAX_TRIES 3

void print_usage()
{
    printf("Usage: ./ping_test <hostname/IP-address> <port number>\n");
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        print_usage();
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock_fd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Get server address information
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;

    int ret = getaddrinfo(host, NULL, &hints, &result);
    if (ret != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in *sa = (struct sockaddr_in *)result->ai_addr;
    sa->sin_port = htons(port);

    // Send ping request to server
    char buf[BUF_SIZE];
    memset(buf, 0, sizeof(buf));
    strcpy(buf, "PING");

    struct timespec send_time;
    clock_gettime(CLOCK_MONOTONIC_RAW, &send_time);
    ssize_t bytes_sent = sendto(sock_fd, buf, sizeof(buf), 0, (struct sockaddr *)sa, sizeof(struct sockaddr_in));

    if (bytes_sent < 0) {
        perror("ping request send failed");
        exit(EXIT_FAILURE);
    }

    // Wait for response from server
    int tries = 0;
    char recv_buf[BUF_SIZE];
    memset(recv_buf, 0, sizeof(recv_buf));
    socklen_t addr_len = sizeof(struct sockaddr_in);

    while ((recvfrom(sock_fd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)sa, &addr_len) < 0) && (tries < MAX_TRIES)) {
        tries++;
        printf("Ping request failed, retrying...\n");

        // Send ping request to server
        memset(buf, 0, sizeof(buf));
        strcpy(buf, "PING");
        bytes_sent = sendto(sock_fd, buf, sizeof(buf), 0, (struct sockaddr *)sa, sizeof(struct sockaddr_in));

        if (bytes_sent < 0) {
            perror("ping request send failed");
            exit(EXIT_FAILURE);
        }
    }

    if (tries == MAX_TRIES) {
        printf("Max number of tries reached. Ping failed.\n");
    } else {
        struct timespec recv_time;
        clock_gettime(CLOCK_MONOTONIC_RAW, &recv_time);

        double rtt = (double)(recv_time.tv_sec - send_time.tv_sec) * 1000.0 + (double)(recv_time.tv_nsec - send_time.tv_nsec) / 1000000.0;

        printf("Ping successful! RTT = %.2f ms\n", rtt);
    }

    close(sock_fd);

    return 0;
}