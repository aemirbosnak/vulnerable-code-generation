//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10
#define SELECT_TIMEOUT 10

volatile int is_running = 1;

struct client {
    int fd;
    struct sockaddr_in address;
    bool connected;
};

void signal_handler(int sig) {
    is_running = 0;
}

void add_client(int sockfd, struct client *clients, int *num_clients) {
    if (*num_clients >= MAX_CLIENTS) {
        printf("Max number of clients reached\n");
        return;
    }
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    int new_fd = accept(sockfd, (struct sockaddr *) &address, &addrlen);
    if (new_fd < 0) {
        perror("accept failed");
        return;
    }
    printf("New client connected: %s:%d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
    clients[*num_clients].fd = new_fd;
    clients[*num_clients].address = address;
    clients[*num_clients].connected = true;
    *num_clients += 1;
}

void remove_client(struct client *clients, int *num_clients, int i) {
    printf("Client disconnected: %s:%d\n", inet_ntoa(clients[i].address.sin_addr), ntohs(clients[i].address.sin_port));
    close(clients[i].fd);
    *num_clients -= 1;
    clients[i] = clients[*num_clients];
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [port]\n", argv[0]);
        exit(1);
    }
    int port = atoi(argv[1]);
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(1);
    }
    if (listen(sockfd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(1);
    }
    printf("Server started on port %d\n", port);
    struct client clients[MAX_CLIENTS];
    int num_clients = 0;
    fd_set readfds;
    signal(SIGINT, signal_handler);
    while (is_running) {
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        int max_fd = sockfd;
        for (int i = 0; i < num_clients; i++) {
            FD_SET(clients[i].fd, &readfds);
            if (clients[i].fd > max_fd) {
                max_fd = clients[i].fd;
            }
        }
        struct timeval timeout;
        timeout.tv_sec = SELECT_TIMEOUT;
        timeout.tv_usec = 0;
        int status = select(max_fd + 1, &readfds, NULL, NULL, &timeout);
        if (status < 0) {
            perror("select failed");
            exit(1);
        } else if (status == 0) {
            printf("Timeout occurred\n");
        } else {
            if (FD_ISSET(sockfd, &readfds)) {
                add_client(sockfd, clients, &num_clients);
            }
            for (int i = 0; i < num_clients; i++) {
                if (FD_ISSET(clients[i].fd, &readfds)) {
                    char buffer[BUFFER_SIZE];
                    ssize_t n = recv(clients[i].fd, buffer, BUFFER_SIZE, 0);
                    if (n < 0) {
                        perror("recv failed");
                        remove_client(clients, &num_clients, i);
                        i--;
                    } else if (n == 0) {
                        remove_client(clients, &num_clients, i);
                        i--;
                    }
                }
            }
        }
    }
    close(sockfd);
    printf("Server stopped\n");
    return 0;
}