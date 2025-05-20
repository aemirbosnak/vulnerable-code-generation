//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo;
    char *hostname = "localhost";
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    char *port = "21";
    char *command = "USER anonymous\r\n";
    char *response = (char *) malloc(BUFFER_SIZE);

    if (argc > 1) {
        hostname = argv[1];
    }

    if (argc > 2) {
        username = argv[2];
    }

    if (argc > 3) {
        password = argv[3];
    }

    if (argc > 4) {
        port = argv[4];
    }

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if ((getaddrinfo(hostname, port, &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(EAI_SYSTEM));
        return 1;
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen)!= 0) {
        perror("connect");
        return 1;
    }

    printf("Connected to %s\n", hostname);

    if (send(sockfd, command, strlen(command), 0)!= strlen(command)) {
        perror("send");
        return 1;
    }

    memset(response, 0, BUFFER_SIZE);
    if ((recv(sockfd, response, BUFFER_SIZE, 0)) < 0) {
        perror("recv");
        return 1;
    }

    printf("Response: %s\n", response);

    close(sockfd);
    return 0;
}