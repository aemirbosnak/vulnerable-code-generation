//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define BUF_SIZE 100

int main(int argc, char* argv[]){
    
    if(argc!=3){
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int sock;
    struct sockaddr_in server_address;
    char message[BUF_SIZE], server_reply[BUF_SIZE];
    
    //create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock==-1){
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    puts("Socket Created");
    bzero(&server_address, sizeof(server_address));
    
    //fill in the details
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));
    
    if(connect(sock, (struct sockaddr*)&server_address, sizeof(server_address))<0){
        perror("connection failed");
        exit(EXIT_FAILURE);
    }
    
    puts("Connected\n");
    
    //keep communicating
    while(1){
        printf("Enter message: ");
        bzero(&message, sizeof(message));
        fgets(message, BUF_SIZE, stdin);
        
        //send the message
        if(send(sock, message, strlen(message), 0)<0){
            perror("send failed");
            exit(EXIT_FAILURE);
        }
        
        //receive a reply
        if(recv(sock, server_reply, BUF_SIZE, 0)<0){
            perror("recv failed");
            break;
        }
        
        printf("Server Reply: %s\n", server_reply);
        
        if(strncmp(server_reply, "quit", 4)==0){
            break;
        }
    }
    
    close(sock);
    return 0;
}