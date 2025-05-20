//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void respond(FILE *fp) {
    char response[BUFFER_SIZE];
    fgets(response, BUFFER_SIZE, fp);
    printf("Server: %s", response);
}

void send_command(int sockfd, const char *cmd) {
    write(sockfd, cmd, strlen(cmd));
    respond(fdopen(sockfd, "r"));
}

void smtp_client(const char *hostname, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to the server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    respond(fdopen(sockfd, "r"));

    char smtp_command[BUFFER_SIZE];

    snprintf(smtp_command, sizeof(smtp_command), "HELO %s\r\n", hostname);
    send_command(sockfd, smtp_command);

    snprintf(smtp_command, sizeof(smtp_command), "MAIL FROM:<%s>\r\n", from);
    send_command(sockfd, smtp_command);

    snprintf(smtp_command, sizeof(smtp_command), "RCPT TO:<%s>\r\n", to);
    send_command(sockfd, smtp_command);

    send_command(sockfd, "DATA\r\n");

    // Prepare the email content
    snprintf(buffer, sizeof(buffer),
             "Subject: %s\r\n"
             "From: %s\r\n"
             "To: %s\r\n"
             "\r\n"
             "%s\r\n"
             ".\r\n", subject, from, to, body);

    write(sockfd, buffer, strlen(buffer));
    respond(fdopen(sockfd, "r"));

    send_command(sockfd, "QUIT\r\n");

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <hostname> <from> <to> <subject> <body>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *from = argv[2];
    const char *to = argv[3];
    const char *subject = argv[4];
    const char *body = argv[5];

    smtp_client(hostname, from, to, subject, body);

    return EXIT_SUCCESS;
}