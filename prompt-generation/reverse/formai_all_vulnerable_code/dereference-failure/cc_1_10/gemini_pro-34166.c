//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

struct proxy_settings {
    char *host;
    char *port;
    int listen_port;
};

static struct proxy_settings settings;

static int parse_args(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            settings.host = argv[++i];
        } else if (strcmp(argv[i], "-p") == 0) {
            settings.port = argv[++i];
        } else if (strcmp(argv[i], "-l") == 0) {
            settings.listen_port = atoi(argv[++i]);
        } else {
            printf("Usage: %s -h <host> -p <port> -l <port>\n", argv[0]);
            exit(1);
        }
    }
    return 0;
}

static int create_socket(int port) {
    int sockfd;
    struct sockaddr_in addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    return sockfd;
}

static int accept_client(int listen_fd) {
    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len;

    client_addr_len = sizeof(client_addr);
    client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_fd == -1) {
        perror("accept");
        exit(1);
    }

    return client_fd;
}

static int forward_request(int client_fd) {
    int remote_fd;
    char buf[1024];
    ssize_t bytes_read;

    remote_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (remote_fd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in remote_addr;
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_port = htons(atoi(settings.port));
    remote_addr.sin_addr.s_addr = inet_addr(settings.host);

    if (connect(remote_fd, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    while ((bytes_read = read(client_fd, buf, sizeof(buf))) > 0) {
        if (write(remote_fd, buf, bytes_read) == -1) {
            perror("write");
            exit(1);
        }
    }

    close(remote_fd);
    return 0;
}

int main(int argc, char *argv[]) {
    int listen_fd;
    int client_fd;

    parse_args(argc, argv);

    listen_fd = create_socket(settings.listen_port);

    while (1) {
        client_fd = accept_client(listen_fd);
        forward_request(client_fd);
        close(client_fd);
    }

    close(listen_fd);
    return 0;
}