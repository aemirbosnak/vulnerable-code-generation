//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#define MAX_HOSTNAME 64
#define MAX_DATA 1024
#define TRUE 1
#define FALSE 0
#define PING_TIMEOUT 5  // in seconds

// Function to print error messages
void error_message(const char* message) {
    perror(message);
    exit(1);
}

// Function to print usage instructions
void print_usage() {
    printf("Usage:./ping <hostname>\n");
}

// Function to send a ping packet and receive a response
int send_ping(int sockfd, const char* hostname) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7);  // ICMP protocol

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        error_message("Invalid hostname");
    }

    int bytes_sent = sendto(sockfd, "PING", strlen("PING"), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (bytes_sent <= 0) {
        error_message("Failed to send ping packet");
    }

    char buffer[MAX_DATA];
    struct sockaddr_in client_addr;
    socklen_t addr_len = sizeof(client_addr);
    int bytes_received = recvfrom(sockfd, buffer, MAX_DATA, 0, (struct sockaddr*)&client_addr, &addr_len);
    if (bytes_received <= 0) {
        error_message("Failed to receive response");
    }

    if (strcmp(buffer, "PONG")!= 0) {
        printf("Invalid response received\n");
        return FALSE;
    }

    return TRUE;
}

// Function to measure round-trip time
double measure_rtt(int sockfd, const char* hostname) {
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    if (!send_ping(sockfd, hostname)) {
        return -1;
    }

    gettimeofday(&end_time, NULL);
    double rtt = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_usec - start_time.tv_usec) / 1000.0;
    return rtt;
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        print_usage();
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        error_message("Failed to create socket");
    }

    char hostname[MAX_HOSTNAME];
    strcpy(hostname, argv[1]);

    double rtt = measure_rtt(sockfd, hostname);
    if (rtt == -1) {
        printf("Host is not reachable\n");
    } else {
        printf("Round-trip time: %.2f ms\n", rtt);
    }

    close(sockfd);
    return 0;
}