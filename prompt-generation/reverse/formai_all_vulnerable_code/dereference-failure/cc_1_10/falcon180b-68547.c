//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    struct hostent *he;
    struct sockaddr_in server_addr;
    int sockfd;
    int port = 80;
    char buf[BUF_SIZE];
    int nbytes;

    // Look up the host name
    he = gethostbyname(host);
    if (he == NULL) {
        fprintf(stderr, "Error: %s\n", hstrerror(h_errno));
        return 1;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    // Connect to the server
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *) he->h_addr);

    // Send a request
    nbytes = send(sockfd, "GET / HTTP/1.1\r\nHost: ", 32, 0);
    if (nbytes == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    // Receive a response
    memset(buf, 0, BUF_SIZE);
    nbytes = recv(sockfd, buf, BUF_SIZE, 0);
    if (nbytes == -1) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return 1;
    }

    // Print the response
    printf("Response:\n%s\n", buf);

    // Close the socket
    close(sockfd);

    return 0;
}