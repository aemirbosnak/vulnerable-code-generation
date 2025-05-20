//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[1024];
    char from_addr[256], to_addr[256];

    // Set up the sender address
    strcpy(from_addr, "romeo@capulet.com");

    // Set up the receiver address
    strcpy(to_addr, "juliet@capulet.com");

    // Set up the port number for the SMTP server
    portno = 25;

    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address structure
    server = gethostbyname("mail.capulet.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(EXIT_FAILURE);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send the email message
    printf("Type the message you want to send:\n");
    fgets(buf, sizeof(buf), stdin);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    return 0;
}