//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include<stdio.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>

#define BUF_SIZE 1024

void error_handling(char* msg);

int main(int argc, char* argv[]){
    int sock;
    struct sockaddr_in serv_addr;
    char buf[BUF_SIZE];
    int str_len, resp_len = -1;
    int first_resp = 1;
    char* user = "USERNAME";
    char* pass = "PASSWORD";
    
    if(argc != 3){
        printf("Usage: %s <IP> <port> \n", argv[0]);
        exit(1);
    }
    
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1){
        error_handling("socket() error");
    }
    
    memset(&serv_addr, 0 ,sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));
    
    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr))==-1){
        error_handling("connect() error");
    }
    
    str_len = read(sock, buf, BUF_SIZE-1);
    if(str_len == -1){
        error_handling("read() error");
    }
    
    buf[str_len] = 0;
    printf("%s\n", buf);
    memset(buf, 0, BUF_SIZE);
    
    while(1){
        if(first_resp){
            sprintf(buf, "USER %s\n", user);
        } else {
            sprintf(buf, "PASS %s\n", pass);
        }
        
        write(sock, buf, strlen(buf));
        memset(buf, 0, BUF_SIZE);
        str_len = read(sock, buf, BUF_SIZE-1);
        if(str_len == -1){
            error_handling("read() error");
        }
        
        buf[str_len] = 0;
        printf("%s\n", buf);
        memset(buf, 0, BUF_SIZE);
        
        if(first_resp){
            first_resp = 0;
        } else {
            if(resp_len != strlen(buf)){
                resp_len = strlen(buf);
                printf("You have %d new emails\n", resp_len);
            }
        }
        
        sleep(5);
    }
    
    close(sock);
    return 0;
}

void error_handling(char* msg){
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}