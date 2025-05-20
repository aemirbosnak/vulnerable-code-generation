//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    char buf[BUF_SIZE];
    int rv;
    int numbytes;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("localhost", "80", &hints, &servinfo))!= 0) {
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

    freeaddrinfo(servinfo);

    while(1){
        printf("Enter the number of packets to send: ");
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            send(sockfd, "GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: localhost\r\nConnection: close\r\n\r\n"), 0);
            usleep(100000);
        }
        usleep(500000);
        while(1){
            numbytes = recv(sockfd, buf, BUF_SIZE-1, 0);
            if(numbytes <= 0)
                break;
            buf[numbytes] = '\0';
            printf("%s", buf);
        }
    }

    close(sockfd);
    return 0;
}