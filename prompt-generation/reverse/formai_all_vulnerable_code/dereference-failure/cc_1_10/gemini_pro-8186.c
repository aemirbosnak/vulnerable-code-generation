//GEMINI-pro DATASET v1.0 Category: Simple Web Server ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <time.h>

#define BUFSIZE 1024
#define MAX_CLIENTS 10

typedef struct {
    int sockfd;
    char buf[BUFSIZE];
    int len;
} client_t;

void handle_client(client_t *client) {
    if (client->len <= 0) {
        close(client->sockfd);
        free(client);
        return;
    }

    char *request = strtok(client->buf, " ");
    if (strcmp(request, "GET") == 0) {
        char *path = strtok(NULL, " ");
        if (path == NULL || strcmp(path, "/") == 0) {
            path = "./index.html";
        } else if (path[0] == '/') {
            path++;
        }

        int fd = open(path, O_RDONLY);
        if (fd < 0) {
            send(client->sockfd, "HTTP/1.1 404 Not Found\r\n\r\n", 26, 0);
            close(client->sockfd);
            free(client);
            return;
        }

        struct stat st;
        fstat(fd, &st);
        char *content_type = "text/plain";
        if (strstr(path, ".html")) {
            content_type = "text/html";
        } else if (strstr(path, ".css")) {
            content_type = "text/css";
        } else if (strstr(path, ".js")) {
            content_type = "application/javascript";
        } else if (strstr(path, ".jpg")) {
            content_type = "image/jpeg";
        } else if (strstr(path, ".png")) {
            content_type = "image/png";
        } else if (strstr(path, ".gif")) {
            content_type = "image/gif";
        }

        char buf[BUFSIZE];
        snprintf(buf, BUFSIZE, "HTTP/1.1 200 OK\r\nContent-Type: %s\r\nContent-Length: %ld\r\n\r\n", content_type, st.st_size);
        send(client->sockfd, buf, strlen(buf), 0);

        while ((client->len = read(fd, client->buf, BUFSIZE)) > 0) {
            send(client->sockfd, client->buf, client->len, 0);
        }

        close(fd);
        close(client->sockfd);
        free(client);
    } else if (strcmp(request, "POST") == 0) {
        // TODO: Handle POST requests
        send(client->sockfd, "HTTP/1.1 501 Not Implemented\r\n\r\n", 31, 0);
        close(client->sockfd);
        free(client);
    } else {
        send(client->sockfd, "HTTP/1.1 400 Bad Request\r\n\r\n", 27, 0);
        close(client->sockfd);
        free(client);
    }
}

void accept_clients(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    while (1) {
        int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_sockfd < 0) {
            perror("accept");
            continue;
        }

        client_t *client = malloc(sizeof(client_t));
        client->sockfd = client_sockfd;
        client->len = recv(client_sockfd, client->buf, BUFSIZE, 0);

        handle_client(client);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Invalid port number: %d\n", port);
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) < 0) {
        perror("setsockopt");
        close(sockfd);
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        close(sockfd);
        return 1;
    }

    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen");
        close(sockfd);
        return 1;
    }

    accept_clients(sockfd);

    close(sockfd);
    return 0;
}