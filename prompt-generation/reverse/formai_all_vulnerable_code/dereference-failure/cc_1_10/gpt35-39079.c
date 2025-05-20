//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define MAX_STRING 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

void send_command(SSL* ssl, char* command) {
    char buffer[MAX_STRING];
    sprintf(buffer, "%s\r\n", command);
    if (SSL_write(ssl, buffer, strlen(buffer)) < 0) {
        error("Error writing to socket");
    }
}

void read_response(SSL* ssl) {
    char buffer[MAX_STRING];
    int num_read;
    while((num_read = SSL_read(ssl, buffer, MAX_STRING)) > 0) {
        buffer[num_read] = '\0';
        printf("%s", buffer);
        if (strchr(buffer, '\n') != NULL) {
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    int portno, sockfd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    SSL_CTX *ctx;
    SSL *ssl;

    if (argc < 4) {
        fprintf(stderr,"usage %s hostname port username\n", argv[0]);
        exit(0);
    }

    portno = atoi(argv[2]);
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("Error, no such host");
    }

    // Setup socket connection
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error connecting to server");
    }

    // Setup SSL connection
    SSL_load_error_strings();
    SSL_library_init();
    ctx = SSL_CTX_new(TLSv1_2_client_method());
    if (ctx == NULL) {
        error("Error initializing OpenSSL context");
    }
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sockfd);
    if (SSL_connect(ssl) < 0) {
        error("Error establishing SSL connection");
    }

    // Login to IMAP server
    read_response(ssl);
    send_command(ssl, "A001 LOGIN user@email.com password");
    read_response(ssl);
    send_command(ssl, "A002 SELECT INBOX");
    read_response(ssl);

    // List all messages in INBOX folder
    send_command(ssl, "A003 FETCH 1:* (BODY[HEADER.FIELDS (FROM SUBJECT DATE)])");
    read_response(ssl);

    // Logout and clean up
    send_command(ssl, "A004 LOGOUT");
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sockfd);
    return 0;
}