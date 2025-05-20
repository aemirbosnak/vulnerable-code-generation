//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

void receive(int sockfd, char* buf) {
    // Receive message from server
    int len = recv(sockfd, buf, BUF_SIZE, 0);

    // Print message
    printf("Server says: %s", buf);
}

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check for error creating socket
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket.\n");
        exit(1);
    }

    // Retrieve server information
    struct hostent *server = gethostbyname(argv[1]);

    // Check for error retrieving server information
    if (server == NULL) {
        fprintf(stderr, "Error retrieving server information.\n");
        exit(1);
    }

    // Initialize socket address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting to server.\n");
        exit(1);
    }

    // Send message to server
    char* msg = "Hello, server!\n";
    int len = strlen(msg);
    int bytes_sent = send(sockfd, msg, len, 0);
    if (bytes_sent < 0) {
        fprintf(stderr, "Error sending message to server.\n");
        exit(1);
    }

    // Receive message from server
    char buf[BUF_SIZE];
    receive(sockfd, buf);

    // Close socket
    close(sockfd);

    return 0;
}