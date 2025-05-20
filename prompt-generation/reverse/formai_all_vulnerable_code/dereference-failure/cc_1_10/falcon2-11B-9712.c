//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Romeo and Juliet
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *servinfo, *p;
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    rv = getaddrinfo(NULL, argv[1], &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        int sockfd;
        struct sockaddr_in server_addr;

        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            perror("socket");
            continue;
        }

        server_addr.sin_family = p->ai_family;
        server_addr.sin_port = htons(p->ai_addrlen);
        memcpy((char *)&server_addr.sin_addr, p->ai_addr, p->ai_addrlen);

        if (connect(sockfd, (struct sockaddr *)&server_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(sockfd);
            continue;
        }

        printf("Connected to %s on port %d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

        char buffer[1024];
        int bytes_read;
        while ((bytes_read = recv(sockfd, buffer, sizeof buffer, 0)) > 0) {
            printf("%s", buffer);
        }

        close(sockfd);
    }

    freeaddrinfo(servinfo);

    return 0;
}