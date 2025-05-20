//GPT-4o-mini DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <errno.h>

#define PACKET_SIZE 64
#define TIMEOUT 1
#define MAX_ATTEMPTS 5

typedef struct {
    char ip[16];
    int successful_pings;
    int total_pings;
} PingResult;

void send_ping(const char* ip_address);
void sigalrm_handler(int signal);
void ping(const char* ip_address);
void print_results(PingResult result);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    ping(argv[1]);
    return EXIT_SUCCESS;
}

void ping(const char* ip_address) {
    struct sockaddr_in addr;
    strcpy(addr.sin_zero, "\0");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    if (inet_pton(AF_INET, ip_address, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", ip_address);
        return;
    }

    PingResult result;
    strcpy(result.ip, ip_address);
    result.successful_pings = 0;
    result.total_pings = 0;

    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        send_ping(ip_address);
        result.total_pings++;
        sleep(1);
    }

    print_results(result);
}

void send_ping(const char* ip_address) {
    int sockfd;
    struct sockaddr_in addr;
    char packet[PACKET_SIZE];
    struct timeval start, end;

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    if (inet_pton(AF_INET, ip_address, &addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", ip_address);
        return;
    }

    memset(packet, 0, PACKET_SIZE);
    if (sendto(sockfd, packet, PACKET_SIZE, 0, (struct sockaddr*)&addr, sizeof(addr)) <= 0) {
        perror("Sending packet failed");
        close(sockfd);
        return;
    }

    signal(SIGALRM, sigalrm_handler);
    alarm(TIMEOUT);

    gettimeofday(&start, NULL);
    char buffer[PACKET_SIZE];
    socklen_t addr_len = sizeof(addr);

    if (recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&addr, &addr_len) < 0) {
        if (errno == EINTR) {
            printf("Request timed out for %s\n", ip_address);
        } else {
            perror("Error receiving packet");
        }
    } else {
        gettimeofday(&end, NULL);
        double time_taken = (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
        printf("Reply from %s: time=%.2f ms\n", ip_address, time_taken);
    }

    close(sockfd);
}

void sigalrm_handler(int signal) {
    // Timeout handler
}

void print_results(PingResult result) {
    printf("\n--- Ping statistics for %s ---\n", result.ip);
    printf("%d packets transmitted, %d received, %.2f%% packet loss\n",
           result.total_pings, result.successful_pings,
           ((result.total_pings - result.successful_pings) / (double)result.total_pings) * 100);
}