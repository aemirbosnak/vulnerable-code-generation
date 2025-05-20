//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        exit(1);
    }

    struct hostent *he;
    struct in_addr *ipv4;
    struct sockaddr_in addr;

    if ((he = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error: Unknown host %s\n", argv[1]);
        exit(1);
    }

    ipv4 = (struct in_addr *) he->h_addr_list[0];

    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = ipv4->s_addr;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: Failed to create socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("Error: Failed to connect");
        exit(1);
    }

    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer));

    if (n == -1) {
        perror("Error: Failed to read from socket");
        exit(1);
    }

    printf("Port %d is %s\n", ntohs(addr.sin_port), buffer);

    close(sockfd);

    return 0;
}