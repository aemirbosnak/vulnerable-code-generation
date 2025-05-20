//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <smtp_server> <sender_email> <recipient_email> <message_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the SMTP server address
    char *smtp_server = argv[1];

    // Get the sender's email address
    char *sender_email = argv[2];

    // Get the recipient's email address
    char *recipient_email = argv[3];

    // Get the message file
    char *message_file = argv[4];

    // Open a socket to the SMTP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    if (inet_aton(smtp_server, &server_addr.sin_addr) == 0) {
        perror("inet_aton");
        return EXIT_FAILURE;
    }

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Read the greeting from the SMTP server
    char greeting[MAX_LINE_LENGTH];
    if (recv(sock, greeting, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the HELO command
    char helo_command[MAX_LINE_LENGTH];
    snprintf(helo_command, MAX_LINE_LENGTH, "HELO localhost\r\n");
    if (send(sock, helo_command, strlen(helo_command), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response to the HELO command
    char helo_response[MAX_LINE_LENGTH];
    if (recv(sock, helo_response, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the MAIL FROM command
    char mail_from_command[MAX_LINE_LENGTH];
    snprintf(mail_from_command, MAX_LINE_LENGTH, "MAIL FROM: <%s>\r\n", sender_email);
    if (send(sock, mail_from_command, strlen(mail_from_command), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response to the MAIL FROM command
    char mail_from_response[MAX_LINE_LENGTH];
    if (recv(sock, mail_from_response, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the RCPT TO command
    char rcpt_to_command[MAX_LINE_LENGTH];
    snprintf(rcpt_to_command, MAX_LINE_LENGTH, "RCPT TO: <%s>\r\n", recipient_email);
    if (send(sock, rcpt_to_command, strlen(rcpt_to_command), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response to the RCPT TO command
    char rcpt_to_response[MAX_LINE_LENGTH];
    if (recv(sock, rcpt_to_response, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the DATA command
    char data_command[MAX_LINE_LENGTH];
    strcpy(data_command, "DATA\r\n");
    if (send(sock, data_command, strlen(data_command), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response to the DATA command
    char data_response[MAX_LINE_LENGTH];
    if (recv(sock, data_response, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Open the message file
    FILE *message_file_ptr = fopen(message_file, "r");
    if (message_file_ptr == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Send the message
    char message[MAX_LINE_LENGTH];
    while (fgets(message, MAX_LINE_LENGTH, message_file_ptr) != NULL) {
        if (send(sock, message, strlen(message), 0) <= 0) {
            perror("send");
            return EXIT_FAILURE;
        }
    }

    // Send a period to indicate the end of the message
    char period[2];
    strcpy(period, ".\r\n");
    if (send(sock, period, strlen(period), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response to the message
    char message_response[MAX_LINE_LENGTH];
    if (recv(sock, message_response, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Send the QUIT command
    char quit_command[MAX_LINE_LENGTH];
    strcpy(quit_command, "QUIT\r\n");
    if (send(sock, quit_command, strlen(quit_command), 0) <= 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Read the response to the QUIT command
    char quit_response[MAX_LINE_LENGTH];
    if (recv(sock, quit_response, MAX_LINE_LENGTH, 0) <= 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sock);

    return EXIT_SUCCESS;
}