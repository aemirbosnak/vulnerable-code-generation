//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct {
    char *to;
    char *from;
    char *subject;
    char *body;
} email_t;

void send_email(email_t email, char *host, int port) {
    // Connect to the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Could not create socket. Error code: %d\n", sockfd);
        exit(1);
    }

    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        printf("Could not resolve hostname: %s\n", host);
        exit(1);
    }

    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Could not connect to SMTP server\n");
        exit(1);
    }

    // Send the email
    char buffer[1024] = {0};
    recv(sockfd, buffer, sizeof(buffer), 0); // Wait for server response
    sprintf(buffer, "HELO %s\r\n", host);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0); // Wait for server response

    sprintf(buffer, "MAIL FROM: <%s>\r\n", email.from);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0); // Wait for server response

    sprintf(buffer, "RCPT TO: <%s>\r\n", email.to);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0); // Wait for server response

    sprintf(buffer, "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0); // Wait for server response

    sprintf(buffer, "Subject: %s\r\n\r\n%s\r\n.\r\n", email.subject, email.body);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0); // Wait for server response

    sprintf(buffer, "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0); // Wait for server response

    close(sockfd);
    printf("Email sent to %s\n", email.to);
}

int main() {
    // Set up email parameters
    email_t email = {
        .to = "jane.doe@example.com",
        .from = "john.doe@example.com",
        .subject = "Hello Jane!",
        .body = "Hey Jane,\n\nThis is a message from your friend John. How are you?\n\nBest,\nJohn"
    };

    // Send the email
    send_email(email, "smtp.example.com", 25);

    return 0;
}