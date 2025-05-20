//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PING_PACKET_SIZE 64

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <number of pings>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int num_pings = atoi(argv[2]);

    struct sockaddr_in server_addr;
    struct hostent *host;

    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Failed to resolve hostname %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    char ping_packet[PING_PACKET_SIZE];
    memset(ping_packet, 0, PING_PACKET_SIZE);

    struct timeval start_time, end_time;
    long long total_time = 0;
    int num_received = 0;

    for (int i = 0; i < num_pings; i++) {
        gettimeofday(&start_time, NULL);

        if (sendto(sockfd, ping_packet, PING_PACKET_SIZE, 0, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            fprintf(stderr, "Failed to send ping packet\n");
            continue;
        }

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);

        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        int num_fds = select(sockfd + 1, &read_fds, NULL, NULL, &timeout);
        if (num_fds < 0) {
            fprintf(stderr, "Failed to select on socket\n");
            continue;
        }

        if (FD_ISSET(sockfd, &read_fds)) {
            char recv_packet[PING_PACKET_SIZE];
            struct sockaddr_in recv_addr;
            socklen_t recv_addr_len = sizeof(recv_addr);

            if (recvfrom(sockfd, recv_packet, PING_PACKET_SIZE, 0, (struct sockaddr *)&recv_addr, &recv_addr_len) < 0) {
                fprintf(stderr, "Failed to receive ping packet\n");
                continue;
            }

            gettimeofday(&end_time, NULL);
            total_time += (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);
            num_received++;
        }
    }

    close(sockfd);

    double avg_time = (double)total_time / num_received;

    printf("Average ping time: %.2f ms\n", avg_time);
    printf("Number of pings received: %d\n", num_received);

    return 0;
}