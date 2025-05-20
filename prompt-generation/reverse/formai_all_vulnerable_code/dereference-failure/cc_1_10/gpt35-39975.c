//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);
SSL_CTX *sslInit(void);
int tcpConnect(char *server, int port);
void startTLS(SSL *ssl);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("usage: %s server port username\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    int port = atoi(argv[2]);
    char *user = argv[3];

    // Connect to IMAP server
    int sockfd = tcpConnect(server, port);
    SSL_CTX *ctx = sslInit();
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    SSL_connect(ssl);
    startTLS(ssl);

    // Send IMAP login command
    char buffer[BUFFER_SIZE];
    char *login = malloc(strlen(user) + 16);
    sprintf(login, "LOGIN %s *******\r\n", user); // password masked
    SSL_write(ssl, login, strlen(login));
    SSL_read(ssl, buffer, BUFFER_SIZE);
    free(login);

    // Check if login was successful
    if (strstr(buffer, "OK LOGIN Completed") == NULL) {
        printf("Unable to login. Server says: %s\n", buffer);
        close(sockfd);
        SSL_shutdown(ssl);
        SSL_free(ssl);
        SSL_CTX_free(ctx);
        return 1;
    }

    // Request mailbox status
    char *status = "STATUS INBOX (MESSAGES UNSEEN)\r\n";
    SSL_write(ssl, status, strlen(status));
    SSL_read(ssl, buffer, BUFFER_SIZE);

    // Parse mailbox status response
    int messages = 0, unseen = 0;
    char *ptr;
    ptr = strstr(buffer, "MESSAGES ");
    if (ptr != NULL) sscanf(ptr, "MESSAGES %d", &messages);
    ptr = strstr(buffer, "UNSEEN ");
    if (ptr != NULL) sscanf(ptr, "UNSEEN %d", &unseen);

    // Print mailbox status
    printf("Welcome, %s. You have %d message(s), %d of which are new.\n", user, messages, unseen);

    // Quit session
    char *quit = "LOGOUT\r\n";
    SSL_write(ssl, quit, strlen(quit));
    SSL_read(ssl, buffer, BUFFER_SIZE);

    // Close connection
    close(sockfd);
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}

SSL_CTX *sslInit(void) {
    SSL_library_init();
    SSL_load_error_strings();

    SSL_CTX *ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL) {
        ERR_print_errors_fp(stderr);
        exit(1);
    }

    return ctx;
}

int tcpConnect(char *server, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) error_handling("socket() error");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(server);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) error_handling("connect() error");

    return sockfd;
}

void startTLS(SSL *ssl) {
    char buffer[BUFFER_SIZE];
    SSL_write(ssl, "STARTTLS\r\n", strlen("STARTTLS\r\n"));
    SSL_read(ssl, buffer, BUFFER_SIZE);
    SSL_set_cipher_list(ssl, "HIGH:!aNULL:!MD5");
    SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);
    SSL_set_verify(ssl, SSL_VERIFY_PEER, NULL);
}