//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/mman.h>

#define MAP_SIZE (1024*1024*10) //10 MB
#define PAGE_SIZE getpagesize()

//Function to read the file into memory mapped region
void read_file(int fd,void* addr,size_t count){
    ssize_t nread;
    char* buffer=(char*)addr;
    while(count>0){
        nread=read(fd,buffer,count);
        if(nread==-1){
            perror("read");
            exit(1);
        }
        buffer+=nread;
        count-=nread;
    }
}

//Function to write the changes back to file
void write_file(int fd,void* addr,size_t count){
    ssize_t nwritten;
    char* buffer=(char*)addr;
    while(count>0){
        nwritten=write(fd,buffer,count);
        if(nwritten==-1){
            perror("write");
            exit(1);
        }
        buffer+=nwritten;
        count-=nwritten;
    }
}

int main(int argc,char** argv){
    int fd;
    char* filename;
    void* addr;
    struct stat statbuf;
    if(argc!=3){
        printf("Usage: %s <filename> <offset>\n",argv[0]);
        exit(1);
    }
    filename=argv[1];
    off_t offset=atoi(argv[2]);

    //Open the file
    fd=open(filename,O_RDWR);
    if(fd==-1){
        perror("open");
        exit(1);
    }

    //Get file size
    if(fstat(fd,&statbuf)==-1){
        perror("fstat");
        exit(1);
    }

    //Map the file into memory
    addr=mmap(NULL,statbuf.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(addr==MAP_FAILED){
        perror("mmap");
        exit(1);
    }

    //Seek to the specified offset
    if(lseek(fd,offset,SEEK_SET)==-1){
        perror("lseek");
        exit(1);
    }

    //Read the file into memory mapped region
    read_file(fd,addr,statbuf.st_size);

    //Make changes to the file
    char* buffer=(char*)addr;
    int i;
    for(i=0;i<statbuf.st_size;i++){
        if(buffer[i]=='a')
            buffer[i]='b';
    }

    //Write the changes back to file
    write_file(fd,addr,statbuf.st_size);

    //Unmap the file from memory
    if(munmap(addr,statbuf.st_size)==-1){
        perror("munmap");
        exit(1);
    }

    //Close the file
    if(close(fd)==-1){
        perror("close");
        exit(1);
    }
    return 0;
}