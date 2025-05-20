//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_SIZE 1024

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_SIZE];
    
    printf("Welcome to SMTP Client!\n");
    printf("Let's send an email with SMTP.\n");
    
    printf("Enter hostname: ");
    char hostname[MAX_SIZE];
    fgets(hostname, MAX_SIZE, stdin);
    strtok(hostname, "\n");
    
    printf("Enter port number: ");
    char port[MAX_SIZE];
    fgets(port, MAX_SIZE, stdin);
    portno = atoi(port);
    
    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: No such host.\n");
        printf("Exiting program...\n");
        return 0;
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket.\n");
        printf("Exiting program...\n");
        return 0;
    }
    
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr*) server->h_addr);
    
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Could not connect to server.\n");
        printf("Exiting program...\n");
        return 0;
    }
    
    printf("Connected to server!\n");
    
    n = read(sockfd, buffer, MAX_SIZE - 1);
    if (n < 0) {
        printf("Error: Failed to read from socket.\n");
        printf("Exiting program...\n");
        return 0;
    }
    
    buffer[n] = '\0';
    printf("%s", buffer);
    
    printf("Enter your name: ");
    char name[MAX_SIZE];
    fgets(name, MAX_SIZE, stdin);
    strtok(name, "\n");
    
    printf("Enter email address: ");
    char email[MAX_SIZE];
    fgets(email, MAX_SIZE, stdin);
    strtok(email, "\n");
    
    printf("Enter recipient email address: ");
    char recipient[MAX_SIZE];
    fgets(recipient, MAX_SIZE, stdin);
    strtok(recipient, "\n");
    
    printf("Enter subject: ");
    char subject[MAX_SIZE];
    fgets(subject, MAX_SIZE, stdin);
    strtok(subject, "\n");
    
    printf("Enter message: ");
    char message[MAX_SIZE];
    fgets(message, MAX_SIZE, stdin);
    strtok(message, "\n");
    
    char emailHeader[MAX_SIZE];
    sprintf(emailHeader, "From: %s <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n", name, email, recipient, subject);
    
    char emailBody[MAX_SIZE];
    sprintf(emailBody, "%s\r\n.\r\n", message);
    
    char emailContent[MAX_SIZE];
    sprintf(emailContent, "HELO %s\r\nMAIL From: <%s>\r\nRCPT To: <%s>\r\nDATA\r\n%s%sQUIT\r\n", hostname, email, recipient, emailHeader, emailBody);
    
    n = write(sockfd, emailContent, strlen(emailContent));
    if (n < 0) {
        printf("Error: Failed to write to socket.\n");
        printf("Exiting program...\n");
        return 0;
    }
    
    memset(buffer, 0, MAX_SIZE);
    n = read(sockfd, buffer, MAX_SIZE - 1);
    if (n < 0) {
        printf("Error: Failed to read from socket.\n");
        printf("Exiting program...\n");
        return 0;
    }
    
    buffer[n] = '\0';
    printf("%s", buffer);
    
    close(sockfd);
    printf("Disconnected from server. Email sent!\n");
    
    return 0;
}