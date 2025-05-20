//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_BUFF 1024

void handle_socket(int sockfd, char *cmd, char *arg) {
    char buff[MAX_BUFF];
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, arg, strlen(arg), 0);
    recv(sockfd, buff, MAX_BUFF, 0);
    printf("%s\n", buff);
}

void handle_file(int sockfd, char *cmd, char *arg) {
    int fd;
    char buff[MAX_BUFF];
    if ((fd = open(arg, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0) {
        perror("open");
        return;
    }
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, arg, strlen(arg), 0);
    while (recv(sockfd, buff, MAX_BUFF, 0) > 0) {
        write(fd, buff, strlen(buff));
    }
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <host> <port> <command> <argument>\n", argv[0]);
        exit(1);
    }
    int sockfd;
    struct sockaddr_in server_addr;
    char *host = argv[1];
    int port = atoi(argv[2]);
    char *cmd = argv[3];
    char *arg = argv[4];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_aton(host, &server_addr.sin_addr) <= 0) {
        perror("inet_aton");
        exit(1);
    }
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }
    if (strcmp(cmd, "RETR") == 0) {
        handle_file(sockfd, cmd, arg);
    } else {
        handle_socket(sockfd, cmd, arg);
    }
    close(sockfd);
    return 0;
}