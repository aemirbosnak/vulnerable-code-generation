//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s destination_address\n", argv[0]);
        return 1;
    }

    char *destination_address = argv[1];
    struct hostent *host = gethostbyname(destination_address);
    if (!host) {
        printf("Could not resolve destination address\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Could not create socket\n");
        return 1;
    }

    struct sockaddr_in server_address;
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_address.sin_addr.s_addr, host->h_length);
    server_address.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Could not connect to server\n");
        return 1;
    }

    char buffer[BUFFER_SIZE];

    // Wait for server's greeting message
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send HELO message
    memset(buffer, 0, BUFFER_SIZE);
    printf("HELO myclientdomain.com\n");
    sprintf(buffer, "HELO myclientdomain.com\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server's response to HELO message
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send MAIL FROM message
    memset(buffer, 0, BUFFER_SIZE);
    printf("MAIL FROM:<sender@example.com>\n");
    sprintf(buffer, "MAIL FROM:<sender@example.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server's response to MAIL FROM message
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send RCPT TO message
    memset(buffer, 0, BUFFER_SIZE);
    printf("RCPT TO:<recipient@example.com>\n");
    sprintf(buffer, "RCPT TO:<recipient@example.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server's response to RCPT TO message
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send DATA message
    memset(buffer, 0, BUFFER_SIZE);
    printf("DATA\n");
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server's response to DATA message
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send message body
    
    char *message_body = "From: sender@example.com\nTo: recipient@example.com\nSubject: Test\n\nThis is a test message.\n";
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "%s", message_body);
    send(sockfd, buffer, strlen(buffer), 0);

    // Send end of message signal
    memset(buffer, 0, BUFFER_SIZE);
    sprintf(buffer, "\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server's response to end of message signal
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send QUIT message
    memset(buffer, 0, BUFFER_SIZE);
    printf("QUIT\n");
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for server's response to QUIT message
    memset(buffer, 0, BUFFER_SIZE);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("%s", buffer);

    close(sockfd);

    return 0;
}