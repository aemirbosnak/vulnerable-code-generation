//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>
#include <sys/time.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZE];
    struct timeval start_time, end_time;

    while (1) {
        // Send a message to the server.
        strcpy(buf, "Hello world!");
        int sent_bytes = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *) &server_addr, sizeof(server_addr));
        if (sent_bytes == -1) {
            perror("sendto");
            exit(EXIT_FAILURE);
        }

        // Get the current time.
        gettimeofday(&start_time, NULL);

        // Receive a message from the server.
        int recv_bytes = recvfrom(sockfd, buf, BUFSIZE, 0, NULL, NULL);
        if (recv_bytes == -1) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        // Get the current time.
        gettimeofday(&end_time, NULL);

        // Calculate the round-trip time.
        long rtt = (end_time.tv_sec - start_time.tv_sec) * 1000000 + (end_time.tv_usec - start_time.tv_usec);

        // Print the round-trip time.
        printf("Round-trip time: %ld microseconds\n", rtt);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}