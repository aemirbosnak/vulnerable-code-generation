//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFSIZE 1024

void error(char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if(argc != 3){
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        error("ERROR: cannot create socket");
    }

    // Set up server address
    struct sockaddr_in serv_addr;
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr(hostname);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR: cannot connect to server");
    }
    printf("Connected to server\n");

    // Get client greeting
    char recv_buff[BUFFSIZE] = {0};
    if(recv(sockfd, recv_buff, BUFFSIZE, 0) < 0){
        error("ERROR: cannot receive client greeting");
    }
    printf("Client greeting: %s\n", recv_buff);

    // Send login command
    char user_cmd[BUFFSIZE] = {0};
    sprintf(user_cmd, "a001 LOGIN username password\n");
    if(send(sockfd, user_cmd, strlen(user_cmd), 0) < 0){
        error("ERROR: cannot login to server");
    }

    // Get server response to login
    char auth_buff[BUFFSIZE] = {0};
    if(recv(sockfd, auth_buff, BUFFSIZE, 0) < 0){
        error("ERROR: cannot receive login response");
    }
    printf("Server response: %s\n", auth_buff);

    // Send select inbox command
    char select_cmd[BUFFSIZE] = {0};
    sprintf(select_cmd, "a002 SELECT INBOX\n");
    if(send(sockfd, select_cmd, strlen(select_cmd), 0) < 0){
        error("ERROR: cannot select INBOX");
    }

    // Get server response to select inbox
    char select_buff[BUFFSIZE] = {0};
    if(recv(sockfd, select_buff, BUFFSIZE, 0) < 0){
        error("ERROR: cannot receive select response");
    }
    printf("Server response: %s\n", select_buff);

    // Send logout command
    char logout_cmd[BUFFSIZE] = {0};
    sprintf(logout_cmd, "a003 LOGOUT\n");
    if(send(sockfd, logout_cmd, strlen(logout_cmd), 0) < 0){
        error("ERROR: cannot logout from server");
    }

    // Get server response to logout
    char logout_buff[BUFFSIZE] = {0};
    if(recv(sockfd, logout_buff, BUFFSIZE, 0) < 0){
        error("ERROR: cannot receive logout response");
    }
    printf("Server response: %s\n", logout_buff);

    // Close socket
    close(sockfd);

    return 0;
}