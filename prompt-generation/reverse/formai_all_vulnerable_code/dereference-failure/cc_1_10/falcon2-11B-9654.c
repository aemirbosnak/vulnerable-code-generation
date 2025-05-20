//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int server_fd, new_socket, portno;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen;
    char buffer[256];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    listen(server_fd, 5);

    while (1) {
        addrlen = sizeof(client_addr);
        new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (new_socket < 0) {
            perror("accept");
            exit(1);
        }

        while (1) {
            bzero(buffer, 256);
            read(new_socket, buffer, 256);
            if (strncmp(buffer, "exit", 4) == 0) {
                break;
            }
            write(new_socket, "You: ", 6);
            write(new_socket, buffer, strlen(buffer));
            write(new_socket, "\n", 1);
        }
        close(new_socket);
    }
    close(server_fd);
    return 0;
}