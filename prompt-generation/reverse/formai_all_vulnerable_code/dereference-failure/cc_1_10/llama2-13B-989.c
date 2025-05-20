//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <poll.h>
#include <time.h>

#define MAX_CLIENT_CONNECTIONS 10
#define PORT_RANGE 1024-2048

struct client_data {
    int sock;
    struct sockaddr_in client_addr;
    char client_ip[INET_ADDRSTRLEN];
};

void* scan_ports(void* arg) {
    int port = *(int*)arg;
    struct client_data* cd = malloc(sizeof(struct client_data));
    cd->sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&cd->client_addr, 0, sizeof(struct sockaddr_in));
    cd->client_addr.sin_family = AF_INET;
    cd->client_addr.sin_port = htons(port);
    inet_pton(AF_INET, "127.0.0.1", &cd->client_addr.sin_addr);

    connect(cd->sock, (struct sockaddr*)&cd->client_addr, sizeof(struct sockaddr_in));
    char buffer[1024];
    read(cd->sock, buffer, 1024);
    close(cd->sock);

    printf("Port %d is open\n", port);

    free(cd);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port_range>\n", argv[0]);
        return 1;
    }

    int port_range = atoi(argv[1]);
    int sockets[MAX_CLIENT_CONNECTIONS];
    struct pollfd fds[MAX_CLIENT_CONNECTIONS];

    for (int i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
        sockets[i] = socket(AF_INET, SOCK_STREAM, 0);
        fds[i].fd = sockets[i];
        fds[i].events = POLLIN;
        fds[i].revents = 0;
    }

    for (int port = port_range; port >= 0; port -= 2) {
        int pid = fork();
        if (pid == 0) {
            scan_ports(&port);
        } else {
            wait(NULL);
        }
    }

    for (int i = 0; i < MAX_CLIENT_CONNECTIONS; i++) {
        close(sockets[i]);
    }

    return 0;
}