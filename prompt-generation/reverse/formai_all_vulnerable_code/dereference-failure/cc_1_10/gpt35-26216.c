//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <string.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <SMTP server>\n", argv[0]);
        return 1;
    }

    // Setup connection to SMTP server
    struct hostent *he;
    he = gethostbyname(argv[1]);
    if (he == NULL) {
        printf("Error: unknown host %s\n", argv[1]);
        return 1;
    }

    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error: socket creation failed\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr, he->h_addr_list[0], he->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: connection failed\n");
        return 1;
    }

    // Send initial message to the SMTP server
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "HELO %s\r\n", argv[1]);
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for response
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send message to the SMTP server
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "MAIL FROM:<sender@example.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for response
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send message to the SMTP server
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "RCPT TO:<recipient@example.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for response
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send message to the SMTP server
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for response
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send message to the SMTP server
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "From: <sender@example.com>\r\nTo: <recipient@example.com>\r\nSubject: SMTP Client Example\r\n\r\nHello, this is a test message from the SMTP client example program.\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for response
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Send message to the SMTP server
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Wait for response
    memset(buffer, 0, sizeof(buffer));
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("%s", buffer);

    // Close connection to SMTP server
    close(sockfd);

    printf("Program completed successfully\n");

    return 0;
}