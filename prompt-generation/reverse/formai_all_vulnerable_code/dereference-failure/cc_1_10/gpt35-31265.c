//FormAI DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024
#define DEFAULT_PORT 80
#define DEFAULT_TIMEOUT 1

void print_usage() {
    printf("Usage: ./ping [hostname or IP address]\n");
}

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    return sockfd;
}

struct sockaddr_in create_address(char* ip_address, int port) {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip_address, &(server_addr.sin_addr));
    return server_addr;
}

double calculate_time_diff(struct timespec start, struct timespec end) {
    return (double) (end.tv_sec - start.tv_sec) + ((double) (end.tv_nsec - start.tv_nsec) / 1000000000.0);
}

int ping(char* ip_address) {
    int sockfd = create_socket();
    struct sockaddr_in server_addr = create_address(ip_address, DEFAULT_PORT);
    struct timespec start_time, end_time;
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    snprintf(buffer, BUFFER_SIZE, "GET / HTTP/1.1\nHost: %s\nConnection: close\n\n", ip_address);

    clock_gettime(CLOCK_MONOTONIC_RAW, &start_time);
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        return -1;
    }

    if (write(sockfd, buffer, strlen(buffer)) < 0) {
        perror("write failed");
        return -1;
    }

    int bytes_recvd;
    char recv_buffer[BUFFER_SIZE];
    memset(recv_buffer, 0, BUFFER_SIZE);
    struct timeval time_out;
    time_out.tv_sec = DEFAULT_TIMEOUT;
    time_out.tv_usec = 0;
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);
    if (select(sockfd + 1, &read_fds, NULL, NULL, &time_out) == 0) {
        printf("Request Timed Out\n");
        return -1;
    }
    if ((bytes_recvd = recv(sockfd, recv_buffer, BUFFER_SIZE - 1, 0)) < 0) {
        perror("recv failed");
        return -1;
    }
    clock_gettime(CLOCK_MONOTONIC_RAW, &end_time);
    double time_diff = calculate_time_diff(start_time, end_time) * 1000.0;
    printf("PING %s: %d bytes received in %.2fms\n", ip_address, bytes_recvd, time_diff);
    close(sockfd);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage();
        return EXIT_FAILURE;
    }
    char* target_ip_addr = argv[1];
    if (ping(target_ip_addr) != 0) {
        printf("Ping test unsuccessful\n");
    }
    return EXIT_SUCCESS;
}