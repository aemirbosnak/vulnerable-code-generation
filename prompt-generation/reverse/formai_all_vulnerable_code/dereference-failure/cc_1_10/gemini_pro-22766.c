//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

// Our faithful assistant, Dr. Watson
int Watson(char *host) {
    struct hostent *he;
    struct sockaddr_in addr;
    int sockfd;
    int bytes_sent, bytes_received;
    char *request = "Elementary, my dear Watson!";
    char response[1024];

    // Establish a connection to the specified host
    if ((he = gethostbyname(host)) == NULL) {
        printf("Watson: I regret to inform you, no such host exists.\n");
        return -1;
    }

    // Create a socket for communication
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Watson: My apologies, but I am unable to create a socket.");
        return -1;
    }

    // Prepare the address structure
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(80);
    addr.sin_addr = *((struct in_addr *)he->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Watson: I fear we have encountered an issue connecting to the server.");
        return -1;
    }

    // Send our request
    bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        perror("Watson: My attempts to relay the request were unsuccessful.");
        return -1;
    }

    // Receive the response
    bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
    if (bytes_received < 0) {
        perror("Watson: The server's response eludes us.");
        return -1;
    }

    // Close the connection
    close(sockfd);

    // Interpret the response
    if (strstr(response, "200 OK") != NULL) {
        printf("Watson: Excellent, my friend! The server responds with a positive affirmation.\n");
        return 0;
    } else {
        printf("Watson: Alas, the server's response is a perplexing enigma.\n");
        return -1;
    }
}

int main(int argc, char **argv) {
    // Elementary, my dear Watson
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return -1;
    }

    // Engage the powers of deduction
    int result = Watson(argv[1]);

    // Conclude the investigation
    if (result == 0) {
        printf("Sherlock Holmes: The server is alive and well, my dear Watson.\n");
    } else {
        printf("Sherlock Holmes: The server remains an elusive mystery, Watson.\n");
    }

    return 0;
}