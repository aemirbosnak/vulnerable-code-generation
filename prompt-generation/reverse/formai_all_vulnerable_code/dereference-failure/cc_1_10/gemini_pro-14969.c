//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/time.h>
#include <signal.h>

#define DEFAULT_HOST "www.google.com"
#define DEFAULT_PORT 80
#define BUFSIZE 1024
#define MAX_RTT 1000000  // microseconds

// Global variables
int sockfd;
int seq_num;
struct timeval start_time;
struct sockaddr_in server_addr;
char buf[BUFSIZE];
int rtt[MAX_RTT];

// Signal handler
void sig_handler(int signum) {
    (void)signum;  // Suppress unused variable warning
    gettimeofday(&start_time, NULL);
    send(sockfd, buf, 1, 0);
    seq_num++;
}

int main(int argc, char *argv[]) {
    // Parse arguments
    char *host = DEFAULT_HOST;
    int port = DEFAULT_PORT;
    if (argc >= 2) {
        host = argv[1];
    }
    if (argc >= 3) {
        port = atoi(argv[2]);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        herror("gethostbyname");
        exit(1);
    }
    memcpy(&server_addr.sin_addr, hostent->h_addr, hostent->h_length);

    // Set up the signal handler
    signal(SIGALRM, sig_handler);

    // Start the timer
    gettimeofday(&start_time, NULL);

    // Send a probe packet
    send(sockfd, buf, 1, 0);
    seq_num = 0;

    // Loop until the user presses Ctrl-C
    while (1) {
        // Pause for 1 second
        alarm(1);

        // Wait for a response packet
        struct sockaddr_in from_addr;
        socklen_t from_len = sizeof(from_addr);
        int nbytes = recvfrom(sockfd, buf, BUFSIZE, 0, (struct sockaddr *)&from_addr, &from_len);
        if (nbytes < 0) {
            if (errno == EINTR) {
                continue;
            } else {
                perror("recvfrom");
                exit(1);
            }
        }

        // Check if the response packet is from the server
        if (from_addr.sin_addr.s_addr != server_addr.sin_addr.s_addr ||
            from_addr.sin_port != server_addr.sin_port) {
            continue;
        }

        // Calculate the round-trip time
        struct timeval end_time;
        gettimeofday(&end_time, NULL);
        long long rtt_us = (end_time.tv_sec - start_time.tv_sec) * 1000000 +
                             (end_time.tv_usec - start_time.tv_usec);

        // Store the round-trip time
        rtt[seq_num % MAX_RTT] = rtt_us;

        // Print the round-trip time
        printf("Round-trip time for packet %d: %lld microseconds\n", seq_num, rtt_us);
    }

    // Close the socket
    close(sockfd);

    return 0;
}