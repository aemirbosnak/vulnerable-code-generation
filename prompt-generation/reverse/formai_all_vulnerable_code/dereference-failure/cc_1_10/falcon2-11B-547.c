//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <time.h>

void signal_handler(int signum) {
    fprintf(stderr, "Exiting server...\n");
    exit(1);
}

int main(int argc, char* argv[]) {
    int server_fd, conn_fd, n;
    char buffer[256], line[256];
    struct sockaddr_in client_addr;
    struct hostent *server_addr;
    struct sigaction sa;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    signal(SIGINT, signal_handler);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr = gethostbyname("localhost");
    if (server_addr == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        exit(1);
    }

    bzero((char*) &client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    bcopy((char*) server_addr->h_addr, (char*) &client_addr.sin_addr.s_addr, server_addr->h_length);
    client_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr*) &client_addr, sizeof(client_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        conn_fd = accept(server_fd, (struct sockaddr*) &client_addr, (socklen_t*) &n);
        if (conn_fd < 0) {
            perror("accept");
            exit(1);
        }

        bzero(buffer, 256);
        n = read(conn_fd, buffer, 256);
        if (n <= 0) {
            close(conn_fd);
            continue;
        }

        buffer[n] = '\0';

        printf("Received message from client: %s\n", buffer);

        time_t cur_time = time(NULL);
        char* time_stamp = ctime(&cur_time);
        strcpy(line, time_stamp);
        strcat(line, ": ");
        strcat(line, buffer);
        send(conn_fd, line, strlen(line), 0);

        close(conn_fd);
    }

    return 0;
}