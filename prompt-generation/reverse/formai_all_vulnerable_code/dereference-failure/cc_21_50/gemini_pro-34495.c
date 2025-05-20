//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s <sender> <recipient> <subject> <body>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
    {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr) != 1)
    {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the server's greeting
    char line[MAX_LINE_LENGTH + 1];
    if (recv(sock, line, MAX_LINE_LENGTH, 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the HELO command
    snprintf(line, sizeof(line), "HELO localhost\r\n");
    if (send(sock, line, strlen(line), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    if (recv(sock, line, MAX_LINE_LENGTH, 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    snprintf(line, sizeof(line), "MAIL FROM: <%s>\r\n", argv[1]);
    if (send(sock, line, strlen(line), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    if (recv(sock, line, MAX_LINE_LENGTH, 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    snprintf(line, sizeof(line), "RCPT TO: <%s>\r\n", argv[2]);
    if (send(sock, line, strlen(line), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    if (recv(sock, line, MAX_LINE_LENGTH, 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the DATA command
    snprintf(line, sizeof(line), "DATA\r\n");
    if (send(sock, line, strlen(line), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    if (recv(sock, line, MAX_LINE_LENGTH, 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the email's header
    snprintf(line, sizeof(line), "From: %s\r\n", argv[1]);
    if (send(sock, line, strlen(line), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    snprintf(line, sizeof(line), "To: %s\r\n", argv[2]);
    if (send(sock, line, strlen(line), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    snprintf(line, sizeof(line), "Subject: %s\r\n", argv[3]);
    if (send(sock, line, strlen(line), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    snprintf(line, sizeof(line), "\r\n");
    if (send(sock, line, strlen(line), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the email's body
    if (send(sock, argv[4], strlen(argv[4]), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Send the end of the email
    snprintf(line, sizeof(line), ".\r\n");
    if (send(sock, line, strlen(line), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the server's response
    if (recv(sock, line, MAX_LINE_LENGTH, 0) == -1)
    {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    snprintf(line, sizeof(line), "QUIT\r\n");
    if (send(sock, line, strlen(line), 0) == -1)
    {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}