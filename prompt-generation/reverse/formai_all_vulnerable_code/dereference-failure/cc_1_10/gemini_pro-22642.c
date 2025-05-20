//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <regex.h>

typedef struct Email {
    char *from;
    char *to;
    char *subject;
    char *body;
} Email;

typedef struct EmailClient {
    Email *email;
    char *host;
    int port;
} EmailClient;

EmailClient *create_email(char *from, char *to, char *subject, char *body) {
    EmailClient *email_client = (EmailClient *)malloc(sizeof(EmailClient));
    email_client->email = (Email *)malloc(sizeof(Email));
    email_client->email->from = strdup(from);
    email_client->email->to = strdup(to);
    email_client->email->subject = strdup(subject);
    email_client->email->body = strdup(body);
    return email_client;
}

void send_email(EmailClient *email_client) {
    // Connect to the SMTP server
    FILE *smtp_connection = fopen(email_client->host, "w");
    if (smtp_connection == NULL) {
        perror("Error connecting to SMTP server");
        return;
    }

    // Send the HELO command
    fprintf(smtp_connection, "HELO mydomain.com\r\n");
    char response[1024];
    fgets(response, sizeof(response), smtp_connection);
    if (strncmp(response, "250", 3) != 0) {
        fprintf(stderr, "Error sending HELO command: %s", response);
        return;
    }

    // Send the MAIL FROM command
    fprintf(smtp_connection, "MAIL FROM: %s\r\n", email_client->email->from);
    fgets(response, sizeof(response), smtp_connection);
    if (strncmp(response, "250", 3) != 0) {
        fprintf(stderr, "Error sending MAIL FROM command: %s", response);
        return;
    }

    // Send the RCPT TO command
    fprintf(smtp_connection, "RCPT TO: %s\r\n", email_client->email->to);
    fgets(response, sizeof(response), smtp_connection);
    if (strncmp(response, "250", 3) != 0) {
        fprintf(stderr, "Error sending RCPT TO command: %s", response);
        return;
    }

    // Send the DATA command
    fprintf(smtp_connection, "DATA\r\n");
    fgets(response, sizeof(response), smtp_connection);
    if (strncmp(response, "354", 3) != 0) {
        fprintf(stderr, "Error sending DATA command: %s", response);
        return;
    }

    // Send the email headers
    fprintf(smtp_connection, "From: %s\r\n", email_client->email->from);
    fprintf(smtp_connection, "To: %s\r\n", email_client->email->to);
    fprintf(smtp_connection, "Subject: %s\r\n", email_client->email->subject);
    fprintf(smtp_connection, "\r\n");

    // Send the email body
    fprintf(smtp_connection, "%s\r\n", email_client->email->body);

    // Send the QUIT command
    fprintf(smtp_connection, "QUIT\r\n");
    fgets(response, sizeof(response), smtp_connection);
    if (strncmp(response, "221", 3) != 0) {
        fprintf(stderr, "Error sending QUIT command: %s", response);
        return;
    }

    // Close the connection to the SMTP server
    fclose(smtp_connection);
}

bool is_valid_email_address(char *email_address) {
    // Compile the regular expression
    regex_t re;
    int err = regcomp(&re, "^[a-zA-Z0-9.!#$%&'*+/=?^_`{|}~-]+@[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(?:\\.[a-zA-Z0-9](?:[a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*$", REG_EXTENDED);
    if (err != 0) {
        fprintf(stderr, "Error compiling regular expression: %s", strerror(err));
        return false;
    }

    // Perform the matching
    regmatch_t match;
    int status = regexec(&re, email_address, 1, &match, 0);
    regfree(&re);

    // Check the matching status
    return status == 0;
}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s from to subject body\n", argv[0]);
        return 1;
    }

    char *from = argv[1];
    if (!is_valid_email_address(from)) {
        fprintf(stderr, "Error: Invalid 'from' email address: %s\n", from);
        return 1;
    }

    char *to = argv[2];
    if (!is_valid_email_address(to)) {
        fprintf(stderr, "Error: Invalid 'to' email address: %s\n", to);
        return 1;
    }

    char *subject = argv[3];
    char *body = argv[4];

    EmailClient *email_client = create_email(from, to, subject, body);
    email_client->host = "smtp.example.com";
    email_client->port = 25;

    send_email(email_client);

    return 0;
}