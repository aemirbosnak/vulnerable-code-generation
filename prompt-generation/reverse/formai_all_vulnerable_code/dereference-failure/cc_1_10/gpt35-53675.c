//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

// Function to send a command to the server
void send_message(int sockfd, char *msg) {
    char buf[BUF_SIZE];
    int len = strlen(msg);
    memcpy(buf, msg, len);
    buf[len] = '\r';
    buf[len+1] = '\n';
    buf[len+2] = '\0';
    send(sockfd, buf, strlen(buf), 0);
}

// Function to read a response from the server
void read_response(int sockfd) {
    char buf[BUF_SIZE];
    int bytes = recv(sockfd, buf, BUF_SIZE - 1, 0);
    buf[bytes] = '\0';
    printf("%s\n", buf);
}

int main(int argc, char **argv) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Greeting message
    read_response(sockfd);

    // Send EHLO command
    send_message(sockfd, "EHLO mydomain.com");
    read_response(sockfd);

    // Send MAIL FROM command
    send_message(sockfd, "MAIL FROM:<myemail@mydomain.com>");
    read_response(sockfd);

    // Send RCPT TO command
    send_message(sockfd, "RCPT TO:<your-email@your-domain.com>");
    read_response(sockfd);

    // Send DATA command
    send_message(sockfd, "DATA");
    read_response(sockfd);

    // Send message body
    send_message(sockfd, "From: myemail@mydomain.com\r\nTo: your-email@your-domain.com\r\nSubject: SMTP client example\r\n\r\nHello, this is a test email from my SMTP client.");
    send_message(sockfd, ".");
    read_response(sockfd);

    // Send QUIT command
    send_message(sockfd, "QUIT");
    read_response(sockfd);

    close(sockfd);
    return 0;
}