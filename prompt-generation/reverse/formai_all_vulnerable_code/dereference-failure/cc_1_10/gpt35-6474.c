//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

// Function to connect to a POP3 server
int connectToServer(const char* server, const int port) {
    struct sockaddr_in server_address;
    int sockfd;
    
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(server);
    server_address.sin_port = htons(port);
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error: Create socket failed! ");
        exit(1);
    }
    
    // Connect to server
    if(connect(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("Error: Connect to server failed! ");
        exit(1);
    }
    
    return sockfd;
}

// Function to receive message from server
void receiveMessage(int sockfd, char* buffer) {
    memset(buffer, 0, BUFFER_SIZE);
    if(read(sockfd, buffer, BUFFER_SIZE) < 0) {
        perror("Error: Receive message failed! ");
        exit(1);
    }
    printf("%s\n", buffer);
}

// Function to send message to server
void sendMessage(int sockfd, const char* message) {
    if(write(sockfd, message, strlen(message)) < 0) {
        perror("Error: Send message failed! ");
        exit(1);
    }
}

// Main function
int main(int argc, char* argv[]) {
    if(argc < 4) {
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        return 0;
    }
    
    int sockfd = connectToServer(argv[1], atoi(argv[2])); // Connect to server
    
    char buffer[BUFFER_SIZE];
    receiveMessage(sockfd, buffer); // Receive greeting message from server
    sendMessage(sockfd, "USER "); // Send username
    sendMessage(sockfd, argv[3]);
    sendMessage(sockfd, "\r\n");
    receiveMessage(sockfd, buffer); // Receive response from server
    if(strncmp(buffer, "+OK", 3) != 0) { // Check if authentication is successful
        printf("Authentication failed. Quitting...\n");
        close(sockfd);
        return 0;
    }
    
    sendMessage(sockfd, "PASS "); // Send password
    char password[BUFFER_SIZE];
    printf("Please enter your password: ");
    scanf("%[^\n]%*c", password);
    sendMessage(sockfd, password);
    sendMessage(sockfd, "\r\n");
    receiveMessage(sockfd, buffer); // Receive response from server
    if(strncmp(buffer, "+OK", 3) != 0) { // Check if authentication is successful
        printf("Authentication failed. Quitting...\n");
        close(sockfd);
        return 0;
    }
    
    sendMessage(sockfd, "STAT\r\n"); // Send STAT command to get number of emails
    receiveMessage(sockfd, buffer); // Receive response from server
    int numEmails = 0;
    sscanf(buffer, "+OK %d", &numEmails);
    printf("Total number of emails: %d\n", numEmails);
    
    sendMessage(sockfd, "RETR 1\r\n"); // Send RETR command to get the first email
    receiveMessage(sockfd, buffer); // Receive response from server
    if(strncmp(buffer, "+OK", 3) != 0) { // Check if RETR command is successful
        printf("Error: RETR command failed. Quitting...\n");
        close(sockfd);
        return 0;
    }
    
    printf("First email:\n");
    while(1) { // Keep receiving email content until the end
        receiveMessage(sockfd, buffer);
        if(strncmp(buffer, ".\r\n", 3) == 0) { // End of email content
            break;
        }
        printf("%s", buffer);
    }
    
    sendMessage(sockfd, "QUIT\r\n"); // Send QUIT command to quit
    receiveMessage(sockfd, buffer); // Receive response from server
    
    printf("All done. Bye!\n");
    close(sockfd);
    
    return 0;
}