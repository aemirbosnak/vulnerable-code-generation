//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define SMTP_PORT 25
#define BUF_SIZE 1024

void send_email(char *recipient, char *subject, char *body) {
    int sockfd;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buf[BUF_SIZE];
    char *host = "localhost";

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get the server's IP address
    server = gethostbyname(host);
    if (server == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char *) &serv_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(SMTP_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Say hello to the server
    snprintf(buf, BUF_SIZE, "HELO %s\r\n", host);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Get the server's response
    if (read(sockfd, buf, BUF_SIZE) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Send the sender's email address
    snprintf(buf, BUF_SIZE, "MAIL FROM: <%s>\r\n", "sender@example.com");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Get the server's response
    if (read(sockfd, buf, BUF_SIZE) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Send the recipient's email address
    snprintf(buf, BUF_SIZE, "RCPT TO: <%s>\r\n", recipient);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Get the server's response
    if (read(sockfd, buf, BUF_SIZE) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Send the data
    snprintf(buf, BUF_SIZE, "DATA\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Get the server's response
    if (read(sockfd, buf, BUF_SIZE) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Send the subject
    snprintf(buf, BUF_SIZE, "Subject: %s\r\n", subject);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Send the body
    snprintf(buf, BUF_SIZE, "%s\r\n", body);
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // End the data
    snprintf(buf, BUF_SIZE, ".\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Get the server's response
    if (read(sockfd, buf, BUF_SIZE) < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    // Quit the server
    snprintf(buf, BUF_SIZE, "QUIT\r\n");
    if (write(sockfd, buf, strlen(buf)) < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s recipient subject body\n", argv[0]);
        return EXIT_FAILURE;
    }

    send_email(argv[1], argv[2], argv[3]);

    return EXIT_SUCCESS;
}