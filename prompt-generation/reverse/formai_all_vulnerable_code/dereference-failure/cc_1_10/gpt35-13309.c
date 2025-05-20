//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

typedef struct {
    int conn_fd;
    char* server_ip;
    int server_port;
} connect_info_t;

void* process_request(void* arg) {
    connect_info_t* conn_info = (connect_info_t*) arg;

    int server_sock_fd;
    struct sockaddr_in server_addr;

    server_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock_fd < 0) {
        perror("socket failed");
        return NULL;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(conn_info->server_ip);
    server_addr.sin_port = htons(conn_info->server_port);

    if (connect(server_sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        close(server_sock_fd);
        return NULL;
    }

    char buffer[4096];
    int bytes_read;
    while ((bytes_read = read(conn_info->conn_fd, buffer, sizeof(buffer))) > 0) {
        write(server_sock_fd, buffer, bytes_read);
    }

    close(conn_info->conn_fd);
    close(server_sock_fd);
    free(conn_info->server_ip);
    free(conn_info);

    return NULL;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s <bind_ip> <bind_port>\n", argv[0]);
        exit(1);
    }

    int bind_port = atoi(argv[2]);
    if (bind_port == 0) {
        printf("Invalid bind port provided\n");
        exit(1);
    }

    int bind_sock_fd;
    struct sockaddr_in bind_addr;

    bind_sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (bind_sock_fd < 0) {
        perror("socket failed");
        exit(1);
    }

    memset(&bind_addr, 0, sizeof(bind_addr));
    bind_addr.sin_family = AF_INET;
    bind_addr.sin_addr.s_addr = inet_addr(argv[1]);
    bind_addr.sin_port = htons(bind_port);

    if (bind(bind_sock_fd, (struct sockaddr*) &bind_addr, sizeof(bind_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(bind_sock_fd, 5) < 0) {
        perror("listen failed");
        exit(1);
    }

    while (1) {
        int conn_sock_fd;
        struct sockaddr_in conn_addr;
        socklen_t conn_addr_len = sizeof(conn_addr);

        conn_sock_fd = accept(bind_sock_fd, (struct sockaddr*) &conn_addr, &conn_addr_len);
        if (conn_sock_fd < 0) {
            perror("accept failed");
            continue;
        }

        char* server_ip;
        int server_port;
        char request[4096];
        int request_len = 0;
        int bytes_read;
        int is_first_line = 1;

        while ((bytes_read = read(conn_sock_fd, request + request_len, sizeof(request) - request_len - 1)) > 0) {
            request_len += bytes_read;
            if (is_first_line && strstr(request, "\r\n") != NULL) {
                char* p = strtok(request, " ");
                p = strtok(NULL, " ");
                if (strstr(p, "://") != NULL) {
                    p = strstr(p, "://") + 3;
                }
                if (p == NULL) {
                    break;
                }
                char* colon = strstr(p, ":");
                if (colon != NULL) {
                    server_ip = strndup(p, colon - p);
                    server_port = atoi(colon + 1);
                } else {
                    server_ip = strdup(p);
                    server_port = 80;
                }
                break;
            } else if (request_len >= sizeof(request) - 1) {
                break;
            }
        }

        if (server_ip != NULL) {
            pthread_t thread_id;
            connect_info_t* conn_info = malloc(sizeof(connect_info_t));
            conn_info->conn_fd = conn_sock_fd;
            conn_info->server_ip = server_ip;
            conn_info->server_port = server_port;
            pthread_create(&thread_id, NULL, process_request, conn_info);
            pthread_detach(thread_id);
        } else {
            close(conn_sock_fd);
        }
    }

    close(bind_sock_fd);
    return 0;
}