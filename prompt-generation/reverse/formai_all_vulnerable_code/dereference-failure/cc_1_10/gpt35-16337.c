//FormAI DATASET v1.0 Category: Networking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    
    // check for correct usage
    if (argc != 3) {
        printf("Usage: %s <ip address> <port number>\n", argv[0]);
        return 1;
    }
    
    // create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        return 1;
    }
    
    // set up socket address
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("Invalid IP address");
        return 1;
    }
    
    // connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) == -1) {
        perror("Failed to connect to server");
        return 1;
    }
    
    printf("Connection established!\n");
    
    // message loop
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        printf("Enter a message to send: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        
        // check for exit command
        if (strncmp(buffer, "exit", 4) == 0) {
            printf("Closing connection...\n");
            break;
        }
        
        // send message to server
        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("Failed to send message");
            return 1;
        }
        
        // receive message from server
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            perror("Failed to receive message");
            return 1;
        }
        
        printf("Received message: %s", buffer);
    }
    
    // close sockets
    close(sockfd);
    
    return 0;
}