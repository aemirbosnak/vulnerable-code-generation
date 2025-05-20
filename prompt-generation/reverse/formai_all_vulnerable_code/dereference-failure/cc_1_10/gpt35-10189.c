//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_MSG_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

//Function to start the proxy server
void startProxyServer(int portNumber) {
    
    int sockfd, newsockfd, clientLength, n;
    char buffer[MAX_MSG_SIZE];
    struct sockaddr_in serverAddress, clientAddress;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }
    
    bzero((char *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family      = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port        = htons(portNumber);
    
    if (bind(sockfd, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
        error("ERROR on binding");
    }
    
    listen(sockfd, 5);
    
    clientLength = sizeof(clientAddress);
    
    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *) &clientAddress, &clientLength);
        if (newsockfd < 0) {
            error("ERROR on accept");
        }
        
        bzero(buffer, MAX_MSG_SIZE);
        
        n = read(newsockfd, buffer, MAX_MSG_SIZE);
        if (n < 0) {
            error("ERROR reading from socket");
        }
        printf("Received message: %s\n", buffer);
        
        //Here we can modify the request as per our requirement
        //For example, we can modify the URL or headers
        
        //Connect to the remote server
        int remoteSockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (remoteSockfd < 0) {
            error("ERROR opening socket");
        }
        
        struct sockaddr_in remoteAddress;
        bzero((char *) &remoteAddress, sizeof(remoteAddress));
        remoteAddress.sin_family = AF_INET;
        remoteAddress.sin_addr.s_addr = inet_addr("192.168.1.100"); //Replace with the IP address of the remote server
        remoteAddress.sin_port = htons(80); //Replace with the port number of the remote server
        
        if (connect(remoteSockfd, (struct sockaddr *) &remoteAddress, sizeof(remoteAddress)) < 0) {
            error("ERROR connecting to remote server");
        }
        
        //Forward the modified request to the remote server
        n = write(remoteSockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to remote server");
        }
        printf("Sent message to remote server: %s\n", buffer);
        
        //Read the response from remote server
        bzero(buffer, MAX_MSG_SIZE);
        n = read(remoteSockfd, buffer, MAX_MSG_SIZE);
        if (n < 0) {
            error("ERROR reading from remote server");
        }
        printf("Received message from remote server: %s\n", buffer);
        
        //Forward the response to the client
        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to client");
        }
        close(newsockfd);
        close(remoteSockfd);
    }
}

int main(int argc, char *argv[]) {
    int portNumber = atoi(argv[1]);
    startProxyServer(portNumber);
    return 0;
}