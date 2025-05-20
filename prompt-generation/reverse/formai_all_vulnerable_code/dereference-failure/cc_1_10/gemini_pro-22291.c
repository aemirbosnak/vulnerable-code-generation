//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdbool.h>
#include <time.h>

#define BUFFER_SIZE 64
#define DEFAULT_PORT 80
#define TIMEOUT_MS 500

// A futuristic-styled network ping test program.
// By Default, it will ping google.com:80
int main(int argc, char* argv[]) {
    // Declare variables
    char* host = "google.com";
    int port = DEFAULT_PORT;
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];
    struct timeval timeout;
    fd_set readfds;
    int recv_bytes;
    bool timed_out;
    int seq_num = 0;
    clock_t start, end;
    double rtt;

    // Parse command line arguments
    if (argc >= 2) {
        host = argv[1];
    }
    if (argc >= 3) {
        port = atoi(argv[2]);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the socket timeout
    timeout.tv_sec = 0;
    timeout.tv_usec = TIMEOUT_MS * 1000;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) == -1) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Send a ping message
    sprintf(buffer, "PING %d", seq_num++);
    if (sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    // Wait for a response
    start = clock();
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);
    recv_bytes = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
    end = clock();

    // Calculate the round-trip time
    rtt = (double)(end - start) / CLOCKS_PER_SEC;

    // Check if a response was received
    if (recv_bytes == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (recv_bytes == 0) {
        timed_out = true;
    } else {
        // Receive the response
        recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
        timed_out = false;
    }

    // Print the ping results
    printf("PING %s (%s): ", host, inet_ntoa(servaddr.sin_addr));
    if (timed_out) {
        printf("Request timed out.\n");
    } else {
        printf("seq=%d, rtt=%f ms\n", seq_num - 1, rtt * 1000);
    }

    // Close the socket
    close(sockfd);

    return 0;
}