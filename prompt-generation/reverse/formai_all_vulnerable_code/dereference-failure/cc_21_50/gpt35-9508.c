//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BACKLOG 10
#define BUFFER_SIZE 1024

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <local_port> <remote_host:port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *remote_host;
    int remote_port;
    if (sscanf(argv[2], "%m[^:]:%d", &remote_host, &remote_port) != 2) {
        fprintf(stderr, "Invalid remote host:port specified\n");
        return EXIT_FAILURE;
    }

    int local_port = atoi(argv[1]);

    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == -1) {
        fprintf(stderr, "Failed to create socket: %d - %s\n", errno, strerror(errno));
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr = {0};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(local_port);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(proxy_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        fprintf(stderr, "Failed to bind socket to port %d: %d - %s\n", local_port, errno, strerror(errno));
        close(proxy_socket);
        return EXIT_FAILURE;
    }

    if (listen(proxy_socket, BACKLOG) == -1) {
        fprintf(stderr, "Failed to listen on socket: %d - %s\n", errno, strerror(errno));
        close(proxy_socket);
        return EXIT_FAILURE;
    }

    printf("Proxy listening on port %d\n", local_port);

    while (true) {
        struct sockaddr incoming_addr = {0};
        socklen_t incoming_addr_len = sizeof(incoming_addr);

        int incoming_socket = accept(proxy_socket, &incoming_addr, &incoming_addr_len);
        if (incoming_socket == -1) {
            fprintf(stderr, "Failed to accept incoming connection: %d - %s\n", errno, strerror(errno));
            continue;
        }

        char incoming_addr_str[INET6_ADDRSTRLEN] = {'\0'};
        int incoming_port = 0;

        if (incoming_addr.sa_family == AF_INET) {
            struct sockaddr_in *incoming_addr_in = (struct sockaddr_in *)&incoming_addr;
            inet_ntop(AF_INET, &incoming_addr_in->sin_addr, incoming_addr_str, INET_ADDRSTRLEN);
            incoming_port = ntohs(incoming_addr_in->sin_port);
        } else if (incoming_addr.sa_family == AF_INET6) {
            struct sockaddr_in6 *incoming_addr_in6 = (struct sockaddr_in6 *)&incoming_addr;
            inet_ntop(AF_INET6, &incoming_addr_in6->sin6_addr, incoming_addr_str, INET6_ADDRSTRLEN);
            incoming_port = ntohs(incoming_addr_in6->sin6_port);
        }

        printf("Incoming connection from %s:%d\n", incoming_addr_str, incoming_port);

        char remote_addr_str[INET6_ADDRSTRLEN] = {'\0'};
        if (inet_pton(AF_INET, remote_host, &addr.sin_addr) == -1) {
            fprintf(stderr, "Invalid remote host address: %d - %s\n", errno, strerror(errno));
            close(incoming_socket);
            continue;
        }

        addr.sin_port = htons(remote_port);

        int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
        if (remote_socket == -1) {
            fprintf(stderr, "Failed to create remote socket: %d - %s\n", errno, strerror(errno));
            close(incoming_socket);
            continue;
        }

        if (connect(remote_socket, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            fprintf(stderr, "Failed to connect to remote host: %d - %s\n", errno, strerror(errno));
            close(remote_socket);
            close(incoming_socket);
            continue;
        }

        printf("Connected to remote host %s:%d\n", remote_host, remote_port);

        fd_set fds;

        while (true) {
            FD_ZERO(&fds);
            FD_SET(incoming_socket, &fds);
            FD_SET(remote_socket, &fds);

            if (select(FD_SETSIZE, &fds, NULL, NULL, NULL) == -1) {
                fprintf(stderr, "Select failed: %d - %s\n", errno, strerror(errno));
                close(remote_socket);
                close(incoming_socket);
                break;
            }

            if (FD_ISSET(incoming_socket, &fds)) {
                char buffer[BUFFER_SIZE];
                ssize_t bytes_read = recv(incoming_socket, buffer, BUFFER_SIZE, 0);
                if (bytes_read == -1) {
                    fprintf(stderr, "Failed to read from incoming socket: %d - %s\n", errno, strerror(errno));
                    close(remote_socket);
                    close(incoming_socket);
                    break;
                } else if (bytes_read == 0) {
                    printf("Incoming socket closed by remote host\n");
                    close(remote_socket);
                    close(incoming_socket);
                    break;
                }

                ssize_t bytes_written = send(remote_socket, buffer, bytes_read, 0);
                if (bytes_written == -1) {
                    fprintf(stderr, "Failed to write to remote socket: %d - %s\n", errno, strerror(errno));
                    close(remote_socket);
                    close(incoming_socket);
                    break;
                }
            }

            if (FD_ISSET(remote_socket, &fds)) {
                char buffer[BUFFER_SIZE];
                ssize_t bytes_read = recv(remote_socket, buffer, BUFFER_SIZE, 0);
                if (bytes_read == -1) {
                    fprintf(stderr, "Failed to read from remote socket: %d - %s\n", errno, strerror(errno));
                    close(remote_socket);
                    close(incoming_socket);
                    break;
                } else if (bytes_read == 0) {
                    printf("Remote socket closed by remote host\n");
                    close(remote_socket);
                    close(incoming_socket);
                    break;
                }

                ssize_t bytes_written = send(incoming_socket, buffer, bytes_read, 0);
                if (bytes_written == -1) {
                    fprintf(stderr, "Failed to write to incoming socket: %d - %s\n", errno, strerror(errno));
                    close(remote_socket);
                    close(incoming_socket);
                    break;
                }
            }
        }
    }

    return EXIT_SUCCESS;
}