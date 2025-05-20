//FormAI DATASET v1.0 Category: Simple Web Server ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>

#define ERR_EXIT(m)         \
    do{                     \
        perror(m);          \
        exit(EXIT_FAILURE); \
    }while(0)

#define LISTENQ             1024
#define MAX_LINE            1024
#define MAX_FILE_SIZE       1024

void serve(int sockfd){
    int fd;
    ssize_t n;
    char buf[MAX_LINE];
    char filename[MAX_LINE];
    struct stat file_info;

    for(;;){
        if((n=read(sockfd,buf,MAX_LINE))==0)
            return;
        
        if(sscanf(buf,"GET %s",filename)!=1)
        {
            printf("Invalid input format: %s",buf);
            continue;
        }

        if((fd=open(filename+1,O_RDONLY))==-1)
        {
            printf("Can't open %s\n",filename+1);
            continue;
        }

        stat(filename+1,&file_info);
        snprintf(buf,sizeof(buf),"HTTP/1.0 200 OK\r\n"
                                  "Content-type: text/html\r\n"
                                  "Content-length: %ld\r\n\r\n", file_info.st_size);
        write(sockfd,buf,strlen(buf));

        while((n=read(fd,buf,MAX_FILE_SIZE))>0)
            write(sockfd,buf,n);

        close(fd);
    }
}

int main(int argc, char *argv[]){
    int listenfd,connfd;
    struct sockaddr_in servaddr;

    if(argc!=2)
    {
        printf("Missing argument: <Port>\n");
        exit(EXIT_FAILURE);
    }

    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        ERR_EXIT("socket error");

    memset(&servaddr,0,sizeof(servaddr));
    servaddr.sin_family=AF_INET;
    servaddr.sin_port=htons(atoi(argv[1]));
    servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

    int optval=1;
    if(setsockopt(listenfd,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(optval))==-1)
        ERR_EXIT("setsockopt error");

    if (bind(listenfd, (struct sockaddr *)&servaddr,sizeof(servaddr)) < 0)
        ERR_EXIT("bind error");

    if (listen(listenfd, LISTENQ) < 0)
        ERR_EXIT("listen error");

    for(;;){
        if((connfd=accept(listenfd, (struct sockaddr *)NULL,NULL))==-1){
            if(errno==EINTR)
                continue;
            ERR_EXIT("accept error");
        }
        serve(connfd);
        close(connfd);
    }

    return 0;
}