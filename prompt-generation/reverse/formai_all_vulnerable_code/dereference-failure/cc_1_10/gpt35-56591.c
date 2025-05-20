//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <signal.h>
#include <arpa/inet.h>

#define MAXLINE 1024
#define SA struct sockaddr

void sig_chld(int signo){
    pid_t pid;
    int stat;
    while((pid = waitpid(-1, &stat, WNOHANG)) > 0)
        printf("Child %d terminated\n", pid);
    return;
}

void str_echo(int sockfd){
    ssize_t n;
    char buf[MAXLINE];

    while((n = read(sockfd, buf, MAXLINE)) > 0){
        write(sockfd, buf, n);
    }

    if(n < 0){
        printf("read error");
    }
}

int main(int argc, const char **argv){

    int listenfd, connfd;
    pid_t childpid;
    socklen_t clilen;
    struct sockaddr_in cliaddr, servaddr;

    if(argc != 2){
        printf("usage: a.out <Port Number>");
        exit(1);
    }

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if(listenfd < 0){
        printf("socket error");
        exit(2);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    if(bind(listenfd, (SA*)&servaddr, sizeof(servaddr)) < 0){
        printf("bind error");
        exit(3);
    }

    if(listen(listenfd, 1024) < 0){
        printf("listen error");
        exit(4);
    }

    signal(SIGCHLD, sig_chld);

    for( ; ; ){

        clilen = sizeof(cliaddr);
        connfd = accept(listenfd, (SA*)&cliaddr, &clilen);

        if(connfd < 0){
            printf("accept error");
            exit(5);
        }

        if((childpid = fork()) == 0){

            close(listenfd);
            str_echo(connfd);
            exit(0);
        }

        close(connfd);
    }
    
    return 0;
}