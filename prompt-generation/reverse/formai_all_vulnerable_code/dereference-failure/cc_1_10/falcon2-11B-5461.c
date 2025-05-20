//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: single-threaded
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return 1;
    }
    
    // Initialize the address structure
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(25); // SMTP port
    serverAddr.sin_addr.s_addr = inet_addr("localhost"); // Replace with the IP address of the SMTP server
    
    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }
    
    // Send HELO command
    char command[] = "HELO ";
    strncat(command, "myclient.com", sizeof(command));
    if (send(sockfd, command, strlen(command), 0) < 0) {
        perror("Error sending HELO command");
        return 1;
    }
    
    // Send MAIL FROM command
    char command2[] = "MAIL FROM: <user@example.com>\r\n";
    if (send(sockfd, command2, strlen(command2), 0) < 0) {
        perror("Error sending MAIL FROM command");
        return 1;
    }
    
    // Send RCPT TO command
    char command3[] = "RCPT TO: <recipient@example.com>\r\n";
    if (send(sockfd, command3, strlen(command3), 0) < 0) {
        perror("Error sending RCPT TO command");
        return 1;
    }
    
    // Send DATA command
    char command4[] = "DATA\r\n";
    if (send(sockfd, command4, strlen(command4), 0) < 0) {
        perror("Error sending DATA command");
        return 1;
    }
    
    // Send message content
    char message[] = "Subject: Test Message\r\n"
                     "Hello, this is a test message.\r\n"
                     "--\r\n";
    if (send(sockfd, message, strlen(message), 0) < 0) {
        perror("Error sending message content");
        return 1;
    }
    
    // Send QUIT command
    char command5[] = "QUIT\r\n";
    if (send(sockfd, command5, strlen(command5), 0) < 0) {
        perror("Error sending QUIT command");
        return 1;
    }
    
    // Close the socket
    close(sockfd);
    return 0;
}