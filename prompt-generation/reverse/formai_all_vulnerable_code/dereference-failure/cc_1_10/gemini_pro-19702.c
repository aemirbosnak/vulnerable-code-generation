//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: careful
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BACKLOG 5
#define MAX_CLIENTS 5

struct client_info {
    int fd;
    struct sockaddr_in addr;
};

struct firewall_rule {
    struct in_addr src_addr;
    struct in_addr dst_addr;
    uint16_t src_port;
    uint16_t dst_port;
    int proto;
    int action;
};

struct firewall {
    struct firewall_rule rules[10];
    int num_rules;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    int bind_result = bind(sockfd, (struct sockaddr *) &addr, sizeof(addr));
    if (bind_result == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    int listen_result = listen(sockfd, BACKLOG);
    if (listen_result == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    struct client_info clients[MAX_CLIENTS];
    int num_clients = 0;

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);

        int client_fd = accept(sockfd, (struct sockaddr *) &client_addr, &client_addr_len);
        if (client_fd == -1) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                continue;
            } else {
                perror("accept");
                return EXIT_FAILURE;
            }
        }

        if (num_clients >= MAX_CLIENTS) {
            close(client_fd);
            continue;
        }

        clients[num_clients].fd = client_fd;
        clients[num_clients].addr = client_addr;
        num_clients++;

        printf("Accepted connection from %s:%d\n", inet_ntoa(clients[num_clients - 1].addr.sin_addr), ntohs(clients[num_clients - 1].addr.sin_port));
    }

    return EXIT_SUCCESS;
}