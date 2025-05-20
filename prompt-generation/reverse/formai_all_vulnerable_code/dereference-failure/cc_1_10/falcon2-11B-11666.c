//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    struct sockaddr_in sin;
    struct hostent *he;
    int sockfd, len, i;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get the hostname of the switch
    he = gethostbyname("192.168.1.1");
    if (he == NULL) {
        fprintf(stderr, "Error: gethostbyname() failed\n");
        exit(EXIT_FAILURE);
    }

    // Fill in the switch's IP address
    bzero((char *) &sin, sizeof(sin));
    sin.sin_family = AF_INET;
    bcopy((char *) he->h_addr, (char *) &sin.sin_addr.s_addr, he->h_length);
    sin.sin_port = htons(9);

    // Send an ARP request to the switch
    len = sizeof(sin);
    if (sendto(sockfd, (char *) &sin, len, 0, (struct sockaddr *) &sin, len) < 0) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    // Receive the reply from the switch
    bzero((char *) &sin, sizeof(sin));
    if (recvfrom(sockfd, (char *) &sin, sizeof(sin), 0, NULL, NULL) < 0) {
        perror("recvfrom");
        exit(EXIT_FAILURE);
    }

    // Print out the MAC address of the switch and its IP address
    printf("Switch: %s\n", inet_ntoa(sin.sin_addr));

    // Get the hostnames of the three hosts
    for (i = 0; i < 3; i++) {
        he = gethostbyname("192.168.1.i");
        if (he == NULL) {
            fprintf(stderr, "Error: gethostbyname() failed\n");
            exit(EXIT_FAILURE);
        }

        // Fill in the host's IP address
        bzero((char *) &sin, sizeof(sin));
        sin.sin_family = AF_INET;
        bcopy((char *) he->h_addr, (char *) &sin.sin_addr.s_addr, he->h_length);
        sin.sin_port = htons(9);

        // Send an ARP request to the host
        len = sizeof(sin);
        if (sendto(sockfd, (char *) &sin, len, 0, (struct sockaddr *) &sin, len) < 0) {
            perror("sendto");
            exit(EXIT_FAILURE);
        }

        // Receive the reply from the host
        bzero((char *) &sin, sizeof(sin));
        if (recvfrom(sockfd, (char *) &sin, sizeof(sin), 0, NULL, NULL) < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }

        // Print out the MAC address of the host and its IP address
        printf("Host %d: %s\n", i+1, inet_ntoa(sin.sin_addr));
    }

    // Close the socket
    close(sockfd);
    return 0;
}