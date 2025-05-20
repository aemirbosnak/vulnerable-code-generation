//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUF_SIZE 1024

/* Function to connect to the IMAP server */
int connectToServer(char* serverName, int portNum) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a new socket for TCP connection
    
    if(sockfd < 0) {
        perror("Error opening socket!");
        exit(1);
    }
    
    server = gethostbyname(serverName); // Get the IP address for the given hostname
    
    if(!(server)) {
        perror("Error getting server address!");
        exit(1);
    }
    
    bzero((char *) &serv_addr, sizeof(serv_addr)); // Initialize all bytes to zero in server address
    
    serv_addr.sin_family = AF_INET; // Set address family to IPv4
    
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length); // Copy the server's IP address
    
    serv_addr.sin_port = htons(portNum); // Set the port number
    
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) { // Connect to the server
        perror("Error connecting to server!");
        exit(1);
    }
    
    return sockfd;
}

/* Function to send a message to the server */
void sendMessage(int sockfd, char* message) {
    if(write(sockfd, message, strlen(message)) < 0) { // Write the message to the socket
        perror("Error writing to socket!");
        exit(1);
    }
}

/* Function to read a response from the server */
char* readMessage(int sockfd) {
    char* buffer = malloc(sizeof(char) * BUF_SIZE);
    bzero(buffer, BUF_SIZE);
    
    if(read(sockfd, buffer, BUF_SIZE) < 0) { // Read the response from the socket
        perror("Error reading from socket!");
        exit(1);
    }
    
    return buffer;
}

/* The main function */
int main(int argc, char** argv) {
    int sockfd;
    char* serverName = "imap.google.com";
    int portNum = 993;
    
    sockfd = connectToServer(serverName, portNum); // Connect to the server
    
    char* message = "a001 LOGIN user@example.com password\r\n";
    sendMessage(sockfd, message); // Send the login message
    
    char* response = readMessage(sockfd); // Read the response
    printf("%s", response); // Display the response
    
    free(response); // Free the dynamically allocated memory
    
    close(sockfd); // Close the socket
    
    return 0;
}