//FormAI DATASET v1.0 Category: Network Packet Monitoring ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>


#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Attempt to resolve host name
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Failed to resolve host: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    int on = 1;
    if (setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &on, sizeof(on)) != 0) {
        perror("Failed to set IP_HDRINCL");
        exit(EXIT_FAILURE);
    }

    // Construct destination address
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_addr = *((struct in_addr *)host->h_addr);
    dest_addr.sin_port = htons(atoi(argv[2]));

    // Construct packet
    char buf[BUFFER_SIZE];
    memset(buf, 0, sizeof(buf));

    // Add paranoid monitoring code here
    // ...

    int pkt_len = sendto(sockfd, buf, strlen(buf), 0, (struct sockaddr *)&dest_addr, sizeof(dest_addr));
    if (pkt_len < 0) {
        perror("Failed to send packet");
        exit(EXIT_FAILURE);
    }

    // Clean up
    close(sockfd);

    return EXIT_SUCCESS;
}