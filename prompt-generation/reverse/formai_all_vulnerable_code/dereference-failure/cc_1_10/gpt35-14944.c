//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024

int create_socket(char *server, int port){
    struct hostent *he;
    struct sockaddr_in addr;

    if ((he = gethostbyname(server)) == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr *) he->h_addr);

    if(connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) < 0){
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

int send_cmd(int sockfd, char *cmd){
    char buf[BUF_SIZE];

    memset(buf, 0, BUF_SIZE);
    strcpy(buf, cmd);
    strcat(buf, "\r\n");

    if(write(sockfd, buf, strlen(buf)) < 0){
        perror("write");
        exit(EXIT_FAILURE);
    }

    return 1;
}

int recv_data(int sockfd){
    char buf[BUF_SIZE];
    int n;

    memset(buf, 0, BUF_SIZE);
    while((n=read(sockfd, buf, sizeof(buf)-1)) > 0){
        buf[n] = 0;
        printf("%s", buf);
        if(buf[n-1] == '\n') break;
        memset(buf, 0, BUF_SIZE);
    }

    return n;
}

int main(int argc, char *argv[]){
    if(argc < 4){
        fprintf(stderr, "Usage: %s server username password\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd = create_socket(server, 143);

    recv_data(sockfd);
    send_cmd(sockfd, "a001 login ");
    send_cmd(sockfd, username);
    send_cmd(sockfd, password);

    recv_data(sockfd);
    send_cmd(sockfd, "a002 select inbox");

    recv_data(sockfd);
    send_cmd(sockfd, "a003 fetch 1:* (uid flags)");

    recv_data(sockfd);
    send_cmd(sockfd, "a004 logout");

    close(sockfd);

    return 0;
}