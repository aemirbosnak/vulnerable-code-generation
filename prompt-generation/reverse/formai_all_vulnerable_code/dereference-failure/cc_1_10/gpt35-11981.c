//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    // Check if user provided URL and Port
    if(argc != 3){
        printf("Usage: %s <URL> <Port>\n", argv[0]);
        exit(1);
    }

    char* host = argv[1];   // Website URL
    int port = atoi(argv[2]);   // Proxy port
    
    // To create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }
    
    // Provide Proxy server details
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    // Bind socket to address and port
    int bindResult = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(bindResult < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Wait for Client request
    if (listen(sockfd, 10) < 0) {
        perror("Error listening");
        exit(1);
    }

    int clientSockfd;   // Socket for Client connection
    struct sockaddr_in clientAddr;
    unsigned int len = sizeof(clientAddr);

    printf("Proxy server started on port %d ... \n", port);

    while(1) {
        // Accept Client Connection request
        clientSockfd = accept(sockfd, (struct sockaddr *)&clientAddr, &len);

        // Read Client Request
        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);
        read(clientSockfd, buffer, BUFFER_SIZE);

        printf("Received message from Client: %s\n", buffer);

        // Connect to Web Server
        int webSockfd = socket(AF_INET, SOCK_STREAM, 0);
        struct hostent *server;
        server = gethostbyname(host);
        struct sockaddr_in webAddr;
        bzero((char *) &webAddr, sizeof(webAddr));
        webAddr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&webAddr.sin_addr.s_addr, server->h_length);
        webAddr.sin_port = htons(80);

        int connectResult = connect(webSockfd, (struct sockaddr *)&webAddr, sizeof(webAddr));
        if (connectResult < 0) {
            perror("Error connecting to web server");
            exit(1);
        }

        // Forward HTTP Request to Web Server
        write(webSockfd,buffer,strlen(buffer));
        bzero(buffer,BUFFER_SIZE);

        // Forward Web Server Response to Client
        while(read(webSockfd,buffer,BUFFER_SIZE)>0){
            write(clientSockfd, buffer, strlen(buffer));

            // Initialize buffer to 0s
            bzero(buffer,BUFFER_SIZE);
        }
        
        close(clientSockfd);
        close(webSockfd);
    }

    return 0;
}