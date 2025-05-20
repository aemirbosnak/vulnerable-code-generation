//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: relaxed
// A POP3 client program in C
// Written by [Your Name]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define POP3_PORT 110   // The port number for POP3 protocol
#define MAX_SIZE 1024   // The maximum size of buffer
#define DOMAIN_NAME "pop3.email.com"    // The domain name of email service provider
#define USER_NAME "your_username"       // The username of the email account
#define PASS_WORD "your_password"       // The password of the email account

int main() {
    int sockfd, msg_size;
    char buffer[MAX_SIZE], response[MAX_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    server = gethostbyname(DOMAIN_NAME);
    if (server == NULL) {
        perror("Unable to resolve hostname");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(POP3_PORT);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        exit(1);
    }

    // Receive the welcome message from the server
    bzero(response, MAX_SIZE);
    msg_size = read(sockfd, response, MAX_SIZE - 1);
    printf("%s\n", response);

    // Send the username to the server
    sprintf(buffer, "USER %s\r\n", USER_NAME);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(response, MAX_SIZE);
    msg_size = read(sockfd, response, MAX_SIZE - 1);
    printf("%s\n", response);

    // Send the password to the server
    sprintf(buffer, "PASS %s\r\n", PASS_WORD);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(response, MAX_SIZE);
    msg_size = read(sockfd, response, MAX_SIZE - 1);
    printf("%s\n", response);

    // List all emails in the mailbox
    sprintf(buffer, "LIST\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(response, MAX_SIZE);
    msg_size = read(sockfd, response, MAX_SIZE - 1);
    printf("%s\n", response);

    // Retrieve the first email in the mailbox
    sprintf(buffer, "RETR 1\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(response, MAX_SIZE);
    msg_size = read(sockfd, response, MAX_SIZE - 1);
    printf("%s\n", response);

    // Delete the first email in the mailbox
    sprintf(buffer, "DELE 1\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(response, MAX_SIZE);
    msg_size = read(sockfd, response, MAX_SIZE - 1);
    printf("%s\n", response);

    // Quit the POP3 session
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(response, MAX_SIZE);
    msg_size = read(sockfd, response, MAX_SIZE - 1);
    printf("%s\n", response);

    close(sockfd);
    return 0;
}