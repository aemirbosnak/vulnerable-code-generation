//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;
    char buffer[BUF_SIZE];

    // Get server address
    if ((host = gethostbyname("smtp.example.com")) == NULL) {
        fprintf(stderr, "Error: Invalid hostname\n");
        return 1;
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        fprintf(stderr, "Error: Could not create socket\n");
        return 1;
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error: Could not connect to server\n");
        return 1;
    }

    // Send HELO command
    send(sock, "HELO example.com\r\n", strlen("HELO example.com\r\n"), 0);

    // Send MAIL FROM command
    send(sock, "MAIL FROM:<sender@example.com>\r\n", strlen("MAIL FROM:<sender@example.com>\r\n"), 0);

    // Send RCPT TO command
    send(sock, "RCPT TO:<recipient@example.com>\r\n", strlen("RCPT TO:<recipient@example.com>\r\n"), 0);

    // Send DATA command
    send(sock, "DATA\r\n", strlen("DATA\r\n"), 0);

    // Send message body
    send(sock, "Subject: Test Message\r\n\r\nThis is a test message.\r\n.\r\n", strlen("Subject: Test Message\r\n\r\nThis is a test message.\r\n.\r\n"), 0);

    // Close connection
    close(sock);

    return 0;
}