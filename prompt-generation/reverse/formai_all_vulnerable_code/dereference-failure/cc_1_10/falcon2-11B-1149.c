//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    char* hostname = "smtp.example.com";
    char* username = "your_username";
    char* password = "your_password";
    char* recipient = "recipient@example.com";
    char* message = "Hello, World!";
    char* subject = "Test Email";

    struct hostent* server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: hostname not found\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: socket creation failed\n");
        exit(1);
    }

    int result = connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (result < 0) {
        fprintf(stderr, "Error: connection failed\n");
        exit(1);
    }

    char command[1024];
    sprintf(command, "EHLO localhost\r\n");
    write(sockfd, command, strlen(command));
    fflush(stdout);

    sprintf(command, "MAIL FROM: %s\r\n", username);
    write(sockfd, command, strlen(command));
    fflush(stdout);

    sprintf(command, "RCPT TO: %s\r\n", recipient);
    write(sockfd, command, strlen(command));
    fflush(stdout);

    sprintf(command, "DATA\r\n");
    write(sockfd, command, strlen(command));
    fflush(stdout);

    sprintf(command, "From: %s <%s>\r\n", username, username);
    write(sockfd, command, strlen(command));
    fflush(stdout);

    sprintf(command, "To: %s\r\n", recipient);
    write(sockfd, command, strlen(command));
    fflush(stdout);

    sprintf(command, "Subject: %s\r\n", subject);
    write(sockfd, command, strlen(command));
    fflush(stdout);

    sprintf(command, "This is a test email.\r\n.\r\n");
    write(sockfd, command, strlen(command));
    fflush(stdout);

    sprintf(command, "QUIT\r\n");
    write(sockfd, command, strlen(command));
    fflush(stdout);

    close(sockfd);
    return 0;
}