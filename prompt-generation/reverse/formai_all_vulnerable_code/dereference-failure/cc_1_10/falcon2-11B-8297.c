//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main()
{
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;

    char buf[256];
    char *host = "localhost";
    char *msg = "Hello, SMTP Client!";

    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr,"No such host\n");
        exit(0);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serveraddr.sin_addr.s_addr, server->h_length);
    serveraddr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    n = write(sockfd, msg, strlen(msg));
    if (n == -1) {
        perror("write failed");
        exit(1);
    }

    printf("Message sent: %s\n", buf);

    close(sockfd);

    return 0;
}