//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

struct client_args {
    int client_sock;
    int server_sock;
};

void* handle_client(void* args) {
    struct client_args* client_args = (struct client_args*)args;
    char buf[BUF_SIZE];
    int n;

    while ((n = read(client_args->client_sock, buf, BUF_SIZE)) > 0) {
        if (write(client_args->server_sock, buf, n) == -1) {
            perror("write to server failed");
            break;
        }
    }

    if (n == -1) {
        perror("read from client failed");
    }

    close(client_args->client_sock);
    close(client_args->server_sock);
    free(client_args);

    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <proxy_port> <server_address>\n", argv[0]);
        return 1;
    }

    int proxy_port = atoi(argv[1]);
    char* server_address = argv[2];

    int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_sock == -1) {
        perror("socket creation failed");
        return 1;
    }

    struct sockaddr_in listen_addr;
    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    listen_addr.sin_port = htons(proxy_port);

    if (bind(listen_sock, (struct sockaddr*)&listen_addr, sizeof(listen_addr)) == -1) {
        perror("bind failed");
        return 1;
    }

    if (listen(listen_sock, SOMAXCONN) == -1) {
        perror("listen failed");
        return 1;
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int client_sock = accept(listen_sock, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sock == -1) {
            perror("accept failed");
            continue;
        }

        struct hostent* server = gethostbyname(server_address);
        if (server == NULL) {
            fprintf(stderr, "gethostbyname failed\n");
            close(client_sock);
            continue;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr = *(struct in_addr*)server->h_addr;
        server_addr.sin_port = htons(80);

        int server_sock = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sock == -1) {
            perror("socket creation failed");
            close(client_sock);
            continue;
        }

        if (connect(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
            perror("connect failed");
            close(client_sock);
            close(server_sock);
            continue;
        }

        struct client_args* args = malloc(sizeof(struct client_args));
        args->client_sock = client_sock;
        args->server_sock = server_sock;

        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, (void*)args) != 0) {
            perror("pthread_create failed");
            close(client_sock);
            close(server_sock);
            free(args);
            continue;
        }

        pthread_detach(thread);
    }

    close(listen_sock);

    return 0;
}