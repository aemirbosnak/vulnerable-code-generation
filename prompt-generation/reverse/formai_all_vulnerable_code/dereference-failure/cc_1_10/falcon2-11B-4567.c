//Falcon2-11B DATASET v1.0 Category: Wireless Network Scanner ; Style: immersive
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 50007

void print_error(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        print_error("ERROR opening socket");
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        print_error("ERROR, no such host");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        print_error("ERROR connecting");
    }

    char buffer[256];
    bzero(buffer, 256);
    n = read(sockfd, buffer, 256);
    if (n < 0) {
        print_error("ERROR reading from socket");
    }

    printf("Received: %s\n", buffer);

    close(sockfd);

    return 0;
}