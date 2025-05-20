//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    /* create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("Error opening socket");

    /* get server hostname */
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host\n");
        exit(1);
    }

    /* clear server address */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);

    /* set address family and port number */
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    /* copy ip address to server address */
    bcopy((char *)server->h_addr_list[0],
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    /* connect to server */
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("Error connecting");

    /* send HELO command */
    sprintf(buffer, "HELO mycomputer\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("Error writing to socket");

    /* receive reply */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0)
        error("Error reading from socket");
    printf("%s\n", buffer);

    /* send MAIL FROM command */
    sprintf(buffer, "MAIL FROM: <user@example.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("Error writing to socket");

    /* receive reply */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0)
        error("Error reading from socket");
    printf("%s\n", buffer);

    /* send RCPT TO command */
    sprintf(buffer, "RCPT TO: <recipient@example.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("Error writing to socket");

    /* receive reply */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0)
        error("Error reading from socket");
    printf("%s\n", buffer);

    /* send DATA command */
    sprintf(buffer, "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("Error writing to socket");

    /* receive reply */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0)
        error("Error reading from socket");
    printf("%s\n", buffer);

    /* send email message */
    sprintf(buffer, "From: <user@example.com>\r\nTo: <recipient@example.com>\r\nSubject: SMTP Test\r\n\r\nThis is a test message from my SMTP client program.\r\n.\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("Error writing to socket");

    /* receive reply */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0)
        error("Error reading from socket");
    printf("%s\n", buffer);

    /* close connection */
    close(sockfd);

    return 0;
}