//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc!= 3) {
        printf("Usage: %s <SMTP Server IP/Domain> <Email Address>\n", argv[0]);
        return 1;
    }

    char *smtp_server = argv[1];
    char *email_address = argv[2];

    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error: Could not create socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);

    if (inet_pton(AF_INET, smtp_server, &server_addr.sin_addr) <= 0) {
        printf("Error: Invalid SMTP Server IP/Domain\n");
        close(sock);
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to SMTP Server\n");
        close(sock);
        return 1;
    }

    printf("Connected to SMTP Server: %s\n", smtp_server);

    char *helo = "HELO ";
    char *mail_from = "MAIL FROM:<";
    char *rcpt_to = "RCPT TO:<";
    char *data = "DATA\r\n";
    char *subject = "Subject: Test Email\r\n";
    char *body = "This is a test email sent using a SMTP client program.\r\n";
    char *quit = "QUIT\r\n";

    send(sock, helo, strlen(helo), 0);
    send(sock, smtp_server, strlen(smtp_server), 0);

    send(sock, mail_from, strlen(mail_from), 0);
    send(sock, email_address, strlen(email_address), 0);

    send(sock, rcpt_to, strlen(rcpt_to), 0);
    send(sock, email_address, strlen(email_address), 0);

    send(sock, data, strlen(data), 0);

    send(sock, subject, strlen(subject), 0);
    send(sock, body, strlen(body), 0);

    send(sock, quit, strlen(quit), 0);

    close(sock);

    printf("Email sent successfully!\n");

    return 0;
}