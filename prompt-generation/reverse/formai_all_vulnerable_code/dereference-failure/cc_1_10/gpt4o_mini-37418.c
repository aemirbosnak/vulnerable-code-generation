//GPT-4o-mini DATASET v1.0 Category: Building a SMTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int smtp_connect(const char *server) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Get the host by the server name
    host = gethostbyname(server);
    if (host == NULL) {
        error("ERROR, no such host");
    }

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        error("ERROR opening socket");
    }

    // Set up the server address structure
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("ERROR connecting");
    }
    return sock;
}

void smtp_send(int sock, const char *msg) {
    if (send(sock, msg, strlen(msg), 0) < 0) {
        error("ERROR sending data");
    }
}

void smtp_receive(int sock, char *buffer, size_t size) {
    bzero(buffer, size);
    if (recv(sock, buffer, size - 1, 0) < 0) {
        error("ERROR receiving data");
    }
}

void smtp_helo(int sock) {
    char buffer[BUFFER_SIZE];
    smtp_send(sock, "HELO localhost\r\n");
    smtp_receive(sock, buffer, sizeof(buffer));
    printf("Server Response: %s", buffer);
}

void smtp_mail(int sock, const char *from) {
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "MAIL FROM:<%s>\r\n", from);
    smtp_send(sock, command);
    smtp_receive(sock, buffer, sizeof(buffer));
    printf("Server Response: %s", buffer);
}

void smtp_rcpt(int sock, const char *to) {
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];

    snprintf(command, sizeof(command), "RCPT TO:<%s>\r\n", to);
    smtp_send(sock, command);
    smtp_receive(sock, buffer, sizeof(buffer));
    printf("Server Response: %s", buffer);
}

void smtp_data(int sock) {
    char buffer[BUFFER_SIZE];
    smtp_send(sock, "DATA\r\n");
    smtp_receive(sock, buffer, sizeof(buffer));
    printf("Server Response: %s", buffer);
    
    // Provide the message data
    smtp_send(sock, "Subject: Test Email\r\n");
    smtp_send(sock, "\r\nThis is a test email sent from a simple SMTP client.\r\n.\r\n");
    
    smtp_receive(sock, buffer, sizeof(buffer));
    printf("Server Response: %s", buffer);
}

void smtp_quit(int sock) {
    char buffer[BUFFER_SIZE];
    smtp_send(sock, "QUIT\r\n");
    smtp_receive(sock, buffer, sizeof(buffer));
    printf("Server Response: %s", buffer);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <smtp_server> <from_email> <to_email>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *smtp_server = argv[1];
    const char *from_email = argv[2];
    const char *to_email = argv[3];

    int sock = smtp_connect(smtp_server);

    smtp_helo(sock);
    smtp_mail(sock, from_email);
    smtp_rcpt(sock, to_email);
    smtp_data(sock);
    smtp_quit(sock);

    close(sock);
    return 0;
}