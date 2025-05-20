//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    int server_fd, new_socket;
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    socklen_t client_len;
    char buffer[256];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    listen(server_fd, 5);

    while (1) {
        client_len = sizeof(client_address);
        new_socket = accept(server_fd, (struct sockaddr *)&client_address, &client_len);
        if (new_socket < 0) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            exit(1);
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        memset(buffer, 0, sizeof(buffer));
        read(new_socket, buffer, sizeof(buffer));

        if (strcmp(buffer, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n") == 0) {
            memset(buffer, 0, sizeof(buffer));
            snprintf(buffer, sizeof(buffer), "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<h1>Hello, World!</h1>\n");
            write(new_socket, buffer, sizeof(buffer));
        }

        close(new_socket);
    }

    close(server_fd);
    return 0;
}