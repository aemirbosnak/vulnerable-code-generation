//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define SMTP_PORT 25
#define CRLF "\r\n"

// Function to send a command to the SMTP server and read the response
void send_command(int sock, char *command) {
    int n = 0;
    char response[MAX_LINE];

    write(sock, command, strlen(command));
    write(sock, CRLF, strlen(CRLF));

    while ((n = read(sock, response, MAX_LINE)) > 0) {
        response[n - 1] = '\0';
        printf("%s", response);
        if (response[n - 2] == '.') {
            printf("\n");
            break;
        }
    }
}

// Function to send an email
void send_email(int sock, char *to, char *subject, char *body) {
    char command[MAX_LINE];

    sprintf(command, "MAIL FROM:<%s>%s", "sender@example.com", CRLF);
    send_command(sock, command);

    sprintf(command, "RCPT TO:<%s>%s", to, CRLF);
    send_command(sock, command);

    sprintf(command, "DATA%s", CRLF);
    send_command(sock, command);

    sprintf(command, "Subject: %s%s", subject, CRLF);
    send_command(sock, command);

    sprintf(command, "%s%s", body, CRLF);
    send_command(sock, command);

    sprintf(command, ".%s", CRLF);
    send_command(sock, command);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *to = "recipient@example.com";
    char *subject = "Test Email";
    char *body = "This is a test email sent from a C program.";

    if (argc!= 4) {
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server.\n");
        return 1;
    }

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    send_email(sock, to, subject, body);

    close(sock);

    return 0;
}