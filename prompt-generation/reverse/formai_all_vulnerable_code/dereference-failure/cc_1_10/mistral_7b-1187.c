//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: high level of detail
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

int create_socket() {
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        die("socket: can't create socket");

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
        die("connect: can't connect");

    return sockfd;
}

void send_mail(int sockfd, const char *from, const char *to, const char *subject, const char *message) {
    char cmd[BUFFER_SIZE];
    char from_addr[100], to_addr[100];
    int len;

    // EHLO command with our SMTP client name
    snprintf(cmd, BUFFER_SIZE, "EHLO smtp-client\r\n");
    write(sockfd, cmd, strlen(cmd));

    // MAIL FROM command with our address
    snprintf(from_addr, sizeof(from_addr), "<%s>", from);
    snprintf(cmd, BUFFER_SIZE, "MAIL FROM:<%s>\r\n", from_addr);
    write(sockfd, cmd, strlen(cmd));

    // RCPT TO command with recipient's address
    snprintf(to_addr, sizeof(to_addr), "<%s>", to);
    snprintf(cmd, BUFFER_SIZE, "RCPT TO:<%s>\r\n", to_addr);
    write(sockfd, cmd, strlen(cmd));

    // Data command to start sending message
    write(sockfd, "\r\nDATA\r\n\r\n", 6);

    // Send message body
    len = send(sockfd, message, strlen(message), 0);
    if (len < 0)
        die("send: error sending message body");

    // Quit command to close connection
    write(sockfd, "\r\nQUIT\r\n\r\n", 6);
}

int main(int argc, char **argv) {
    int sockfd;
    const char *from = "me@example.com";
    const char *to = "you@example.com";
    const char *subject = "Test Email";
    const char *message = "This is a test email from our SMTP client.";

    if (argc != 3 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "Usage: %s <from> <to>\n", argv[0]);
        exit(1);
    }

    strcpy(from, argv[1]);
    strcpy(to, argv[2]);

    sockfd = create_socket();
    send_mail(sockfd, from, to, subject, message);
    close(sockfd);

    printf("Email sent to %s successfully.\n", to);
    return 0;
}