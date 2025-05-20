//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

#define PORT 25
#define MAXLINE 1024
#define MAXEMAIL 128
#define MAXSMTP 256

int main()
{
    int sockfd, n;
    char buf[MAXLINE], sendbuf[MAXLINE];
    struct hostent *server;
    struct sockaddr_in serv_addr;
    struct sockaddr_in cli_addr;

    // Get the server host name
    server = gethostbyname("smtp.gmail.com");

    // Copy the server address into the sockaddr structure
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting\n");
        exit(1);
    }

    // Send HELO command
    strcpy(buf, "HELO localhost\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(1);
    }

    // Send MAIL FROM command
    strcpy(buf, "MAIL FROM:<your-email-address>\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(1);
    }

    // Send RCPT TO command
    strcpy(buf, "RCPT TO:<recepient-email-address>\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(1);
    }

    // Send DATA command
    strcpy(buf, "DATA\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(1);
    }

    // Send the email body
    strcpy(sendbuf, "This is the body of the email\r\n.");
    n = write(sockfd, sendbuf, strlen(sendbuf));
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(1);
    }

    // Send QUIT command
    strcpy(buf, "QUIT\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr, "ERROR writing to socket\n");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}