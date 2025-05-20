//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUF_SIZE 1024

void displayErr(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char** argv) {
    
    if (argc < 3) {
        printf("Usage: ftp_client <IP address> <port number>\n");
        exit(1);
    }

    char* serverIP = argv[1];
    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) displayErr("Error creating socket.\n");

    struct sockaddr_in serverAddr;
    bzero(&serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(serverIP);
    serverAddr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) 
        displayErr("Error connecting to server.\n");

    char buf[BUF_SIZE];
    bzero(buf, BUF_SIZE);

    recv(sockfd, buf, BUF_SIZE, 0);
    printf("%s", buf);

    while(1) {
        bzero(buf, BUF_SIZE);
        fgets(buf, BUF_SIZE, stdin);

        if (strcmp("quit\n", buf) == 0) 
            break;

        if (send(sockfd, buf, strlen(buf), 0) < 0) 
            displayErr("Error sending data.\n");

        bzero(buf, BUF_SIZE);
        recv(sockfd, buf, BUF_SIZE, 0);

        printf("%s", buf);
    }

    close(sockfd);
    return 0;
}