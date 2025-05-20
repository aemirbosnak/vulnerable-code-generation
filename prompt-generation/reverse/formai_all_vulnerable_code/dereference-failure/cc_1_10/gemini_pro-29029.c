//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define PORT_RANGE 65535

int main(int argc, char *argv[]) {
    // Parse the hostname
    char *hostname;
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    hostname = argv[1];

    // Let's create a pirate ship, a.k.a. socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the cannonballs for our attack
    struct sockaddr_in target;
    target.sin_family = AF_INET;
    if (inet_pton(AF_INET, hostname, &target.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }

    // Let's set sail and explore the ports
    for (unsigned short port = 1; port <= PORT_RANGE; port++) {

        // Fire the cannonball!
        target.sin_port = htons(port);
        int status = connect(sockfd, (struct sockaddr *)&target, sizeof(target));

        // Check if the port responded to our attack
        if (status == 0) {
            printf("Port %u: Open\n", port);
        } else if (status == -1 && errno == ETIMEDOUT) {
            printf("Port %u: Filtered\n", port);
        } else if (status == -1 && errno == EACCES) {
            printf("Port %u: Closed\n", port);
        } else {
            perror("connect");
            exit(EXIT_FAILURE);
        }
    }

    // Time to sail back to our home port
    close(sockfd);

    return EXIT_SUCCESS;
}