//Falcon-180B DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <pwd.h>

#define MAX_COMMAND_LENGTH 1024
#define BACKLOG 10

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    // Create socket
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set options on socket
    if (setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        printf("Error setting options on socket\n");
        exit(1);
    }

    // Bind socket to port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket to port\n");
        exit(1);
    }

    // Listen on socket
    if (listen(listen_fd, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        // Accept connection from client
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addrlen);
        if (client_fd == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        // Fork process to handle client request
        pid_t pid = fork();
        if (pid == -1) {
            printf("Error forking process\n");
            exit(1);
        } else if (pid == 0) {
            // Child process
            close(listen_fd);
            char *args[3];
            args[0] = "bash";
            args[1] = "-c";
            char command[MAX_COMMAND_LENGTH];
            snprintf(command, MAX_COMMAND_LENGTH, "echo \"Request from %s:%d\" >> /tmp/server.log; read -p \"Enter command: \" cmd; %s", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), command);
            args[2] = NULL;
            execvp(args[0], args);
            exit(1);
        } else {
            // Parent process
            close(client_fd);
        }
    }

    return 0;
}