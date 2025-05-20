//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>

#define BUFF_SIZE 1024

void error_handler(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port_number>\n", argv[0]);
        exit(1);
    }
    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock < 0) {
        error_handler("Error creating socket");
    }
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));
    if(connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error_handler("Error connecting to server");
    }
    char receiveBuffer[BUFF_SIZE+1];
    memset(receiveBuffer, 0, sizeof(receiveBuffer));  
    if(recv(sock, receiveBuffer, BUFF_SIZE, 0) < 0) {
        error_handler("Error receiving message from server");
    }
    printf("%s", receiveBuffer);
    char sendBuffer[BUFF_SIZE+1];
    memset(sendBuffer, 0, sizeof(sendBuffer));  
    sprintf(sendBuffer, "01 LOGIN myuser mypasswd\r\n");   
    if(send(sock, sendBuffer, strlen(sendBuffer), 0) < 0) {
        error_handler("Error sending message to server");
    }
    memset(receiveBuffer, 0, sizeof(receiveBuffer));  
    if(recv(sock, receiveBuffer, BUFF_SIZE, 0) < 0) {
        error_handler("Error receiving message from server");
    }
    printf("%s", receiveBuffer);
    memset(sendBuffer, 0, sizeof(sendBuffer));  
    sprintf(sendBuffer, "02 LIST \"\" *\r\n");   
    if(send(sock, sendBuffer, strlen(sendBuffer), 0) < 0) {
        error_handler("Error sending message to server");
    }
    memset(receiveBuffer, 0, sizeof(receiveBuffer));  
    if(recv(sock, receiveBuffer, BUFF_SIZE, 0) < 0) {
        error_handler("Error receiving message from server");
    }
    printf("%s", receiveBuffer);
    memset(sendBuffer, 0, sizeof(sendBuffer));  
    sprintf(sendBuffer, "03 LOGOUT\r\n");   
    if(send(sock, sendBuffer, strlen(sendBuffer), 0) < 0) {
        error_handler("Error sending message to server");
    }
    memset(receiveBuffer, 0, sizeof(receiveBuffer));  
    if(recv(sock, receiveBuffer, BUFF_SIZE, 0) < 0) {
        error_handler("Error receiving message from server");
    }
    printf("%s", receiveBuffer);
    close(sock);
    return 0;
}