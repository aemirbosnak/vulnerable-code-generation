//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the SMTP port
#define SMTP_PORT 25

// Define the maximum size of the email message
#define MAX_EMAIL_SIZE 1024

// Define the maximum size of the SMTP command buffer
#define MAX_SMTP_COMMAND_SIZE 128

// Define the SMTP commands
#define SMTP_COMMAND_HELO "HELO example.com\r\n"
#define SMTP_COMMAND_MAIL_FROM "MAIL FROM: <sender@example.com>\r\n"
#define SMTP_COMMAND_RCPT_TO "RCPT TO: <recipient@example.com>\r\n"
#define SMTP_COMMAND_DATA "DATA\r\n"
#define SMTP_COMMAND_QUIT "QUIT\r\n"

// Define the SMTP response codes
#define SMTP_RESPONSE_250 "250 OK"
#define SMTP_RESPONSE_550 "550 Requested action not taken: mailbox unavailable"

// Send an SMTP command to the server
int send_smtp_command(int sockfd, char *command)
{
    int len = strlen(command);

    // Send the command to the server
    if (send(sockfd, command, len, 0) != len)
    {
        perror("send");
        return -1;
    }

    // Receive the response from the server
    char response[MAX_SMTP_COMMAND_SIZE];
    if (recv(sockfd, response, MAX_SMTP_COMMAND_SIZE, 0) <= 0)
    {
        perror("recv");
        return -1;
    }

    // Check the response code
    if (strncmp(response, SMTP_RESPONSE_250, strlen(SMTP_RESPONSE_250)) != 0)
    {
        fprintf(stderr, "Error: SMTP server returned error code %s\n", response);
        return -1;
    }

    return 0;
}

// Send an email message to the server
int send_email(int sockfd, char *from, char *to, char *message)
{
    // Send the HELO command
    if (send_smtp_command(sockfd, SMTP_COMMAND_HELO) != 0)
    {
        return -1;
    }

    // Send the MAIL FROM command
    if (send_smtp_command(sockfd, SMTP_COMMAND_MAIL_FROM) != 0)
    {
        return -1;
    }

    // Send the RCPT TO command
    if (send_smtp_command(sockfd, SMTP_COMMAND_RCPT_TO) != 0)
    {
        return -1;
    }

    // Send the DATA command
    if (send_smtp_command(sockfd, SMTP_COMMAND_DATA) != 0)
    {
        return -1;
    }

    // Send the email message
    if (send(sockfd, message, strlen(message), 0) != strlen(message))
    {
        perror("send");
        return -1;
    }

    // Send the .\r\n command to terminate the email message
    if (send(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"), 0) != strlen("\r\n.\r\n"))
    {
        perror("send");
        return -1;
    }

    // Send the QUIT command
    if (send_smtp_command(sockfd, SMTP_COMMAND_QUIT) != 0)
    {
        return -1;
    }

    return 0;
}

// Main function
int main(int argc, char *argv[])
{
    // Check if the correct number of arguments was provided
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <from> <to> <message>\n", argv[0]);
        return 1;
    }

    // Get the sender, recipient, and message from the command line arguments
    char *from = argv[1];
    char *to = argv[2];
    char *message = argv[3];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        perror("socket");
        return 1;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        perror("connect");
        return 1;
    }

    // Send the email message
    if (send_email(sockfd, from, to, message) != 0)
    {
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}