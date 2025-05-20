//FormAI DATASET v1.0 Category: Email Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 993 // Standard IMAP4 port
#define HOST "imap.gmail.com" // Host address of the IMAP server

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main() {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    bzero(buffer, 256);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get the server's IP address
    server = gethostbyname(HOST);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Configure the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Send the login information
    sprintf(buffer, "a001 LOGIN your_email_address your_password\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read the server's response
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send the select mailbox command
    sprintf(buffer, "a002 SELECT INBOX\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read the server's response
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Send the logout command
    sprintf(buffer, "a003 LOGOUT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Read the server's response
    bzero(buffer,256);
    n = read(sockfd, buffer, 255);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // Close the socket
    close(sockfd);
    return 0;
}