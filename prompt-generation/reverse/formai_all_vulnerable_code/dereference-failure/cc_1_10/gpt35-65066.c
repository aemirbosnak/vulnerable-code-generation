//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int port = 995; // default POP3 SSL port
    char *host;
    char *username;
    char *password;
    int sock_fd;
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buf[BUF_SIZE];
    int num_bytes;
    SSL_CTX *ctx;
    SSL *ssl;

    // check command line arguments
    if (argc != 4) {
        printf("Usage: pop3client <host> <username> <password>");
        exit(1);
    }

    // set variables from command line arguments
    host = argv[1];
    username = argv[2];
    password = argv[3];

    // set up SSL context
    SSL_library_init();
    ctx = SSL_CTX_new(SSLv23_client_method());
    if (!ctx) {
        printf("Failed to create SSL context");
        exit(1);
    }

    // load trust store
    if (!SSL_CTX_load_verify_locations(ctx, "/etc/ssl/certs/ca-certificates.crt", NULL)) {
        printf("Failed to load trust store");
        exit(1);
    }

    // create socket
    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Failed to create socket");
        exit(1);
    }

    // get host by name
    server = gethostbyname(host);
    if (!server) {
        printf("Failed to get host entry");
        exit(1);
    }

    // populate server address struct
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    serv_addr.sin_port = htons(port);

    // connect to server
    if (connect(sock_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Failed to connect to server");
        exit(1);
    }

    // set up SSL on socket
    ssl = SSL_new(ctx);
    SSL_set_fd(ssl, sock_fd);
    if (SSL_connect(ssl) <= 0) {
        printf("Failed to set up SSL on socket");
        exit(1);
    }

    // get welcome message
    num_bytes = SSL_read(ssl, buf, BUF_SIZE - 1);
    buf[num_bytes] = '\0';
    printf("Server: %s", buf);

    // send username
    sprintf(buf, "USER %s\r\n", username);
    SSL_write(ssl, buf, strlen(buf));
    num_bytes = SSL_read(ssl, buf, BUF_SIZE - 1);
    buf[num_bytes] = '\0';
    printf("Server: %s", buf);

    // send password
    sprintf(buf, "PASS %s\r\n", password);
    SSL_write(ssl, buf, strlen(buf));
    num_bytes = SSL_read(ssl, buf, BUF_SIZE - 1);
    buf[num_bytes] = '\0';
    printf("Server: %s", buf);

    // send STAT command to get mailbox status
    SSL_write(ssl, "STAT\r\n", strlen("STAT\r\n"));
    num_bytes = SSL_read(ssl, buf, BUF_SIZE - 1);
    buf[num_bytes] = '\0';
    printf("Server: %s", buf);

    // close SSL and socket
    SSL_shutdown(ssl);
    SSL_free(ssl);
    SSL_CTX_free(ctx);
    close(sock_fd);

    return 0;
}