//FormAI DATASET v1.0 Category: Socket programming ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>

#define MAXBUFLEN 1024 // Maximum buffer length

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in serv_addr;
    char buf[MAXBUFLEN];
    
    // Creating Socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    if(sockfd == -1) {
        printf("Socket Creation Failed\n");
        exit(1);
    }
    else {
        printf("Socket Created Successfully!\n");
    }
    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    serv_addr.sin_port = htons(8000);
    
    // Connect to the server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Connection Failed. Error : %s\n", strerror(errno));
        exit(1);
    }
    else {
        printf("Connected to the server successfully!\n");
    }
    
    // Receive data from server
    int num_bytes = recv(sockfd, buf, MAXBUFLEN, 0);
    
    if(num_bytes < 0) {
        printf("Error receiving data\n");
        exit(1);
    }
    else {
        printf("Received Data: %s\n", buf);
    }
    
    // Close socket
    close(sockfd);
    return 0;
}