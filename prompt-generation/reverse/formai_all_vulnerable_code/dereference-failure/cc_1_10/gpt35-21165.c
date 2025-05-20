//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    char username[BUF_SIZE];
    char password[BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Enter your username: ");
    fgets(username, BUF_SIZE, stdin);
    printf("Enter your password: ");
    fgets(password, BUF_SIZE, stdin);

    sprintf(buffer, "USER %s\n", username);
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid username\n");
        exit(1);
    }

    sprintf(buffer, "PASS %s\n", password);
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid password\n");
        exit(1);
    }

    sprintf(buffer, "LIST\n");
    n = write(sockfd, buffer, strlen(buffer));

    if (n < 0) {
        error("ERROR writing to socket");
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE);

    if (n < 0) {
        error("ERROR reading from socket");
    }

    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error getting mail count\n");
        exit(1);
    }

    printf("%s", buffer);

    close(sockfd);
    return 0;
}