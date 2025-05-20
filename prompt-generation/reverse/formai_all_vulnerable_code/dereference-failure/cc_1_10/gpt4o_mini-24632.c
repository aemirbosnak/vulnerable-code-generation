//GPT-4o-mini DATASET v1.0 Category: Email Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <openssl/ssl.h>
#include <openssl/err.h>
#include <netdb.h>
#include <sys/socket.h>

#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 587
#define BUFFER_SIZE 1024

typedef struct {
    const char *to;
    const char *subject;
    const char *body;
} Email;

void handle_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void *send_email(void *arg) {
    Email *email = (Email *)arg;
    SSL_CTX *ctx;
    SSL *ssl;
    int sockfd;
    struct hostent *host;
    struct sockaddr_in server_addr;

    // Initialize OpenSSL
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();
    
    ctx = SSL_CTX_new(TLS_client_method());
    if (!ctx) handle_error("Unable to create SSL context");

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) handle_error("Unable to create socket");

    host = gethostbyname(SMTP_SERVER);
    if (!host) handle_error("Unable to get host by name");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(SMTP_PORT);

    // Connect to SMTP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
        handle_error("Unable to connect to server");

    // Create SSL connection
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) <= 0) handle_error("SSL connection failed");

    char buffer[BUFFER_SIZE];
    snprintf(buffer, sizeof(buffer), "EHLO localhost\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    printf("Server: %s", buffer);

    snprintf(buffer, sizeof(buffer), "MAIL FROM:<your_email@example.com>\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", email->to);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    
    snprintf(buffer, sizeof(buffer), "Subject: %s\r\n\r\n%s\r\n.\r\n", email->subject, email->body);
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    SSL_write(ssl, buffer, strlen(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);
    
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    SSL_CTX_free(ctx);
    
    printf("Email sent to: %s\n", email->to);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <to_email> <subject> <body>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Email email;
    email.to = argv[1];
    email.subject = argv[2];
    email.body = argv[3];

    pthread_t thread_id;
    int result = pthread_create(&thread_id, NULL, send_email, (void *)&email);
    if (result != 0) {
        handle_error("Failed to create thread");
    }

    pthread_join(thread_id, NULL);
    return EXIT_SUCCESS;
}