//MISTRAL-7B DATASET v1.0 Category: Building a SMTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 25
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serveraddr;
    struct hostent *server;

    char sendmail[BUFFER_SIZE];
    char to[256];
    char from[256];
    char subject[256];
    char message[1024];

    // Input email details
    printf("Enter recipient email: ");
    scanf("%s", to);
    printf("Enter sender email: ");
    scanf("%s", from);
    printf("Enter email subject: ");
    scanf("%s", subject);
    printf("Enter email message: ");
    scanf("%s", message);

    // Initialize socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("ERROR opening socket");
    }

    // Get server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
         (char *)&serveraddr.sin_addr.s_addr,
         server->h_length);
    serveraddr.sin_port = htons(SERVER_PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serveraddr, sizeof(serveraddr)) < 0) {
        die("ERROR connecting");
    }

    // Send HELO command
    send(sockfd, "HELO Client\r\n", strlen("HELO Client\r\n"), 0);

    // Send MAIL FROM command
    sprintf(sendmail, "MAIL FROM:<%s>\r\n", from);
    send(sockfd, sendmail, strlen(sendmail), 0);

    // Send RCPT TO command
    sprintf(sendmail, "RCPT TO:<%s>\r\n", to);
    send(sockfd, sendmail, strlen(sendmail), 0);

    // Send DATA command
    send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0);

    // Send email headers
    sprintf(sendmail, "From: %s\r\n", from);
    send(sockfd, sendmail, strlen(sendmail), 0);
    sprintf(sendmail, "To: %s\r\n", to);
    send(sockfd, sendmail, strlen(sendmail), 0);
    sprintf(sendmail, "Subject: %s\r\n", subject);
    send(sockfd, sendmail, strlen(sendmail), 0);

    // Send email body
    send(sockfd, message, strlen(message), 0);

    // Send QUIT command
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);

    // Close socket
    close(sockfd);

    printf("Email sent successfully!\n");
    return 0;
}