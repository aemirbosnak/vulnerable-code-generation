//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int servSock, cliSock, maxSock, optval = 1;
    struct sockaddr_in servAddr, cliAddr;
    socklen_t cliLen = sizeof(cliAddr);
    fd_set fds;
    char buffer[BUFSIZE];
    
    // Check for proper command line args
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    
    // Create socket for incoming connections
    if ((servSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        error("ERROR opening socket");
    }
    
    // setsockopt: Reuse the port if it's still in TIME_WAIT
    setsockopt(servSock, SOL_SOCKET, SO_REUSEADDR, (const void *)&optval, sizeof(int));
    
    // Construct local address structure
    memset(&servAddr, 0, sizeof(servAddr));
    servAddr.sin_family = AF_INET;            // Internet address family
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); // Any incoming interface
    servAddr.sin_port = htons(atoi(argv[1]));    // Local port
    
    // Bind to the local address
    if (bind(servSock, (struct sockaddr *)&servAddr, sizeof(servAddr)) < 0) {
        error("ERROR on binding");
    }
    
    // Mark the socket so it will listen for incoming connections
    if (listen(servSock, 5) < 0) {
        error("ERROR on listen");
    }
    
    cliSock = accept(servSock, (struct sockaddr *)&cliAddr, &cliLen);
    
    // Check for successful connection with client
    if (cliSock < 0) {
        error("ERROR on accept");
    }
    
    // Set the maximum file descriptor number for select
    maxSock = cliSock + 1;
    
    // Loop indefinitely
    while (1) {
        // Zero out the buffer to receive incoming data
        memset(buffer, 0, BUFSIZE);
        
        // Set up the file descriptor set
        FD_ZERO(&fds);
        FD_SET(cliSock, &fds);
        
        // Wait for incoming data
        if (select(maxSock, &fds, NULL, NULL, NULL) < 0) {
            error("ERROR in select");
        }
        
        // Check for incoming data on the client socket
        if (FD_ISSET(cliSock, &fds)) {
            if (recv(cliSock, buffer, BUFSIZE, 0) < 0) {
                error("ERROR in recv");
            }
            
            // Log incoming request
            printf("Received HTTP request:\n%s\n", buffer);
            
            // Do whatever you want with the request here
            // For example, you can modify it or forward it to another server
            
            // For this example, we'll just echo it back to the client
            if (send(cliSock, buffer, strlen(buffer), 0) < 0) {
                error("ERROR in send");
            }
        }
    }
    
    // Close the client socket
    close(cliSock);
    
    // Close the server socket
    close(servSock);
    
    return 0;
}