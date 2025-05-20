//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: scalable
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <netdb.h>

#define MAX_CLIENTS 10
#define MAX_EVENTS 100

struct client_info {
    int fd;
    struct sockaddr_in addr;
    pthread_t thread;
};

struct event_info {
    int fd;
    struct sockaddr_in addr;
    char *data;
};

struct intrusion_detection_system {
    int num_clients;
    struct client_info clients[MAX_CLIENTS];
    int num_events;
    struct event_info events[MAX_EVENTS];
    pthread_mutex_t mutex;
};

struct intrusion_detection_system *ids;

void init_ids() {
    ids = malloc(sizeof(struct intrusion_detection_system));
    ids->num_clients = 0;
    ids->num_events = 0;
    pthread_mutex_init(&ids->mutex, NULL);
}

void destroy_ids() {
    pthread_mutex_destroy(&ids->mutex);
    free(ids);
}

void handle_client_connection(int fd) {
    int addrlen = sizeof(struct sockaddr_in);
    struct sockaddr_in addr;
    if (getsockname(fd, (struct sockaddr *)&addr, &addrlen) == -1) {
        perror("getsockname");
        close(fd);
        return;
    }
    pthread_mutex_lock(&ids->mutex);
    if (ids->num_clients >= MAX_CLIENTS) {
        close(fd);
        pthread_mutex_unlock(&ids->mutex);
        return;
    }
    ids->clients[ids->num_clients].fd = fd;
    ids->clients[ids->num_clients].addr = addr;
    ids->num_clients++;
    pthread_mutex_unlock(&ids->mutex);
}

void handle_client_data(int fd) {
    char buffer[1024];
    int n;
    n = read(fd, buffer, sizeof(buffer));
    if (n == -1) {
        perror("read");
        close(fd);
        return;
    }
    buffer[n] = '\0';
    pthread_mutex_lock(&ids->mutex);
    if (ids->num_events >= MAX_EVENTS) {
        close(fd);
        pthread_mutex_unlock(&ids->mutex);
        return;
    }
    ids->events[ids->num_events].fd = fd;
    ids->events[ids->num_events].addr = ids->clients[fd].addr;
    ids->events[ids->num_events].data = malloc(n + 1);
    strcpy(ids->events[ids->num_events].data, buffer);
    ids->num_events++;
    pthread_mutex_unlock(&ids->mutex);
}

void handle_client_disconnection(int fd) {
    pthread_mutex_lock(&ids->mutex);
    for (int i = 0; i < ids->num_clients; i++) {
        if (ids->clients[i].fd == fd) {
            ids->clients[i] = ids->clients[ids->num_clients - 1];
            ids->num_clients--;
            break;
        }
    }
    pthread_mutex_unlock(&ids->mutex);
}

void *client_thread(void *arg) {
    int fd = *(int *)arg;
    while (1) {
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(fd, &rfds);
        struct timeval tv;
        tv.tv_sec = 0;
        tv.tv_usec = 100000;
        int n = select(fd + 1, &rfds, NULL, NULL, &tv);
        if (n == -1) {
            perror("select");
            close(fd);
            pthread_exit(NULL);
        }
        if (FD_ISSET(fd, &rfds)) {
            handle_client_data(fd);
        }
    }
}

void start_ids() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }
    int opt = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        perror("setsockopt");
        exit(1);
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }
    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }
    while (1) {
        struct sockaddr_in addr;
        int addrlen = sizeof(addr);
        int fd = accept(sockfd, (struct sockaddr *)&addr, &addrlen);
        if (fd == -1) {
            perror("accept");
            continue;
        }
        handle_client_connection(fd);
        pthread_create(&ids->clients[ids->num_clients - 1].thread, NULL, client_thread, &fd);
    }
}

int main() {
    init_ids();
    start_ids();
    destroy_ids();
    return 0;
}