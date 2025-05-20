//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Cyberpunk
// Welcome to the Neon-Soaked Network Matrix, Runner!

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <time.h>

// Ping parameters
#define PING_COUNT 10
#define PING_INTERVAL 1

// Packet loss and latency statistics
int packet_loss_count = 0;
float total_latency = 0.0;

int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int sockfd;
    struct sockaddr_in addr;
    socklen_t addr_len;
    char buf[PING_COUNT];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Resolve hostname
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Set target address
    addr.sin_family = AF_INET;
    addr.sin_port = htons(5000);
    addr.sin_addr = *((struct in_addr *) host->h_addr);
    addr_len = sizeof(addr);

    // Initialize random number generator
    srand(time(NULL));

    printf("Neon Pulse Detected: Starting Network QoS Scan...\n");

    // Send pings and calculate latency and packet loss
    for (int i = 0; i < PING_COUNT; i++) {
        // Send ping
        time_t start_time = time(NULL);
        sendto(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &addr, addr_len);
        recvfrom(sockfd, buf, sizeof(buf), 0, (struct sockaddr *) &addr, &addr_len);
        time_t end_time = time(NULL);

        // Calculate latency
        float latency = (float) (end_time - start_time);
        total_latency += latency;

        // Check for packet loss
        if (end_time - start_time > 1) {
            packet_loss_count++;
        }

        // Chill for a bit in the neon lights...
        sleep(PING_INTERVAL);
    }

    // Analyze data
    float avg_latency = total_latency / PING_COUNT;
    float packet_loss_rate = (float) packet_loss_count / PING_COUNT;

    // Decrypt the QoS metrics
    printf("Cyberlink Established: Quality of Service Analysis Report\n");
    printf("Average Latency: %.2f ms, Packet Loss: %.2f%%\n", avg_latency * 1000, packet_loss_rate * 100);

    // Initiate connection termination sequence
    shutdown(sockfd, SHUT_RDWR);
    return EXIT_SUCCESS;
}