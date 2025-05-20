//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int server_fd, new_socket, n;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return 1;
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        return 1;
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        return 1;
    }

    while (1) {
        new_socket = accept(server_fd, (struct sockaddr *) &client_addr, &client_len);
        if (new_socket < 0) {
            perror("accept");
            continue;
        }

        char buffer[1024];
        bzero(buffer, sizeof(buffer));
        n = read(new_socket, buffer, sizeof(buffer));
        if (n < 0) {
            perror("read");
            continue;
        }
        buffer[n] = '\0';

        printf("Received: %s\n", buffer);

        char reply[1024];
        bzero(reply, sizeof(reply));
        sprintf(reply, "Hello, %s!\n", buffer);

        if (write(new_socket, reply, strlen(reply)) < 0) {
            perror("write");
            close(new_socket);
            continue;
        }
        close(new_socket);
    }

    close(server_fd);
    return 0;
}