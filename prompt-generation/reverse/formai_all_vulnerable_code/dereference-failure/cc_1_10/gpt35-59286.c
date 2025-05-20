//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    memset(buffer, 0, sizeof buffer);
    sprintf(buffer, "USER %s\r\n", "exampleusername");

    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    memset(buffer, 0, sizeof buffer);
    sprintf(buffer, "PASS %s\r\n", "examplepassword");

    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    memset(buffer, 0, sizeof buffer);
    sprintf(buffer, "RETR %s\r\n", "1");

    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, 1024, 0);
    printf("%s", buffer);

    close(sockfd);
    return 0;
}