//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define BUFSIZE 4096

// Function to send a message to the server
void send_message(int sockfd, char *message) {
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("send()");
        exit(EXIT_FAILURE);
    }
}

// Function to receive a message from the server
void receive_message(int sockfd) {
    char buffer[BUFSIZE];
    if (recv(sockfd, buffer, BUFSIZE, 0) < 0) {
        perror("recv()");
        exit(EXIT_FAILURE);
    }
    printf("%s", buffer);
}

int main(int argc, char **argv) {
    // Check command line arguments
    if (argc != 4) {
        printf("Usage: %s <hostname> <port> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket()");
        exit(EXIT_FAILURE);
    }

    // Resolve the host name
    struct addrinfo hints, *results;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    int status = getaddrinfo(argv[1], argv[2], &hints, &results);
    if (status != 0) {
        fprintf(stderr, "getaddrinfo(): %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(sockfd, results->ai_addr, results->ai_addrlen) < 0) {
        perror("connect()");
        exit(EXIT_FAILURE);
    }

    // Send the message
    send_message(sockfd, argv[3]);

    // Receive the response
    receive_message(sockfd);

    // Close the socket
    close(sockfd);

    return 0;
}