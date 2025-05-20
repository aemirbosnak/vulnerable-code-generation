//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Function to print error message and exit program
void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // Check command line arguments
    if (argc < 3) {
        fprintf(stderr,"usage %s hostname port\n", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");

    // Set server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");

    // Loop to send/receive data
    while(1) {
        printf("Please enter message: ");
        bzero(buffer,BUFFER_SIZE);
        fgets(buffer,BUFFER_SIZE-1,stdin);
        n = write(sockfd,buffer,strlen(buffer));
        if (n < 0) 
            error("ERROR writing to socket");

        bzero(buffer,BUFFER_SIZE);
        n = read(sockfd,buffer,BUFFER_SIZE-1);
        if (n < 0) 
            error("ERROR reading from socket");

        printf("Server: %s",buffer);
    }

    // Close socket and exit program
    close(sockfd);
    return 0;
}