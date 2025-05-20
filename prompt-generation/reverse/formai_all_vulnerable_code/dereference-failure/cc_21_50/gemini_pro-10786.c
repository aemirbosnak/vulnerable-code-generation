//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ctype.h>

#define SMTP_PORT 25

int main(int argc, char *argv[])
{
    // Check if the user has provided enough arguments
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <sender> <recipient> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the sender, recipient, and message from the command line
    char *sender = argv[1];
    char *recipient = argv[2];
    char *message = argv[3];

    // Create a socket for communicating with the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the SMTP server
    struct hostent *host = gethostbyname("smtp.example.com");
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname: smtp.example.com\n");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SMTP_PORT);
    addr.sin_addr = *((struct in_addr *) host->h_addr);
    if (connect(sockfd, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    char buf[1024];
    int nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is a greeting
    if (strncmp(buf, "220", 3) != 0) {
        fprintf(stderr, "Expected greeting from SMTP server, but received: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the HELO command to the SMTP server
    snprintf(buf, sizeof(buf), "HELO %s\r\n", "example.com");
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is a successful HELO
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Expected successful HELO from SMTP server, but received: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command to the SMTP server
    snprintf(buf, sizeof(buf), "MAIL FROM:<%s>\r\n", sender);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is a successful MAIL FROM
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Expected successful MAIL FROM from SMTP server, but received: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command to the SMTP server
    snprintf(buf, sizeof(buf), "RCPT TO:<%s>\r\n", recipient);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is a successful RCPT TO
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Expected successful RCPT TO from SMTP server, but received: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the DATA command to the SMTP server
    if (send(sockfd, "DATA\r\n", strlen("DATA\r\n"), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is a successful DATA
    if (strncmp(buf, "354", 3) != 0) {
        fprintf(stderr, "Expected successful DATA from SMTP server, but received: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the message to the SMTP server
    if (send(sockfd, message, strlen(message), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the end of the message to the SMTP server
    if (send(sockfd, "\r\n.\r\n", 5, 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is a successful message sent
    if (strncmp(buf, "250", 3) != 0) {
        fprintf(stderr, "Expected successful message sent from SMTP server, but received: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Send the QUIT command to the SMTP server
    if (send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Get the response from the SMTP server
    nbytes = recv(sockfd, buf, sizeof(buf), 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is a successful QUIT
    if (strncmp(buf, "221", 3) != 0) {
        fprintf(stderr, "Expected successful QUIT from SMTP server, but received: %s\n", buf);
        return EXIT_FAILURE;
    }

    // Close the socket
    if (close(sockfd) == -1) {
        perror("close");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}