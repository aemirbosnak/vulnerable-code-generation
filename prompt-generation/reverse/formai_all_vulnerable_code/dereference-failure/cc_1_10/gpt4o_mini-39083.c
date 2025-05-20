//GPT-4o-mini DATASET v1.0 Category: Building a POP3 Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 995 // POP3 over SSL port
#define BUFFER_SIZE 4096

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void initialize_ssl() {
    SSL_library_init();
    SSL_load_error_strings();
    OpenSSL_add_all_algorithms();
}

SSL *create_ssl_connection(int sockfd) {
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        handle_error("Unable to create SSL context");
    }

    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);

    if (SSL_connect(ssl) <= 0) {
        handle_error("SSL connect error");
    }

    return ssl;
}

void send_command(SSL *ssl, const char *cmd) {
    SSL_write(ssl, cmd, strlen(cmd));
}

char *receive_response(SSL *ssl) {
    static char buffer[BUFFER_SIZE];

    memset(buffer, 0, sizeof(buffer));
    SSL_read(ssl, buffer, sizeof(buffer) - 1);

    return buffer;
}

void list_emails(SSL *ssl) {
    send_command(ssl, "LIST\r\n");
    printf("Response: %s", receive_response(ssl));
}

void retrieve_email(SSL *ssl, int email_number) {
    char cmd[50];
    snprintf(cmd, sizeof(cmd), "RETR %d\r\n", email_number);
    send_command(ssl, cmd);
    printf("Response: %s", receive_response(ssl));
}

void quit_pop3(SSL *ssl) {
    send_command(ssl, "QUIT\r\n");
    receive_response(ssl); // Read final response
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *username = argv[2];
    const char *password = argv[3];

    initialize_ssl();

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        handle_error("Error retrieving host");
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Error opening socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Error connecting to server");
    }

    SSL *ssl = create_ssl_connection(sockfd);

    char cmd[BUFFER_SIZE];

    snprintf(cmd, sizeof(cmd), "USER %s\r\n", username);
    send_command(ssl, cmd);
    printf("Response: %s", receive_response(ssl));

    snprintf(cmd, sizeof(cmd), "PASS %s\r\n", password);
    send_command(ssl, cmd);
    printf("Response: %s", receive_response(ssl));

    printf("List of emails:\n");
    list_emails(ssl);

    int email_number;
    printf("Enter the email number to retrieve: ");
    scanf("%d", &email_number);
    retrieve_email(ssl, email_number);

    quit_pop3(ssl);

    SSL_free(ssl);
    close(sockfd);
    return 0;
}