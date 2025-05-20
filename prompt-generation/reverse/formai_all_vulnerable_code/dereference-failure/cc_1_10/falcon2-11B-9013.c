//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 80

int main(int argc, char *argv[]) {
    struct hostent *he;
    struct sockaddr_in sa;
    int sockfd;
    int addrlen;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    he = gethostbyname(argv[1]);
    if (he == NULL) {
        fprintf(stderr, "Error: Unknown host\n");
        exit(1);
    }

    sa.sin_family = AF_INET;
    sa.sin_port = htons(PORT);
    sa.sin_addr = *(struct in_addr *)he->h_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    addrlen = sizeof(sa);
    if (connect(sockfd, (struct sockaddr *)&sa, addrlen) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[1024];
    printf("Client connected to server\n");
    while (1) {
        if (read(sockfd, buffer, sizeof(buffer)) < 0) {
            perror("read");
            exit(1);
        }
        printf("Server response: %s\n", buffer);
        send(sockfd, "Client response: ", 15, 0);
        if (write(sockfd, buffer, strlen(buffer))!= strlen(buffer)) {
            perror("write");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}