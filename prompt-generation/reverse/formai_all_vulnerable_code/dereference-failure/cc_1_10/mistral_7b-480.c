//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    const char *host = "smtp.gmail.com";
    const char *from = "sender@example.com";
    const char *to = "recipient@example.com";
    const char *subject = "Hello, World!";

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(587);

    if (inet_pton(AF_INET, host, &server_addr.sin_addr) <= 0)
        die("Invalid address/ Address not supported");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        die("Connection failed");

    write(sockfd, "EHLO localhost\r\n", strlen("EHLO localhost\r\n"));

    char *auth_command = "AUTH LOGIN\r\n";
    write(sockfd, auth_command, strlen(auth_command));

    const char *username = "sender@example.com";
    char *username_bytes = malloc(strlen(username) + 1);
    strcpy(username_bytes, username);

    write(sockfd, username_bytes, strlen(username_bytes));
    free(username_bytes);

    const char *password = "password";
    char *password_bytes = malloc(strlen(password) + 1);
    strcpy(password_bytes, password);

    write(sockfd, password_bytes, strlen(password_bytes));
    free(password_bytes);

    write(sockfd, "MAIL FROM: <%s>\r\n", from);
    write(sockfd, "Rcpt TO: <%s>\r\n", to);

    char *data = "DATA\r\n";
    write(sockfd, data, strlen(data));

    write(sockfd, "From: %s\r\n", from);
    write(sockfd, "To: %s\r\n", to);
    write(sockfd, "Subject: %s\r\n", subject);
    write(sockfd, "\r\n", 1);

    write(sockfd, "The quick brown fox jumps over the lazy dog.\r\n", strlen("The quick brown fox jumps over the lazy dog.\r\n"));
    write(sockfd, "\r\n.", 1);

    char *quit_command = "QUIT\r\n";
    write(sockfd, quit_command, strlen(quit_command));

    close(sockfd);
    return 0;
}