//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define MAX_CONNECTIONS 10

struct connection {
    int sockfd;
    struct sockaddr_in addr;
    char *name;
};

struct firewall {
    int num_connections;
    struct connection connections[MAX_CONNECTIONS];
};

struct firewall *firewall_new() {
    struct firewall *fw = malloc(sizeof(struct firewall));
    if (fw == NULL) {
        perror("malloc");
        return NULL;
    }
    fw->num_connections = 0;
    memset(fw->connections, 0, sizeof(fw->connections));
    return fw;
}

void firewall_free(struct firewall *fw) {
    for (int i = 0; i < fw->num_connections; i++) {
        close(fw->connections[i].sockfd);
        free(fw->connections[i].name);
    }
    free(fw);
}

int firewall_add_connection(struct firewall *fw, int sockfd, struct sockaddr_in *addr) {
    if (fw->num_connections >= MAX_CONNECTIONS) {
        return -1;
    }

    struct connection *conn = &fw->connections[fw->num_connections];
    conn->sockfd = sockfd;
    conn->addr = *addr;
    conn->name = strdup(inet_ntoa(addr->sin_addr));
    fw->num_connections++;
    return 0;
}

int firewall_remove_connection(struct firewall *fw, int sockfd) {
    for (int i = 0; i < fw->num_connections; i++) {
        struct connection *conn = &fw->connections[i];
        if (conn->sockfd == sockfd) {
            close(conn->sockfd);
            free(conn->name);
            memmove(&fw->connections[i], &fw->connections[i + 1], (fw->num_connections - i - 1) * sizeof(struct connection));
            fw->num_connections--;
            return 0;
        }
    }
    return -1;
}

int firewall_listen(struct firewall *fw, int port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    int optval = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) == -1) {
        perror("setsockopt");
        close(sockfd);
        return -1;
    }

    struct sockaddr_in addr = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(port),
    };

    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        close(sockfd);
        return -1;
    }

    if (listen(sockfd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        close(sockfd);
        return -1;
    }

    return sockfd;
}

int firewall_accept(struct firewall *fw, int listen_sockfd) {
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);

    int sockfd = accept(listen_sockfd, (struct sockaddr *)&addr, &addrlen);
    if (sockfd == -1) {
        perror("accept");
        return -1;
    }

    if (firewall_add_connection(fw, sockfd, &addr) == -1) {
        close(sockfd);
        return -1;
    }

    return sockfd;
}

int main() {
    struct firewall *fw = firewall_new();
    if (fw == NULL) {
        fprintf(stderr, "Error creating firewall\n");
        return EXIT_FAILURE;
    }

    int listen_sockfd = firewall_listen(fw, 8080);
    if (listen_sockfd == -1) {
        fprintf(stderr, "Error listening on port 8080\n");
        firewall_free(fw);
        return EXIT_FAILURE;
    }

    printf("Firewall listening on port 8080\n");

    while (1) {
        int sockfd = firewall_accept(fw, listen_sockfd);
        if (sockfd == -1) {
            perror("accept");
            continue;
        }

        printf("New connection from %s\n", inet_ntoa(((struct sockaddr_in *)&fw->connections[fw->num_connections - 1].addr)->sin_addr));
    }

    firewall_free(fw);
    return EXIT_SUCCESS;
}