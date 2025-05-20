//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: real-life
/*
 * C program that demonstrates a simple IMAP client
 * The program connects to a server, logs in with a username and password,
 * fetches email headers, and displays them on the console
 * It uses the OpenSSL library for secure connections
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netdb.h>
#include <netinet/in.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 4096

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s SERVER USERNAME PASSWORD\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Resolve server name to IP address
    struct hostent *he = gethostbyname(server);
    if (he == NULL) {
        fprintf(stderr, "Error resolving server name.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize socket connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket.\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(993); // IMAP over SSL
    memcpy(&serv_addr.sin_addr, he->h_addr, he->h_length);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Error connecting to server.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize SSL connection
    SSL_library_init();
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    if (ctx == NULL) {
        fprintf(stderr, "Error creating SSL context.\n");
        exit(EXIT_FAILURE);
    }
    SSL *ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) != 1) {
        fprintf(stderr, "Error establishing SSL connection.\n");
        exit(EXIT_FAILURE);
    }

    // Log in to server
    char *login_cmd = malloc(BUF_SIZE);
    snprintf(login_cmd, BUF_SIZE, "LOGIN %s %s\r\n", username, password);
    SSL_write(ssl, login_cmd, strlen(login_cmd));
    free(login_cmd);

    // Receive response
    char *resp = malloc(BUF_SIZE);
    bool success = false;
    while (true) {
        int num_bytes = SSL_read(ssl, resp, BUF_SIZE-1);
        if (num_bytes <= 0) {
            fprintf(stderr, "Error receiving server response.\n");
            exit(EXIT_FAILURE);
        }
        resp[num_bytes] = '\0';
        if (strstr(resp, "OK LOGIN Completed") != NULL) {
            success = true;
            break;
        }
        if (strstr(resp, "NO ") != NULL || strstr(resp, "BAD ") != NULL) {
            fprintf(stderr, "Error logging in to server (%s).\n", resp);
            exit(EXIT_FAILURE);
        }
    }
    free(resp);

    if (!success) {
        fprintf(stderr, "Error logging in to server (unknown error).\n");
        exit(EXIT_FAILURE);
    }

    // List mailboxes
    SSL_write(ssl, "LIST \"\" \"*\"\r\n", 13);

    // Receive response
    resp = malloc(BUF_SIZE);
    while (true) {
        int num_bytes = SSL_read(ssl, resp, BUF_SIZE-1);
        if (num_bytes <= 0) {
            fprintf(stderr, "Error receiving server response.\n");
            exit(EXIT_FAILURE);
        }
        resp[num_bytes] = '\0';
        if (strcmp(resp, "\r\n") == 0) {
            break;
        }
        printf("%s", resp);
    }
    free(resp);

    // Select mailbox
    SSL_write(ssl, "SELECT INBOX\r\n", 14);

    // Receive response
    resp = malloc(BUF_SIZE);
    while (true) {
        int num_bytes = SSL_read(ssl, resp, BUF_SIZE-1);
        if (num_bytes <= 0) {
            fprintf(stderr, "Error receiving server response.\n");
            exit(EXIT_FAILURE);
        }
        resp[num_bytes] = '\0';
        if (strstr(resp, "EXISTS") != NULL) {
            break;
        }
    }
    free(resp);

    // Fetch headers
    SSL_write(ssl, "FETCH 1:* (BODY[HEADER.FIELDS (DATE FROM SUBJECT)])\r\n", 50);

    // Receive response
    resp = malloc(BUF_SIZE);
    while (true) {
        int num_bytes = SSL_read(ssl, resp, BUF_SIZE-1);
        if (num_bytes <= 0) {
            fprintf(stderr, "Error receiving server response.\n");
            exit(EXIT_FAILURE);
        }
        resp[num_bytes] = '\0';
        if (strcmp(resp, "\r\n") == 0) {
            break;
        }
        printf("%s", resp);
    }
    free(resp);

    // Log out of server
    SSL_write(ssl, "LOGOUT\r\n", 8);

    // Receive response
    resp = malloc(BUF_SIZE);
    while (true) {
        int num_bytes = SSL_read(ssl, resp, BUF_SIZE-1);
        if (num_bytes <= 0) {
            break;
        }
        resp[num_bytes] = '\0';
        if (strcmp(resp, "* BYE Logging out\r\n") == 0) {
            break;
        }
    }
    free(resp);

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);

    return EXIT_SUCCESS;
}