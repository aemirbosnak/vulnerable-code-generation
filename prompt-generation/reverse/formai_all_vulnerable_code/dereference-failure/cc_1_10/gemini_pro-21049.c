//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: systematic
#include <errno.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

#define PORT 8080
#define MAX_REQUEST_LEN 1024

struct request {
    int fd;
    char *buf;
    size_t len;
    char *path;
};

void serve_file(struct request *req) {
    struct stat st;

    if (fstat(req->fd, &st) == -1) {
        perror("fstat");
        return;
    }

    if (!S_ISREG(st.st_mode)) {
        fprintf(stderr, "%s is not a regular file\n", req->path);
        return;
    }

    if ((req->buf = malloc(st.st_size)) == NULL) {
        perror("malloc");
        return;
    }

    if (read(req->fd, req->buf, st.st_size) != st.st_size) {
        perror("read");
        return;
    }

    req->len = st.st_size;
}

void send_response(struct request *req) {
    char *header;

    if (req->len == 0) {
        header = "HTTP/1.1 204 No Content\r\n";
    } else {
        header = "HTTP/1.1 200 OK\r\n";
    }

    if (write(req->fd, header, strlen(header)) != strlen(header)) {
        perror("write");
        return;
    }

    if (req->len > 0) {
        if (write(req->fd, req->buf, req->len) != req->len) {
            perror("write");
            return;
        }
    }
}

void handle_request(struct request *req) {
    char *method, *path, *version;

    if (sscanf(req->buf, "%ms %ms %ms\r\n", &method, &path, &version) != 3) {
        fprintf(stderr, "Invalid request: %s\n", req->buf);
        return;
    }

    if (strcmp(method, "GET") != 0) {
        fprintf(stderr, "Unsupported method: %s\n", method);
        return;
    }

    if (strcmp(version, "HTTP/1.1") != 0) {
        fprintf(stderr, "Unsupported version: %s\n", version);
        return;
    }

    req->path = path;

    if ((req->fd = open(path, O_RDONLY)) == -1) {
        perror("open");
        return;
    }

    serve_file(req);
    send_response(req);

    close(req->fd);
    free(req->buf);
}

void accept_loop(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;
    int client_sockfd;
    struct request req;

    while (1) {
        client_addr_len = sizeof(client_addr);
        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            if (errno == EINTR) {
                continue;
            }

            perror("accept");
            return;
        }

        req.fd = client_sockfd;
        req.buf = NULL;
        req.len = 0;
        req.path = NULL;

        if (recv(client_sockfd, req.buf, MAX_REQUEST_LEN, 0) == -1) {
            perror("recv");
            close(client_sockfd);
            continue;
        }

        handle_request(&req);

        close(client_sockfd);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        close(sockfd);
        return 1;
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen");
        close(sockfd);
        return 1;
    }

    accept_loop(sockfd);

    close(sockfd);

    return 0;
}