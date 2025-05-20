//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: artistic
// A symphony of pings, a rhythmic tapestry of network harmony.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>

// A canvas of colors, painting the network's response.
#define COLOR_GREEN "\033[0;32m"
#define COLOR_RED "\033[0;31m"
#define COLOR_YELLOW "\033[0;33m"
#define COLOR_RESET "\033[0m"

// The maestro's baton, conducting the network's rhythm.
struct ping_stats {
    unsigned int sent;
    unsigned int received;
    unsigned int lost;
    unsigned int min_time;
    unsigned int max_time;
    unsigned int avg_time;
};

// The heartbeat of the network, measured in milliseconds.
unsigned int ping_time(const char *hostname) {
    struct timespec start, end;
    struct sockaddr_in addr;
    int sockfd, ret;
    char buf[1024];

    // Establish a socket connection, a conduit for our pings.
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // Set the destination, a beacon in the network's vastness.
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(33434);
    ret = inet_aton(hostname, &addr.sin_addr);
    if (ret == 0) {
        perror("Invalid hostname");
        close(sockfd);
        return -1;
    }

    // Send the ping, a gentle nudge to the network.
    clock_gettime(CLOCK_REALTIME, &start);
    ret = sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        perror("Sendto failed");
        close(sockfd);
        return -1;
    }

    // Wait for the echo, the network's reply to our call.
    ret = recvfrom(sockfd, buf, sizeof(buf), 0, NULL, NULL);
    if (ret < 0) {
        perror("Recvfrom failed");
        close(sockfd);
        return -1;
    }
    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate the time it took, a measure of the network's speed.
    unsigned int time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_nsec - start.tv_nsec) / 1000000;
    close(sockfd);
    return time;
}

// The grand conductor, orchestrating the pings.
struct ping_stats ping_test(const char *hostname, unsigned int count) {
    struct ping_stats stats = {0};
    unsigned int i;

    // Send the pings, each a ripple in the network's fabric.
    for (i = 0; i < count; i++) {
        stats.sent++;
        unsigned int time = ping_time(hostname);
        if (time > 0) {
            stats.received++;
            stats.avg_time = (stats.avg_time * (stats.received - 1) + time) / stats.received;
            if (time < stats.min_time || stats.min_time == 0)
                stats.min_time = time;
            if (time > stats.max_time)
                stats.max_time = time;
        } else {
            stats.lost++;
        }
    }

    return stats;
}

// The grand finale, a symphony of statistics.
void print_stats(const char *hostname, const struct ping_stats *stats) {
    float loss_percent = (float)stats->lost / stats->sent * 100.0;

    // Paint the statistics on the canvas of the terminal.
    printf("Ping statistics for %s:\n", hostname);
    printf("Packets: sent %d, received %d, lost %d (%0.2f%% loss)\n", stats->sent, stats->received, stats->lost, loss_percent);
    printf("Round-trip times in milliseconds:\n");
    printf("\tMinimum: %d ms\n", stats->min_time);
    printf("\tAverage: %d ms\n", stats->avg_time);
    printf("\tMaximum: %d ms\n", stats->max_time);
}

// The entry point, where the symphony begins.
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <count>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Parse the command line arguments, the maestro's instructions.
    const char *hostname = argv[1];
    unsigned int count = atoi(argv[2]);

    // Perform the ping test, a rhythmic probing of the network.
    struct ping_stats stats = ping_test(hostname, count);

    // Print the statistics, a symphony of numbers and insights.
    print_stats(hostname, &stats);

    return EXIT_SUCCESS;
}