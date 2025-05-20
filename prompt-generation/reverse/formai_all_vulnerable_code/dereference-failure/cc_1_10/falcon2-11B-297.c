//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Parent Process
int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <port> <command>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char command[1024] = {'\0'};
    strcpy(command, argv[2]);

    // Create a socket
    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        return 1;
    }

    // Bind the socket to the port
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if (bind(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    // Listen for incoming connections
    listen(socket_fd, 5);

    printf("Listening on port %d...\n", port);

    // Accept incoming connections
    int client_fd = accept(socket_fd, NULL, NULL);
    if (client_fd == -1) {
        perror("accept");
        return 1;
    }

    printf("Incoming connection from %s\n", inet_ntoa(server_addr.sin_addr));

    // Create a new child process to execute the command
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        if (execvp(command, argv) == -1) {
            perror("execvp");
            exit(1);
        }
    }
    else {
        // Parent process
        close(client_fd);

        char buf[1024] = {'\0'};
        read(socket_fd, buf, sizeof(buf));
        printf("Received: %s\n", buf);

        close(socket_fd);
        exit(0);
    }

    return 0;
}