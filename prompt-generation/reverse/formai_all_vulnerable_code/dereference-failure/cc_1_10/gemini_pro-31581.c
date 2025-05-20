//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_CONNECTIONS 10

struct connection {
    int sockfd;
    struct sockaddr_in addr;
    char *buffer;
    size_t buffer_size;
};

struct firewall {
    int sockfd;
    struct sockaddr_in addr;
    struct connection connections[MAX_CONNECTIONS];
    int num_connections;
};

void firewall_init(struct firewall *fw, int port) {
    fw->sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (fw->sockfd == -1) {
        perror("socket");
        exit(1);
    }

    fw->addr.sin_family = AF_INET;
    fw->addr.sin_port = htons(port);
    fw->addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(fw->sockfd, (struct sockaddr *)&fw->addr, sizeof(fw->addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(fw->sockfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        exit(1);
    }

    fw->num_connections = 0;
}

void firewall_accept(struct firewall *fw) {
    struct sockaddr_in addr;
    socklen_t addr_len = sizeof(addr);
    int sockfd = accept(fw->sockfd, (struct sockaddr *)&addr, &addr_len);
    if (sockfd == -1) {
        perror("accept");
        return;
    }

    if (fw->num_connections >= MAX_CONNECTIONS) {
        close(sockfd);
        return;
    }

    struct connection *conn = &fw->connections[fw->num_connections++];
    conn->sockfd = sockfd;
    conn->addr = addr;
    conn->buffer = NULL;
    conn->buffer_size = 0;
}

void firewall_recv(struct firewall *fw) {
    for (int i = 0; i < fw->num_connections; i++) {
        struct connection *conn = &fw->connections[i];
        char buffer[1024];
        ssize_t nbytes = recv(conn->sockfd, buffer, sizeof(buffer), 0);
        if (nbytes < 0) {
            if (errno == EAGAIN || errno == EWOULDBLOCK) {
                continue;
            } else {
                perror("recv");
                close(conn->sockfd);
                fw->num_connections--;
                continue;
            }
        } else if (nbytes == 0) {
            close(conn->sockfd);
            fw->num_connections--;
            continue;
        }

        if (conn->buffer == NULL) {
            conn->buffer = malloc(nbytes);
            memcpy(conn->buffer, buffer, nbytes);
            conn->buffer_size = nbytes;
        } else {
            conn->buffer = realloc(conn->buffer, conn->buffer_size + nbytes);
            memcpy(conn->buffer + conn->buffer_size, buffer, nbytes);
            conn->buffer_size += nbytes;
        }
    }
}

void firewall_send(struct firewall *fw) {
    for (int i = 0; i < fw->num_connections; i++) {
        struct connection *conn = &fw->connections[i];
        if (conn->buffer_size > 0) {
            ssize_t nbytes = send(conn->sockfd, conn->buffer, conn->buffer_size, 0);
            if (nbytes < 0) {
                if (errno == EAGAIN || errno == EWOULDBLOCK) {
                    continue;
                } else {
                    perror("send");
                    close(conn->sockfd);
                    fw->num_connections--;
                    continue;
                }
            } else if (nbytes == 0) {
                close(conn->sockfd);
                fw->num_connections--;
                continue;
            }

            memmove(conn->buffer, conn->buffer + nbytes, conn->buffer_size - nbytes);
            conn->buffer_size -= nbytes;
        }
    }
}

void firewall_close(struct firewall *fw) {
    for (int i = 0; i < fw->num_connections; i++) {
        close(fw->connections[i].sockfd);
    }

    close(fw->sockfd);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    struct firewall fw;
    firewall_init(&fw, port);

    while (1) {
        firewall_accept(&fw);
        firewall_recv(&fw);
        firewall_send(&fw);
    }

    firewall_close(&fw);

    return 0;
}