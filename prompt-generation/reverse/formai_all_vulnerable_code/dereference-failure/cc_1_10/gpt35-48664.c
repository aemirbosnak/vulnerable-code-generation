//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

#define BUF_SIZE 512

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[BUF_SIZE];
    struct sockaddr_in servAddr;
    int servPort;
    char *servIP;
    char *username;

    // Checking command line arguments
    if (argc != 4) {
        printf("Correct usage: %s <Server IP> <Server Port> <username>\n", argv[0]);
        exit(1);
    }
    
    servIP = argv[1];
    servPort = atoi(argv[2]);
    username = argv[3];

    // Creating TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        exit(1);
    }

    // Setting up server address
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;
    servAddr.sin_addr.s_addr = inet_addr(servIP);
    servAddr.sin_port = htons(servPort);
  
    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
        printf("Error: Could not connect to server\n");
        close(sockfd);
        exit(1);
    }

    // Sending initial message to server
    sprintf(buffer, "Hello, server! This is %s", username);
    write(sockfd, buffer, strlen(buffer));

    // Receiving response from server
    memset(buffer, 0, BUF_SIZE);
    read(sockfd, buffer, BUF_SIZE - 1);
    printf("Server says: %s\n", buffer);

    // Closing the socket
    close(sockfd);

    return 0;
}