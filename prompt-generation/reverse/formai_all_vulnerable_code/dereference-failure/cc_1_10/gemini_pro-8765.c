//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
    // Check for correct usage
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <interval>\n", argv[0]);
        exit(1);
    }

    // Get the hostname and interval
    char *hostname = argv[1];
    int interval = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Get the IP address of the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        herror("gethostbyname");
        exit(1);
    }

    // Connect to the hostname
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80); // HTTP port
    memcpy(&serv_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send an HTTP GET request to the hostname
    char request[BUFSIZE];
    snprintf(request, BUFSIZE, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the HTTP response from the hostname
    char response[BUFSIZE];
    int n = recv(sockfd, response, BUFSIZE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }

    // Check the HTTP status code
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL) {
        fprintf(stderr, "Invalid HTTP response\n");
        exit(1);
    }

    char *status_code = strtok(status_line, " ");
    if (status_code == NULL) {
        fprintf(stderr, "Invalid HTTP response\n");
        exit(1);
    }

    // Print the HTTP status code
    printf("%s\n", status_code);

    // Close the socket
    close(sockfd);

    return 0;
}