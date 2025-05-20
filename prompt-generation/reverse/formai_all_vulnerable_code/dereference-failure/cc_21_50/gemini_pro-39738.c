//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFFER_SIZE];
    char *host, *user, *pass, *to, *from, *subject, *message;

    if (argc != 9) {
        fprintf(stderr, "Usage: %s <host> <user> <pass> <to> <from> <subject> <message>\n", argv[0]);
        exit(1);
    }

    // Get the host, user, pass, to, from, subject, message from the command line arguments
    host = argv[1];
    user = argv[2];
    pass = argv[3];
    to = argv[4];
    from = argv[5];
    subject = argv[6];
    message = argv[7];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get the server's IP address
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error getting server's IP address\n");
        exit(1);
    }

    // Set up the server's address
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    memcpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Receive the server's greeting
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error receiving server's greeting");
        exit(1);
    }
    printf("%s", buffer);

    // Send the HELO command
    snprintf(buffer, BUFFER_SIZE, "HELO %s\r\n", host);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending HELO command");
        exit(1);
    }

    // Receive the server's response to the HELO command
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error receiving server's response to HELO command");
        exit(1);
    }
    printf("%s", buffer);

    // Send the AUTH LOGIN command
    snprintf(buffer, BUFFER_SIZE, "AUTH LOGIN\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending AUTH LOGIN command");
        exit(1);
    }

    // Receive the server's response to the AUTH LOGIN command
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error receiving server's response to AUTH LOGIN command");
        exit(1);
    }
    printf("%s", buffer);

    // Send the user name
    snprintf(buffer, BUFFER_SIZE, "%s\r\n", user);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending user name");
        exit(1);
    }

    // Receive the server's response to the user name
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error receiving server's response to user name");
        exit(1);
    }
    printf("%s", buffer);

    // Send the password
    snprintf(buffer, BUFFER_SIZE, "%s\r\n", pass);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending password");
        exit(1);
    }

    // Receive the server's response to the password
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error receiving server's response to password");
        exit(1);
    }
    printf("%s", buffer);

    // Send the MAIL FROM command
    snprintf(buffer, BUFFER_SIZE, "MAIL FROM: <%s>\r\n", from);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending MAIL FROM command");
        exit(1);
    }

    // Receive the server's response to the MAIL FROM command
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error receiving server's response to MAIL FROM command");
        exit(1);
    }
    printf("%s", buffer);

    // Send the RCPT TO command
    snprintf(buffer, BUFFER_SIZE, "RCPT TO: <%s>\r\n", to);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending RCPT TO command");
        exit(1);
    }

    // Receive the server's response to the RCPT TO command
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error receiving server's response to RCPT TO command");
        exit(1);
    }
    printf("%s", buffer);

    // Send the DATA command
    snprintf(buffer, BUFFER_SIZE, "DATA\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending DATA command");
        exit(1);
    }

    // Receive the server's response to the DATA command
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error receiving server's response to DATA command");
        exit(1);
    }
    printf("%s", buffer);

    // Send the email
    snprintf(buffer, BUFFER_SIZE, "From: %s\r\n", from);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending From header");
        exit(1);
    }

    snprintf(buffer, BUFFER_SIZE, "To: %s\r\n", to);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending To header");
        exit(1);
    }

    snprintf(buffer, BUFFER_SIZE, "Subject: %s\r\n", subject);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending Subject header");
        exit(1);
    }

    snprintf(buffer, BUFFER_SIZE, "\r\n%s\r\n", message);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending message body");
        exit(1);
    }

    // Send the QUIT command
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending QUIT command");
        exit(1);
    }

    // Receive the server's response to the QUIT command
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("Error receiving server's response to QUIT command");
        exit(1);
    }
    printf("%s", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}