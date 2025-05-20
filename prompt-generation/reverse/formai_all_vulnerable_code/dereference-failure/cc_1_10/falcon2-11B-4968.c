//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to check if a host is alive
int ping(char* hostname, int timeout) {
    // Create a socket
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Create a struct to hold the host's information
    struct hostent* host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Fill in the struct's address and port fields
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr.s_addr, host->h_addr, host->h_length);
    addr.sin_port = htons(80);

    // Connect to the host
    if (connect(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send a ping request
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);
    write(sockfd, request, strlen(request));

    // Receive the response
    char response[100];
    memset(response, 0, sizeof(response));
    int n = read(sockfd, response, sizeof(response));

    // Check the response code
    int response_code = response[0] - '0';
    if (response_code == 200) {
        printf("PONG! %s is alive.\n", hostname);
    } else {
        printf("NOPE! %s is not alive.\n", hostname);
    }

    // Close the socket
    close(sockfd);

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // Ping the host
    ping(argv[1], 5);

    return 0;
}