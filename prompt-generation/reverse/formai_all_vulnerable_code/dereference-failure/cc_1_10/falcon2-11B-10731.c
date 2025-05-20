//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[256];
    char *email;

    // Set up server information
    email = "example@example.com";
    portno = 25;
    server = gethostbyname("localhost");

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)server->h_addr, (int)server->h_length) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    // Send email command
    sprintf(buffer, "EHLO %s\r\n", email);
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    // Send email message
    sprintf(buffer, "MAIL FROM: %s\r\n", email);
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    sprintf(buffer, "RCPT TO: %s\r\n", email);
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    sprintf(buffer, "DATA\r\n");
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    sprintf(buffer, "Subject: Test Email\r\n");
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    sprintf(buffer, "\r\n");
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    sprintf(buffer, "From: %s\r\n", email);
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    sprintf(buffer, "To: %s\r\n", email);
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    sprintf(buffer, "Content-Type: text/plain; charset=utf-8\r\n");
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    sprintf(buffer, "\r\n");
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    sprintf(buffer, "This is a test email\r\n");
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    sprintf(buffer, "\r\n.");
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    sprintf(buffer, "QUIT\r\n");
    write(sockfd, buffer, strlen(buffer));
    printf("Server response: %s\r\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}