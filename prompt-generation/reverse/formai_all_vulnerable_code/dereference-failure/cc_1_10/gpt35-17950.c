//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <ctype.h>

#define MAXSIZE 1024 

void error(char *msg) 
{ 
    perror(msg); 
    exit(1); 
} 

int main(int argc, char *argv[]) 
{ 
    int sockfd, portno, n; 
    struct sockaddr_in serv_addr; 
    char buffer[MAXSIZE]; 

    if (argc < 3) { 
        fprintf(stderr,"usage %s hostname port\n", argv[0]); 
        exit(1); 
    } 

    portno = atoi(argv[2]); 

    sockfd = socket(AF_INET, SOCK_STREAM, 0); 

    if (sockfd < 0) 
        error("ERROR opening socket"); 

    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(portno); 
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]); 

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting"); 

    printf("Connected to the server!\n"); 
    
    //RECEIVING WELCOME MESSAGE FROM THE SERVER 
    char welcome_message[MAXSIZE];
    bzero(welcome_message,sizeof(welcome_message));
    n = read(sockfd,welcome_message,sizeof(welcome_message));
    if(n<0)
        error("ERROR reading from server");
    printf("%s\n",welcome_message);
    
    while(1){
        printf("ftp-client> ");
        bzero(buffer,MAXSIZE); 
        fgets(buffer,MAXSIZE,stdin);
        
        //REMOVING TRAILING NEWLINE CHARACTER
        buffer[strcspn(buffer,"\n")] = 0;
        
        //COMMAND PROCESSING
        if(strncmp(buffer,"quit",4)==0)
            break;
        else if(strncmp(buffer,"get ",4)==0){
            char filename[MAXSIZE];
            bzero(filename,sizeof(filename));
            sscanf(buffer+4,"%s",filename);
            char file_request[MAXSIZE];
            sprintf(file_request,"RETR %s",filename);
            write(sockfd,file_request,strlen(file_request));
            
            //RECEIVING FILE STATUS FROM THE SERVER
            char file_status[MAXSIZE];
            bzero(file_status,sizeof(file_status));
            n = read(sockfd,file_status,sizeof(file_status));
            if(n<0)
                error("ERROR reading from server");
            printf("%s",file_status);
            
            if(strncmp(file_status,"550",3)==0)
                continue;
            
            FILE *fp = fopen(filename,"wb");
            
            //RECEIVING FILE DATA
            bzero(buffer,MAXSIZE); 
            int bytesRecv = 0;
            while((bytesRecv = read(sockfd,buffer,MAXSIZE)) > 0){
                fwrite(buffer,sizeof(char),bytesRecv,fp);
                if(bytesRecv<MAXSIZE)
                    break;
                bzero(buffer,MAXSIZE); 
            }
            printf("File received successfully!\n");
            fclose(fp);
        }
        else{
            printf("Invalid command!\n");
        }

    }
    
    printf("Quitting...\n");
    close(sockfd); 
    return 0; 

}