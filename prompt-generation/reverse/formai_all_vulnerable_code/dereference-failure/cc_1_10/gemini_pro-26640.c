//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <syslog.h>

#define MAX_CONNECTIONS 10

typedef struct {
    int fd;
    struct sockaddr_in addr;
} connection;

connection connections[MAX_CONNECTIONS];
int num_connections = 0;

int listen_fd;

void accept_connection()
{
    struct sockaddr_in addr;
    socklen_t addrlen = sizeof(addr);
    int fd = accept(listen_fd, (struct sockaddr*)&addr, &addrlen);
    if (fd == -1) {
        perror("accept");
        return;
    }
    if (num_connections >= MAX_CONNECTIONS) {
        close(fd);
        return;
    }
    connections[num_connections].fd = fd;
    connections[num_connections].addr = addr;
    num_connections++;
}

void handle_connection(int fd)
{
    char buf[1024];
    int nread;
    while ((nread = read(fd, buf, sizeof(buf))) > 0) {
        buf[nread] = '\0';
        printf("Received: %s\n", buf);
        write(fd, buf, nread);
    }
    if (nread == 0) {
        printf("Connection closed\n");
        close(fd);
    } else {
        perror("read");
        close(fd);
    }
}

int main(int argc, char** argv)
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int port = atoi(argv[1]);

    openlog("firewall", LOG_PID | LOG_NDELAY, LOG_LOCAL0);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(listen_fd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }
    if (listen(listen_fd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    fd_set readfds;
    while (1) {
        FD_ZERO(&readfds);
        FD_SET(listen_fd, &readfds);
        for (int i = 0; i < num_connections; i++) {
            FD_SET(connections[i].fd, &readfds);
        }
        int max_fd = listen_fd;
        for (int i = 0; i < num_connections; i++) {
            if (connections[i].fd > max_fd) {
                max_fd = connections[i].fd;
            }
        }
        int ret = select(max_fd + 1, &readfds, NULL, NULL, NULL);
        if (ret == -1) {
            perror("select");
            continue;
        }
        if (FD_ISSET(listen_fd, &readfds)) {
            accept_connection();
        }
        for (int i = 0; i < num_connections; i++) {
            if (FD_ISSET(connections[i].fd, &readfds)) {
                handle_connection(connections[i].fd);
            }
        }
    }

    closelog();

    return EXIT_SUCCESS;
}