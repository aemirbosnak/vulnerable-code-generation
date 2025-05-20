//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXHOSTNAME 256
#define PORT 25 // SMTP port number

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <email_address> [mail_server]\n", argv[0]);
        exit(1);
    }

    char *email_address = argv[1];
    char *mail_server_name = (argc == 3) ? argv[2] : "localhost";
    struct hostent *mail_server = gethostbyname(mail_server_name);
    if (mail_server == NULL) {
        fprintf(stderr, "Could not resolve mail server: %s\n", mail_server_name);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        exit(1);
    }

    struct sockaddr_in mail_server_address;
    bzero(&mail_server_address, sizeof(mail_server_address));
    mail_server_address.sin_family = AF_INET;
    memcpy(&mail_server_address.sin_addr.s_addr, mail_server->h_addr_list[0], mail_server->h_length);
    mail_server_address.sin_port = htons(PORT);
    if (connect(sockfd, (struct sockaddr *)&mail_server_address, sizeof(mail_server_address)) < 0) {
        perror("Could not connect to mail server");
        exit(1);
    }

    char buffer[256];
    int n;

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("Could not read from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send HELO command
    sprintf(buffer, "HELO %s\r\n", mail_server_name);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Could not write to socket");
        exit(1);
    }

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("Could not read from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send MAIL FROM command
    sprintf(buffer, "MAIL FROM:<%s>\r\n", email_address);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Could not write to socket");
        exit(1);
    }

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("Could not read from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send RCPT TO command
    printf("Enter recipient email address: ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    sprintf(buffer, "RCPT TO:<%s>\r\n", buffer);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Could not write to socket");
        exit(1);
    }

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("Could not read from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send DATA command
    sprintf(buffer, "DATA\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Could not write to socket");
        exit(1);
    }

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("Could not read from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send email message
    printf("Enter email message (end with a single dot on a line): \n");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (strcmp(buffer, ".\n") == 0) {
            break;
        }
        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n < 0) {
            perror("Could not write to socket");
            exit(1);
        }
    }

    // Send QUIT command
    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Could not write to socket");
        exit(1);
    }

    n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
    if (n < 0) {
        perror("Could not read from socket");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    close(sockfd);
    return 0;
}