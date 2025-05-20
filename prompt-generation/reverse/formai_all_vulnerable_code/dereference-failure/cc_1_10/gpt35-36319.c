//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

/* Function to check for errors */
void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    /* Send the user name */
    printf("Enter your user name: ");
    scanf("%s", buffer);
    bzero(buffer, 1024);
    sprintf(buffer, "USER %s\r\n", buffer);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    /* Get the response from the server */
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    /* Send the password */
    printf("Enter your password: ");
    scanf("%s", buffer);
    bzero(buffer, 1024);
    sprintf(buffer, "PASS %s\r\n", buffer);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    /* Get the response from the server */
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    /* Send the LIST command to get a list of mail */
    bzero(buffer, 1024);
    sprintf(buffer, "LIST\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    /* Get the response from the server */
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    /* Send the QUIT command to exit */
    bzero(buffer, 1024);
    sprintf(buffer, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    close(sockfd);
    return 0;
}