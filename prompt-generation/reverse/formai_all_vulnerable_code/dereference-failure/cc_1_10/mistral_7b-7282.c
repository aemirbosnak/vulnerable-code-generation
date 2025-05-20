//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <from_address> <to_address>\n", argv[0]);
        exit(1);
    }

    const char *from_address = argv[1];
    const char *to_address = argv[2];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        die("socket");

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) <= 0)
        die("Invalid address/ Address not supported");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        die("Connection failed");

    write(sockfd, "HELO localhost\r\n", 7); // Greeting the SMTP server

    size_t from_len = strlen(from_address);
    size_t to_len = strlen(to_address);

    write(sockfd, "MAIL FROM:<", 11);
    write(sockfd, from_address, from_len);
    write(sockfd, ">\r\n", from_len + 2);

    write(sockfd, "Rcpt TO:<", 8);
    write(sockfd, to_address, to_len);
    write(sockfd, ">\r\n", to_len + 2);

    write(sockfd, "DATA\r\n", 5);

    char *message = "Subject: Test email\r\n\r\nThis is a test email.\r\n";
    size_t message_len = strlen(message);

    write(sockfd, message, message_len);

    write(sockfd, "\r\n.\r\n", 4);

    int rc = recv(sockfd, NULL, 1, 0);
    if (rc < 0)
        die("Error during sending the email");

    if (rc != 250) {
        char buf[BUFFER_SIZE];
        read(sockfd, buf, BUFFER_SIZE);
        fprintf(stderr, "Server response: %s\n", buf);
        die("Failed to send email");
    }

    printf("Email sent to %s successfully.\n", to_address);

    close(sockfd);

    return 0;
}