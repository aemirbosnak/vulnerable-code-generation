//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    char *ip;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc!= 4) {
        fprintf(stderr, "Usage:./client <IP> <PORT> <MESSAGE>\n");
        exit(1);
    }

    ip = argv[1];
    portno = atoi(argv[2]);
    char *message = argv[3];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    server = gethostbyname(ip);

    if (server == NULL) {
        printf("No such host\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    memcpy(&serv_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting\n");
        exit(1);
    }

    send(sockfd, message, strlen(message), 0);

    close(sockfd);

    return 0;
}