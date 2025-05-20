//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_CONNECTIONS 10
#define MAX_BUFFER_SIZE 1024

struct connection {
    int fd;
    struct sockaddr_in addr;
    char* buffer;
    size_t buffer_size;
};

struct connection connections[MAX_CONNECTIONS];
int num_connections = 0;

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    if (port <= 0 || port > 65535) {
        fprintf(stderr, "Invalid port: %d\n", port);
        return 1;
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, MAX_CONNECTIONS) == -1) {
        perror("listen");
        return 1;
    }

    fd_set read_fds;
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);

        for (int i = 0; i < num_connections; i++) {
            FD_SET(connections[i].fd, &read_fds);
        }

        int max_fd = server_fd;
        for (int i = 0; i < num_connections; i++) {
            if (connections[i].fd > max_fd) {
                max_fd = connections[i].fd;
            }
        }

        int num_ready = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if (num_ready == -1) {
            perror("select");
            return 1;
        }

        if (FD_ISSET(server_fd, &read_fds)) {
            struct sockaddr_in client_addr;
            socklen_t client_addr_len = sizeof(client_addr);
            int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
            if (client_fd == -1) {
                perror("accept");
                continue;
            }

            if (num_connections >= MAX_CONNECTIONS) {
                close(client_fd);
                continue;
            }

            connections[num_connections].fd = client_fd;
            connections[num_connections].addr = client_addr;
            connections[num_connections].buffer = malloc(MAX_BUFFER_SIZE);
            connections[num_connections].buffer_size = 0;
            num_connections++;
        }

        for (int i = 0; i < num_connections; i++) {
            if (FD_ISSET(connections[i].fd, &read_fds)) {
                char buffer[MAX_BUFFER_SIZE];
                ssize_t num_bytes = recv(connections[i].fd, buffer, MAX_BUFFER_SIZE, 0);
                if (num_bytes == -1) {
                    perror("recv");
                    close(connections[i].fd);
                    connections[i] = connections[num_connections - 1];
                    num_connections--;
                    continue;
                }

                if (num_bytes == 0) {
                    close(connections[i].fd);
                    connections[i] = connections[num_connections - 1];
                    num_connections--;
                    continue;
                }

                memcpy(connections[i].buffer + connections[i].buffer_size, buffer, num_bytes);
                connections[i].buffer_size += num_bytes;

                if (connections[i].buffer_size >= 4) {
                    uint32_t magic_number = ntohl(*(uint32_t*)connections[i].buffer);
                    if (magic_number != 0x42424242) {
                        fprintf(stderr, "Invalid magic number: 0x%08x\n", magic_number);
                        close(connections[i].fd);
                        connections[i] = connections[num_connections - 1];
                        num_connections--;
                        continue;
                    }

                    uint16_t payload_size = ntohs(*(uint16_t*)(connections[i].buffer + 4));
                    if (payload_size > MAX_BUFFER_SIZE - 6) {
                        fprintf(stderr, "Invalid payload size: %d\n", payload_size);
                        close(connections[i].fd);
                        connections[i] = connections[num_connections - 1];
                        num_connections--;
                        continue;
                    }

                    if (connections[i].buffer_size >= 6 + payload_size) {
                        char* payload = connections[i].buffer + 6;
                        printf("Received payload: %s\n", payload);

                        close(connections[i].fd);
                        connections[i] = connections[num_connections - 1];
                        num_connections--;
                    }
                }
            }
        }
    }

    return 0;
}