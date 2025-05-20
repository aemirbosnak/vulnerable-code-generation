//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SERVER_PORT 25 // SMTP port number

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char message[1024];
    char buffer[1024];

    // check for the correct number of arguments
    if (argc < 3) {
        fprintf(stderr,"usage: %s hostname message\n", argv[0]);
        exit(1);
    }

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // get the server's IP address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    // configure the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(SERVER_PORT);

    // connect to the server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // read the server's response
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n",buffer);

    // send the HELO message
    sprintf(message, "HELO %s\r\n", argv[1]);
    write(sockfd, message, strlen(message));
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n",buffer);

    // send the MAIL FROM message
    sprintf(message, "MAIL FROM:<%s>\r\n", argv[1]);
    write(sockfd, message, strlen(message));
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n",buffer);

    // send the RCPT TO message
    sprintf(message, "RCPT TO:<%s>\r\n", argv[2]);
    write(sockfd, message, strlen(message));
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n",buffer);

    // send the DATA message
    sprintf(message, "DATA\r\n");
    write(sockfd, message, strlen(message));
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n",buffer);

    // send the message body
    sprintf(message, "%s\r\n.\r\n", argv[3]);
    write(sockfd, message, strlen(message));
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n",buffer);

    // send the QUIT message
    sprintf(message, "QUIT\r\n");
    write(sockfd, message, strlen(message));
    bzero(buffer,1024);
    read(sockfd,buffer,1024);
    printf("%s\n",buffer);

    // close the socket
    close(sockfd);

    return 0;
}