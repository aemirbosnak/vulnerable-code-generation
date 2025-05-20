//FormAI DATASET v1.0 Category: Network Ping Test ; Style: curious
// Welcome curious programmers!

// Today, we'll be creating a unique C Network Ping Test example program
// that's guaranteed to satisfy your burning curiosity.

// Let's start by including the necessary libraries.
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <unistd.h>

// Next up, we need to define some constants.
#define MAX_PACKET_SIZE 4096
#define DEFAULT_PORT 80
#define DEFAULT_TIMEOUT 2
#define DEFAULT_COUNT 5

// We'll be using a struct to keep all relevant information in one place.
struct ping_result {
    char *dst_ip;
    int count;
    double max_time;
    double min_time;
    double avg_time;
};

// Let's create a function to calculate the time elapsed between two timeval structs.
double time_diff(struct timeval start, struct timeval end) {
    return (end.tv_sec - start.tv_sec) * 1000.0 + (end.tv_usec - start.tv_usec) / 1000.0;
}

// Our main function needs to accept command line arguments.
int main(int argc, char *argv[]) {
    // Let's start with some argument parsing.
    if (argc < 2) {
        printf("Usage: %s <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Next, we need to resolve the destination host name to an IP address.
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Unable to resolve destination '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // We also need to allocate enough memory to store the IP address as a string.
    char *dst_ip = inet_ntoa(*((struct in_addr *) host->h_addr_list[0]));

    // Let's initialize some variables.
    int port = DEFAULT_PORT;
    int timeout = DEFAULT_TIMEOUT;
    int count = DEFAULT_COUNT;

    // Check for optional arguments.
    if (argc > 2) {
        port = atoi(argv[2]);
    }
    if (argc > 3) {
        timeout = atoi(argv[3]);
    }
    if (argc > 4) {
        count = atoi(argv[4]);
    }

    // Allocate memory for our ping result struct.
    struct ping_result *result = (struct ping_result *) malloc(sizeof(struct ping_result));
    result->dst_ip = dst_ip;
    result->count = count;
    result->max_time = 0;
    result->min_time = 0;
    result->avg_time = 0;

    // Let's start the actual ping test.
    printf("Pinging %s (%s) on port %d...\n", argv[1], dst_ip, port);

    // We'll use a for loop to send and receive packets.
    for (int i = 1; i <= count; i++) {
        // We'll start by creating a socket and connecting to the destination.
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in servaddr;
        memset(&servaddr, 0, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr(dst_ip);
        servaddr.sin_port = htons(port);
        connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr));

        // Next, we need to create a packet to send.
        char packet[MAX_PACKET_SIZE];
        memset(packet, 'a', sizeof(packet));

        // Let's record the current time before sending the packet.
        struct timeval start_time;
        gettimeofday(&start_time, NULL);

        // Send the packet and wait for a response.
        write(sockfd, packet, sizeof(packet));
        fd_set readset;
        FD_ZERO(&readset);
        FD_SET(sockfd, &readset);
        struct timeval timeout_val;
        timeout_val.tv_sec = timeout;
        timeout_val.tv_usec = 0;
        select(sockfd + 1, &readset, NULL, NULL, &timeout_val);

        // Record the time again after receiving the response.
        struct timeval end_time;
        gettimeofday(&end_time, NULL);

        // Calculate the time elapsed and update our result struct.
        double time_elapsed = time_diff(start_time, end_time);
        result->min_time = (i == 1) ? time_elapsed : fmin(time_elapsed, result->min_time);
        result->max_time = fmax(time_elapsed, result->max_time);
        result->avg_time += time_elapsed;

        // Close the socket and print the result for this packet.
        close(sockfd);
        printf("Packet %d: %.2fms\n", i, time_elapsed);
    }

    // When we're done, print the average time and other statistics.
    result->avg_time /= count;
    printf("\n--- %s ping statistics ---\n", argv[1]);
    printf("%d packets transmitted, %d received, %d%% packet loss, time %.0fms\n",
           count, count, 0, result->avg_time);
    printf("rtt min/avg/max = %.2f/%.2f/%.2f ms\n",
           result->min_time, result->avg_time, result->max_time);

    // Free the memory we allocated and exit gracefully.
    free(result);
    return 0;
}