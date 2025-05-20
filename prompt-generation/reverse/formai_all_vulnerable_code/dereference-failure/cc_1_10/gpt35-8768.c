//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define READ_BUFFER_SIZE 1024

// Function to display error messages
void error(const char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    char read_buffer[READ_BUFFER_SIZE];
    char user_input[100];
    struct sockaddr_in serv_addr;
    
    // Check for proper number of arguments (IP address and port number)
    if(argc < 3) {
        printf("Please provide IP address and port number!\n");
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        error("Error creating socket!\n");
    }
    
    // Set server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    
    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0) {
        error("Error: Invalid address!\n");
    }
    
    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server!\n");
    }
    
    // Receive connection acknowledgement from server
    n = read(sockfd, read_buffer, READ_BUFFER_SIZE - 1);
    if(n < 0) {
        error("Error reading server response!\n");
    }
    
    printf("%s\n", read_buffer);
    
    // Loop to process user input
    while(1) {
        bzero(user_input, sizeof(user_input));
        printf("Enter command: ");
        fgets(user_input, sizeof(user_input), stdin);
        
        // Send user input to server
        n = write(sockfd, user_input, strlen(user_input));
        if(n < 0) {
            error("Error writing to server!\n");
        }
        
        bzero(read_buffer, sizeof(read_buffer));
        n = read(sockfd, read_buffer, READ_BUFFER_SIZE - 1);
        if(n < 0) {
            error("Error reading server response!\n");
        }
        
        printf("%s\n", read_buffer);
        
        // Check for quit command
        if(strncmp(user_input, "quit", 4) == 0) {
            break;
        }
    }
    
    // Close socket
    close(sockfd);
    
    return 0;
}