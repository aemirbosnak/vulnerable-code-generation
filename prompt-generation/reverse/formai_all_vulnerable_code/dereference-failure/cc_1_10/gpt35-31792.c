//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: happy
// Let's start by including the required libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Define the buffer limit
#define BUF_SIZE 1024

// A helpful function to check for errors
void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(0);
    }
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if (sockfd < 0)
        error("ERROR opening socket");
    
    // Get the server details from the hostname
    server = gethostbyname(argv[1]);
    
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }
   
    // Set the server address details
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
   
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // Send the HELO message to the server
    bzero(buffer, BUF_SIZE);
    strcpy(buffer, "HELO Localhost\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0)
        error("ERROR reading from socket");

    printf("%s\n", buffer);
    
    // Send the MAIL FROM message to the server
    bzero(buffer, BUF_SIZE);
    strcpy(buffer, "MAIL FROM: <example@mail.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0)
        error("ERROR reading from socket");

    printf("%s\n", buffer);
    
    // Send the RCPT TO message to the server
    bzero(buffer, BUF_SIZE);
    strcpy(buffer, "RCPT TO: <destination@mail.com>\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0)
        error("ERROR reading from socket");

    printf("%s\n", buffer);
    
    // Send the DATA message to the server
    bzero(buffer, BUF_SIZE);
    strcpy(buffer, "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0)
        error("ERROR reading from socket");

    printf("%s\n", buffer);
    
    // Send the message content to the server
    bzero(buffer, BUF_SIZE);
    strcpy(buffer, "From: example@mail.com\r\nTo: destination@mail.com\r\nSubject: This is a test email\r\n\r\nThis is a test email sent from a C program\r\n.\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0)
        error("ERROR reading from socket");

    printf("%s\n", buffer);
    
    // Send the QUIT message to the server
    bzero(buffer, BUF_SIZE);
    strcpy(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0)
        error("ERROR reading from socket");

    printf("%s\n", buffer);
    
    // Close the socket connection
    close(sockfd);
    return 0;
}