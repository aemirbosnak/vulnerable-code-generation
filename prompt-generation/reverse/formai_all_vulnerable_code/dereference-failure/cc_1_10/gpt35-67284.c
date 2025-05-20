//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: light-weight
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#include <openssl/ssl.h>
#include <openssl/err.h>

#define SMTP_PORT       25
#define BUF_LEN         1024

int main(int argc, char **argv) {
    char *hostname;
    char *sender_email;
    char *recipient_email;
    char *subject;
    char *body;

    if (argc != 6) {
        printf("Usage: %s <hostname> <sender_email> <recipient_email> <subject> <body>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];
    sender_email = argv[2];
    recipient_email = argv[3];
    subject = argv[4];
    body = argv[5];

    // Set up SSL
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());

    // Connect to server
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *he;

    if ((he = gethostbyname(hostname)) == NULL) {
        perror("gethostbyname");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    server_addr.sin_port = htons(SMTP_PORT);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // SSL handshake
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock);
    if (SSL_connect(ssl) <= 0) {
        ERR_print_errors_fp(stderr);
        return 1;
    }

    // Send email
    char buf[BUF_LEN];
    int len;

    // Read initial greeting
    SSL_read(ssl, buf, BUF_LEN);

    // Send EHLO
    snprintf(buf, BUF_LEN, "EHLO %s\r\n", hostname);
    SSL_write(ssl, buf, strlen(buf));

    // Read response
    SSL_read(ssl, buf, BUF_LEN);

    // Send MAIL FROM
    snprintf(buf, BUF_LEN, "MAIL FROM: <%s>\r\n", sender_email);
    SSL_write(ssl, buf, strlen(buf));

    // Read response
    SSL_read(ssl, buf, BUF_LEN);

    // Send RCPT TO
    snprintf(buf, BUF_LEN, "RCPT TO: <%s>\r\n", recipient_email);
    SSL_write(ssl, buf, strlen(buf));

    // Read response
    SSL_read(ssl, buf, BUF_LEN);

    // Send DATA
    SSL_write(ssl, "DATA\r\n", 6);

    // Read response
    SSL_read(ssl, buf, BUF_LEN);

    // Send message headers
    snprintf(buf, BUF_LEN, "From: <%s>\r\n", sender_email);
    SSL_write(ssl, buf, strlen(buf));

    snprintf(buf, BUF_LEN, "To: <%s>\r\n", recipient_email);
    SSL_write(ssl, buf, strlen(buf));

    snprintf(buf, BUF_LEN, "Subject: %s\r\n", subject);
    SSL_write(ssl, buf, strlen(buf));

    // Send message body
    SSL_write(ssl, "\r\n", 2);
    SSL_write(ssl, body, strlen(body));

    // Send message termination
    SSL_write(ssl, "\r\n.\r\n", 5);

    // Read response
    SSL_read(ssl, buf, BUF_LEN);

    // Send QUIT
    SSL_write(ssl, "QUIT\r\n", 6);

    // Read response
    SSL_read(ssl, buf, BUF_LEN);

    // Disconnect
    SSL_shutdown(ssl);
    close(sock);

    // Clean up SSL
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return 0;
}