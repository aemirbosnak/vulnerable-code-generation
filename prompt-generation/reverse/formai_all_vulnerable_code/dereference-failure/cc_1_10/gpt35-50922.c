//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAX_BUF_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUF_SIZE];

    if (argc < 3) {
       fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
       exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Enter username: ");
    bzero(buffer, MAX_BUF_SIZE);
    fgets(buffer, MAX_BUF_SIZE, stdin);

    char *username = strtok(buffer, "\n");
    char auth_msg[MAX_BUF_SIZE];
    snprintf(auth_msg, MAX_BUF_SIZE, "USER %s\r\n", username);

    n = write(sockfd, auth_msg, strlen(auth_msg));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(buffer, MAX_BUF_SIZE);
    n = read(sockfd, buffer, MAX_BUF_SIZE);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    printf("Enter password: ");
    bzero(buffer, MAX_BUF_SIZE);
    fgets(buffer, MAX_BUF_SIZE, stdin);

    char *password = strtok(buffer, "\n");
    snprintf(auth_msg, MAX_BUF_SIZE, "PASS %s\r\n", password);

    n = write(sockfd, auth_msg, strlen(auth_msg));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(buffer, MAX_BUF_SIZE);
    n = read(sockfd, buffer, MAX_BUF_SIZE);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    char quit_msg[MAX_BUF_SIZE];
    snprintf(quit_msg, MAX_BUF_SIZE, "QUIT\r\n");

    n = write(sockfd, quit_msg, strlen(quit_msg));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(buffer, MAX_BUF_SIZE);
    n = read(sockfd, buffer, MAX_BUF_SIZE);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    close(sockfd);
    return 0;
}