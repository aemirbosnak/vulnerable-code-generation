//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: futuristic
// LunaNet: Cybernetic Internet Speed Analyzer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOSTNAME_LEN 256
#define MAX_BUF_SIZE 1024

// Function to measure the time it takes to send and receive a packet to a remote host
double measure_latency(char *hostname) {
    struct timespec start_time, end_time;
    struct addrinfo hints, *res;
    int sockfd;
    char buf[MAX_BUF_SIZE];
    double elapsed_time;

    // Resolve the hostname to an IP address
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if (getaddrinfo(hostname, NULL, &hints, &res) != 0) {
        perror("getaddrinfo");
        return -1.0;
    }

    // Create a socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        freeaddrinfo(res);
        return -1.0;
    }

    // Connect to the remote host
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) != 0) {
        perror("connect");
        freeaddrinfo(res);
        close(sockfd);
        return -1.0;
    }

    // Send a packet to the remote host
    if (send(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("send");
        freeaddrinfo(res);
        close(sockfd);
        return -1.0;
    }

    // Receive a packet from the remote host
    if (recv(sockfd, buf, MAX_BUF_SIZE, 0) == -1) {
        perror("recv");
        freeaddrinfo(res);
        close(sockfd);
        return -1.0;
    }

    // Measure the elapsed time
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    clock_gettime(CLOCK_MONOTONIC, &end_time);
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000.0 + (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0;

    // Clean up
    freeaddrinfo(res);
    close(sockfd);

    return elapsed_time;
}

// Function to determine if a connection is stable
int is_stable_connection(char *hostname, int num_tests, double latency_threshold) {
    int i;
    double avg_latency = 0.0;

    // Measure the latency multiple times
    for (i = 0; i < num_tests; i++) {
        double latency = measure_latency(hostname);
        if (latency < 0.0) {
            return -1;
        }
        avg_latency += latency;
    }
    avg_latency /= num_tests;

    // Check if the average latency is below the threshold
    return avg_latency <= latency_threshold;
}

int main(int argc, char **argv) {
    char hostname[MAX_HOSTNAME_LEN];
    int num_tests, latency_threshold;

    // Check if the command-line arguments are valid
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <num_tests> <latency_threshold>\n", argv[0]);
        return EXIT_FAILURE;
    }
    strcpy(hostname, argv[1]);
    num_tests = atoi(argv[2]);
    latency_threshold = atoi(argv[3]);

    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random greeting
    char *greetings[] = {"Greetings, cybernaut!", "Welcome to the network!", "Prepare for hyperspace travel!", "Engage warp engines!"};
    int greeting_index = rand() % (sizeof(greetings) / sizeof(char *));
    printf("%s\n", greetings[greeting_index]);

    // Check if the connection is stable
    int is_stable = is_stable_connection(hostname, num_tests, latency_threshold);

    // Print the results
    if (is_stable) {
        printf("Your connection to %s is stable.\n", hostname);
    } else {
        printf("Your connection to %s is unstable.\n", hostname);
    }

    return EXIT_SUCCESS;
}