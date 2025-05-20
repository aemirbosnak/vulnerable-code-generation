//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFSIZE 4096

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        perror("ERROR opening socket");

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0)
        perror("ERROR connecting");

    char *request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char *host = argv[1];
    char message[sizeof(request) + sizeof(host)];
    sprintf(message, request, host);
    if (write(sockfd, message, strlen(message)) < 0)
        perror("ERROR writing to socket");

    bzero(buffer,BUFSIZE);
    while ((n = read(sockfd,buffer,BUFSIZE-1)) > 0) {
        printf("%s", buffer);
        bzero(buffer,BUFSIZE);
    }

    if (n < 0)
        perror("ERROR reading from socket");
    close(sockfd);
    return 0;
}