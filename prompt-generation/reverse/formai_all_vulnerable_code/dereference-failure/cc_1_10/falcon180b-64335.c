//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 5
#define BUFFER_SIZE 1024

void error_handling(char* message);

int main(int argc, char* argv[]) {
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1) {
        error_handling("socket failed");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind failed");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        error_handling("listen failed");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        socklen_t addr_size;
        client_fd = accept(listen_fd, (struct sockaddr*)&client_addr, &addr_size);

        if (client_fd == -1) {
            error_handling("accept failed");
            exit(1);
        }

        printf("Client connected with IP address: %s and port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        send(client_fd, "Welcome to the server\n", strlen("Welcome to the server\n"), 0);

        while (recv(client_fd, buffer, BUFFER_SIZE, 0) > 0) {
            printf("Client message: %s\n", buffer);
            send(client_fd, buffer, strlen(buffer), 0);
        }

        close(client_fd);
    }

    return 0;
}

void error_handling(char* message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(1);
}