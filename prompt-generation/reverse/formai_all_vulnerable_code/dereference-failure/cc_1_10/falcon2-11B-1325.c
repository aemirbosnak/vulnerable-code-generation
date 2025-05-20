//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to perform a network ping test
void ping_test(char *hostname, int port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Resolve the hostname to an IP address
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }

    // Create an Internet address from the IP address
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Send the ping request
    int n = send(sockfd, "PING", 4, 0);
    if (n < 0) {
        perror("ERROR sending");
        exit(EXIT_FAILURE);
    }

    // Receive the pong response
    char pong_buffer[256];
    bzero(pong_buffer, 256);
    int m = recv(sockfd, pong_buffer, 255, 0);
    if (m < 0) {
        perror("ERROR receiving");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    // Print the result
    printf("PING %s (%s) %d bytes of data.\n", hostname, inet_ntoa(serv_addr.sin_addr), m);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Perform a network ping test
    ping_test(argv[1], atoi(argv[2]));

    return 0;
}