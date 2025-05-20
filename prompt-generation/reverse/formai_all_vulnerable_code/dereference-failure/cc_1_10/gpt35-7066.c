//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_PORT 25
#define MAX_BUFFER_SIZE 1024

void error(char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char **argv)
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname message\n", argv[0]);
        exit(0);
    }

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
    serv_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");

    printf("%s",buffer);

    char *message = argv[2];
    char *cmd = "HELO localhost";
    char *mail_from = "MAIL FROM:<youremail@gmail.com>";
    char *rcpt_to = "RCPT TO:<recipientemail@yahoo.com>";
    char *data = "DATA";

    // Issue HELO command
    n = write(sockfd, cmd, strlen(cmd));
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");

    printf("%s",buffer);

    // Issue MAIL FROM command
    n = write(sockfd, mail_from, strlen(mail_from));
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");

    printf("%s",buffer);

    // Issue RCPT TO command
    n = write(sockfd, rcpt_to, strlen(rcpt_to));
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");

    printf("%s",buffer);

    // Issue DATA command
    n = write(sockfd, data, strlen(data));
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");

    printf("%s",buffer);

    // Send message
    n = write(sockfd, message, strlen(message));
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");

    printf("%s",buffer);

    // Close connection
    n = write(sockfd, "QUIT", strlen("QUIT"));
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, MAX_BUFFER_SIZE);
    n = read(sockfd, buffer, MAX_BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");

    printf("%s",buffer);

    close(sockfd);
    return 0;
}