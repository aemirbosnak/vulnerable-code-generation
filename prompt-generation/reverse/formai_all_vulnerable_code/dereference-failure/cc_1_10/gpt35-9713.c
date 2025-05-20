//FormAI DATASET v1.0 Category: Network Ping Test ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>

#define MAX_PING_COUNT 1000
#define PING_SLEEP_TIME 1000000

// Function to calculate the time difference
double time_diff(struct timeval x, struct timeval y) {
    double x_ms, y_ms, diff;
     
    x_ms = (double)x.tv_sec*1000000 + (double)x.tv_usec;
    y_ms = (double)y.tv_sec*1000000 + (double)y.tv_usec;
     
    diff = (double)y_ms - (double)x_ms;
     
    return diff;
}

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Usage: ./ping hostname\n");
        exit(0);
    }

    char *hostname = argv[1];
    int sockfd, count = 0, recv_count = 0;
    double rtt_sum = 0;
    struct sockaddr_in servaddr;
    char sendbuff[100], recvbuff[100];
    struct timeval start_time, end_time;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
        printf("Socket creation failed with error: %d\n", errno);
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(0); // kernel will assign the port number
    servaddr.sin_addr.s_addr = inet_addr(hostname);

    printf("PING %s:\n", hostname);

    while(count < MAX_PING_COUNT) {

        // Preparing the ICMP packet to send
        bzero(sendbuff, sizeof sendbuff);
        snprintf(sendbuff, sizeof sendbuff, "PING %d %ld", getpid(), time(NULL));

        // Set start time
        gettimeofday(&start_time, NULL);

        // Send ICMP packet
        if (sendto(sockfd, sendbuff, sizeof sendbuff, 0, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
            printf("Error sending ICMP packet: %d\n", errno);
            break;
        }

        // Receive the response
        bzero(recvbuff, sizeof recvbuff);
        if(recvfrom(sockfd, recvbuff, sizeof recvbuff, 0, NULL, NULL) < 0) {
            printf("Error receiving ICMP packet: %d\n", errno);
            break;
        }

        // Set end time
        gettimeofday(&end_time, NULL);

        // Calculate Round Trip Time (rtt) in milliseconds
        double rtt = time_diff(start_time, end_time) / 1000.0;

        // Update stats
        rtt_sum += rtt;
        recv_count++;
        count++;

        // Print the response
        printf("Response from %s: bytes=%d time=%.2fms\n", hostname, (int) sizeof(recvbuff), rtt);

        // Sleep for PING_SLEEP_TIME microseconds before sending next packet
        usleep(PING_SLEEP_TIME);
    }

    // Print stats
    printf("\n--- %s ping statistics ---\n", hostname);
    printf("%d packets transmitted, %d received, %.0f%% packet loss, time %.0fms\n",
                        count, recv_count, ((count - recv_count) / (double)count) * 100.0, rtt_sum);
    printf("rtt min/avg/max = %.2f/%.2f/%.2f ms\n", 0.0, rtt_sum / recv_count, 0.0);

    return 0;
}