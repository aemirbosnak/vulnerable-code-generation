//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#define SMTP_PORT 25

int main(int argc, char **argv)
{
    // Check if the number of arguments is correct.
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <hostname> <email>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname and email address from the command line arguments.
    char *hostname = argv[1];
    char *email = argv[2];

    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the hostname.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL)
    {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the HELO command.
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "HELO %s\r\n", hostname);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is OK.
    if (strncmp(buffer, "250", 3) != 0)
    {
        fprintf(stderr, "Error: %s\n", buffer);
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command.
    snprintf(buffer, sizeof(buffer), "MAIL FROM: <%s>\r\n", email);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is OK.
    if (strncmp(buffer, "250", 3) != 0)
    {
        fprintf(stderr, "Error: %s\n", buffer);
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command.
    snprintf(buffer, sizeof(buffer), "RCPT TO: <%s>\r\n", email);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is OK.
    if (strncmp(buffer, "250", 3) != 0)
    {
        fprintf(stderr, "Error: %s\n", buffer);
        return EXIT_FAILURE;
    }

    // Send the DATA command.
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is OK.
    if (strncmp(buffer, "354", 3) != 0)
    {
        fprintf(stderr, "Error: %s\n", buffer);
        return EXIT_FAILURE;
    }

    // Send the email message.
    snprintf(buffer, sizeof(buffer), "From: %s\r\nTo: %s\r\nSubject: Test email\r\n\r\nThis is a test email.\r\n.\r\n", email, email);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the SMTP server.
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the response is OK.
    if (strncmp(buffer, "250", 3) != 0)
    {
        fprintf(stderr, "Error: %s\n", buffer);
        return EXIT_FAILURE;
    }

    // Send the QUIT command.
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}