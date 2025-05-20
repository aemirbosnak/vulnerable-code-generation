//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char message[1000];
    int n;

    if (argc < 3) {
        printf("Usage: %s <server_address> <port_number>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to SMTP server\n");

    sprintf(message, "EHLO %s\r\n", argv[1]);
    send(sockfd, message, strlen(message), 0);

    char buffer[1000];
    memset(buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Received response: %s\n", buffer);

    sprintf(message, "MAIL FROM:<%s>\r\n", argv[1]);
    send(sockfd, message, strlen(message), 0);

    memset(buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Received response: %s\n", buffer);

    sprintf(message, "RCPT TO:<%s>\r\n", argv[2]);
    send(sockfd, message, strlen(message), 0);

    memset(buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Received response: %s\n", buffer);

    sprintf(message, "DATA\r\n");
    send(sockfd, message, strlen(message), 0);

    sprintf(message, "Subject: SMTP Test\r\n\r\nTest message sent successfully!\r\n");
    send(sockfd, message, strlen(message), 0);

    memset(buffer, 0, sizeof(buffer));
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Received response: %s\n", buffer);

    close(sockfd);

    return 0;
}