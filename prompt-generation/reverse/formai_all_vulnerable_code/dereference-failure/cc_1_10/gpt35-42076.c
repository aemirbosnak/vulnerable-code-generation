//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<netdb.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv){
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[MAX_BUFFER_SIZE];
    
    // Check if input is correct
    if(argc != 3){
        printf("Usage: <hostname> <port>\n");
        exit(EXIT_FAILURE);
    }

    // Creating Socket for IMAP
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1){
        printf("Socket Creation Failed!\n");
        exit(EXIT_FAILURE);
    }
    
    // Clearing the Server Address Values
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));

    // Checking Host
    struct hostent *host = gethostbyname(argv[1]);

    if(host == NULL){
        printf("Invalid Hostname!\n");
        exit(EXIT_FAILURE);
    }
    
    // Copying Host Name into Server Address
    bcopy((char *)host->h_addr, (char *)&servaddr.sin_addr.s_addr, host->h_length);

    // Connecting to the Server using the created Socket
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0){
        printf("Connection Failed!\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Connected to IMAP Server Successfully!\n");

    // Receiving the Greeting Message from Server
    bzero(buffer, MAX_BUFFER_SIZE);
    n = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("Greeting message received from server: %s\n", buffer);

    // Closing the Socket Connection
    close(sockfd);
    return 0;
}