//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <pthread.h>

#define MAX_CLIENTS 1024
#define MAX_BUF_SIZE 1024

typedef struct client_info_s client_info_t;
struct client_info_s {
    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
};

typedef struct thread_args_s thread_args_t;
struct thread_args_s {
    int client_fd;
    int server_fd;
};

void *handle_client(void *args) {
    thread_args_t *arg = (thread_args_t *) args;
    int client_fd = arg->client_fd;
    int server_fd = arg->server_fd;
    char buf[MAX_BUF_SIZE];

    while (1) {
        int read_res = read(client_fd, buf, MAX_BUF_SIZE);

        // client closed connection
        if (read_res == 0) {
            close(client_fd);
            break;
        }

        if (read_res < 0) {
            perror("read error");
            close(client_fd);
            break;
        }

        int write_res = write(server_fd, buf, read_res);

        if (write_res < 0) {
            perror("write error");
            close(client_fd);
            break;
        }

        // server closed connection
        if (write_res == 0) {
            close(client_fd);
            break;
        }
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_str = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in proxy_addr;
    memset(&proxy_addr, 0, sizeof(proxy_addr));

    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy_addr.sin_port = htons(port);

    int proxy_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (proxy_fd < 0) {
        perror("socket error");
        exit(EXIT_FAILURE);
    }

    int enable = 1;

    if (setsockopt(proxy_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        perror("setsockopt error");
        exit(EXIT_FAILURE);
    }

    if (bind(proxy_fd, (struct sockaddr *) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("bind error");
        exit(EXIT_FAILURE);
    }

    if (listen(proxy_fd, MAX_CLIENTS) < 0) {
        perror("listen error");
        exit(EXIT_FAILURE);
    }

    while (1) {
        client_info_t client_info;
        memset(&client_info, 0, sizeof(client_info));
        client_info.client_addr_len = sizeof(client_info.client_addr);

        int client_fd = accept(proxy_fd, (struct sockaddr *) &client_info.client_addr, &client_info.client_addr_len);

        if (client_fd < 0) {
            perror("accept error");
            continue;
        }

        printf("New client connected from %s:%d\n",
               inet_ntoa(client_info.client_addr.sin_addr),
               ntohs(client_info.client_addr.sin_port));

        struct hostent *server = gethostbyname(ip_str);

        if (server == NULL) {
            fprintf(stderr, "Error: no such host %s\n", ip_str);
            close(client_fd);
            continue;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
        server_addr.sin_port = htons(port);

        int server_fd = socket(AF_INET, SOCK_STREAM, 0);

        if (server_fd < 0) {
            perror("socket error");
            close(client_fd);
            continue;
        }

        if (connect(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
            perror("connect error");
            close(client_fd);
            close(server_fd);
            continue;
        }

        printf("Connected to server %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));

        pthread_t thread;
        thread_args_t *args = malloc(sizeof(thread_args_t));
        args->client_fd = client_fd;
        args->server_fd = server_fd;

        if (pthread_create(&thread, NULL, handle_client, args) != 0) {
            perror("pthread_create error");
            close(client_fd);
            close(server_fd);
            free(args);
            continue;
        }

        pthread_detach(thread);
    }

    return 0;
}