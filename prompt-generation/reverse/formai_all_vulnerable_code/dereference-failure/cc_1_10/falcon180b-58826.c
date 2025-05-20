//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server_info;
    char buffer[BUFFER_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage:./smtp_client <server_ip> <sender_email> <receiver_email>\n");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Connect to server
    server_info = gethostbyname(argv[1]);
    if (server_info == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy(server_info->h_addr, &server_addr.sin_addr.s_addr, server_info->h_length);
    server_addr.sin_port = htons(25);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send HELO command
    send(sockfd, "HELO ", 5, 0);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send RCPT TO command
    sprintf(buffer, "RCPT TO:<%s>", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send DATA command
    send(sockfd, "DATA", 4, 0);

    // Send email body
    char email_body[] = "Subject: Test Email\r\n\r\nThis is a test email sent using a SMTP client program.\r\n";
    send(sockfd, email_body, strlen(email_body), 0);

    // Send dot to end email
    send(sockfd, ". ", 2, 0);

    // Receive server response
    bzero(buffer, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}