//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define PORT "9000"  // Port Number

void *get_in_addr(struct sockaddr *sa) {  // get IPv4 or IPv6 address
    if (sa->sa_family == AF_INET) {
        return &(((struct sockaddr_in*)sa)->sin_addr);
    }
    return &(((struct sockaddr_in6*)sa)->sin6_addr);
}

int main(int argc, char *argv[]) {
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: Failed to create socket.");
        exit(EXIT_FAILURE);
    }

    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;  // IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;  // use my IP

    int status = getaddrinfo(NULL, PORT, &hints, &servinfo);
    if (status != 0) {
        perror("Error: Failed to get address information.");
        exit(EXIT_FAILURE);
    }

    // bind socket to port
    for (p = servinfo; p != NULL; p = p->ai_next) {
        if (bind(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("Error: Failed to bind socket.");
            continue;
        }
        break;
    }

    // check for errors
    if (p == NULL) {
        perror("Error: Failed to bind socket.");
        exit(EXIT_FAILURE);
    }

    freeaddrinfo(servinfo);  // done with this structure

    // listen for connections
    if (listen(sockfd, 10) == -1) {
        perror("Error: Failed to listen for connections.");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections
    struct sockaddr_storage their_addr;  // client's address information
    socklen_t addr_size = sizeof their_addr;

    while(1) {
        int new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
        if (new_fd == -1) {
            perror("Error: Failed to accept incoming connection.");
            continue;
        }

        char s[INET6_ADDRSTRLEN];
        inet_ntop(their_addr.ss_family, get_in_addr((struct sockaddr *)&their_addr), s, sizeof s);
        printf("Connection accepted from %s.\n", s);

        // receive data from client
        char buf[1024];
        if (recv(new_fd, buf, sizeof buf, 0) == -1) {
            perror("Error: Failed to receive data from client.");
            close(new_fd);
            continue;
        }

        printf("Received data from client: %s\n", buf);

        // close the connection
        close(new_fd);
    }

    // close the socket
    close(sockfd);

    return 0;
}