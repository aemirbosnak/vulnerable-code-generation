//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>

#define BUFFSIZE 4096

void handle_client(int socket_fd, int conn_fd) {
    char buffer[BUFFSIZE];
    int bytes_read;

    while (1) {
        bytes_read = read(conn_fd, buffer, BUFFSIZE);
        if (bytes_read <= 0) {
            printf("Client disconnected\n");
            break;
        }

        write(socket_fd, buffer, bytes_read);
    }

    close(conn_fd);
}

void start_server(int port) {
    int socket_fd, conn_fd, newsockfd, pid, len, i, valread;
    struct sockaddr_in serv_addr, cli_addr;
    struct sigaction sa;

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(socket_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(socket_fd, 5) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    sa.sa_handler = SIG_IGN;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGCHLD, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    while (1) {
        len = sizeof(cli_addr);
        conn_fd = accept(socket_fd, (struct sockaddr *) &cli_addr, &len);
        if (conn_fd == -1) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        pid = fork();
        if (pid == 0) {
            close(conn_fd);
            handle_client(socket_fd, conn_fd);
            exit(EXIT_SUCCESS);
        } else {
            wait(NULL);
        }
    }
}

int main(int argc, char *argv[]) {
    int port = 8000;

    if (argc == 2) {
        port = atoi(argv[1]);
    }

    start_server(port);

    return 0;
}