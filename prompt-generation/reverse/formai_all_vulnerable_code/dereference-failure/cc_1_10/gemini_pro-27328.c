//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get server address
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton: invalid address\n");
        return EXIT_FAILURE;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Create buffers
    char *send_buff = malloc(BUFF_SIZE);
    char *recv_buff = malloc(BUFF_SIZE);
    if (send_buff == NULL || recv_buff == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Initialize buffers
    memset(send_buff, 0, BUFF_SIZE);
    memset(recv_buff, 0, BUFF_SIZE);

    // Send data to server
    int sent_bytes = send(sockfd, send_buff, BUFF_SIZE, 0);
    if (sent_bytes == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive data from server
    int recv_bytes = recv(sockfd, recv_buff, BUFF_SIZE, 0);
    if (recv_bytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Calculate elapsed time
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_nsec - start_time.tv_nsec) / 1e9;

    // Calculate bandwidth
    double bandwidth = sent_bytes / elapsed_time / 1024 / 1024;

    // Print results
    printf("Elapsed time: %f seconds\n", elapsed_time);
    printf("Bandwidth: %f Mbits/s\n", bandwidth);

    // Free resources
    free(send_buff);
    free(recv_buff);
    close(sockfd);

    return EXIT_SUCCESS;
}