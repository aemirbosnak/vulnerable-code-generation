//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 80
#define HOST "www.google.com"

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(HOST);
    if (server == NULL) {
        fprintf(stderr, "Hostname could not be resolved\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    if (send(sockfd, "GET / HTTP/1.1\r\nHost: " HOST "\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: " HOST "\r\n\r\n"), 0) == -1) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    printf("Sent: %s\n", "GET / HTTP/1.1\r\nHost: " HOST "\r\n\r\n");

    char buf[1024];
    if (recv(sockfd, buf, sizeof(buf), 0) > 0) {
        printf("Received: %s\n", buf);
    } else {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    close(sockfd);
    return 0;
}