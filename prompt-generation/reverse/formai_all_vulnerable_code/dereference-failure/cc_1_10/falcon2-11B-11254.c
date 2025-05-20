//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <server_port> <client_ip>\n", argv[0]);
        return 1;
    }

    int server_port = atoi(argv[1]);
    char* client_ip = argv[2];

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("Error creating socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    bzero((char*)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(server_port);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error binding socket");
        return 1;
    }

    if (listen(server_fd, 5) == -1) {
        perror("Error listening on socket");
        return 1;
    }

    int client_fd;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("Error accepting client connection");
            continue;
        }

        char buffer[1024];
        int n = read(client_fd, buffer, sizeof(buffer));
        if (n <= 0) {
            perror("Error reading from client");
            close(client_fd);
            continue;
        }

        printf("Received: %s\n", buffer);

        send(client_fd, buffer, sizeof(buffer), 0);

        close(client_fd);
    }

    close(server_fd);
    return 0;
}