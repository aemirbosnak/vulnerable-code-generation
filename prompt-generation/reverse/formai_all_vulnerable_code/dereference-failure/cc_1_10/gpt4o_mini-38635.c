//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>

#define PACKET_SIZE 64
#define MAX_ATTEMPTS 4
#define TIMEOUT 1

typedef struct {
    char hostname[256];
    int attempts;
    int received;
    int sent;
    double total_time;
} PingTest;

void handle_alarm(int signal) {
    // Timeout function
}

double get_time_difference(struct timespec start, struct timespec end) {
    return (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
}

int ping(const char *hostname, int attempts) {
    struct addrinfo hints, *res;
    char buffer[PACKET_SIZE];
    int sockfd;
    char ip_str[INET6_ADDRSTRLEN];
    int sent = 0, received = 0;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;  // IPv4
    hints.ai_socktype = SOCK_DGRAM; // Datagram socket

    if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
        perror("getaddrinfo");
        return -1;
    }

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
        perror("socket");
        freeaddrinfo(res);
        return -1;
    }

    for (int i = 0; i < attempts; i++) {
        struct timespec start, end;
        snprintf(buffer, sizeof(buffer), "Ping request %d", i + 1);
        socklen_t addr_len = res->ai_addrlen;

        // Sending ping
        if (sendto(sockfd, buffer, strlen(buffer), 0, res->ai_addr, addr_len) < 0) {
            perror("sendto");
            break;
        }
        sent++;

        // Set up alarm for timeout
        signal(SIGALRM, handle_alarm);
        alarm(TIMEOUT);

        // Record the start time
        clock_gettime(CLOCK_MONOTONIC, &start);
        
        // Wait for a response
        if (recvfrom(sockfd, buffer, sizeof(buffer), 0, res->ai_addr, &addr_len) > 0) {
            // Response received
            clock_gettime(CLOCK_MONOTONIC, &end);
            received++;
            double time_taken = get_time_difference(start, end) * 1000; // convert to milliseconds
            inet_ntop(res->ai_family, &((struct sockaddr_in *)res->ai_addr)->sin_addr, ip_str, sizeof(ip_str));
            printf("Reply from %s: time=%.2fms\n", ip_str, time_taken);
        } else {
            // Timeout or error
            printf("Request timeout for ping %d\n", i + 1);
        }

        alarm(0); // Disable the alarm
    }

    freeaddrinfo(res);
    close(sockfd);

    printf("\n--- %s ping statistics ---\n", hostname);
    printf("%d packets transmitted, %d received, %.1f%% packet loss\n", sent, received, 
           sent > 0 ? ((sent - received) / (double)sent) * 100 : 0.0);
    return 0;
}

int main(int argc, char *argv[]) {
    PingTest test;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(test.hostname, argv[1], sizeof(test.hostname) - 1);
    test.hostname[sizeof(test.hostname) - 1] = '\0';
    test.attempts = MAX_ATTEMPTS;
    test.received = 0;
    test.sent = 0;
    test.total_time = 0.0;

    printf("Pinging %s with %d bytes of data:\n\n", test.hostname, PACKET_SIZE);

    ping(test.hostname, test.attempts);

    return 0;
}