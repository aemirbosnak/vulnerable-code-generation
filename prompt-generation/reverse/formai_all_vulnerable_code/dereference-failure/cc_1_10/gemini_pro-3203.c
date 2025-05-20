//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define MAX_REQUEST_SIZE 1024

struct client_info {
    int sockfd;
    char ip_address[INET_ADDRSTRLEN];
    int port;
    char request[MAX_REQUEST_SIZE];
    int request_len;
    char response[MAX_REQUEST_SIZE];
    int response_len;
};

struct proxy {
    int listenfd;
    struct sockaddr_in listenaddr;
    struct sockaddr_in clientaddr;
    socklen_t clientaddr_len;
    int maxfd;
    fd_set readfds;
    struct client_info clients[MAX_CLIENTS];
};

void init_proxy(struct proxy *proxy, int port) {
    proxy->listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy->listenfd == -1) {
        perror("socket");
        exit(1);
    }

    proxy->listenaddr.sin_family = AF_INET;
    proxy->listenaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    proxy->listenaddr.sin_port = htons(port);

    if (bind(proxy->listenfd, (struct sockaddr *)&proxy->listenaddr, sizeof(proxy->listenaddr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(proxy->listenfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    proxy->maxfd = proxy->listenfd;
    FD_ZERO(&proxy->readfds);
    FD_SET(proxy->listenfd, &proxy->readfds);
}

void accept_connection(struct proxy *proxy) {
    int newsockfd = accept(proxy->listenfd, (struct sockaddr *)&proxy->clientaddr, &proxy->clientaddr_len);
    if (newsockfd == -1) {
        perror("accept");
        return;
    }

    if (proxy->maxfd < newsockfd) {
        proxy->maxfd = newsockfd;
    }

    FD_SET(newsockfd, &proxy->readfds);
    proxy->clients[newsockfd].sockfd = newsockfd;
    inet_ntop(AF_INET, &proxy->clientaddr.sin_addr, proxy->clients[newsockfd].ip_address, INET_ADDRSTRLEN);
    proxy->clients[newsockfd].port = ntohs(proxy->clientaddr.sin_port);
    proxy->clients[newsockfd].request_len = 0;
    proxy->clients[newsockfd].response_len = 0;
}

void handle_client(struct proxy *proxy, int sockfd) {
    struct client_info *client = &proxy->clients[sockfd];

    if (client->request_len == 0) {
        int n = read(sockfd, client->request, MAX_REQUEST_SIZE);
        if (n == -1) {
            perror("read");
            return;
        } else if (n == 0) {
            FD_CLR(sockfd, &proxy->readfds);
            close(sockfd);
            return;
        }
        client->request_len = n;
    }

    // Parse the request and extract the target host and port
    char *host = NULL;
    char *port = NULL;
    char *path = NULL;
    if (sscanf(client->request, "GET %s HTTP/1.1\r\nHost: %s:%s\r\n", path, host, port) != 3) {
        printf("Invalid request from %s:%d\n", client->ip_address, client->port);
        return;
    }

    // Connect to the target host and port
    int targetfd = socket(AF_INET, SOCK_STREAM, 0);
    if (targetfd == -1) {
        perror("socket");
        return;
    }

    struct sockaddr_in targetaddr;
    targetaddr.sin_family = AF_INET;
    targetaddr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, host, &targetaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return;
    }

    if (connect(targetfd, (struct sockaddr *)&targetaddr, sizeof(targetaddr)) == -1) {
        perror("connect");
        return;
    }

    // Send the request to the target host
    if (write(targetfd, client->request, client->request_len) == -1) {
        perror("write");
        return;
    }

    // Read the response from the target host
    while (1) {
        char buffer[1024];
        int n = read(targetfd, buffer, sizeof(buffer));
        if (n == -1) {
            perror("read");
            return;
        } else if (n == 0) {
            break;
        }
        client->response_len += n;
        if (client->response_len >= MAX_REQUEST_SIZE) {
            printf("Response from %s:%d too large\n", client->ip_address, client->port);
            return;
        }
        memcpy(client->response + client->response_len - n, buffer, n);
    }

    // Send the response to the client
    if (write(sockfd, client->response, client->response_len) == -1) {
        perror("write");
        return;
    }

    // Close the connections
    close(targetfd);
    FD_CLR(sockfd, &proxy->readfds);
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    struct proxy proxy;
    init_proxy(&proxy, atoi(argv[1]));

    while (1) {
        proxy.readfds = proxy.readfds;
        if (select(proxy.maxfd + 1, &proxy.readfds, NULL, NULL, NULL) == -1) {
            perror("select");
            return 1;
        }

        if (FD_ISSET(proxy.listenfd, &proxy.readfds)) {
            accept_connection(&proxy);
        }

        for (int i = 0; i <= proxy.maxfd; i++) {
            if (FD_ISSET(i, &proxy.readfds) && i != proxy.listenfd) {
                handle_client(&proxy, i);
            }
        }
    }

    return 0;
}