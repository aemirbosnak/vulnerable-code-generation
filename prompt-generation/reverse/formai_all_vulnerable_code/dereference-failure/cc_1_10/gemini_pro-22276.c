//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int sockfd, n, bytes_read, bytes_sent;
    struct sockaddr_in servaddr;
    struct timeval start, end;
    char buf[BUFSIZE];
    char *hostname;
    int port;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return EXIT_FAILURE;
    }

    hostname = argv[1];
    port = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton error for %s\n", hostname);
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Record the start time
    gettimeofday(&start, NULL);

    // Send data to the server
    for (n = 0; n < BUFSIZE; n++) {
        buf[n] = 'a';
    }
    bytes_sent = send(sockfd, buf, BUFSIZE, 0);
    if (bytes_sent < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive data from the server
    bytes_read = recv(sockfd, buf, BUFSIZE, 0);
    if (bytes_read < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Record the end time
    gettimeofday(&end, NULL);

    // Calculate the elapsed time
    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    // Calculate the throughput
    double throughput = (bytes_sent + bytes_read) / elapsed_time;

    // Print the results
    printf("Throughput: %.2f Mbps\n", throughput * 8 / 1000000);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}