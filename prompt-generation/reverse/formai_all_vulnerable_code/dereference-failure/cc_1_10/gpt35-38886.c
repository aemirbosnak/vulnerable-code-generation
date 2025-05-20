//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc,char**argv){

    if(argc!=2){
        printf("Usage: %s <url>\n",argv[0]);
        return 1;
    }

    char*url=argv[1];

    //Separate host and path
    char*host=strtok(url,"/");
    char*path=strtok(NULL,"");

    //Create socket
    int sockfd=socket(AF_INET,SOCK_STREAM,0);
    if(sockfd<0){
        perror("Could not create socket");
        return 1;
    }

    //Resolve host
    struct sockaddr_in server;
    server.sin_family=AF_INET;
    server.sin_addr.s_addr=inet_addr(host);
    server.sin_port=htons(80);

    if(connect(sockfd,(struct sockaddr*)&server,sizeof(server))<0){
        perror("Could not connect to server");
        return 1;
    }

    //Send request
    char*request=malloc(strlen(path)+strlen(host)+30);
    sprintf(request,"GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n",path,host);
    if(write(sockfd,request,strlen(request))<0){
        perror("Could not send request");
        return 1;
    }

    //Receive response
    char buffer[1024];
    int count;
    int total=0;
    while((count=read(sockfd,buffer,sizeof(buffer)))>0){
        fwrite(buffer,count,1,stdout);
        total+=count;
    }
    if(count<0){
        perror("Could not receive response");
        return 1;
    }

    printf("\n\nTotal received: %d bytes\n",total);

    return 0;
}