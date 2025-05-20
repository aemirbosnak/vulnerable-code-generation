//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

#define PORT 21
#define BUFFER_SIZE 1024

void usage() {
    printf("Usage:./ftp_client <host> <username> <password> <command>\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc!= 5) {
        usage();
    }

    char *host = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    char *command = argv[4];

    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char s[NI_MAXSERV];
    int rv;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    if ((rv = getaddrinfo(host, "21", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    char *msg = (char *)malloc(BUFFER_SIZE);
    sprintf(msg, "USER %s\r\n", username);
    send(sockfd, msg, strlen(msg), 0);

    char *response = (char *)malloc(BUFFER_SIZE);
    memset(response, 0, BUFFER_SIZE);
    recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Response: %s\n", response);

    sprintf(msg, "PASS %s\r\n", password);
    send(sockfd, msg, strlen(msg), 0);

    memset(response, 0, BUFFER_SIZE);
    recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Response: %s\n", response);

    sprintf(msg, "%s\r\n", command);
    send(sockfd, msg, strlen(msg), 0);

    memset(response, 0, BUFFER_SIZE);
    recv(sockfd, response, BUFFER_SIZE, 0);
    printf("Response: %s\n", response);

    close(sockfd);

    return 0;
}