//FormAI DATASET v1.0 Category: Network Ping Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/time.h>

#define BUFFER_SIZE 100

// Function to calculate the time difference between two timevals
double timeval_diff(struct timeval *start_time, struct timeval *end_time)
{
    return (double)((end_time->tv_sec * (double)1000000 + end_time->tv_usec) - (start_time->tv_sec * (double)1000000 + start_time->tv_usec)) / 1000;
}

int main(int argc, char* argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [hostname/IP address]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* host_name = argv[1];
    struct hostent* host_info = gethostbyname(host_name);

    if (host_info == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", host_name);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in s_address;
    memset(&s_address, 0, sizeof(s_address));
    s_address.sin_family = AF_INET;
    s_address.sin_port = htons(80);
    memcpy(&s_address.sin_addr.s_addr, host_info->h_addr, host_info->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: socket() failed");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, (struct sockaddr*)&s_address, sizeof(s_address)) < 0) {
        perror("Error: connect() failed");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    long double avg_rtt = 0;
    int packet_loss_count = 0;
    int sequence_number = 0;
    int max_hop_count = 100;
    int ttl = 1;
    int opt_val = 1;

    struct timeval start_time, end_time;
    fd_set read_fd_set;
    FD_ZERO(&read_fd_set);
    FD_SET(sockfd, &read_fd_set);

    setsockopt(sockfd, IPPROTO_IP, IP_TTL, &ttl, sizeof(int));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&opt_val, sizeof(int));

    printf("PING %s\n", argv[1]);

    while (ttl <= max_hop_count) {
        memset(&buffer, 0, sizeof(buffer));
        sprintf(buffer, "PING %d ", ttl);
        gettimeofday(&start_time, NULL);
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            printf("Packet sending failed.\n");
        }

        if (select(sockfd + 1, &read_fd_set, NULL, NULL, NULL) > 0) {
            int recv_bytes = recv(sockfd, buffer, sizeof(buffer)-1, 0);
            gettimeofday(&end_time, NULL);

            if (recv_bytes > 0) {
                sequence_number++;
                double rtt = timeval_diff(&start_time, &end_time);
                printf("%d bytes from %s: PING seq=%d ttl=%d time=%.3f ms\n", recv_bytes, argv[1], sequence_number, ttl, rtt);
                avg_rtt += rtt;
            }
            else {
                packet_loss_count++;
                printf("Request timed out.\n");
            }
        }
        else {
            packet_loss_count++;
            printf("Request timed out.\n");
        }

        ttl++;
    }

    if (avg_rtt > 0) {
        avg_rtt /= (double)(sequence_number);
        printf("--- ping statistics ---\n");
        printf("%d packets transmitted, %d received, %d%% packet loss, time %.0Lfms\n", sequence_number, sequence_number - packet_loss_count, (int)((double)packet_loss_count / sequence_number * 100.0), avg_rtt);
    }
    else {
        printf("--- ping statistics ---\n");
        printf("%d packets transmitted, 0 received, 100%% packet loss\n", sequence_number);
    }

    close(sockfd);

    return 0;
}