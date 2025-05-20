//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Setup the socket
    struct addrinfo hints, *results, *p;
    int sockfd;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = 0;
    int status;
    if ((status = getaddrinfo(argv[1], argv[2], &hints, &results)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }
    for (p = results; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        if (connect(sockfd, p->ai_addr, p->ai_addrlen) != -1) {
            break;
        }
        close(sockfd);
    }
    if (p == NULL) {
        fprintf(stderr, "Failed to connect\n");
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(results);

    // Start the conversation
    char buffer[BUF_SIZE];
    int nbytes;
    char *response;
    nbytes = recv(sockfd, buffer, BUF_SIZE - 1, 0);
    buffer[nbytes] = '\0';
    printf("Server: %s", buffer);
    sprintf(buffer, "HELO client\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    nbytes = recv(sockfd, buffer, BUF_SIZE - 1, 0);
    buffer[nbytes] = '\0';
    printf("Server: %s", buffer);
    sprintf(buffer, "MAIL FROM:<sender@example.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    nbytes = recv(sockfd, buffer, BUF_SIZE - 1, 0);
    buffer[nbytes] = '\0';
    printf("Server: %s", buffer);
    sprintf(buffer, "RCPT TO:<recipient@example.net>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    nbytes = recv(sockfd, buffer, BUF_SIZE - 1, 0);
    buffer[nbytes] = '\0';
    printf("Server: %s", buffer);
    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    nbytes = recv(sockfd, buffer, BUF_SIZE - 1, 0);
    buffer[nbytes] = '\0';
    printf("Server: %s", buffer);
    sprintf(buffer, "Subject: Test email\r\n\r\nThis is a test email\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    nbytes = recv(sockfd, buffer, BUF_SIZE - 1, 0);
    buffer[nbytes] = '\0';
    printf("Server: %s", buffer);
    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Close the socket
    close(sockfd);
    return 0;
}