//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>

#define DEFAULT_TIMEOUT 1000 // 1 second, in milliseconds
#define DEFAULT_ATTEMPTS 3

static volatile int received_response = 0;

void handle_timeout(int signum) {
    if (signum == SIGALRM) {
        received_response = 0;
        alarm(0); // cancel the alarm
    }
}

int ping(const char *host, int timeout, int attempts) {
    struct sockaddr_in addr;
    int sockfd, bytes_sent, bytes_received;
    char buffer[1024];
    struct timeval tv;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Set the timeout
    tv.tv_sec = timeout / 1000;
    tv.tv_usec = (timeout % 1000) * 1000;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));

    // Set the address
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr.s_addr = inet_addr(host);

    // Send the ping request
    bytes_sent = sendto(sockfd, buffer, 1, 0, (struct sockaddr *) &addr, sizeof(addr));
    if (bytes_sent == -1) {
        perror("sendto");
        close(sockfd);
        return -1;
    }

    // Set an alarm to handle timeouts
    signal(SIGALRM, handle_timeout);
    alarm(timeout);

    // Wait for the response
    bytes_received = recvfrom(sockfd, buffer, sizeof(buffer), 0, NULL, NULL);

    // Cancel the alarm
    alarm(0);

    // Close the socket
    close(sockfd);

    // Check if we received a response
    if (bytes_received > 0) {
        received_response = 1;
        return 0;
    }

    // Check if we timed out
    if (received_response == 0) {
        return -1;
    }

    // Otherwise, we received an error
    return -1;
}

int main(int argc, char **argv) {
    char *host;
    int timeout, attempts, i;

    // Parse the command line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host> [timeout] [attempts]\n", argv[0]);
        return 1;
    }
    host = argv[1];
    timeout = DEFAULT_TIMEOUT;
    attempts = DEFAULT_ATTEMPTS;
    if (argc >= 3) {
        timeout = atoi(argv[2]);
    }
    if (argc >= 4) {
        attempts = atoi(argv[3]);
    }

    // Ping the host
    for (i = 0; i < attempts; i++) {
        if (ping(host, timeout, attempts) == 0) {
            printf("Ping successful!\n");
            return 0;
        }
    }

    // Ping failed
    printf("Ping failed!\n");
    return 1;
}