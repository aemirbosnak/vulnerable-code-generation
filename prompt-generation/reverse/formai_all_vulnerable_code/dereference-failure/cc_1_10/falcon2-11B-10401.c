//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (0 > (sockfd = socket(AF_INET, SOCK_STREAM, 0))) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("www.google.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    char buf[1024];
    int len;

    while ((len = read(sockfd, buf, sizeof(buf))) > 0) {
        printf("%s", buf);
    }

    if (len < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("\n");
    return 0;
}