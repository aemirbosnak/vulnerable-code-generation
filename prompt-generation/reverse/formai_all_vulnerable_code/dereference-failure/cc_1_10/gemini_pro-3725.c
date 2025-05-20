//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUFF_SIZE 4096

struct client_info {
    int sockfd;
    char *host;
    int port;
    char *path;
};

typedef struct client_info ClientInfo;

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);

    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    int bind_res = bind(listenfd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (bind_res == -1) {
        perror("bind");
        return 1;
    }

    int listen_res = listen(listenfd, 10);
    if (listen_res == -1) {
        perror("listen");
        return 1;
    }

    while (1) {
        struct sockaddr_in clientaddr;
        socklen_t clientaddr_len = sizeof(clientaddr);

        int connfd = accept(listenfd, (struct sockaddr *) &clientaddr, &clientaddr_len);
        if (connfd == -1) {
            perror("accept");
            continue;
        }

        char recv_buff[MAX_BUFF_SIZE];
        memset(recv_buff, 0, MAX_BUFF_SIZE);

        int recv_res = recv(connfd, recv_buff, MAX_BUFF_SIZE, 0);
        if (recv_res == -1) {
            perror("recv");
            close(connfd);
            continue;
        }

        ClientInfo client;
        client.sockfd = connfd;
        parse_request(recv_buff, &client);

        int remotefd = connect_to_server(client.host, client.port);
        if (remotefd == -1) {
            send_error(connfd, 502, "Bad Gateway");
            close(connfd);
            continue;
        }

        forward_request(connfd, remotefd);

        close(remotefd);
        close(connfd);
    }

    close(listenfd);

    return 0;
}

int parse_request(char *request, ClientInfo *client) {
    char *host_start = strstr(request, "Host: ");
    if (host_start == NULL) {
        return -1;
    }

    char *host_end = strstr(host_start, "\r\n");
    if (host_end == NULL) {
        return -1;
    }

    size_t host_len = host_end - host_start - 6;
    client->host = malloc(host_len + 1);
    memcpy(client->host, host_start + 6, host_len);
    client->host[host_len] = '\0';

    char *port_start = strstr(request, ":");
    if (port_start == NULL) {
        return -1;
    }

    char *port_end = strstr(port_start, "\r\n");
    if (port_end == NULL) {
        return -1;
    }

    size_t port_len = port_end - port_start - 1;
    char port_str[port_len + 1];
    memcpy(port_str, port_start + 1, port_len);
    port_str[port_len] = '\0';

    client->port = atoi(port_str);

    char *path_start = strstr(request, "GET ");
    if (path_start == NULL) {
        return -1;
    }

    char *path_end = strstr(path_start, "HTTP");
    if (path_end == NULL) {
        return -1;
    }

    size_t path_len = path_end - path_start - 4;
    client->path = malloc(path_len + 1);
    memcpy(client->path, path_start + 4, path_len);
    client->path[path_len] = '\0';

    return 0;
}

int connect_to_server(char *host, int port) {
    int remotefd = socket(AF_INET, SOCK_STREAM, 0);
    if (remotefd == -1) {
        perror("socket");
        return -1;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(host);
    servaddr.sin_port = htons(port);

    int connect_res = connect(remotefd, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (connect_res == -1) {
        perror("connect");
        return -1;
    }

    return remotefd;
}

int forward_request(int connfd, int remotefd) {
    char send_buff[MAX_BUFF_SIZE];
    memset(send_buff, 0, MAX_BUFF_SIZE);

    int recv_res;
    int send_res;

    while ((recv_res = recv(connfd, send_buff, MAX_BUFF_SIZE, 0)) > 0) {
        send_res = send(remotefd, send_buff, recv_res, 0);
        if (send_res == -1) {
            perror("send");
            return -1;
        }
    }

    if (recv_res == -1) {
        perror("recv");
        return -1;
    }

    while ((recv_res = recv(remotefd, send_buff, MAX_BUFF_SIZE, 0)) > 0) {
        send_res = send(connfd, send_buff, recv_res, 0);
        if (send_res == -1) {
            perror("send");
            return -1;
        }
    }

    if (recv_res == -1) {
        perror("recv");
        return -1;
    }

    return 0;
}

int send_error(int sockfd, int code, char *message) {
    char err_buff[MAX_BUFF_SIZE];
    memset(err_buff, 0, MAX_BUFF_SIZE);

    snprintf(err_buff, MAX_BUFF_SIZE, "HTTP/1.1 %d %s\r\nContent-Length: %d\r\nConnection: close\r\n\r\n%s", code, message, strlen(message), message);

    int send_res = send(sockfd, err_buff, strlen(err_buff), 0);
    if (send_res == -1) {
        perror("send");
        return -1;
    }

    return 0;
}