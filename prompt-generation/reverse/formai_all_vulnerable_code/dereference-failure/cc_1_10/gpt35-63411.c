//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <fcntl.h>

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        fprintf(stderr, "Unknown host %s.\n", argv[1]);
        exit(2);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(3);
    }

    struct sockaddr_in dest;
    dest.sin_family = AF_INET;
    dest.sin_port = htons (80);
    memcpy(&dest.sin_addr.s_addr, he->h_addr, sizeof dest.sin_addr.s_addr);

    if (connect(sockfd, (struct sockaddr *)&dest, sizeof dest) == -1) {
        perror("connect");
        exit(4);
    }

    int addrlen;
    struct sockaddr_in src;
    addrlen = sizeof(src);
    getsockname(sockfd, (struct sockaddr *)&src, &addrlen);

    int port;
    socklen_t optlen = sizeof(port);
    getsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &port, &optlen);

    char addr_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(src.sin_addr), addr_str, INET_ADDRSTRLEN);

    printf("%s:%d\n", addr_str, ntohs(src.sin_port));

    close(sockfd);

    return 0;
}