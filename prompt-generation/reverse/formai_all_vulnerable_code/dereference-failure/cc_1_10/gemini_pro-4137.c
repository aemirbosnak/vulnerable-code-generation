//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>

#define MSIZE 1024

int main(int c,char**v)
{
    int fd,fd1,t,n;
    char ch,buf[MSIZE];
    if(c!=4)
    {
        fprintf(stderr,"Usage:%s source destination mode\n",v[0]);
        exit(EXIT_FAILURE);
    }
    if((fd=open(v[1],O_RDONLY))==-1)
    {
        perror("Cannot open source file");
        exit(EXIT_FAILURE);
    }
    if((fd1=open(v[2],O_WRONLY|O_CREAT|O_EXCL,0666))==-1)
    {
        perror("Cannot open destination file");
        exit(EXIT_FAILURE);
    }
    if(!strcmp(v[3],"e"))
    {
        while((n=read(fd,buf,MSIZE))>0)
        {
            t=0;
            while(t<n)
                t+=write(fd1,buf+t,n-t);
        }
    }
    else if(!strcmp(v[3],"d"))
    {
        while(ch=getchar())
        {
            write(fd1,&ch,1);
        }
    }
    close(fd);
    close(fd1);
    return 0;
}