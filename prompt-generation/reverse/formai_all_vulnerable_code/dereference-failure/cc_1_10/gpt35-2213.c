//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define MAX_LEN 1024

int main(int argc, char** argv){
    if(argc != 4){
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        return 1;
    }
    int sockfd, n;
    char recvline[MAX_LEN + 1];
    struct sockaddr_in servaddr;
    char userInput[MAX_LEN + 1], buffer[MAX_LEN + 1];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0){
        perror("socket error");
        return 1;
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0){
        printf("inet_pton error for %s\n", argv[1]);
        return 1;
    }
    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
        perror("connect error");
        return 1;
    }
    // Wait for welcome message
    printf("Connected to server %s:%s\n", argv[1], argv[2]);
    bzero(recvline, MAX_LEN);
    n = recv(sockfd, recvline, MAX_LEN, 0);
    if(n < 0){
        perror("receive");
        return 1;
    }
    printf("%s\n", recvline);
    // Send username
    sprintf(buffer, "USER %s\r\n", argv[3]);
    write(sockfd, buffer, strlen(buffer));
    bzero(recvline, MAX_LEN);
    n = recv(sockfd, recvline, MAX_LEN, 0);
    if(n < 0){
        perror("receive");
        return 1;
    }
    printf("%s\n", recvline);
    // Send password
    printf("Enter password: ");
    fflush(stdout);
    fgets(userInput, MAX_LEN, stdin);
    sprintf(buffer, "PASS %s\r\n", userInput);
    write(sockfd, buffer, strlen(buffer));
    bzero(recvline, MAX_LEN);
    n = recv(sockfd, recvline, MAX_LEN, 0);
    if(n < 0){
        perror("receive");
        return 1;
    }
    printf("%s\n", recvline);
    // List messages
    write(sockfd, "LIST\r\n", 6);
    bzero(recvline, MAX_LEN);
    n = recv(sockfd, recvline, MAX_LEN, 0);
    if(n < 0){
        perror("receive");
        return 1;
    }
    printf("%s\n", recvline);
    // Logout
    write(sockfd, "QUIT\r\n", 6);
    bzero(recvline, MAX_LEN);
    n = recv(sockfd, recvline, MAX_LEN, 0);
    if(n < 0){
        perror("receive");
        return 1;
    }
    printf("%s\n", recvline);
    close(sockfd);
    return 0;
}