//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: Linus Torvalds
// Compiling this code is easy, just remember to link against the necessary libraries
// gcc smtp_client.c -o smtp_client -lssl -lcrypto

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define SMTP_PORT 25
#define SMTP_SSL_PORT 465

// This function sends a command to the SMTP server
int send_command(SSL *ssl, const char *command)
{
    int len = strlen(command);
    int ret = SSL_write(ssl, command, len);
    if (ret <= 0) {
        ERR_print_errors_fp(stderr);
        return -1;
    }
    return 0;
}

// This function receives a response from the SMTP server
int receive_response(SSL *ssl, char *buf, int buf_size)
{
    int ret = SSL_read(ssl, buf, buf_size);
    if (ret <= 0) {
        ERR_print_errors_fp(stderr);
        return -1;
    }
    buf[ret] = '\0';
    return 0;
}

// This function sends an email message
int send_email(SSL *ssl, const char *from, const char *to, const char *subject, const char *message)
{
    // Send the HELO command
    if (send_command(ssl, "HELO localhost\r\n") != 0) {
        return -1;
    }

    // Receive the HELO response
    char buf[1024];
    if (receive_response(ssl, buf, sizeof(buf)) != 0) {
        return -1;
    }

    // Send the MAIL FROM command
    snprintf(buf, sizeof(buf), "MAIL FROM: <%s>\r\n", from);
    if (send_command(ssl, buf) != 0) {
        return -1;
    }

    // Receive the MAIL FROM response
    if (receive_response(ssl, buf, sizeof(buf)) != 0) {
        return -1;
    }

    // Send the RCPT TO command
    snprintf(buf, sizeof(buf), "RCPT TO: <%s>\r\n", to);
    if (send_command(ssl, buf) != 0) {
        return -1;
    }

    // Receive the RCPT TO response
    if (receive_response(ssl, buf, sizeof(buf)) != 0) {
        return -1;
    }

    // Send the DATA command
    if (send_command(ssl, "DATA\r\n") != 0) {
        return -1;
    }

    // Receive the DATA response
    if (receive_response(ssl, buf, sizeof(buf)) != 0) {
        return -1;
    }

    // Send the email message
    snprintf(buf, sizeof(buf), "From: %s\r\n", from);
    if (send_command(ssl, buf) != 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "To: %s\r\n", to);
    if (send_command(ssl, buf) != 0) {
        return -1;
    }

    snprintf(buf, sizeof(buf), "Subject: %s\r\n", subject);
    if (send_command(ssl, buf) != 0) {
        return -1;
    }

    if (send_command(ssl, "\r\n") != 0) {
        return -1;
    }

    if (send_command(ssl, message) != 0) {
        return -1;
    }

    if (send_command(ssl, "\r\n.\r\n") != 0) {
        return -1;
    }

    // Receive the DATA response
    if (receive_response(ssl, buf, sizeof(buf)) != 0) {
        return -1;
    }

    // Send the QUIT command
    if (send_command(ssl, "QUIT\r\n") != 0) {
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[])
{
    // Initialize the OpenSSL library
    SSL_library_init();

    // Create a new SSL context
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        return -1;
    }

    // Create a new SSL connection
    SSL *ssl = SSL_new(ctx);
    if (ssl == NULL) {
        ERR_print_errors_fp(stderr);
        SSL_CTX_free(ctx);
        return -1;
    }

    // Connect to the SMTP server
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SMTP_PORT);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (connect(SSL_get_fd(ssl), (struct sockaddr *)&addr, sizeof(addr)) != 0) {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return -1;
    }

    // Perform the SMTP handshake
    if (SSL_connect(ssl) != 1) {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return -1;
    }

    // Send an email message
    if (send_email(ssl, "from@example.com", "to@example.com", "Test email", "This is a test email\n") != 0) {
        ERR_print_errors_fp(stderr);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return -1;
    }

    // Close the SMTP connection
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return 0;
}