//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: thriller
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

void error(char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");
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
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Login to POP3 server
    memset(buffer, '\0', sizeof(buffer));
    sprintf(buffer, "USER username\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
         error("ERROR writing to socket");
    memset(buffer, '\0', sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0)
         error("ERROR reading from socket");
    printf("%s", buffer);

    memset(buffer, '\0', sizeof(buffer));
    sprintf(buffer, "PASS password\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
         error("ERROR writing to socket");
    memset(buffer, '\0', sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer)-1);
    if (n < 0)
         error("ERROR reading from socket");
    printf("%s", buffer);

    // List messages
    memset(buffer, '\0', sizeof(buffer));
    sprintf(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
         error("ERROR writing to socket");
    memset(buffer, '\0', sizeof(buffer));
    while ((n = read(sockfd, buffer, sizeof(buffer)-1)) > 0) {
        printf("%s", buffer);
        if (strstr(buffer, "\r\n.\r\n"))
            break;
        memset(buffer, '\0', sizeof(buffer));
    }
    if (n < 0)
         error("ERROR reading from socket");

    // Close connection
    memset(buffer, '\0', sizeof(buffer));
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
         error("ERROR writing to socket");
    close(sockfd);
    return 0;
}