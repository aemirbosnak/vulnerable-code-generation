//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    // Create a socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Get hostname
    char hostname[1024];
    if (gethostname(hostname, sizeof(hostname)) < 0) {
        perror("gethostname");
        exit(1);
    }

    // Create a data structure for IP address and port
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;
    int rv = getaddrinfo(hostname, NULL, &hints, &res);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }
    struct sockaddr_in *addr = (struct sockaddr_in*)res->ai_addr;

    // Send UDP packet
    char buf[1024];
    sprintf(buf, "Hello from %s!\n", hostname);
    int len = sendto(sockfd, buf, strlen(buf), 0, addr->sin_addr.s_addr, addr->sin_port);
    if (len < 0) {
        perror("sendto");
        exit(1);
    }

    // Receive UDP packet
    char recvbuf[1024];
    memset(recvbuf, 0, sizeof(recvbuf));
    int recvlen = recvfrom(sockfd, recvbuf, sizeof(recvbuf), 0, NULL, NULL);
    if (recvlen <= 0) {
        perror("recvfrom");
        exit(1);
    }
    printf("Received: %s\n", recvbuf);

    // Clean up
    freeaddrinfo(res);
    close(sockfd);

    return 0;
}