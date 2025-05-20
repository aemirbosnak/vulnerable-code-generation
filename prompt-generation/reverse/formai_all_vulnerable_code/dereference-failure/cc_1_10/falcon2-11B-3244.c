//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[])
{
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        return 1;
    }

    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding to port");
        return 1;
    }

    if (listen(listen_fd, 5) == -1) {
        perror("Error listening for connections");
        return 1;
    }

    while (1) {
        int client_fd = accept(listen_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("Error accepting connection");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
        char buffer[1024];
        int len = read(client_fd, buffer, sizeof(buffer));
        if (len == -1) {
            perror("Error reading from client");
            close(client_fd);
            continue;
        }

        printf("Received message from client: %s\n", buffer);
        for (int i = 0; i < len; i++) {
            write(client_fd, buffer + i, len - i);
        }
        close(client_fd);
    }

    return 0;
}