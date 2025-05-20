//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_BUF_SIZE 4096

struct thread_args {
    int client_fd;
    int server_fd;
};

void *handle_client(void *args) {
    int client_fd = ((struct thread_args *)args)->client_fd;
    int server_fd = ((struct thread_args *)args)->server_fd;
    char buf[MAX_BUF_SIZE];
    int nbytes;

    while ((nbytes = read(client_fd, buf, sizeof(buf))) > 0) {
        write(server_fd, buf, nbytes);
        if ((nbytes = read(server_fd, buf, sizeof(buf))) > 0) {
            write(client_fd, buf, nbytes);
        } else {
            break;
        }
    }

    close(client_fd);
    close(server_fd);

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    int listen_sock, client_sock, server_sock;
    struct sockaddr_in listen_addr, client_addr;
    socklen_t client_addr_len;
    pthread_t thread;
    struct thread_args args;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((listen_sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&listen_addr, 0, sizeof(listen_addr));
    listen_addr.sin_family = AF_INET;
    listen_addr.sin_addr.s_addr = INADDR_ANY;
    listen_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_sock, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    while (1) {
        client_addr_len = sizeof(client_addr);
        if ((client_sock = accept(listen_sock, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("accept");
            continue;
        }

        struct hostent *host = gethostbyname("example.com");
        server_sock = socket(PF_INET, SOCK_STREAM, 0);
        struct sockaddr_in server_addr = {0};
        server_addr.sin_family = AF_INET;
        server_addr.sin_addr.s_addr = inet_addr(inet_ntoa(*((struct in_addr *)host->h_addr)));
        server_addr.sin_port = htons(80);
        connect(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

        args.client_fd = client_sock;
        args.server_fd = server_sock;
        pthread_create(&thread, NULL, handle_client, &args);
    }

    close(listen_sock);

    return 0;
}