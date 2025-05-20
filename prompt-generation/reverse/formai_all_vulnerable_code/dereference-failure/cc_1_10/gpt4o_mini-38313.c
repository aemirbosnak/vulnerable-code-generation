//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 25
#define BUFFER_SIZE 1024
#define EMAIL_MAX 256

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_command(int sockfd, const char *cmd) {
    send(sockfd, cmd, strlen(cmd), 0);
    char buffer[BUFFER_SIZE];
    recv(sockfd, buffer, sizeof(buffer)-1, 0);
    printf("%s", buffer);
}

int main() {
    int sockfd;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    
    printf("Cryptic Email Client Initiated...\n");
    printf("Input SMTP Server: ");
    
    char smtp_server[EMAIL_MAX];
    fgets(smtp_server, sizeof(smtp_server), stdin);
    smtp_server[strcspn(smtp_server, "\n")] = 0; // remove newline

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("Error opening socket");

    struct hostent *server_host = gethostbyname(smtp_server);
    if (server_host == NULL) error("No such host");
    
    bzero((char *) &server, sizeof(server));
    server.sin_family = AF_INET;
    bcopy((char *)server_host->h_addr, (char *)&server.sin_addr.s_addr, server_host->h_length);
    server.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) 
        error("Unable to connect");

    recv(sockfd, buffer, sizeof(buffer)-1, 0); // Read server response
    printf("%s", buffer);

    send_command(sockfd, "HELO client\r\n");
    
    char email_from[EMAIL_MAX], email_to[EMAIL_MAX], subject[EMAIL_MAX], message[BUFFER_SIZE];

    printf("Input your email (sender): ");
    fgets(email_from, sizeof(email_from), stdin);
    email_from[strcspn(email_from, "\n")] = 0;

    printf("Input recipient email: ");
    fgets(email_to, sizeof(email_to), stdin);
    email_to[strcspn(email_to, "\n")] = 0;

    printf("Input email subject: ");
    fgets(subject, sizeof(subject), stdin);
    subject[strcspn(subject, "\n")] = 0;

    printf("Input your message: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    char command[BUFFER_SIZE];

    sprintf(command, "MAIL FROM:<%s>\r\n", email_from);
    send_command(sockfd, command);

    sprintf(command, "RCPT TO:<%s>\r\n", email_to);
    send_command(sockfd, command);

    send_command(sockfd, "DATA\r\n");

    sprintf(command, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, message);
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, buffer, sizeof(buffer)-1, 0);
    printf("%s", buffer);
    
    send_command(sockfd, "QUIT\r\n");
    close(sockfd);
    
    printf("Email Sent! Closing Client...\n");
    return 0;
}