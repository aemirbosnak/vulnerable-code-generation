//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/time.h>

#define PORT "8888"

#define MAXDATASIZE 100

int main(int argc, char *argv[]) {
    int sockfd, rv, numbytes;
    struct addrinfo hints, *servinfo, *p;
    struct sockaddr_storage their_addr;
    char buf[MAXDATASIZE];
    socklen_t addr_len;
    char s[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    if ((rv = getaddrinfo(argv[1], PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    // loop through all the results and make a socket
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype,
                             p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "client: failed to create socket\n");
        exit(1);
    }

    // set timeout for the UDP socket
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        perror("Error setting socket timeout");
        exit(1);
    }

    // check internet connection by sending a simple ping
    const char *ping_message = "PING INTERNET";
    if ((numbytes = sendto(sockfd, ping_message, strlen(ping_message), 0,
                           p->ai_addr, p->ai_addrlen)) == -1) {
        perror("Error sending ping message");
        exit(1);
    }

    printf("Sending ping message '%s' to %s\n", ping_message, argv[1]);

    addr_len = sizeof their_addr;
    if ((numbytes = recvfrom(sockfd, buf, MAXDATASIZE - 1, 0,
                             (struct sockaddr *) &their_addr, &addr_len)) == -1) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            perror("Error: Timeout waiting for ping response");
            exit(1);
        } else {
            perror("Error receiving ping response");
            exit(1);
        }
    }

    buf[numbytes] = '\0';
    printf("Received ping response: '%s'\n", buf);

    close(sockfd);

    freeaddrinfo(servinfo);

    return 0;
}