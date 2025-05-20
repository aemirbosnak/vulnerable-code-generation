//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/mman.h>

#define BUFSIZE 4096

static int server_socket_fd = -1;
static int client_socket_fd = -1;

static void sigint_handler(int signum) {
    if (server_socket_fd != -1) {
        close(server_socket_fd);
    }
    if (client_socket_fd != -1) {
        close(client_socket_fd);
    }
    exit(0);
}

static int create_server_socket(int port) {
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        perror("socket");
        return -1;
    }

    int opt = 1;
    if (setsockopt(server_socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        close(server_socket_fd);
        return -1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(server_socket_fd);
        return -1;
    }

    if (listen(server_socket_fd, 10) == -1) {
        perror("listen");
        close(server_socket_fd);
        return -1;
    }

    return server_socket_fd;
}

static int accept_client_connection(int server_socket_fd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int client_socket_fd = accept(server_socket_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_socket_fd == -1) {
        perror("accept");
        return -1;
    }

    return client_socket_fd;
}

static int handle_client_request(int client_socket_fd) {
    char buf[BUFSIZE];
    memset(buf, 0, BUFSIZE);

    int num_bytes_read = read(client_socket_fd, buf, BUFSIZE - 1);
    if (num_bytes_read == -1) {
        perror("read");
        return -1;
    }

    if (num_bytes_read == 0) {
        return 0;
    }

    char *request_line = strtok(buf, "\r\n");
    if (request_line == NULL) {
        return -1;
    }

    char *method = strtok(request_line, " ");
    if (method == NULL) {
        return -1;
    }

    char *uri = strtok(NULL, " ");
    if (uri == NULL) {
        return -1;
    }

    char *http_version = strtok(NULL, " ");
    if (http_version == NULL) {
        return -1;
    }

    if (strcmp(method, "GET") != 0) {
        return -1;
    }

    if (strcmp(http_version, "HTTP/1.1") != 0) {
        return -1;
    }

    char *file_path = uri + 1;
    if (strcmp(file_path, "") == 0) {
        file_path = "index.html";
    }

    int file_fd = open(file_path, O_RDONLY);
    if (file_fd == -1) {
        if (errno == ENOENT) {
            return 404;
        } else {
            return 500;
        }
    }

    struct stat file_stat;
    if (fstat(file_fd, &file_stat) == -1) {
        return 500;
    }

    void *file_data = mmap(NULL, file_stat.st_size, PROT_READ, MAP_PRIVATE, file_fd, 0);
    if (file_data == MAP_FAILED) {
        return 500;
    }

    char response[BUFSIZE];
    memset(response, 0, BUFSIZE);

    sprintf(response, "HTTP/1.1 200 OK\r\nContent-Length: %ld\r\nContent-Type: text/html\r\n\r\n", file_stat.st_size);
    write(client_socket_fd, response, strlen(response));
    write(client_socket_fd, file_data, file_stat.st_size);

    munmap(file_data, file_stat.st_size);
    close(file_fd);

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    signal(SIGINT, sigint_handler);

    server_socket_fd = create_server_socket(port);
    if (server_socket_fd == -1) {
        return 1;
    }

    while (1) {
        client_socket_fd = accept_client_connection(server_socket_fd);
        if (client_socket_fd == -1) {
            continue;
        }

        int status = handle_client_request(client_socket_fd);

        if (status == 404) {
            char response[BUFSIZE];
            memset(response, 0, BUFSIZE);

            sprintf(response, "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n");
            write(client_socket_fd, response, strlen(response));
        } else if (status == 500) {
            char response[BUFSIZE];
            memset(response, 0, BUFSIZE);

            sprintf(response, "HTTP/1.1 500 Internal Server Error\r\nContent-Length: 0\r\n\r\n");
            write(client_socket_fd, response, strlen(response));
        }

        close(client_socket_fd);
    }

    close(server_socket_fd);

    return 0;
}