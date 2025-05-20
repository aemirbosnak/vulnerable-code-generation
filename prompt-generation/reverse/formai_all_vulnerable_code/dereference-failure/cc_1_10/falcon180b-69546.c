//Falcon-180B DATASET v1.0 Category: Firewall ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc!= 3) {
        printf("Usage:./firewall <allow/deny> <port>\n");
        return 1;
    }

    char *action = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints, *servinfo, *p;
    int rv;
    int yes = 1;
    int sockfd;

    // Set up hints for getaddrinfo()
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    // Get address information for the server
    if ((rv = getaddrinfo("localhost", NULL, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    // Loop through all the results and make a socket for each
    for (p = servinfo; p!= NULL; p = p->ai_next) {

        // Create a socket
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        // Set the socket option for reuse
        if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int)) == -1) {
            perror("setsockopt");
            close(sockfd);
            continue;
        }

        // Bind the socket to an address and port
        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("bind");
            close(sockfd);
            continue;
        }

        // Listen for incoming connections
        if (listen(sockfd, 5) == -1) {
            perror("listen");
            close(sockfd);
            continue;
        }

        if (strcmp(action, "allow") == 0) {
            printf("Allowing connections on port %d\n", port);
        } else if (strcmp(action, "deny") == 0) {
            printf("Denying connections on port %d\n", port);
        } else {
            printf("Invalid action\n");
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);
    return 0;
}