//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 587
#define MAX_BUF_SIZE 1024

// Function to send email
int send_email(char *mail_from, char *rcpt_to, char *subject, char *body) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    // Connect to the SMTP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return -1;
    }

    // Read the greeting from the server
    char buf[MAX_BUF_SIZE];
    if (read(sock, buf, MAX_BUF_SIZE) < 0) {
        perror("read");
        return -1;
    }

    // Send the HELO command
    sprintf(buf, "HELO localhost\r\n");
    if (write(sock, buf, strlen(buf)) < 0) {
        perror("write");
        return -1;
    }

    // Read the server's response
    if (read(sock, buf, MAX_BUF_SIZE) < 0) {
        perror("read");
        return -1;
    }

    // Send the MAIL FROM command
    sprintf(buf, "MAIL FROM: <%s>\r\n", mail_from);
    if (write(sock, buf, strlen(buf)) < 0) {
        perror("write");
        return -1;
    }

    // Read the server's response
    if (read(sock, buf, MAX_BUF_SIZE) < 0) {
        perror("read");
        return -1;
    }

    // Send the RCPT TO command
    sprintf(buf, "RCPT TO: <%s>\r\n", rcpt_to);
    if (write(sock, buf, strlen(buf)) < 0) {
        perror("write");
        return -1;
    }

    // Read the server's response
    if (read(sock, buf, MAX_BUF_SIZE) < 0) {
        perror("read");
        return -1;
    }

    // Send the DATA command
    sprintf(buf, "DATA\r\n");
    if (write(sock, buf, strlen(buf)) < 0) {
        perror("write");
        return -1;
    }

    // Read the server's response
    if (read(sock, buf, MAX_BUF_SIZE) < 0) {
        perror("read");
        return -1;
    }

    // Send the email body
    sprintf(buf, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    if (write(sock, buf, strlen(buf)) < 0) {
        perror("write");
        return -1;
    }

    // Read the server's response
    if (read(sock, buf, MAX_BUF_SIZE) < 0) {
        perror("read");
        return -1;
    }

    // Send the QUIT command
    sprintf(buf, "QUIT\r\n");
    if (write(sock, buf, strlen(buf)) < 0) {
        perror("write");
        return -1;
    }

    // Close the socket
    close(sock);

    return 0;
}

int main() {
    // Set the sender and recipient email addresses
    char *mail_from = "romeo@example.com";
    char *rcpt_to = "juliet@example.com";

    // Set the email subject and body
    char *subject = "A Message from Romeo";
    char *body = "My dearest Juliet,\n\nI write to you with a heavy heart, for I fear that our love is doomed. The feud between our families has driven us apart, and I fear that it will never end. But I cannot bear the thought of living without you, and I will do whatever it takes to be with you. \n\nYours forever,\nRomeo";

    // Send the email
    int res = send_email(mail_from, rcpt_to, subject, body);
    if (res != 0) {
        printf("Error sending email: %d\n", res);
        return -1;
    }

    return 0;
}