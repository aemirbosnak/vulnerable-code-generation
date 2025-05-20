//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main() {
    int sockfd, ret;
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    char host[NI_MAXHOST], service[NI_MAXSERV];

    // Initialize hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;

    // Get address information for specified host and port
    if ((ret = getaddrinfo("localhost", "8080", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(ret));
        exit(1);
    }

    // Loop through all the results and connect to the first we can
    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sockfd);
        sockfd = -1;
    }

    if (sockfd == -1) {
        fprintf(stderr, "failed to connect\n");
        exit(1);
    }

    // Send and receive data
    while (1) {
        char send_buf[BUF_SIZE];
        char recv_buf[BUF_SIZE];

        memset(send_buf, 0, sizeof(send_buf));
        memset(recv_buf, 0, sizeof(recv_buf));

        sprintf(send_buf, "Thou art a QoS monitor of the realm!");

        ret = send(sockfd, send_buf, strlen(send_buf), 0);
        if (ret == -1) {
            perror("send");
            exit(1);
        }

        ret = recv(sockfd, recv_buf, BUF_SIZE, 0);
        if (ret == -1) {
            perror("recv");
            exit(1);
        }

        printf("Received: %s\n", recv_buf);
    }

    close(sockfd);

    return 0;
}