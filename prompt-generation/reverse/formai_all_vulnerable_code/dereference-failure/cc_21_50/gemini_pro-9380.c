//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <sender> <recipient> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the sender and recipient addresses.
    char *sender = argv[1];
    char *recipient = argv[2];

    // Get the message.
    char *message = argv[3];

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server.
    struct hostent *host = gethostbyname("localhost");
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr, host->h_addr, host->h_length);
    addr.sin_port = htons(SMTP_PORT);

    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the HELO command.
    char helo[] = "HELO localhost\r\n";
    if (send(sockfd, helo, strlen(helo), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    char buf[1024];
    int n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Check the server's response.
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command.
    char mail_from[1024];
    snprintf(mail_from, sizeof(mail_from), "MAIL FROM: %s\r\n", sender);
    if (send(sockfd, mail_from, strlen(mail_from), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Check the server's response.
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command.
    char rcpt_to[1024];
    snprintf(rcpt_to, sizeof(rcpt_to), "RCPT TO: %s\r\n", recipient);
    if (send(sockfd, rcpt_to, strlen(rcpt_to), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Check the server's response.
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the DATA command.
    char data[] = "DATA\r\n";
    if (send(sockfd, data, strlen(data), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Check the server's response.
    if (strncmp(buf, "354", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the message.
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the period to indicate the end of the message.
    char period[] = ".\r\n";
    if (send(sockfd, period, strlen(period), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Receive the server's response.
    n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
        perror("recv");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Check the server's response.
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Send the QUIT command.
    char quit[] = "QUIT\r\n";
    if (send(sockfd, quit, strlen(quit), 0) == -1) {
        perror("send");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}