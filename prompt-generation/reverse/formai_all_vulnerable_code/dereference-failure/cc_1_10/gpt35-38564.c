//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 993  // IMAP4 SSL port

int main() {

    int sockfd, n, len;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // resolve hostname
    server = gethostbyname("mail.example.com");
    if (server == NULL) {
        perror("ERROR no such host");
        exit(1);
    }

    // clear server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // set server address structure
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // receive server greeting
    char buffer[1024];
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // send login credentials
    char user[50] = "username";
    char pass[50] = "password";
    char login[100];
    sprintf(login, "login %s %s\r\n", user, pass);
    n = write(sockfd, login, strlen(login));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // receive login response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // select inbox folder
    n = write(sockfd, "select inbox\r\n", 15);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // receive select response
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // logout and disconnect
    n = write(sockfd, "logout\r\n", 8);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    close(sockfd);

    return 0;
}