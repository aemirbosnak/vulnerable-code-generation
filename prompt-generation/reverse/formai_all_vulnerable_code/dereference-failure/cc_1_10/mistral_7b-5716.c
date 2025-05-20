//MISTRAL-7B DATASET v1.0 Category: Building a FTP Client ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define PORT 21
#define MAXDATASIZE 1024
#define BUFFER_SIZE 256

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_ftp(const char *host) {
    int sockfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        die("socket: unable to open socket");

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        die("inet_pton: unable to convert host address");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        die("connect: unable to connect to host");

    return sockfd;
}

void login(int connfd, const char *username, const char *password) {
    char cmd[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(cmd, BUFFER_SIZE, "USER %s\r\n", username);
    write(connfd, cmd, strlen(cmd));

    read(connfd, response, BUFFER_SIZE);
    printf("%s", response);

    snprintf(cmd, BUFFER_SIZE, "PASS %s\r\n", password);
    write(connfd, cmd, strlen(cmd));

    read(connfd, response, BUFFER_SIZE);
    printf("%s", response);
}

void type(int connfd, const char *type) {
    char cmd[BUFFER_SIZE];

    snprintf(cmd, BUFFER_SIZE, "TYPE %s\r\n", type);
    write(connfd, cmd, strlen(cmd));
}

void ls(int connfd) {
    char cmd[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    snprintf(cmd, BUFFER_SIZE, "LIST\r\n");
    write(connfd, cmd, strlen(cmd));

    ssize_t n;
    while ((n = read(connfd, response, BUFFER_SIZE)) > 0) {
        printf("%s", response);
    }
}

void quit(int connfd) {
    char cmd[BUFFER_SIZE];

    snprintf(cmd, BUFFER_SIZE, "QUIT\r\n");
    write(connfd, cmd, strlen(cmd));

    close(connfd);
}

int main(int argc, char *argv[]) {
    int connfd;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <username:password>\n", argv[0]);
        exit(1);
    }

    const char *host = argv[1];
    const char *username_password = argv[2];
    const size_t username_len = strlen(strtok(argv[2], ":"));
    const char *username = strtok(argv[2], ":");
    const char *password = username_password + username_len + 1;

    connfd = connect_ftp(host);
    login(connfd, username, password);
    type(connfd, "Ascii");
    ls(connfd);
    quit(connfd);

    return 0;
}