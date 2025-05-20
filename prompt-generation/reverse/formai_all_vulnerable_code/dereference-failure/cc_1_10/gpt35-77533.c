//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUF_SIZE 1024

void receive(int sockfd, char *buffer) 
{
    int numBytes = read(sockfd, buffer, BUF_SIZE-1);
    if(numBytes < 0) {
        perror("Error in reading from socket");
        exit(1);
    }
    buffer[numBytes] = '\0';
}

void sendCommand(int sockfd, char *buffer, char *command) 
{
    int numBytes = snprintf(buffer, BUF_SIZE-1, "%s\r\n", command);    
    if(write(sockfd, buffer, numBytes) < 0) {
        perror("Error in writing to socket");
        exit(1);
    }
    receive(sockfd, buffer);
}

int main(int argc, char **argv) 
{
    if(argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }
    int sockfd, portno;
    struct sockaddr_in serverAddr;
    struct hostent *server;

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }
    server = gethostbyname(argv[1]);
    if(server == NULL) {
        perror("Error, no such host");
        exit(1);
    }
    bzero((char *) &serverAddr, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serverAddr.sin_addr.s_addr, server->h_length);
    serverAddr.sin_port = htons(portno);
    if(connect(sockfd,(struct sockaddr *) &serverAddr,sizeof(serverAddr)) < 0) {
        perror("Error connecting to host");
        exit(1);
    }
    char buffer[BUF_SIZE];
    receive(sockfd, buffer);

    sendCommand(sockfd, buffer, "USER username"); // Replace with your username
    sendCommand(sockfd, buffer, "PASS password"); // Replace with your password

    sendCommand(sockfd, buffer, "STAT"); // Get total message count

    int messageCount;
    sscanf(buffer, "+OK %d", &messageCount);

    for(int i=1; i<=messageCount; i++) {
        sendCommand(sockfd, buffer, "RETR "+i); // Get each message
        printf("------------------ MESSAGE %d ------------------\n", i);
        printf("%s\n", buffer); // Print message
    }

    sendCommand(sockfd, buffer, "QUIT"); // Close connection
    printf("\nAll done!");

    return 0;
}