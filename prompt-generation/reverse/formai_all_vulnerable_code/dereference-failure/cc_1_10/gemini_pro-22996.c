//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in servaddr;
    struct hostent *h;
    char buf[BUFSIZE];
    int n, i;
    struct timeval start, end;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Lookup the hostname
    if ((h = gethostbyname(argv[1])) == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    memcpy(&servaddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Start the timer
    gettimeofday(&start, NULL);

    // Send the data
    for (i = 0; i < BUFSIZE; i++) {
        buf[i] = 'a';
    }
    if (send(sockfd, buf, BUFSIZE, 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the data
    if ((n = recv(sockfd, buf, BUFSIZE, 0)) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Stop the timer
    gettimeofday(&end, NULL);

    // Calculate the elapsed time
    double elapsed = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    // Calculate the speed
    double speed = (BUFSIZE * 8) / (elapsed / 1000000.0);

    // Print the speed
    printf("Speed: %.2f Mbps\n", speed);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}