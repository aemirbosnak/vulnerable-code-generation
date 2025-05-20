//FormAI DATASET v1.0 Category: Socket programming ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("socket() error");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind() error");
        exit(EXIT_FAILURE);
    }

    if (listen(server_sock, 5) == -1) {
        perror("listen() error");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %s\n", argv[1]);

    while(1) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_size = sizeof(client_addr);

        int client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_sock == -1) {
            perror("accept() error");
            continue;
        }

        char buf[BUF_SIZE];
        memset(buf, 0, BUF_SIZE);

        int read_size;
        while ((read_size = read(client_sock, buf, BUF_SIZE)) > 0) {
            if (write(client_sock, buf, strlen(buf)) != strlen(buf)) {
                fprintf(stderr, "write() error");
            }
            memset(buf, 0, BUF_SIZE);
        }

        if (read_size == -1) {
            perror("read() error");
            exit(EXIT_FAILURE);
        }

        close(client_sock);
    }

    close(server_sock);

    return 0;
}