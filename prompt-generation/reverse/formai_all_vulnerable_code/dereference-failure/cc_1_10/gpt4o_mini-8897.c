//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_EMAIL_SIZE 1024
#define MAX_BUF_SIZE 2048
#define SMTP_SERVER "smtp.gmail.com"
#define SMTP_PORT 465

// Function prototypes
void die(const char *message);
SSL_CTX *initialize_ssl_context();
void send_email(const char *to, const char *from, const char *subject, const char *body, const char *username, const char *password);

int main() {
    char to[MAX_EMAIL_SIZE];
    char from[MAX_EMAIL_SIZE];
    char subject[MAX_EMAIL_SIZE];
    char body[MAX_BUF_SIZE];
    char username[MAX_EMAIL_SIZE];
    char password[MAX_EMAIL_SIZE];

    printf("Welcome to Simple Email Client\n");
    printf("Enter your email: ");
    fgets(from, MAX_EMAIL_SIZE, stdin);
    from[strcspn(from, "\n")] = 0; // Remove trailing newline

    printf("Enter your password: ");
    fgets(password, MAX_EMAIL_SIZE, stdin);
    password[strcspn(password, "\n")] = 0; // Remove trailing newline

    printf("Enter recipient email: ");
    fgets(to, MAX_EMAIL_SIZE, stdin);
    to[strcspn(to, "\n")] = 0; // Remove trailing newline

    printf("Enter subject: ");
    fgets(subject, MAX_EMAIL_SIZE, stdin);
    subject[strcspn(subject, "\n")] = 0; // Remove trailing newline

    printf("Enter body: ");
    fgets(body, MAX_BUF_SIZE, stdin);
    body[strcspn(body, "\n")] = 0; // Remove trailing newline

    send_email(to, from, subject, body, username, password);

    return 0;
}

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

SSL_CTX *initialize_ssl_context() {
    SSL_CTX *ctx;

    SSL_load_error_strings();
    OpenSSL_add_ssl_algorithms();
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        abort();
    }
    return ctx;
}

void send_email(const char *to, const char *from, const char *subject, const char *body, const char *username, const char *password) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;
    SSL_CTX *ctx;
    SSL *ssl;
    char buf[MAX_BUF_SIZE];

    ctx = initialize_ssl_context();
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) die("Socket creation failed");

    host = gethostbyname(SMTP_SERVER);
    if (host == NULL) die("Error resolving hostname");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) die("Connection Failed");

    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        ERR_print_errors_fp(stderr);
        close(sockfd);
        return;
    }

    // Start SMTP conversation
    SSL_read(ssl, buf, sizeof(buf));
    printf("Server: %s\n", buf);

    snprintf(buf, sizeof(buf), "EHLO %s\r\n", from);
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, sizeof(buf));
    printf("Server: %s\n", buf);

    snprintf(buf, sizeof(buf), "AUTH LOGIN\r\n");
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, sizeof(buf));
    printf("Server: %s\n", buf);

    snprintf(buf, sizeof(buf), "%s\r\n", username); // Send username
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, sizeof(buf));
    printf("Server: %s\n", buf);

    snprintf(buf, sizeof(buf), "%s\r\n", password); // Send password
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, sizeof(buf));
    printf("Server: %s\n", buf);

    snprintf(buf, sizeof(buf), "MAIL FROM:<%s>\r\n", from);
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, sizeof(buf));
    printf("Server: %s\n", buf);

    snprintf(buf, sizeof(buf), "RCPT TO:<%s>\r\n", to);
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, sizeof(buf));
    printf("Server: %s\n", buf);

    snprintf(buf, sizeof(buf), "DATA\r\n");
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, sizeof(buf));
    printf("Server: %s\n", buf);

    snprintf(buf, sizeof(buf), "Subject: %s\r\n\r\n%s\r\n.\r\n", subject, body);
    SSL_write(ssl, buf, strlen(buf));
    SSL_read(ssl, buf, sizeof(buf));
    printf("Server: %s\n", buf);

    SSL_write(ssl, "QUIT\r\n", 7); // Ending the session
    SSL_read(ssl, buf, sizeof(buf));
    printf("Server: %s\n", buf);

    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    EVP_cleanup();
}