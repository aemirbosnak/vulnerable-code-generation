//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 4096

void print_error(const char* message) {
    fprintf(stderr, "%s", message);
    exit(1);
}

void proxy(int client_fd, char* dest_address, char* dest_port) {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        print_error("Error creating server socket.\n");
    }

    struct addrinfo hints, *server_info, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(dest_address, dest_port, &hints, &server_info);
    if (status != 0) {
        print_error("Error getting server address.\n");
    }

    for (p = server_info; p != NULL; p = p->ai_next) {
        if (connect(server_fd, p->ai_addr, p->ai_addrlen) == -1) {
            close(server_fd);
            continue;
        }
        break;
    }

    if (p == NULL) {
        print_error("Error connecting to server.\n");
    }

    fd_set read_fds;
    while (true) {
        FD_ZERO(&read_fds);
        FD_SET(client_fd, &read_fds);
        FD_SET(server_fd, &read_fds);

        int max_fd = (client_fd > server_fd) ? client_fd : server_fd;

        int ready = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if (ready == -1) {
            print_error("Error in select system call.\n");
        }

        if (FD_ISSET(client_fd, &read_fds)) {
            char buffer[MAX_BUFFER_SIZE];
            int num_bytes = recv(client_fd, buffer, MAX_BUFFER_SIZE, 0);
            if (num_bytes == -1 || num_bytes == 0) {
                break;
            }
            send(server_fd, buffer, num_bytes, 0);
        }

        if (FD_ISSET(server_fd, &read_fds)) {
            char buffer[MAX_BUFFER_SIZE];
            int num_bytes = recv(server_fd, buffer, MAX_BUFFER_SIZE, 0);
            if (num_bytes == -1 || num_bytes == 0) {
                break;
            }
            send(client_fd, buffer, num_bytes, 0);
        }
    }

    close(server_fd);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        print_error("Usage: ./proxy <server_address> <server_port>\n");
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        print_error("Error creating server socket.\n");
    }

    struct sockaddr_in server_addr, client_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[2]));

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        print_error("Error binding server socket.\n");
    }

    if (listen(server_fd, 10) == -1) {
        print_error("Error listening on server socket.\n");
    }

    socklen_t client_addr_len = sizeof(client_addr);
    while (true) {
        int client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            print_error("Error accepting connection.\n");
        }

        printf("Accepted client connection from %s:%d\n",
            inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        proxy(client_fd, argv[1], argv[2]);

        printf("Closing connection\n");
        close(client_fd);
    }

    close(server_fd);
    return 0;
}