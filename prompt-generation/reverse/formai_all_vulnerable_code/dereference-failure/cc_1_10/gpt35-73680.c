//FormAI DATASET v1.0 Category: Network Ping Test ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 5000 // Define the port number for the socket
#define BUF_SIZE 512 // Define the buffer size for the socket

// Function to calculate the time difference between two timespecs
double elapsed_time(struct timespec start, struct timespec end) {
    double start_time = (double) start.tv_sec + (double) start.tv_nsec / 1000000000.0;
    double end_time = (double) end.tv_sec + (double) end.tv_nsec / 1000000000.0;
    return end_time - start_time;
}

int main(int argc, char *argv[]) {
    if (argc != 2) { // Check if the user provided a valid IP address argument
        printf("Usage: %s <IP Address>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sfd, s, j;
    size_t len;
    ssize_t nread;
    char buf[BUF_SIZE];
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
    hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
    hints.ai_flags = 0;
    hints.ai_protocol = 0;          /* Any protocol */

    s = getaddrinfo(argv[1], NULL, &hints, &result);
    if (s != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

    // Try to create a socket and bind it to a local port
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype,
                rp->ai_protocol);
        if (sfd == -1)
            continue;
        if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
            break;                  /* Success */

        close(sfd);
    }

    if (rp == NULL) {               /* No address succeeded */
        fprintf(stderr, "Could not bind\n");
        exit(EXIT_FAILURE);
    }

    // Print the IP address and port that the socket is bound to
    struct sockaddr_in *addr = (struct sockaddr_in *) rp->ai_addr;
    printf("Bound to %s:%d\n", inet_ntoa(addr->sin_addr), ntohs(addr->sin_port));

    len = rp->ai_addrlen;
    freeaddrinfo(result);

    struct timespec start_time, end_time;
    int packet_count = 0, packet_loss = 0;
    double packet_rtt_sum = 0.0, min_rtt = 0.0, max_rtt = 0.0;

    for (int i = 0; i < 10; i++) {
        packet_count++;

        // Fill the buffer with the current packet number and send it to the target IP address
        sprintf(buf, "PING %d", i);
        if (sendto(sfd, buf, strlen(buf), 0, rp->ai_addr, len) == -1) {
            packet_loss++;
            continue;
        }

        // Start the timer for this packet
        if (clock_gettime(CLOCK_MONOTONIC, &start_time) == -1) {
            perror("clock_gettime");
            exit(EXIT_FAILURE);
        }

        // Receive the response from the target IP address
        nread = recvfrom(sfd, buf, BUF_SIZE, 0, NULL, NULL);
        if (nread == -1) {
            packet_loss++;
            continue;
        }

        // Stop the timer for this packet
        if (clock_gettime(CLOCK_MONOTONIC, &end_time) == -1) {
            perror("clock_gettime");
            exit(EXIT_FAILURE);
        }

        double packet_rtt = elapsed_time(start_time, end_time);

        // Determine the minimum and maximum RTT so far
        if (i == 0) {
            min_rtt = packet_rtt;
            max_rtt = packet_rtt;
        } else {
            if (packet_rtt < min_rtt)
                min_rtt = packet_rtt;
            if (packet_rtt > max_rtt)
                max_rtt = packet_rtt;
        }

        packet_rtt_sum += packet_rtt;

        // Print the response and RTT for this packet
        buf[nread] = '\0';
        printf("Response from %s: %s - RTT=%.3f ms\n", argv[1], buf, packet_rtt * 1000);

        // Sleep for one second before sending the next packet
        sleep(1);
    }

    // Print the statistics for the ping test
    double packet_loss_percent = (double) packet_loss / packet_count * 100;
    double avg_rtt = packet_rtt_sum / packet_count;
    printf("\n--- Ping statistics for %s ---\n", argv[1]);
    printf("%d packets transmitted, %d received, %.1f%% packet loss, time %dms\n",
            packet_count, packet_count - packet_loss, packet_loss_percent, packet_count * 1000);
    printf("rtt min/avg/max = %.3f/%.3f/%.3f ms\n", min_rtt * 1000, avg_rtt * 1000, max_rtt * 1000);

    close(sfd);
    return 0;
}