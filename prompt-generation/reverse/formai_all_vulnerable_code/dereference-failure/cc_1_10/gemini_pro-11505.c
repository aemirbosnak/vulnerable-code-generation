//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_BUF_SIZE 4096

// Function to resolve a domain name to an IP address
char *resolve_host(char *hostname) {
    struct hostent *host;
    char *ip;

    host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error resolving hostname: %s\n", hostname);
        return NULL;
    }

    ip = inet_ntoa(*((struct in_addr *)host->h_addr_list[0]));
    return strdup(ip);
}

// Function to send an HTTP GET request and receive the response
int send_http_get(char *host, char *port, char *path) {
    int sockfd;
    struct sockaddr_in servaddr;
    char *ip;
    char buf[MAX_BUF_SIZE];
    int n;

    // Resolve the hostname to an IP address
    ip = resolve_host(host);
    if (ip == NULL) {
        return -1;
    }

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return -1;
    }

    // Set up the server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));
    servaddr.sin_addr.s_addr = inet_addr(ip);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error connecting to server");
        close(sockfd);
        return -1;
    }

    // Send the HTTP GET request
    sprintf(buf, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("Error sending HTTP GET request");
        close(sockfd);
        return -1;
    }

    // Receive the HTTP response
    memset(buf, 0, MAX_BUF_SIZE);
    n = read(sockfd, buf, MAX_BUF_SIZE);
    if (n < 0) {
        perror("Error receiving HTTP response");
        close(sockfd);
        return -1;
    }

    // Print the HTTP response
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <host> <port> <path>\n", argv[0]);
        return 1;
    }

    if (send_http_get(argv[1], argv[2], argv[3]) < 0) {
        return 1;
    }

    return 0;
}