//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    char hostname[MAX_BUFFER_SIZE];
    printf("Enter the name of the SMTP server: ");
    scanf("%s", hostname);

    // Get email credentials
    char sender[MAX_BUFFER_SIZE];
    printf("Enter your email address: ");
    scanf("%s", sender);

    char recipient[MAX_BUFFER_SIZE];
    printf("Enter the recipient's email address: ");
    scanf("%s", recipient);

    char subject[MAX_BUFFER_SIZE];
    printf("Enter the email subject: ");
    scanf("%s", subject);

    // Get email body from a file
    char filename[MAX_BUFFER_SIZE];
    printf("Enter the file name of the email body: ");
    scanf("%s", filename);

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return 0;
    }

    char buffer[MAX_BUFFER_SIZE];
    size_t bytesRead;
    int offset = 0;

    while ((bytesRead = fread(buffer + offset, 1, MAX_BUFFER_SIZE - offset, fp)) > 0) {
        offset += bytesRead;
    }

    buffer[offset] = 0;
    fclose(fp);

    // Create the email message
    char message[MAX_BUFFER_SIZE];
    snprintf(message, MAX_BUFFER_SIZE, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s", sender, recipient, subject, buffer);

    // Open connection with SMTP server
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Cannot resolve hostname: %s\n", hostname);
        return 0;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Cannot create socket!\n");
        return 0;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(25);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Cannot connect to SMTP server: %s\n", hostname);
        return 0;
    }

    // Read SMTP server welcome message
    char response[MAX_BUFFER_SIZE];
    recv(sockfd, response, MAX_BUFFER_SIZE, 0);
    printf("%s\n", response);

    // Send HELO command
    char heloCmd[MAX_BUFFER_SIZE];
    snprintf(heloCmd, MAX_BUFFER_SIZE, "HELO %s\r\n", hostname);
    send(sockfd, heloCmd, strlen(heloCmd), 0);

    // Read SMTP server response to HELO command
    recv(sockfd, response, MAX_BUFFER_SIZE, 0);
    printf("%s\n", response);

    // Send MAIL FROM command
    char mailFromCmd[MAX_BUFFER_SIZE];
    snprintf(mailFromCmd, MAX_BUFFER_SIZE, "MAIL FROM: <%s>\r\n", sender);
    send(sockfd, mailFromCmd, strlen(mailFromCmd), 0);

    // Read SMTP server response to MAIL FROM command
    recv(sockfd, response, MAX_BUFFER_SIZE, 0);
    printf("%s\n", response);

    // Send RCPT TO command
    char rcptToCmd[MAX_BUFFER_SIZE];
    snprintf(rcptToCmd, MAX_BUFFER_SIZE, "RCPT TO: <%s>\r\n", recipient);
    send(sockfd, rcptToCmd, strlen(rcptToCmd), 0);

    // Read SMTP server response to RCPT TO command
    recv(sockfd, response, MAX_BUFFER_SIZE, 0);
    printf("%s\n", response);

    // Send DATA command
    char dataCmd[MAX_BUFFER_SIZE];
    snprintf(dataCmd, MAX_BUFFER_SIZE, "DATA\r\n");
    send(sockfd, dataCmd, strlen(dataCmd), 0);

    // Read SMTP server response to DATA command
    recv(sockfd, response, MAX_BUFFER_SIZE, 0);
    printf("%s\n", response);

    // Send email message
    send(sockfd, message, strlen(message), 0);

    // Send QUIT command
    char quitCmd[MAX_BUFFER_SIZE];
    snprintf(quitCmd, MAX_BUFFER_SIZE, "QUIT\r\n");
    send(sockfd, quitCmd, strlen(quitCmd), 0);

    // Read SMTP server response to QUIT command
    recv(sockfd, response, MAX_BUFFER_SIZE, 0);
    printf("%s\n", response);

    // Close connection with SMTP server
    close(sockfd);

    return 0;
}