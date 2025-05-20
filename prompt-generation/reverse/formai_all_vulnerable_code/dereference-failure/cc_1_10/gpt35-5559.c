//FormAI DATASET v1.0 Category: Socket programming ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    // Host information
    struct hostent *host;
    
    // Server information
    struct sockaddr_in server;
    
    // Socket file descriptor
    int sockfd;
    
    // Port number for the server
    int port = 6789;
    
    // Buffer to hold messages from client
    char buffer[1024];
    
    // Check if the user entered a hostname as an argument
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }
    
    // Get the host information using the hostname
    if ((host = gethostbyname(argv[1])) == NULL) {
        printf("Error: Host not found.\n");
        exit(1);
    }
    
    // Create the socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }
    
    // Configure the server address
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr = *((struct in_addr *) host->h_addr);
    memset(&(server.sin_zero), 0, 8);
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server, sizeof(struct sockaddr)) == -1) {
        printf("Error: Could not connect to server.\n");
        exit(1);
    }
    
    // Receive message from server
    if (recv(sockfd, buffer, 1024, 0) == -1) {
        printf("Error: Could not receive message from server.\n");
        exit(1);
    }
    
    // Print the received message
    printf("Message from server: %s\n", buffer);
    
    // Close the socket
    close(sockfd);
    
    return 0;
}