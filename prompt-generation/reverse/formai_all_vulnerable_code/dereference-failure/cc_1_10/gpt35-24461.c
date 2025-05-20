//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];
    char message[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname recipient_email\n", argv[0]);
        exit(1);
    }

    portno = SMTP_PORT;
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
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Wait for the welcome message from the server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Send HELO message
    sprintf(message, "HELO %s\r\n", argv[1]);
    n = write(sockfd, message, strlen(message));
    if (n < 0) error("ERROR writing to socket");

    // Wait for the response from the server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Send MAIL FROM message
    sprintf(message, "MAIL FROM:<%s>\r\n", argv[1]);
    n = write(sockfd, message, strlen(message));
    if (n < 0) error("ERROR writing to socket");

    // Wait for the response from the server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Send RCPT TO message
    sprintf(message, "RCPT TO:<%s>\r\n", argv[2]);
    n = write(sockfd, message, strlen(message));
    if (n < 0) error("ERROR writing to socket");

    // Wait for the response from the server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Send DATA message
    sprintf(message, "DATA\r\n");
    n = write(sockfd, message, strlen(message));
    if (n < 0) error("ERROR writing to socket");

    // Wait for the response from the server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Send email message
    printf("Please enter your email message:\n");
    fgets(buffer, BUFFER_SIZE, stdin);

    // Send the body of the email
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) error("ERROR writing to socket");

    // Send the end of email message
    sprintf(message, "\r\n.\r\n");
    n = write(sockfd, message, strlen(message));
    if (n < 0) error("ERROR writing to socket");

    // Wait for the response from the server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Send QUIT message
    sprintf(message, "QUIT\r\n");
    n = write(sockfd, message, strlen(message));
    if (n < 0) error("ERROR writing to socket");

    // Wait for the response from the server
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}