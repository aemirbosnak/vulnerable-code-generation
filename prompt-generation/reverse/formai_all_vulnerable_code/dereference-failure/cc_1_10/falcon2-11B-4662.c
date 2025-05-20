//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    int port;
    char buffer[1024];

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    memset((char *)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        fprintf(stderr, "ERROR on binding\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        fprintf(stderr, "ERROR on connecting\n");
        exit(1);
    }

    if (send(sockfd, "HELO world", 7, 0) == -1) {
        fprintf(stderr, "ERROR sending message\n");
        exit(1);
    }

    if (recv(sockfd, buffer, 1024, 0) == -1) {
        fprintf(stderr, "ERROR receiving response\n");
        exit(1);
    }

    printf("Response: %s\n", buffer);

    close(sockfd);
    exit(0);
}