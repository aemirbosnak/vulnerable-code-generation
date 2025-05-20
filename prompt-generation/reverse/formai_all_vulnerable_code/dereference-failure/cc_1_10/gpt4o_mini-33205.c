//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 587
#define BUFFER_SIZE 1024

void handleError(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int createSocket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        handleError("Socket creation failed");
    }
    return sock;
}

void connectToServer(int sock, const char *hostname) {
    struct sockaddr_in server_addr;
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        handleError("Host lookup failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        handleError("Connection to server failed");
    }
}

void sendCommand(int sock, const char *cmd, char *response, size_t responseSize) {
    send(sock, cmd, strlen(cmd), 0);
    send(sock, "\r\n", 2, 0);
    recv(sock, response, responseSize - 1, 0);
}

void sendEmail(int sock, const char *from, const char *to, const char *subject, const char *body) {
    char response[BUFFER_SIZE];

    sendCommand(sock, "HELO localhost", response, sizeof(response));
    printf("Server response: %s\n", response);

    sendCommand(sock, "MAIL FROM:<", response, sizeof(response));
    printf("Server response: %s\n", response);

    send(sock, from, strlen(from), 0);
    send(sock, ">\r\n", 4, 0);
    recv(sock, response, sizeof(response) - 1, 0);
    printf("Server response: %s\n", response);

    sendCommand(sock, "RCPT TO:<", response, sizeof(response));
    printf("Server response: %s\n", response);

    send(sock, to, strlen(to), 0);
    send(sock, ">\r\n", 4, 0);
    recv(sock, response, sizeof(response) - 1, 0);
    printf("Server response: %s\n", response);

    sendCommand(sock, "DATA", response, sizeof(response));
    printf("Server response: %s\n", response);

    send(sock, "Subject: ", 9, 0);
    send(sock, subject, strlen(subject), 0);
    send(sock, "\r\n\r\n", 4, 0);
    send(sock, body, strlen(body), 0);
    send(sock, "\r\n.\r\n", 5, 0);
    recv(sock, response, sizeof(response) - 1, 0);
    printf("Server response: %s\n", response);

    sendCommand(sock, "QUIT", response, sizeof(response));
    printf("Server response: %s\n", response);
}

int main() {
    const char *smtpServer = "smtp.example.com"; // Replace with your SMTP server
    const char *from = "your_email@example.com"; // Replace with your email
    const char *to = "recipient_email@example.com"; // Replace with recipient email
    const char *subject = "Test Email from SMTP Client";
    const char *body = "Hello,\nThis is a test email sent from a C SMTP client.\nBest regards,\nYour Name";

    int sock = createSocket();
    connectToServer(sock, smtpServer);
    sendEmail(sock, from, to, subject, body);
    
    close(sock);
    return 0;
}