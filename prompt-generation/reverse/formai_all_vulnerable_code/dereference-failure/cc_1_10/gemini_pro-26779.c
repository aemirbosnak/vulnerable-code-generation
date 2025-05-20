//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

// Function to measure the round trip time (RTT) of a network connection
int measure_rtt(const char *hostname, int port) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    // Get the server's IP address
    server = gethostbyname(hostname);
    if (server == NULL) {
        perror("ERROR, no such host");
        return -1;
    }

    // Set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return -1;
    }

    // Send a message to the server
    n = write(sockfd, "Hello world!", 12);
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }

    // Receive a message from the server
    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    int rtt;

    // Check the number of arguments
    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        return -1;
    }

    // Measure the RTT
    rtt = measure_rtt(argv[1], atoi(argv[2]));

    // Print the RTT
    printf("RTT: %d ms\n", rtt);

    return 0;
}