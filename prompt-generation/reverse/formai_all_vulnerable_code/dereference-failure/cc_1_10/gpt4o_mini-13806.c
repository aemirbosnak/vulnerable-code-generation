//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define CLIENT_PORT 9090
#define BUFFER_SIZE 1024
#define TEST_DURATION 5

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void start_server() {
    int sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    socklen_t addr_len;
    ssize_t n;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) 
        error("ERROR on binding");
    
    printf("Server is listening on port %d...\n", SERVER_PORT);
    
    while (1) {
        addr_len = sizeof(client_addr);
        n = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *) &client_addr, &addr_len);
        if (n < 0) error("ERROR on recvfrom");
        
        // Send back the same buffer received as a response
        sendto(sockfd, buffer, n, 0, (struct sockaddr *) &client_addr, addr_len);
    }

    close(sockfd);
}

void start_client() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timespec start, end;
    long elapsed_time;
    ssize_t bytes_sent, bytes_received;
    int packets_sent = 0;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Change to the server IP if needed
    server_addr.sin_port = htons(SERVER_PORT);

    printf("Starting speed test...\n");
    clock_gettime(CLOCK_MONOTONIC, &start);

    while (1) {
        snprintf(buffer, BUFFER_SIZE, "PING %d", packets_sent++);
        bytes_sent = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *) &server_addr, sizeof(server_addr));
        if (bytes_sent < 0) error("ERROR on sendto");

        bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (bytes_received < 0) error("ERROR on recvfrom");

        if (packets_sent >= TEST_DURATION * 10) break; // Limit test duration to TEST_DURATION seconds

        usleep(100000);  // Sleep for 100 milliseconds
    }

    clock_gettime(CLOCK_MONOTONIC, &end);
    
    elapsed_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;

    double speed = (packets_sent * BUFFER_SIZE) / (elapsed_time / 1000.0);
    printf("Test completed: %d packets sent, elapsed time: %ld ms, speed: %.2f bytes/sec\n", packets_sent, elapsed_time, speed);
    
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s [server|client]\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        start_client();
    } else {
        fprintf(stderr, "Invalid argument: %s. Use 'server' or 'client'.\n", argv[1]);
        exit(1);
    }

    return 0;
}