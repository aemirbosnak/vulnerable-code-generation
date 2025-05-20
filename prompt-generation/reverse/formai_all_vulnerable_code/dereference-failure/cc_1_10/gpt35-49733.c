//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 80
#define TIMEOUT 10

void check_website(char *url);

int main(int argc, char **argv){
    if(argc !=2){
        printf("Usage: %s <url>\n",argv[0]);
        exit(1);
    }
    check_website(argv[1]);
    return 0;
}

void check_website(char *url){
    struct sockaddr_in server;
    struct hostent *host;
    int sock,status;
    fd_set fds;
    struct timeval timeout;
    char message[1024];

    host=gethostbyname(url);
    if(host==NULL){
        printf("Unknown host: %s\n",url);
        exit(1);
    }

    sock=socket(AF_INET,SOCK_STREAM,0);
    if(sock<0){
        printf("Error creating socket\n");
        exit(1);
    }

    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr=*((struct in_addr*)host->h_addr);
    memset(&(server.sin_zero),'\0',8);

    if(connect(sock,(struct sockaddr*)&server,sizeof(server))<0){
        printf("Could not connect to server\n");
        exit(1);
    }

    sprintf(message,"HEAD / HTTP/1.1\r\nHost: %s\r\n\r\n",url);
    status=send(sock,message,strlen(message),0);
    if(status<0){
        printf("Error sending request to server\n");
        exit(1);
    }

    FD_ZERO(&fds);
    FD_SET(sock,&fds);

    timeout.tv_sec=TIMEOUT;
    timeout.tv_usec=0;

    status=select(sock+1,&fds,NULL,NULL,&timeout);
    if(status==0){
        printf("Timeout while waiting for response\n");
        exit(1);
    }
    else if(status<0){
        printf("Error in select system call\n");
        exit(1);
    }

    memset(message,0,sizeof(message));
    status=recv(sock,message,sizeof(message)-1,0);
    if(status<0){
        printf("Error receiving response from server\n");
        exit(1);
    }

    printf("%s is up and running!\n",url);
    close(sock);
}