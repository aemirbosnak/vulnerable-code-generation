//FormAI DATASET v1.0 Category: Socket programming ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port number>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket failed");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(1);
    }

    if (listen(server_fd, 5) == -1) {
        perror("listen failed");
        exit(1);
    }

    printf("Listening on port %d...\n", port);

    while (1) {
        int client_fd = accept(server_fd, NULL, NULL);
        if (client_fd == -1) {
            perror("accept failed");
            continue;
        }

        printf("Connection accepted.\n");

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork failed");
            exit(1);
        }

        if (pid == 0) { // child process
            close(server_fd);

            const char* message = "Hello from the server!";
            if (send(client_fd, message, strlen(message), 0) == -1) {
                perror("send failed");
                exit(1);
            }

            close(client_fd);

            printf("Client disconnected.\n");

            exit(0);
        }

        close(client_fd);
    }

    close(server_fd);

    return 0;
}