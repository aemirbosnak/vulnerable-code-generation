//FormAI DATASET v1.0 Category: Browser Plugin ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <stdbool.h>
#include <openssl/ssl.h>
#include <openssl/err.h>

#define PORT 8000
#define MAX_CLIENTS 30

int client_socket[MAX_CLIENTS];
int cur_clients = 0;

pthread_t tid[MAX_CLIENTS];
pthread_mutex_t lock;

SSL_CTX* init_server_ctx(void) {
    SSL_CTX *ctx = NULL;

    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    ctx = SSL_CTX_new(SSLv23_server_method());
    if (ctx == NULL){
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    return ctx;
}

void load_certs(SSL_CTX* ctx, char* cert_path, char* key_path) {
    if (SSL_CTX_use_certificate_file(ctx, cert_path, SSL_FILETYPE_PEM) <= 0) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }

    if (SSL_CTX_use_PrivateKey_file(ctx, key_path, SSL_FILETYPE_PEM) <= 0 ) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
}

void delete_user(int index) {
    pthread_mutex_lock(&lock);
    SSL_shutdown(client_socket[index]);
    SSL_free(client_socket[index]);
    client_socket[index] = -1;
    cur_clients --;
    printf("Client left, current clients: %d\n", cur_clients);
    pthread_mutex_unlock(&lock);
    pthread_exit(NULL);
}

void broadcast(char* data) {
    int i;
    pthread_mutex_lock(&lock);
    for (i = 0; i < MAX_CLIENTS; i++) {
        if(client_socket[i] != -1) {
            SSL_write(client_socket[i], data, strlen(data));
        }
    }
    pthread_mutex_unlock(&lock);
}

void* client_handler(void* arg) {
    SSL* ssl = (SSL*) arg;

    int index = -1, i;
    char client_msg[2048], response[4096];

    pthread_mutex_lock(&lock);
    for (i = 0; i < MAX_CLIENTS; i++) {
        if(client_socket[i] == -1) {
            client_socket[i] = SSL_get_fd(ssl);
            index = i;
            cur_clients ++;
            printf("Client joined, current clients: %d\n", cur_clients);
            break;
        }
    }
    pthread_mutex_unlock(&lock);

    if (index == -1) {
        printf("Max clients limit reached, dropping client...\n");
        SSL_shutdown(ssl);
        SSL_free(ssl);
        pthread_exit(NULL);
    }

    while(1) {
        memset(client_msg, 0, 2048);
        SSL_read(ssl, client_msg, sizeof(client_msg));

        if(strcmp(client_msg, "exit") == 0) {
            delete_user(index);
        }
        else {
            sprintf(response, "[%d]: %s", index, client_msg);
            broadcast(response);
        }
    }
}

int main(int argc, char const *argv[]) {
    SSL_CTX *ctx = NULL;
    SSL *ssl = NULL;

    memset(client_socket, -1, sizeof(client_socket));

    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr); 

    server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1){
        printf("Could not create socket.\n");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, '\0', sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT); 

    if (bind(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0){
        printf("Could not bind socket.\n");
        exit(EXIT_FAILURE);
    }

    listen(server_socket_fd, MAX_CLIENTS);

    ctx = init_server_ctx();
    load_certs(ctx, "server.crt", "server.key");

    while(1) {
        client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_socket_fd == -1) {
            printf("Client connection failed.\n");
            continue;
        }

        ssl = SSL_new(ctx);
        SSL_set_fd(ssl, client_socket_fd);
        SSL_accept(ssl);

        pthread_create(&tid[cur_clients - 1], NULL, client_handler, (void*)ssl);
    }

    SSL_CTX_free(ctx);
    close(server_socket_fd);
    exit(EXIT_SUCCESS);
}