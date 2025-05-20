//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SMTP_PORT 25

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <smtp_server> <sender_email> <recipient_email>\n", argv[0]);
        exit(1);
    }

    char *smtp_server = argv[1];
    char *sender_email = argv[2];
    char *recipient_email = argv[3];

    // Get the IP address of the SMTP server
    struct hostent *host = gethostbyname(smtp_server);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname '%s'\n", smtp_server);
        exit(1);
    }

    // Create a socket and connect to the SMTP server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error: could not create socket");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SMTP_PORT);
    addr.sin_addr = *(struct in_addr *) host->h_addr;

    if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) == -1) {
        perror("Error: could not connect to SMTP server");
        exit(1);
    }

    // Read the greeting from the SMTP server
    char buf[1024];
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("Error: could not read greeting from SMTP server");
        exit(1);
    }

    printf("Greeting: %s\n", buf);

    // Send the HELO command
    snprintf(buf, sizeof(buf), "HELO localhost\r\n");
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error: could not send HELO command");
        exit(1);
    }

    // Read the response from the SMTP server
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("Error: could not read response to HELO command");
        exit(1);
    }

    printf("Response to HELO: %s\n", buf);

    // Send the MAIL FROM command
    snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", sender_email);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error: could not send MAIL FROM command");
        exit(1);
    }

    // Read the response from the SMTP server
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("Error: could not read response to MAIL FROM command");
        exit(1);
    }

    printf("Response to MAIL FROM: %s\n", buf);

    // Send the RCPT TO command
    snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", recipient_email);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error: could not send RCPT TO command");
        exit(1);
    }

    // Read the response from the SMTP server
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("Error: could not read response to RCPT TO command");
        exit(1);
    }

    printf("Response to RCPT TO: %s\n", buf);

    // Send the DATA command
    snprintf(buf, sizeof(buf), "DATA\r\n");
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error: could not send DATA command");
        exit(1);
    }

    // Read the response from the SMTP server
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("Error: could not read response to DATA command");
        exit(1);
    }

    printf("Response to DATA: %s\n", buf);

    // Send the email message
    snprintf(buf, sizeof(buf), "From: %s\r\n", sender_email);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error: could not send email message");
        exit(1);
    }

    snprintf(buf, sizeof(buf), "To: %s\r\n", recipient_email);
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error: could not send email message");
        exit(1);
    }

    snprintf(buf, sizeof(buf), "Subject: Test email\r\n");
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error: could not send email message");
        exit(1);
    }

    snprintf(buf, sizeof(buf), "\r\nThis is a test email.\r\n");
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error: could not send email message");
        exit(1);
    }

    // Send the end of the email message
    snprintf(buf, sizeof(buf), ".\r\n");
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error: could not send end of email message");
        exit(1);
    }

    // Read the response from the SMTP server
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("Error: could not read response to end of email message");
        exit(1);
    }

    printf("Response to end of email message: %s\n", buf);

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    if (send(sock, buf, strlen(buf), 0) == -1) {
        perror("Error: could not send QUIT command");
        exit(1);
    }

    // Read the response from the SMTP server
    if (recv(sock, buf, sizeof(buf), 0) == -1) {
        perror("Error: could not read response to QUIT command");
        exit(1);
    }

    printf("Response to QUIT: %s\n", buf);

    // Close the socket
    close(sock);

    return 0;
}