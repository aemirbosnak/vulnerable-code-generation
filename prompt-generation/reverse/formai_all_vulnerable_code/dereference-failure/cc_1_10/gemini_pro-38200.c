//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

typedef struct {
    struct sockaddr_in address;
    socklen_t length;
} Address;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Setup the socket address.
    Address address;
    address.address.sin_family = AF_INET;
    address.address.sin_port = htons(port);
    if (inet_aton(hostname, &address.address.sin_addr) == 0) {
        fprintf(stderr, "Invalid hostname: %s\n", hostname);
        return EXIT_FAILURE;
    }
    address.length = sizeof(address.address);

    // Send a request to the server.
    char *request = "PING";
    int request_length = strlen(request);
    if (sendto(sockfd, request, request_length, 0, &address.address, address.length) < 0) {
        perror("sendto");
        return EXIT_FAILURE;
    }

    // Receive a response from the server.
    char response[1024];
    int response_length = recvfrom(sockfd, response, sizeof(response), 0, &address.address, &address.length);
    if (response_length < 0) {
        perror("recvfrom");
        return EXIT_FAILURE;
    }

    // Measure the round-trip time.
    struct timeval start_time;
    struct timeval end_time;
    gettimeofday(&start_time, NULL);
    gettimeofday(&end_time, NULL);
    long round_trip_time = (end_time.tv_sec - start_time.tv_sec) * 1000 + (end_time.tv_usec - start_time.tv_usec) / 1000;

    // Print the round-trip time.
    printf("Round-trip time: %ld ms\n", round_trip_time);

    // Close the socket.
    if (close(sockfd) < 0) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}