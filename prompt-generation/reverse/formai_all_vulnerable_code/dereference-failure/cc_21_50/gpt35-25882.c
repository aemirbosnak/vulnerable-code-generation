//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: expert-level
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>

#define HOST "smtp.gmail.com" // SMTP server hostname
#define PORT 587 // SMTP port number
#define BUF_SIZE 1024 // Maximum size of buffer
#define MESSAGE_SIZE 200 // Maximum size of message

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUF_SIZE];
    char message[MESSAGE_SIZE];
    
    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return 1;
    }
    
    // Get the server's DNS entry
    server = gethostbyname(HOST);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        return 1;
    }
    
    // Set up the server address struct
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    
    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return 1;
    }
    
    // Receive greeting from server
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s\n", buffer);
    
    // Send EHLO command to server
    sprintf(message, "EHLO %s\r\n", HOST);
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    
    // Receive response from server
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s\n", buffer);
    
    // Send MAIL FROM command to server
    sprintf(message, "MAIL FROM:<sender@example.com>\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    
    // Receive response from server
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s\n", buffer);
    
    // Send RCPT TO command to server
    sprintf(message, "RCPT TO:<recipient@example.com>\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    
    // Receive response from server
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s\n", buffer);
    
    // Send DATA command to server
    sprintf(message, "DATA\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    
    // Receive response from server
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s\n", buffer);
    
    // Send message header
    sprintf(message, "Subject: SMTP Test\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    sprintf(message, "From: sender@example.com\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    sprintf(message, "To: recipient@example.com\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    sprintf(message, "\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    
    // Send message body
    sprintf(message, "This is a test message.\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    
    // Send end of message signal
    sprintf(message, "\r\n.\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    
    // Receive response from server
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s\n", buffer);
    
    // Send QUIT command to server
    sprintf(message, "QUIT\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        return 1;
    }
    
    // Receive response from server
    memset(buffer, 0, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE-1, 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        return 1;
    }
    printf("%s\n", buffer);
    
    // Close the socket
    close(sockfd);
    
    return 0;
}