//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

#define PORT 25
#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char buffer[MAX_BUFFER_SIZE];

    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    host = gethostbyname(argv[1]);

    if (host == NULL) {
        printf("Error: Host not found\n");
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error: Failed to create socket\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr*)host->h_addr);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error: Connection failed\n");
        exit(EXIT_FAILURE);
    }

    recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    printf("%s\n", buffer);

    strcpy(buffer, "EHLO localhost\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    printf("%s\n", buffer);

    strcpy(buffer, "MAIL FROM:<sender@example.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    printf("%s\n", buffer);

    strcpy(buffer, "RCPT TO:<recipient@example.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    printf("%s\n", buffer);

    strcpy(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    printf("%s\n", buffer);

    strcpy(buffer, "Subject: SMTP Client\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, "Test email from SMTP client\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    strcpy(buffer, ".\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    printf("%s\n", buffer);

    strcpy(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER_SIZE-1, 0);
    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}