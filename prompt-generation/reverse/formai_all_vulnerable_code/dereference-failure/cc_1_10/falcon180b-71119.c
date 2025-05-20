//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netdb.h>
#include <errno.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUFFER_SIZE];
    int numbytes;
    char *username = "anonymous";
    char *password = "anonymous@example.com";

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("ftp.example.com", "21", &hints, &servinfo)!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(errno));
        exit(EXIT_FAILURE);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket error");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect error");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        return 1;
    }

    printf("connected to %s\n", p->ai_canonname);

    if (login(sockfd, username, password)!= 0) {
        fprintf(stderr, "login failed\n");
        return 1;
    }

    while (1) {
        printf("enter command (help for list of commands): ");
        fgets(buffer, BUFFER_SIZE, stdin);
        numbytes = strlen(buffer);
        if (send(sockfd, buffer, numbytes, 0) == -1) {
            perror("send error");
            break;
        }

        numbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (numbytes <= 0) {
            break;
        }

        buffer[numbytes] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}