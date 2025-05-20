//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUFFER_SIZE 1024

void error(char *msg) {
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

    portno = atoi(argv[2]);

     /* Create socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");

    /* Get server by host name */
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    /* Set server address structure */
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    inet_aton(inet_ntoa(*(struct in_addr*)*server->h_addr_list), &serv_addr.sin_addr);

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) error("ERROR connecting");

    /* Send HELO */
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) error("ERROR writing to socket");

    /* Receive reply */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s", buffer);

    /* Send MAIL FROM */
    sprintf(buffer, "MAIL FROM: %s\r\n", "youremail@example.com");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) error("ERROR writing to socket");

    /* Receive reply */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s", buffer);

    /* Send RCPT TO */
    sprintf(buffer, "RCPT TO: %s\r\n", "destination@example.com");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) error("ERROR writing to socket");

    /* Receive reply */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s", buffer);

    /* Send DATA */
    n = write(sockfd, "DATA\r\n", strlen("DATA\r\n"));
    if (n < 0) error("ERROR writing to socket");

    /* Receive reply */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s", buffer);

    /* Send message body */
    char *msg = "Subject: SMTP Client Test\r\n\r\nHello, this is a test email\n";
    n = write(sockfd, msg, strlen(msg));
    if (n < 0) error("ERROR writing to socket");

    /* Send end of email */
    n = write(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"));
    if (n < 0) error("ERROR writing to socket");

    /* Receive reply */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s", buffer);

    /* Quit */
    n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    if (n < 0) error("ERROR writing to socket");

    /* Receive reply */
    bzero(buffer, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE-1);
    if (n < 0) error("ERROR reading from socket");
    printf("%s", buffer);

    /* Close socket */
    close(sockfd);

    return 0;
}