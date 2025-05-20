//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/types.h>
#include <netdb.h>

#define BUFFSIZE 2048

//remember to replace username with your email and host with your imap server
#define USERNAME "username"
#define HOST "imap.gmail.com"

//constants for commands
#define LOGIN "LOGIN"
#define SELECT "SELECT"
#define FETCH "FETCH"
#define BODY "BODY"

int main(int argc, char** argv){
    int sock;
    struct sockaddr_in serveraddr;
    struct hostent *hp;

    //create socket
    sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock<0){
        perror("socket");
        return -1;
    }

    //get server address
    hp=gethostbyname(HOST);
    if(hp==NULL){
        perror("gethostbyname");
        close(sock);
        return -1;
    }

    //set server address
    memset((void *)&serveraddr,0,sizeof(serveraddr));
    memcpy((void *)&serveraddr.sin_addr,(void *)hp->h_addr,hp->h_length);
    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(993);

    //connect to server
    if(connect(sock,(struct sockaddr *)&serveraddr,sizeof(serveraddr))<0){
        perror("connect");
        close(sock);
        return -1;
    }

    //read banner
    char buff[BUFFSIZE];
    memset(buff,0,BUFFSIZE);
    int n=read(sock,buff,BUFFSIZE);
    printf("Banner: %s",buff);

    //login
    memset(buff,0,BUFFSIZE);
    sprintf(buff,"%s %s\r\n",LOGIN,USERNAME);
    write(sock,buff,strlen(buff));
    n=read(sock,buff,BUFFSIZE);
    printf("Login: %s",buff);

    //select inbox
    memset(buff,0,BUFFSIZE);
    sprintf(buff,"%s INBOX\r\n",SELECT);
    write(sock,buff,strlen(buff));
    n=read(sock,buff,BUFFSIZE);
    printf("Select: %s",buff);

    //fetch first email body
    memset(buff,0,BUFFSIZE);
    sprintf(buff,"%s 1 (BODY[1.TEXT])\r\n",FETCH);
    write(sock,buff,strlen(buff));
    n=read(sock,buff,BUFFSIZE);
    printf("Fetch: %s",buff);

    //close connection
    close(sock);

    return 0;
}