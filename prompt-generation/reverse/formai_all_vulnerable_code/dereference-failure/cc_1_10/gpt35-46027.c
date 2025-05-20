//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024

// Function to handle connection errors
void handle_error(char *msg) {
    printf("%s\n", msg);
    ERR_print_errors_fp(stderr);
    exit(1);
}

// Function to set up the SSL connection
SSL* setup_connection(int sockfd) {
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(SSLv23_client_method());
    if (ctx == NULL) {
        handle_error("Error creating SSL context.");
    }
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) == -1) {
        handle_error("Error connecting SSL.");
    }
    return ssl;
}

// Function to send a command to the IMAP server
void send_command(char *command, SSL *ssl) {
    int command_len = strlen(command);
    if (SSL_write(ssl, command, command_len) < 0) {
        handle_error("Error sending command to server.");
    }
}

// Function to receive a response from the IMAP server
char* receive_response(SSL *ssl) {
    char buf[BUF_SIZE];
    int bytes = SSL_read(ssl, buf, BUF_SIZE);
    if (bytes < 0) {
        handle_error("Error receiving response from server.");
    }
    buf[bytes] = '\0';
    return strdup(buf);
}

int main(int argc, char *argv[]) {
    char *host = "mail.example.com";    // Default IMAP server
    char *username;                     // IMAP username
    char *password;                     // IMAP password
    if (argc < 2) {
        printf("Usage: %s <username> [host]\n", argv[0]);
        exit(1);
    } else {
        username = argv[1];
        if (argc > 2) {
            host = argv[2];
        }
    }
    printf("Connecting to IMAP server %s...\n", host);

    // Create socket connection to IMAP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("Error creating socket.");
    }
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        handle_error("Error resolving hostname.");
    }
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(993);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        handle_error("Error connecting to server.");
    }
    SSL *ssl = setup_connection(sockfd);
    printf("Connected to IMAP server.\n");

    // Send login command to IMAP server
    send_command("LOGIN ", ssl);
    send_command(username, ssl);
    send_command(" ", ssl);
    printf("Enter your password:\n");
    password = getpass("");
    send_command(password, ssl);
    send_command("\r\n", ssl);
    char *response = receive_response(ssl);
    if (strstr(response, "OK") == NULL) {
        handle_error("Error logging in to IMAP server.");
    }
    printf("Logged in to IMAP server.\n");

    // Send select command to IMAP server
    send_command("SELECT INBOX\r\n", ssl);
    response = receive_response(ssl);
    if (strstr(response, "OK") == NULL) {
        handle_error("Error selecting INBOX.");
    }

    // Send fetch command to IMAP server
    send_command("FETCH 1 BODY[TEXT]\r\n", ssl);
    response = receive_response(ssl);
    printf("First email message:\n");
    printf("%s\n", response);

    // Send logout command to IMAP server
    send_command("LOGOUT\r\n", ssl);
    response = receive_response(ssl);
    if (strstr(response, "OK") == NULL) {
        handle_error("Error logging out of IMAP server.");
    }
    printf("Logged out of IMAP server.\n");

    // Clean up resources
    SSL_shutdown(ssl);
    close(sockfd);

    return 0;
}