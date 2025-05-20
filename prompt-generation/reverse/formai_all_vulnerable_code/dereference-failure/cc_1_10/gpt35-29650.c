//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 1024
#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_address;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <from> <to> [<cc>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    char *from = argv[2];
    char *to = argv[3];
    char *cc = argc > 4 ? argv[4] : NULL;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname(host);

    if (server == NULL) {
        fprintf(stderr, "Error: No such host: %s\n", host);
        exit(EXIT_FAILURE);
    }

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(SMTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to host");
        exit(EXIT_FAILURE);
    }

    printf("220 %s SMTP Service Ready\n", host);

    // Send HELO command
    snprintf(buffer, MAX_BUFFER_SIZE, "HELO %s\r\n", host);
    send(sockfd, buffer, strlen(buffer), 0);
    printf("HELO %s\n", host);

    // Receive response
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send MAIL FROM command
    snprintf(buffer, MAX_BUFFER_SIZE, "MAIL FROM:<%s>\r\n", from);
    send(sockfd, buffer, strlen(buffer), 0);
    printf("MAIL FROM:<%s>\n", from);

    // Receive response
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send RCPT TO command
    snprintf(buffer, MAX_BUFFER_SIZE, "RCPT TO:<%s>\r\n", to);
    send(sockfd, buffer, strlen(buffer), 0);
    printf("RCPT TO:<%s>\n", to);

    // Receive response
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send DATA command
    snprintf(buffer, MAX_BUFFER_SIZE, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    printf("DATA\n");

    // Receive response
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send email message
    snprintf(buffer, MAX_BUFFER_SIZE,
             "From: <%s>\r\nTo: <%s>\r\nCc: <%s>\r\nSubject: Testing SMTP Client\r\n\r\nThis is a test email message sent using a SMTP client.\r\n", from, to, cc == NULL ? "" : cc);
    send(sockfd, buffer, strlen(buffer), 0);
    printf("######### Email message:\n%s#########", buffer);

    // Send end of email data command
    snprintf(buffer, MAX_BUFFER_SIZE, "\r\n.\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    printf("\n.\n");

    // Receive response
    recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    printf("%s", buffer);

    // Send QUIT command
    snprintf(buffer, MAX_BUFFER_SIZE, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    printf("QUIT\n");

    // Close socket
    close(sockfd);

    exit(EXIT_SUCCESS);
}