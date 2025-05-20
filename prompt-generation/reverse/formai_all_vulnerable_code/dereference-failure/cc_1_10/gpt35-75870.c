//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define BUFFER_SIZE 1024
#define CERT_FILE "server.crt"
#define KEY_FILE "server.key"

volatile sig_atomic_t g_running = true;

void handle_signal(int signo) {
    printf("Received signal %d\n", signo);
    g_running = false;
}

int create_socket(int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 10) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

SSL_CTX* create_ssl_context() {
    SSL_library_init();
    SSL_CTX* ssl_ctx = SSL_CTX_new(TLS_server_method());
    if (ssl_ctx == NULL) {
        perror("SSL_CTX_new");
        exit(EXIT_FAILURE);
    }

    if (SSL_CTX_use_certificate_file(ssl_ctx, CERT_FILE, SSL_FILETYPE_PEM) <= 0) {
        perror("SSL_CTX_use_certificate_file");
        exit(EXIT_FAILURE);
    }

    if (SSL_CTX_use_PrivateKey_file(ssl_ctx, KEY_FILE, SSL_FILETYPE_PEM) <= 0) {
        perror("SSL_CTX_use_PrivateKey_file");
        exit(EXIT_FAILURE);
    }

    if (!SSL_CTX_check_private_key(ssl_ctx)) {
        perror("SSL_CTX_check_private_key");
        exit(EXIT_FAILURE);
    }

    return ssl_ctx;
}

void handle_client(int sockfd, SSL_CTX* ssl_ctx) {
    SSL* ssl = SSL_new(ssl_ctx);
    SSL_set_fd(ssl, sockfd);

    if (SSL_accept(ssl) <= 0) {
        perror("SSL_accept");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_read = SSL_read(ssl, buffer, BUFFER_SIZE);

    if (bytes_read <= 0) {
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sockfd);
        return;
    }

    // Echo back the message
    int bytes_written = SSL_write(ssl, buffer, bytes_read);
    if (bytes_written <= 0) {
        SSL_shutdown(ssl);
        SSL_free(ssl);
        close(sockfd);
        return;
    }

    SSL_shutdown(ssl);
    SSL_free(ssl);
    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    SSL_CTX* ssl_ctx = create_ssl_context();
    int sockfd = create_socket(atoi(argv[1]));

    // Set up signal handler to gracefully shut down on SIGINT and SIGTERM
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (g_running) {
        struct sockaddr_in cli_addr;
        socklen_t cli_size = sizeof(cli_addr);
        int client_fd = accept(sockfd, (struct sockaddr*)&cli_addr, &cli_size);
        if (client_fd < 0) {
            perror("accept");
            continue;
        }

        pid_t child_pid = fork();
        if (child_pid < 0) {
            perror("fork");
            close(client_fd);
        } else if (child_pid == 0) {
            handle_client(client_fd, ssl_ctx);
            return 0;
        } else {
            close(client_fd);
        }
    }

    printf("Shutdown...\n");
    SSL_CTX_free(ssl_ctx);
    close(sockfd);
    return 0;
}