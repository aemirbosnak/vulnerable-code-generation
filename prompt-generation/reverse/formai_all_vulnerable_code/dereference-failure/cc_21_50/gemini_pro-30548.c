//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

// Define the SMTP port
#define SMTP_PORT 25

// Define the maximum buffer size
#define MAX_BUFFER_SIZE 1024

// Define the SMTP commands
#define HELO "HELO %s\r\n"
#define MAIL_FROM "MAIL FROM: <%s>\r\n"
#define RCPT_TO "RCPT TO: <%s>\r\n"
#define DATA "DATA\r\n"
#define QUIT "QUIT\r\n"

// Define the email headers
#define SUBJECT "Subject: %s\r\n"
#define FROM "From: %s\r\n"
#define TO "To: %s\r\n"

// Define the number of arguments
#define NUM_ARGS 5

// Main function
int main(int argc, char *argv[])
{
    // Check the number of arguments
    if (argc != NUM_ARGS)
    {
        printf("Usage: %s <smtp_server> <sender_email> <recipient_email> <subject> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the SMTP server address
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL)
    {
        printf("Error: could not resolve hostname %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create the SMTP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error: could not create socket\n");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        printf("Error: could not connect to server\n");
        return EXIT_FAILURE;
    }

    // Read the welcome message
    char buffer[MAX_BUFFER_SIZE];
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0)
    {
        printf("Error: could not read welcome message\n");
        return EXIT_FAILURE;
    }

    // Send the HELO command
    snprintf(buffer, MAX_BUFFER_SIZE, HELO, argv[0]);
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        printf("Error: could not send HELO command\n");
        return EXIT_FAILURE;
    }

    // Read the response to the HELO command
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0)
    {
        printf("Error: could not read response to HELO command\n");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    snprintf(buffer, MAX_BUFFER_SIZE, MAIL_FROM, argv[2]);
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        printf("Error: could not send MAIL FROM command\n");
        return EXIT_FAILURE;
    }

    // Read the response to the MAIL FROM command
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0)
    {
        printf("Error: could not read response to MAIL FROM command\n");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    snprintf(buffer, MAX_BUFFER_SIZE, RCPT_TO, argv[3]);
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        printf("Error: could not send RCPT TO command\n");
        return EXIT_FAILURE;
    }

    // Read the response to the RCPT TO command
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0)
    {
        printf("Error: could not read response to RCPT TO command\n");
        return EXIT_FAILURE;
    }

    // Send the DATA command
    if (write(sockfd, DATA, strlen(DATA)) < 0)
    {
        printf("Error: could not send DATA command\n");
        return EXIT_FAILURE;
    }

    // Read the response to the DATA command
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0)
    {
        printf("Error: could not read response to DATA command\n");
        return EXIT_FAILURE;
    }

    // Send the email headers
    snprintf(buffer, MAX_BUFFER_SIZE, SUBJECT, argv[4]);
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        printf("Error: could not send email subject\n");
        return EXIT_FAILURE;
    }

    snprintf(buffer, MAX_BUFFER_SIZE, FROM, argv[2]);
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        printf("Error: could not send email from address\n");
        return EXIT_FAILURE;
    }

    snprintf(buffer, MAX_BUFFER_SIZE, TO, argv[3]);
    if (write(sockfd, buffer, strlen(buffer)) < 0)
    {
        printf("Error: could not send email to address\n");
        return EXIT_FAILURE;
    }

    // Send the email message
    if (write(sockfd, argv[5], strlen(argv[5])) < 0)
    {
        printf("Error: could not send email message\n");
        return EXIT_FAILURE;
    }

    // Send the end of message marker
    if (write(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n")) < 0)
    {
        printf("Error: could not send end of message marker\n");
        return EXIT_FAILURE;
    }

    // Read the response to the end of message marker
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0)
    {
        printf("Error: could not read response to end of message marker\n");
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    if (write(sockfd, QUIT, strlen(QUIT)) < 0)
    {
        printf("Error: could not send QUIT command\n");
        return EXIT_FAILURE;
    }

    // Read the response to the QUIT command
    if (read(sockfd, buffer, MAX_BUFFER_SIZE) < 0)
    {
        printf("Error: could not read response to QUIT command\n");
        return EXIT_FAILURE;
    }

    // Close the SMTP socket
    close(sockfd);

    return EXIT_SUCCESS;
}