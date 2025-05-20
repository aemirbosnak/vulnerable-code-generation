//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define PORT 25

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Failed to create socket\n");
        return -1;
    }

    // Resolve the host name to IP address
    struct hostent *server;
    char* hostname = "smtp.example.com";
    server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Failed to resolve hostname\n");
        return -1;
    }

    // Create an address structure for the server
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect to server\n");
        return -1;
    }

    // Send the email command
    char command[128];
    snprintf(command, sizeof(command), "EHLO client\r\n");
    write(sockfd, command, strlen(command));

    // Send the recipient's email address
    snprintf(command, sizeof(command), "MAIL FROM:<recipient@example.com>\r\n");
    write(sockfd, command, strlen(command));

    // Send the subject and body of the email
    snprintf(command, sizeof(command), "RCPT TO:<recipient@example.com>\r\n");
    write(sockfd, command, strlen(command));

    snprintf(command, sizeof(command), "DATA\r\n");
    write(sockfd, command, strlen(command));

    // Send the email body
    snprintf(command, sizeof(command), "From: sender@example.com\r\n");
    write(sockfd, command, strlen(command));
    snprintf(command, sizeof(command), "To: recipient@example.com\r\n");
    write(sockfd, command, strlen(command));
    snprintf(command, sizeof(command), "Subject: Test email\r\n");
    write(sockfd, command, strlen(command));
    snprintf(command, sizeof(command), "\r\n");
    write(sockfd, command, strlen(command));
    snprintf(command, sizeof(command), "This is a test email.\r\n");
    write(sockfd, command, strlen(command));
    snprintf(command, sizeof(command), ".\r\n");
    write(sockfd, command, strlen(command));

    // Send the email ending command
    snprintf(command, sizeof(command), "QUIT\r\n");
    write(sockfd, command, strlen(command));

    close(sockfd);
    return 0;
}