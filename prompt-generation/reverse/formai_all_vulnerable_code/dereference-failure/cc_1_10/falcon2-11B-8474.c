//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <errno.h>
#include <time.h>
#include <sys/socket.h>
#include <unistd.h>

// Define some constants
#define PORT 587
#define BUFSIZE 1024
#define FROM "sender@example.com"
#define TO "recipient@example.com"
#define SUBJECT "Test email"
#define BODY "This is a test email"

// Function to send an email using SMTP
void send_email(char *hostname, int port) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    // Set up the host name and port
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        perror("gethostbyname");
        exit(1);
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = *((unsigned long*)server->h_addr);

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the email
    char msg[BUFSIZE];
    strcpy(msg, "EHLO localhost\r\n");
    write(sock, msg, strlen(msg));

    strcpy(msg, "STARTTLS\r\n");
    write(sock, msg, strlen(msg));

    strcpy(msg, "TLS\r\n");
    write(sock, msg, strlen(msg));

    strcpy(msg, "MAIL FROM: ");
    strcat(msg, FROM);
    strcat(msg, "\r\n");
    write(sock, msg, strlen(msg));

    strcpy(msg, "RCPT TO: ");
    strcat(msg, TO);
    strcat(msg, "\r\n");
    write(sock, msg, strlen(msg));

    strcpy(msg, "DATA\r\n");
    write(sock, msg, strlen(msg));

    strcpy(msg, "From: ");
    strcat(msg, FROM);
    strcat(msg, "\r\n");
    strcat(msg, "To: ");
    strcat(msg, TO);
    strcat(msg, "\r\n");
    strcat(msg, "Subject: ");
    strcat(msg, SUBJECT);
    strcat(msg, "\r\n");
    strcat(msg, "This is a test email\r\n.\r\n");
    write(sock, msg, strlen(msg));

    strcpy(msg, "QUIT\r\n");
    write(sock, msg, strlen(msg));

    // Close the socket
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    // Send the email
    send_email(argv[1], PORT);

    return 0;
}