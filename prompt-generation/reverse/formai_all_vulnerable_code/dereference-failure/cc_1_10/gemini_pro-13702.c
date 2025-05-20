//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: future-proof
#include <arpa/inet.h>
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <signal.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define WEB_ROOT "www"
#define MAX_REQUEST_SIZE 4096
#define MAX_RESPONSE_SIZE 8192

static int listen_fd;
static bool running;

static void cleanup() {
    if (listen_fd != -1) {
        close(listen_fd);
    }
}

static void handle_signal(int sig) {
    if (sig == SIGINT) {
        running = false;
        close(listen_fd);
    }
}

static void send_response(int client_fd, const char *status, const char *body) {
    char response[MAX_RESPONSE_SIZE];
    snprintf(response, MAX_RESPONSE_SIZE, "HTTP/1.1 %s\r\nContent-Type: text/plain\r\nContent-Length: %zu\r\n\r\n%s", status, strlen(body), body);
    send(client_fd, response, strlen(response), 0);
}

static void handle_client(int client_fd) {
    char request[MAX_REQUEST_SIZE];
    int nread = recv(client_fd, request, MAX_REQUEST_SIZE, 0);
    if (nread <= 0) {
        perror("recv");
        close(client_fd);
        return;
    }
    request[nread] = '\0';

    char *method = strtok(request, " ");
    if (strcmp(method, "GET") != 0) {
        send_response(client_fd, "405 Method Not Allowed", "Only GET requests are supported");
        close(client_fd);
        return;
    }

    char *path = strtok(NULL, " ");
    if (path == NULL || *path != '/') {
        send_response(client_fd, "400 Bad Request", "Invalid request path");
        close(client_fd);
        return;
    }

    char filepath[strlen(WEB_ROOT) + strlen(path) + 1];
    strcpy(filepath, WEB_ROOT);
    strcat(filepath, path);

    struct stat file_stat;
    if (stat(filepath, &file_stat) != 0) {
        send_response(client_fd, "404 Not Found", "File not found");
        close(client_fd);
        return;
    }

    if (!S_ISREG(file_stat.st_mode)) {
        send_response(client_fd, "403 Forbidden", "File is not a regular file");
        close(client_fd);
        return;
    }

    if (access(filepath, R_OK) != 0) {
        send_response(client_fd, "403 Forbidden", "File is not accessible");
        close(client_fd);
        return;
    }

    int file_fd = open(filepath, O_RDONLY);
    if (file_fd == -1) {
        perror("open");
        send_response(client_fd, "500 Internal Server Error", "Could not open file");
        close(client_fd);
        return;
    }

    char file_buffer[file_stat.st_size];
    int nread_file = read(file_fd, file_buffer, file_stat.st_size);
    if (nread_file != file_stat.st_size) {
        perror("read");
        send_response(client_fd, "500 Internal Server Error", "Could not read file");
        close(file_fd);
        close(client_fd);
        return;
    }

    send_response(client_fd, "200 OK", file_buffer);
    close(file_fd);
    close(client_fd);
}

int main() {
    atexit(cleanup);
    signal(SIGINT, handle_signal);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    if (bind(listen_fd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    if (listen(listen_fd, 10) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    running = true;
    while (running) {
        int client_fd = accept(listen_fd, NULL, NULL);
        if (client_fd == -1) {
            if (errno == EINTR) {
                continue;  // Interrupted system call, try again
            } else {
                perror("accept");
                return EXIT_FAILURE;
            }
        }

        pthread_t thread;
        pthread_create(&thread, NULL, (void *(*)(void *))handle_client, (void *)client_fd);
        pthread_detach(thread);
    }

    return EXIT_SUCCESS;
}