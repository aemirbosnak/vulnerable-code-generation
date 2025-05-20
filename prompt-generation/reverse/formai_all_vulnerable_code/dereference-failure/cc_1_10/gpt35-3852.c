//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

void send_mail(int sockfd, const char* mail_from, const char* rcpt_to, const char* subject, const char* message) {
    char buffer[1024];
    int n;

    // Send the MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", mail_from);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // Read server response
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send the RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", rcpt_to);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // Read server response
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send the DATA command
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // Read server response
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send the message header
    snprintf(buffer, sizeof(buffer), "From: <%s>\r\nTo: <%s>\r\nSubject: %s\r\n\r\n", mail_from, rcpt_to, subject);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // Send the message body
    snprintf(buffer, sizeof(buffer), "%s\r\n.\r\n", message);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    // Read server response
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("%s", buffer);
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Usage: smtp_client <smtp_server> <mail_from> <rcpt_to> <subject>\n");
        return 1;
    }

    const char* smtp_server = argv[1];
    const char* mail_from = argv[2];
    const char* rcpt_to = argv[3];
    const char* subject = argv[4];

    char* message = malloc(1024 * sizeof(char));
    if (message == NULL) {
        perror("Error allocating memory");
        exit(1);
    }

    // Read message from stdin
    printf("Type message and press Enter key:\n");
    fgets(message, 1024, stdin);

    // Remove trailing newline character
    message[strcspn(message, "\n")] = '\0';

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get server IP address
    struct hostent* server = gethostbyname(smtp_server);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    // Initialize socket address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(25);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read server greeting
    char buffer[1024];
    int n = read(sockfd, buffer, sizeof(buffer) - 1);
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send mail
    send_mail(sockfd, mail_from, rcpt_to, subject, message);

    // Close socket
    close(sockfd);

    return 0;
}