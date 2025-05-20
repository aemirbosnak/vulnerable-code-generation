//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define IMAP_PORT 143
#define IMAP_SSL_PORT 993

struct imap_server {
    char *hostname;
    int port;
    int ssl;
};

struct imap_connection {
    int sockfd;
    SSL *ssl;
};

struct imap_command {
    char *command;
    char *args;
};

struct imap_response {
    char *status;
    char *message;
};

struct imap_message {
    char *uid;
    char *flags;
    char *size;
    char *body;
};

void *imap_connect(void *arg) {
    struct imap_server *server = (struct imap_server *)arg;
    int sockfd;
    SSL *ssl = NULL;
    if (server->ssl) {
        SSL_library_init();
        SSL_load_error_strings();
        ssl = SSL_new(SSL_CTX_new(TLS_client_method()));
        if (ssl == NULL) {
            ERR_print_errors_fp(stderr);
            exit(1);
        }
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(server->port);
    if (inet_pton(AF_INET, server->hostname, &addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }
    if (ssl) {
        SSL_set_fd(ssl, sockfd);
        if (SSL_connect(ssl) != 1) {
            ERR_print_errors_fp(stderr);
            exit(1);
        }
    }
    struct imap_connection *conn = malloc(sizeof(struct imap_connection));
    conn->sockfd = sockfd;
    conn->ssl = ssl;
    return conn;
}

struct imap_response *imap_send_command(struct imap_connection *conn, struct imap_command *command) {
    char *request = malloc(strlen(command->command) + strlen(command->args) + 2);
    sprintf(request, "%s %s\r\n", command->command, command->args);
    if (SSL_write(conn->ssl, request, strlen(request)) <= 0) {
        perror("SSL_write");
        exit(1);
    }
    free(request);
    char *response = malloc(1024);
    int len = SSL_read(conn->ssl, response, 1024);
    if (len <= 0) {
        perror("SSL_read");
        exit(1);
    }
    response[len] = '\0';
    struct imap_response *resp = malloc(sizeof(struct imap_response));
    char *ptr = strchr(response, ' ');
    if (ptr) {
        *ptr = '\0';
        resp->status = strdup(response);
        resp->message = strdup(ptr + 1);
    } else {
        resp->status = strdup(response);
        resp->message = NULL;
    }
    return resp;
}

void imap_close(struct imap_connection *conn) {
    SSL_shutdown(conn->ssl);
    close(conn->sockfd);
    SSL_free(conn->ssl);
    free(conn);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <command>\n", argv[0]);
        exit(1);
    }
    struct imap_server server;
    server.hostname = argv[1];
    server.port = IMAP_PORT;
    server.ssl = 0;
    struct imap_command command;
    command.command = argv[2];
    command.args = NULL;
    pthread_t thread;
    pthread_create(&thread, NULL, imap_connect, &server);
    void *conn = pthread_join(thread, NULL);
    struct imap_response *resp = imap_send_command((struct imap_connection *)conn, &command);
    printf("%s %s\n", resp->status, resp->message);
    imap_close((struct imap_connection *)conn);
    return 0;
}