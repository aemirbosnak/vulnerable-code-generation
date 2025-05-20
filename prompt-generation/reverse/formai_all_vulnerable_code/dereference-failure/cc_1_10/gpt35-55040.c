//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 1024

// Function to initialize a socket and connect to a given address and port
int init_socket(char *server_address, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error in creating socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_address);
    server.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("Error in connecting to server");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to check the network quality of service by measuring the round trip time
double check_network_qos(int sockfd) {
    char buffer[BUFFER_SIZE];
    struct timeval start_time, end_time;
    double rtt;

    // Send the current time to the server
    gettimeofday(&start_time, NULL);
    sprintf(buffer, "%lu", start_time.tv_sec);
    if (send(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error in sending data");
        exit(EXIT_FAILURE);
    }

    // Receive the current time from the server
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
        perror("Error in receiving data");
        exit(EXIT_FAILURE);
    }
    gettimeofday(&end_time, NULL);

    // Calculate the round trip time
    rtt = (double)(end_time.tv_sec - start_time.tv_sec) + (double)(end_time.tv_usec - start_time.tv_usec) / 1000000.0;

    return rtt;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_address = argv[1];
    int port = atoi(argv[2]);

    int sockfd = init_socket(server_address, port);

    // Infinite loop to continuously check the network quality of service
    while (1) {
        double rtt = check_network_qos(sockfd);
        printf("Round trip time: %.3f seconds\n", rtt);
        sleep(1);
    }

    close(sockfd);
    return 0;
}