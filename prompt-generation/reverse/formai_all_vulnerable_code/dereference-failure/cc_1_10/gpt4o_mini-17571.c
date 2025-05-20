//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <signal.h>

#define MAX_PINGS 4
#define BUFFER_SIZE 1024

void draw_shape(int shape) {
    switch (shape) {
        case 0:
            printf("\r👾");
            break;
        case 1:
            printf("\r🌍");
            break;
        case 2:
            printf("\r✨");
            break;
        case 3:
            printf("\r🌈");
            break;
    }
    fflush(stdout);
}

void ping(const char *ip_addr) {
    int ping_sock;
    struct sockaddr_in addr_ping;
    char buffer[BUFFER_SIZE];
    ssize_t recv_len;
    struct timeval start_time, end_time;
    struct timeval timeout;
    fd_set read_fds;

    ping_sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (ping_sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&addr_ping, 0, sizeof(addr_ping));
    addr_ping.sin_family = AF_INET;
    addr_ping.sin_addr.s_addr = inet_addr(ip_addr);
    
    for (int i = 0; i < MAX_PINGS; i++) {
        // Prepare ping packet
        sprintf(buffer, "Ping #%d ", i + 1);
        
        // Get start time
        gettimeofday(&start_time, NULL);
        
        // Send ping
        if (sendto(ping_sock, buffer, strlen(buffer), 0, (struct sockaddr*)&addr_ping, sizeof(addr_ping)) <= 0) {
            perror("Error sending packet");
        }

        // Set timeout for receive with fds
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;
        FD_ZERO(&read_fds);
        FD_SET(ping_sock, &read_fds);

        // Wait for reply
        if (select(ping_sock + 1, &read_fds, NULL, NULL, &timeout) > 0) {
            recv_len = recv(ping_sock, buffer, sizeof(buffer), 0);
            if (recv_len < 0) {
                perror("Error receiving reply");
            } else {
                gettimeofday(&end_time, NULL);
                double time_taken = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;
                printf("Received reply: %s - Time: %.2f ms\n", buffer, time_taken);
            }
        } else {
            printf("Request timed out\n");
        }

        // Draw shape during waiting period
        for (int j = 0; j < 4; j++) {
            draw_shape(j);
            usleep(250000); // Sleep for 250 ms
        }
    }

    close(ping_sock);
    printf("\nPing test completed.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    ping(argv[1]);
    return 0;
}