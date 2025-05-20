//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <resolv.h>
#include <string.h>
#include <netdb.h>
#include <errno.h>

#define MAX_LINE_LEN 1024

int main(int argc, char **argv) {
    // Check args
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // Resolve hostname
    char *hostname = argv[1];
    struct hostent *h = gethostbyname(hostname);
    if (h == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", hstrerror(herror));
        exit(1);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Connect to server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    servaddr.sin_addr = *(struct in_addr *)h->h_addr_list[0];

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send GET request
    char buf[MAX_LINE_LEN];
    snprintf(buf, sizeof(buf), "GET / HTTP/1.0\r\nHost: %s\r\n\r\n", hostname);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive response
    while (1) {
        int n = recv(sockfd, buf, sizeof(buf), 0);
        if (n == -1) {
            perror("recv");
            exit(1);
        } else if (n == 0) {
            break;
        } else {
            printf("%s", buf);
        }
    }

    // Close socket
    close(sockfd);

    return 0;
}