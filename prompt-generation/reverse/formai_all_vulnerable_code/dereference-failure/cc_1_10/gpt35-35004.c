//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUF_SIZE];

    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        error("ERROR invalid server IP address");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting to remote host");
    }

    printf("Connected to FTP server\n");

    char user[MAX_BUF_SIZE], pass[MAX_BUF_SIZE];
    printf("Enter username: ");
    fgets(user, MAX_BUF_SIZE, stdin);
    user[strcspn(user, "\n")] = 0; // remove trailing newline

    printf("Enter password: ");
    fgets(pass, MAX_BUF_SIZE, stdin);
    pass[strcspn(pass, "\n")] = 0; // remove trailing newline

    // send USER command
    char user_cmd[MAX_BUF_SIZE];
    sprintf(user_cmd, "USER %s\r\n", user);
    n = write(sockfd, user_cmd, strlen(user_cmd));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive response for USER command
    bzero(buffer, MAX_BUF_SIZE);
    n = read(sockfd, buffer, MAX_BUF_SIZE);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // send PASS command
    char pass_cmd[MAX_BUF_SIZE];
    sprintf(pass_cmd, "PASS %s\r\n", pass);
    n = write(sockfd, pass_cmd, strlen(pass_cmd));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive response for PASS command
    bzero(buffer, MAX_BUF_SIZE);
    n = read(sockfd, buffer, MAX_BUF_SIZE);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    // send PWD command
    char pwd_cmd[MAX_BUF_SIZE];
    sprintf(pwd_cmd, "PWD\r\n");
    n = write(sockfd, pwd_cmd, strlen(pwd_cmd));
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // receive response for PWD command
    bzero(buffer, MAX_BUF_SIZE);
    n = read(sockfd, buffer, MAX_BUF_SIZE);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", buffer);

    close(sockfd);
    return 0;
}