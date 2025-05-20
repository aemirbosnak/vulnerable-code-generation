//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 587
#define BUFFER_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void send_email(const char *smtp_server, const char *from, const char *to, const char *subject, const char *body) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    SSL_CTX *ctx;
    SSL *ssl;
    char buffer[BUFFER_SIZE];

    // Initialize OpenSSL
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();
    ctx = SSL_CTX_new(TLS_client_method());
    
    // Create a socket and connect to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) error("ERROR opening socket");
    
    server = gethostbyname(smtp_server);
    if (server == NULL) error("ERROR, no such host");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) 
        error("ERROR connecting");

    // Create SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        error("SSL connect error");
    }

    // SMTP commands
    snprintf(buffer, BUFFER_SIZE, "EHLO localhost\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE, "MAIL FROM:<%s>\r\n", from);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE, "RCPT TO:<%s>\r\n", to);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE, "DATA\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);

    snprintf(buffer, BUFFER_SIZE, "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);

    // Quit the SMTP session
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("%s", buffer);

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
}

int main() {
    const char *smtp_server = "smtp.example.com"; // your SMTP server here
    const char *from = "your_email@example.com"; // sender email
    const char *to = "recipient@example.com"; // recipient email
    const char *subject = "Energetic C Email Client!";
    const char *body = "Hello!\nThis is a test email sent from an energetic C email client. Keep coding!";

    printf("🚀 Sending Email...\n");
    send_email(smtp_server, from, to, subject, body);
    printf("📬 Email sent successfully! Check your inbox. 🎉\n");

    return 0;
}