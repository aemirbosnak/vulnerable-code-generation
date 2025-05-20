//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 25

int main() {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }
    
    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "smtp.example.com", &server_addr.sin_addr);
    
    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }
    
    // Send HELO command
    sprintf(buffer, "HELO client.example.com\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        printf("Error sending HELO command\n");
        exit(1);
    }
    
    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<sender@example.com>\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        printf("Error sending MAIL FROM command\n");
        exit(1);
    }
    
    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<recipient@example.com>\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        printf("Error sending RCPT TO command\n");
        exit(1);
    }
    
    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        printf("Error sending DATA command\n");
        exit(1);
    }
    
    // Send message body
    FILE *fp = fopen("message.txt", "r");
    char line[BUFFER_SIZE];
    while (fgets(line, BUFFER_SIZE, fp)!= NULL) {
        n = send(sockfd, line, strlen(line), 0);
        if (n == -1) {
            printf("Error sending message body\n");
            exit(1);
        }
    }
    fclose(fp);
    
    // Send end of data
    sprintf(buffer, ".\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n == -1) {
        printf("Error sending end of data\n");
        exit(1);
    }
    
    // Receive server response
    char response[BUFFER_SIZE];
    n = recv(sockfd, response, BUFFER_SIZE, 0);
    if (n == -1) {
        printf("Error receiving server response\n");
        exit(1);
    }
    printf("Server response: %s", response);
    
    // Close socket
    close(sockfd);
    return 0;
}