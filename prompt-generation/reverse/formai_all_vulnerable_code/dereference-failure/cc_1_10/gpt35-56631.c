//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: decentralized
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 25

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Please provide the email recipient.\n");
        return 1;
    }

    struct hostent *server;
    struct sockaddr_in serv_addr;
    
    char buffer[256];
    
    // Create a TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket.\n");
        return 1;
    }
    
    // Get domain name (MX record) from recipient address
    char *recipient = argv[1];
    char recipient_domain[256];
    strcpy(recipient_domain, strstr(recipient, "@") + 1);
    server = gethostbyname(recipient_domain);
    if (server == NULL) {
        printf("Error finding domain name.\n");
        return 1;
    }
    
    // Connect to SMTP server
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr = *((struct in_addr*) server->h_addr);
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to SMTP server.\n");
        return 1;
    }
    
    // Receive greeting message from SMTP server
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    
    // Send HELO message
    sprintf(buffer, "HELO %s\r\n", recipient_domain);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    
    // Send MAIL FROM message
    sprintf(buffer, "MAIL FROM:<%s>\r\n", "sender@example.com");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    
    // Send RCPT TO message
    sprintf(buffer, "RCPT TO:<%s>\r\n", recipient);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    
    // Send DATA message
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    
    // Send email body
    sprintf(buffer, "From: sender_name <%s>\nTo: <%s>\nSubject: Test email\n\nThis is a test email.\n.\r\n", "sender@example.com", recipient);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    
    // Send QUIT message
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s\n", buffer);
    
    // Close socket
    close(sockfd);
    
    return 0;
}