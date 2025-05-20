//GEMINI-pro DATASET v1.0 Category: Networking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_MSG_LEN 1024

int create_socket(struct sockaddr_in *addr, unsigned short port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    memset(addr, 0, sizeof(*addr));
    addr->sin_family = AF_INET;
    addr->sin_port = htons(port);
    addr->sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *)addr, sizeof(*addr)) < 0) {
        perror("bind");
        close(sockfd);
        return -1;
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

int accept_connection(int sockfd) {
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    int client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_addr_len);
    if (client_sockfd < 0) {
        perror("accept");
        return -1;
    }

    return client_sockfd;
}

int send_message(int sockfd, const char *msg) {
    int len = strlen(msg);
    int sent = 0;

    while (sent < len) {
        int n = send(sockfd, msg + sent, len - sent, 0);
        if (n < 0) {
            perror("send");
            return -1;
        }

        sent += n;
    }

    return 0;
}

int receive_message(int sockfd, char *buf, int len) {
    int received = 0;

    while (received < len) {
        int n = recv(sockfd, buf + received, len - received, 0);
        if (n < 0) {
            perror("recv");
            return -1;
        } else if (n == 0) {
            break;
        }

        received += n;
    }

    buf[received] = '\0';

    return received;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <port> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    unsigned short port = atoi(argv[1]);
    const char *msg = argv[2];

    struct sockaddr_in addr;
    int sockfd = create_socket(&addr, port);
    if (sockfd < 0) {
        return EXIT_FAILURE;
    }

    printf("Server listening on port %d\n", port);

    while (1) {
        int client_sockfd = accept_connection(sockfd);
        if (client_sockfd < 0) {
            continue;
        }

        printf("Client connected\n");

        if (send_message(client_sockfd, msg) < 0) {
            close(client_sockfd);
            continue;
        }

        char buf[MAX_MSG_LEN + 1];
        int len = receive_message(client_sockfd, buf, MAX_MSG_LEN);
        if (len < 0) {
            close(client_sockfd);
            continue;
        }

        printf("Client sent: %s\n", buf);

        close(client_sockfd);
    }

    close(sockfd);

    return EXIT_SUCCESS;
}