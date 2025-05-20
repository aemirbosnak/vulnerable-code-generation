//FormAI DATASET v1.0 Category: Simple Web Server ; Style: complex
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define SMALL_BUF 100

void *request_handler(void *arg);

int main(int argc, char *argv[]) {
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, clnt_addr;
    socklen_t clnt_addr_size = sizeof(clnt_addr);
    char buf[BUF_SIZE];
    pthread_t t_id;

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1) {
        perror("socket() error");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("bind() error");
        exit(1);
    }

    if (listen(serv_sock, 5) == -1) {
        perror("listen() error");
        exit(1);
    }

    while (1) {
        clnt_sock = accept(serv_sock, (struct sockaddr *)&clnt_addr, &clnt_addr_size);
        printf("Connection Request : %s:%d\n", inet_ntoa(clnt_addr.sin_addr), ntohs(clnt_addr.sin_port));

        pthread_create(&t_id, NULL, request_handler, (void *)&clnt_sock);
        pthread_detach(t_id);
    }

    close(serv_sock);
    return 0;
}

void send_data(int clnt_sock, const char *content_type, char *body) {
    char protocol[] = "HTTP/1.0 200 OK\r\n";
    char server[] = "Server: Simple Web Server\r\n";
    char cnt_len[SMALL_BUF];
    char cnt_type[SMALL_BUF];
    char buf[BUF_SIZE];
    int content_length = strlen(body);

    // Content-Type Header
    sprintf(cnt_type, "Content-Type: %s\r\n", content_type);
    // Content-Length Header
    sprintf(cnt_len, "Content-Length: %d\r\n", content_length);

    // Write response headers
    write(clnt_sock, protocol, strlen(protocol));
    write(clnt_sock, server, strlen(server));
    write(clnt_sock, cnt_type, strlen(cnt_type));
    write(clnt_sock, cnt_len, strlen(cnt_len));
    write(clnt_sock, "\r\n", 2);

    // Write response body
    write(clnt_sock, body, content_length);
}

void error_handling(char *message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

void *request_handler(void *arg) {
    int clnt_sock = *((int *)arg);
    char buf[BUF_SIZE];

    if (read(clnt_sock, buf, BUF_SIZE) == -1) {
        perror("read() error");
        close(clnt_sock);
        return NULL;
    }

    char *url = strtok(buf, " ");
    strtok(NULL, " ");
    char *http_version = strtok(NULL, "\r\n");

    if (strncmp(url, "/echo", 5) == 0) {
        char *query_string = strchr(url, '?') + 1;
        send_data(clnt_sock, "text/html", query_string);
    } else {
        send_data(clnt_sock, "text/html", "<html><head><title>Page Not Found</title></head><body><h1>404 - Page not found</h1></body></html>");
    }

    close(clnt_sock);
    return NULL;
}