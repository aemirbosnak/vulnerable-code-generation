//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname sender_email recipient_email\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    // Lookup hostname
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    // Setup server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(SMTP_PORT);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Receive greeting from server
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Send HELO command
    char helo[50];
    snprintf(helo, 50, "HELO %s\r\n", argv[1]);
    n = write(sockfd, helo, strlen(helo));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive response from server
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Send MAIL FROM command
    char mail_from[100];
    snprintf(mail_from, 100, "MAIL FROM:<%s>\r\n", argv[2]);
    n = write(sockfd, mail_from, strlen(mail_from));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive response from server
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Send RCPT TO command
    char rcpt_to[100];
    snprintf(rcpt_to, 100, "RCPT TO:<%s>\r\n", argv[3]);
    n = write(sockfd, rcpt_to, strlen(rcpt_to));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive response from server
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Send DATA command
    char data[] = "DATA\r\n";
    n = write(sockfd, data, strlen(data));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive response from server
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Send message body
    char msg[500];
    printf("Enter message:\n");
    fgets(msg, 500, stdin);
    n = write(sockfd, msg, strlen(msg));
    if (n < 0)
        error("ERROR writing to socket");

    // Send QUIT command
    char quit[] = "QUIT\r\n";
    n = write(sockfd, quit, strlen(quit));
    if (n < 0)
        error("ERROR writing to socket");

    // Receive response from server
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE-1);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    // Close socket
    close(sockfd);
    return 0;
}