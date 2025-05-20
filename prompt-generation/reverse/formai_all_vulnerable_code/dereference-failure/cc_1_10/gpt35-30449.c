//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024

void receive_email(SSL *ssl)
{
    char buf[BUF_SIZE];
    int bytes_received;

    // Issue an IMAP ID command
    SSL_write(ssl, "ID \"IMAP Client\"\r\n", strlen("ID \"IMAP Client\"\r\n"));

    // Wait for server response
    bytes_received = SSL_read(ssl, buf, BUF_SIZE);
    buf[bytes_received] = '\0';

    // Print server response
    printf("%s", buf);

    // Issue a LOGIN command with username and password
    char user[100];
    char pass[100];
    printf("Enter your email address: ");
    scanf("%s", user);
    printf("Enter your password: ");
    scanf("%s", pass);
    char cmd[200];
    sprintf(cmd, "LOGIN %s %s\r\n", user, pass);
    SSL_write(ssl, cmd, strlen(cmd));

    // Wait for server response
    bytes_received = SSL_read(ssl, buf, BUF_SIZE);
    buf[bytes_received] = '\0';

    // Print server response
    printf("%s", buf);

    // Issue a LIST command
    SSL_write(ssl, "LIST\r\n", strlen("LIST\r\n"));

    // Wait for server response
    bytes_received = SSL_read(ssl, buf, BUF_SIZE);
    buf[bytes_received] = '\0';

    // Print server response
    printf("%s", buf);

    // Issue a SELECT command on the first mailbox
    SSL_write(ssl, "SELECT INBOX\r\n", strlen("SELECT INBOX\r\n"));

    // Wait for server response
    bytes_received = SSL_read(ssl, buf, BUF_SIZE);
    buf[bytes_received] = '\0';

    // Print server response
    printf("%s", buf);

    // Issue a FETCH command to retrieve the first email
    SSL_write(ssl, "FETCH 1 BODY\r\n", strlen("FETCH 1 BODY\r\n"));

    // Wait for server response
    bytes_received = SSL_read(ssl, buf, BUF_SIZE);
    buf[bytes_received] = '\0';

    // Print server response
    printf("%s", buf);

    // Issue a LOGOUT command
    SSL_write(ssl, "LOGOUT\r\n", strlen("LOGOUT\r\n"));

    // Wait for server response
    bytes_received = SSL_read(ssl, buf, BUF_SIZE);
    buf[bytes_received] = '\0';

    // Print server response
    printf("%s", buf);
}

int main(int argc, char **argv)
{
    SSL_CTX *ctx;
    SSL *ssl;
    int sd, bytes;
    struct sockaddr_in server;
    char *hostname, *portnum;

    // Check command line arguments
    if (argc != 3)
    {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }
    hostname = argv[1];
    portnum = argv[2];

    // Initialize OpenSSL
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();
    ctx = SSL_CTX_new(TLSv1_2_client_method());

    // Create socket and connect to server
    sd = socket(AF_INET, SOCK_STREAM, 0);
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(hostname);
    server.sin_port = htons(atoi(portnum));
    connect(sd, (struct sockaddr *)&server, sizeof(server));

    // Assign SSL to socket
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sd);
    SSL_connect(ssl);

    // Call receive_email function to interact with server
    receive_email(ssl);

    // Clean up
    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sd);
    SSL_CTX_free(ctx);
    return 0;
}