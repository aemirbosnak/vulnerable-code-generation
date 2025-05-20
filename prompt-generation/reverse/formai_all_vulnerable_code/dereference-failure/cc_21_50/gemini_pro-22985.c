//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: intelligent
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <mailbox>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *host = argv[1];
    const int port = atoi(argv[2]);
    const char *mailbox = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the CAPABILITY command
    char buf[1024];
    snprintf(buf, sizeof(buf), "CAPABILITY\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the CAPABILITY response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Parse the CAPABILITY response
    const char *capabilities = strstr(buf, "IMAP4rev1");
    if (capabilities == NULL) {
        fprintf(stderr, "IMAP4rev1 not supported\n");
        return EXIT_FAILURE;
    }

    // Send the LOGIN command
    snprintf(buf, sizeof(buf), "LOGIN %s %s\r\n", "username", "password");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the LOGIN response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Parse the LOGIN response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "LOGIN failed: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the SELECT command
    snprintf(buf, sizeof(buf), "SELECT %s\r\n", mailbox);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the SELECT response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Parse the SELECT response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "SELECT failed: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the FETCH command
    snprintf(buf, sizeof(buf), "FETCH 1:10 (BODY[TEXT])\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the FETCH response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Parse the FETCH response
    char *start = strstr(buf, "BODY[TEXT]");
    if (start == NULL) {
        fprintf(stderr, "BODY[TEXT] not found\n");
        return EXIT_FAILURE;
    }

    // Print the message body
    start += strlen("BODY[TEXT]");
    while (*start != '\r') {
        putchar(*start++);
    }
    putchar('\n');

    // Send the LOGOUT command
    snprintf(buf, sizeof(buf), "LOGOUT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the LOGOUT response
    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Parse the LOGOUT response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "LOGOUT failed: %s\n", buf);
        return EXIT_FAILURE;
    }

    close(sockfd);
    return EXIT_SUCCESS;
}