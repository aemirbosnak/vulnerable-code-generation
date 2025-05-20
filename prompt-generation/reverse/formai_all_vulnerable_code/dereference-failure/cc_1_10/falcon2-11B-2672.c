//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to send mail using SMTP protocol
int sendMail(char *mailAddress, char *message) {
    struct sockaddr_in serverAddr;
    int sockfd, portno, n;
    struct hostent *server;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        return -1;
    }

    // Resolve the server name
    if ((server = gethostbyname("smtp.gmail.com")) == NULL) {
        perror("gethostbyname");
        return -1;
    }

    // Assign server address to sockaddr_in structure
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(25); // Port number for SMTP
    bzero((char *) &serverAddr.sin_addr, sizeof(serverAddr.sin_addr));
    bcopy((char *)server->h_addr, (char *)&serverAddr.sin_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) == -1) {
        perror("connect failed");
        return -1;
    }

    // Send HELO command
    char hello[80];
    sprintf(hello, "HELO Mail Client\r\n");
    send(sockfd, hello, strlen(hello), 0);

    // Send MAIL FROM command
    sprintf(hello, "MAIL FROM:<%s>\r\n", mailAddress);
    send(sockfd, hello, strlen(hello), 0);

    // Send RCPT TO command
    sprintf(hello, "RCPT TO:<%s>\r\n", mailAddress);
    send(sockfd, hello, strlen(hello), 0);

    // Send DATA command
    sprintf(hello, "DATA\r\n");
    send(sockfd, hello, strlen(hello), 0);

    // Send message
    sprintf(hello, "From: %s\r\nTo: %s\r\nSubject: SMTP Client\r\n\r\n%s\r\n.\r\n", mailAddress, mailAddress, message);
    send(sockfd, hello, strlen(hello), 0);

    // Send QUIT command
    sprintf(hello, "QUIT\r\n");
    send(sockfd, hello, strlen(hello), 0);

    // Close the socket
    close(sockfd);

    return 0;
}

// Main function
int main() {
    char *mailAddress = "your_email@gmail.com";
    char *message = "Hello World";

    sendMail(mailAddress, message);

    return 0;
}