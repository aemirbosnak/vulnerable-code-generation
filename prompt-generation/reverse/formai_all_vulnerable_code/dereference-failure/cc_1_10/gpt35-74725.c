//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <string.h>

#define BUFFER_SIZE 128

void sendMail(int sockfd, char *to, char *from, char *subject, char *message) {
    char buffer[BUFFER_SIZE];
    int n;

    sprintf(buffer, "To: %s\r\nFrom: %s\r\nSubject: %s\r\n\r\n%s\r\n", to, from, subject, message);

    // Send data
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // Read server response
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFFER_SIZE];

    if (argc < 4) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read server welcome message
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    // Send HELO message
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    } 

    // Read server response
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    // Send mail
    char *to = "example@domain.com";
    char *from = "me@mydomain.com";
    char *subject = "Test email";
    char *message = "Hello, this is a test email from my SMTP client program.";

    sendMail(sockfd, to, from, subject, message);

    // Send QUIT message
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    } 

    // Read server response
    bzero(buffer,BUFFER_SIZE);
    n = read(sockfd,buffer,BUFFER_SIZE);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s", buffer);

    close(sockfd);
    return 0;
}