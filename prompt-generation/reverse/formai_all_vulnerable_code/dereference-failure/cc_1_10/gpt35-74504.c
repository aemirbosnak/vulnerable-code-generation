//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFSIZE 1024

void error_handling(char * message);

int main(int argc, char * argv[]){
    int serv_sock;
    int clnt_sock;
    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    char buf[BUFSIZE];
    int len;
    int send_len;

    if(argc != 2){
        printf("Usage : %s <port> \n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1)
        error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr)); //all values in struct are initialized
    serv_addr.sin_family = AF_INET; //Internet protocol version 4
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if(bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");

    if(listen(serv_sock, 5) == -1) //accept upto 5 clients
        error_handling("listen() error");

    len = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &len);
    if(clnt_sock == -1)
        error_handling("accept() error");

    while(1){
        len = recv(clnt_sock, buf, sizeof(buf), 0);
        if(len <= 0)
            break;
        send_len = send(serv_sock, buf, len, 0);
        if(send_len == -1)
            error_handling("send() error");
        printf("Received data: %s \n", buf);
    }

    close(clnt_sock);
    close(serv_sock);
    return 0;
}

void error_handling(char * message){
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}