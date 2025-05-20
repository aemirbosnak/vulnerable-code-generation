//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024 // Buffer size for receiving messages

int main() {
    // Step 1: Establish connection with the IMAP server (using TLS)
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Initialize OpenSSL library
    SSL_load_error_strings();
    SSL_library_init();

    // Create a new SSL context for the connection
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());

    // Create a new socket for the connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: failed to create socket.\n");
        return -1;
    }

    // Get server information from hostname
    server = gethostbyname("imap.example.com");
    if (server == NULL) {
        printf("Error: failed to get server information.\n");
        return -1;
    }

    // Set server address struct
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr,
          server->h_length);
    server_addr.sin_port = htons(993); // IMAP port number

    // Connect to IMAP server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) <
        0) {
        printf("Error: failed to establish connection with IMAP server.\n");
        return -1;
    }

    // Attach SSL to the socket
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        printf("Error: failed to establish secure connection with IMAP server.\n");
        return -1;
    }

    // Step 2: Log in to the IMAP server
    char *username = "example_username";
    char *password = "example_password";
    char login_buf[BUF_SIZE];
    char login_res[BUF_SIZE];
    int login_len;

    // Send LOGIN command to server
    login_len = snprintf(login_buf, BUF_SIZE, "LOGIN %s %s\r\n", username,
                          password);
    SSL_write(ssl, login_buf, login_len);

    // Receive response from server
    SSL_read(ssl, login_res, sizeof(login_res));
    if (strstr(login_res, "OK") == NULL) {
        printf("Error: failed to authenticate with IMAP server.\n");
        return -1;
    }

    // Step 3: List available mailboxes on server
    char list_buf[BUF_SIZE];
    char list_res[BUF_SIZE];
    int list_len;

    // Send LIST command to server
    list_len = snprintf(list_buf, BUF_SIZE, "LIST \"\" *\r\n");
    SSL_write(ssl, list_buf, list_len);

    // Receive response from server
    SSL_read(ssl, list_res, sizeof(list_res));
    printf("Available mailboxes:\n%s\n", list_res);

    // Step 4: Select a mailbox to work with
    char select_buf[BUF_SIZE];
    char select_res[BUF_SIZE];
    int select_len;

    // Send SELECT command to server
    select_len = snprintf(select_buf, BUF_SIZE, "SELECT INBOX\r\n");
    SSL_write(ssl, select_buf, select_len);

    // Receive response from server
    SSL_read(ssl, select_res, sizeof(select_res));
    if (strstr(select_res, "OK") == NULL) {
        printf("Error: failed to select mailbox.\n");
        return -1;
    }

    // Step 5: Retrieve a list of messages in the selected mailbox
    char search_buf[BUF_SIZE];
    char search_res[BUF_SIZE];
    int search_len;

    // Send SEARCH command to server
    search_len = snprintf(search_buf, BUF_SIZE, "SEARCH ALL\r\n");
    SSL_write(ssl, search_buf, search_len);

    // Receive message IDs from server
    SSL_read(ssl, search_res, sizeof(search_res));
    printf("Message IDs in selected mailbox: %s\n", search_res);

    // Step 6: Retrieve the contents of a specific message
    char fetch_buf[BUF_SIZE];
    char fetch_res[BUF_SIZE];
    int fetch_len;

    // Send FETCH command to server for message with ID 1
    fetch_len = snprintf(fetch_buf, BUF_SIZE, "FETCH 1 BODY[TEXT]\r\n");
    SSL_write(ssl, fetch_buf, fetch_len);

    // Receive message contents from server
    SSL_read(ssl, fetch_res, sizeof(fetch_res));
    printf("Contents of message 1:\n%s\n", fetch_res);

    // Step 7: Log out and close the connection
    char logout_buf[BUF_SIZE];
    char logout_res[BUF_SIZE];
    int logout_len;

    // Send LOGOUT command to server
    logout_len = snprintf(logout_buf, BUF_SIZE, "LOGOUT\r\n");
    SSL_write(ssl, logout_buf, logout_len);

    // Receive response from server
    SSL_read(ssl, logout_res, sizeof(logout_res));

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
    return 0;
}