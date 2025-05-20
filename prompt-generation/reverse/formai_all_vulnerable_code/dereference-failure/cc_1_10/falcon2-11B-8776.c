//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

// Function to check if a port is open
int is_port_open(int port, struct sockaddr_in address) {
    int sockfd;
    struct sockaddr_in serv_addr;
    int yes = 1;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Could not create socket.\n");
        return -1;
    }

    memset(&serv_addr, '\0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not bind to port %d.\n", port);
        return -1;
    }

    if (connect(sockfd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        printf("Error: Could not connect to address.\n");
        return -1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) < 0) {
        printf("Error: Could not set SO_REUSEADDR option.\n");
        return -1;
    }

    if (listen(sockfd, 1) < 0) {
        printf("Error: Could not listen on socket.\n");
        return -1;
    }

    close(sockfd);

    return 0;
}

// Main function
int main() {
    int port = 80;
    struct addrinfo hints, *servinfo, *p;
    int rv;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("localhost", NULL, &hints, &servinfo)!= 0) {
        printf("Error: Could not get address information.\n");
        return -1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int sockfd;
        struct sockaddr_in address;
        struct hostent *host;

        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);

        if (sockfd < 0) {
            printf("Error: Could not create socket.\n");
            continue;
        }

        memset(&address, 0, sizeof(address));
        address.sin_family = p->ai_family;
        address.sin_port = htons(port);
        address.sin_addr = *((struct in_addr *)p->ai_addr);

        if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
            printf("Error: Could not connect to address.\n");
            close(sockfd);
            continue;
        }

        if (is_port_open(port, address)!= 0) {
            printf("Port %d is open.\n", port);
        } else {
            printf("Port %d is closed.\n", port);
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);

    return 0;
}