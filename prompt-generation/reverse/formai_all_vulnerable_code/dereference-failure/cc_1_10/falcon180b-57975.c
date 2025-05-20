//Falcon-180B DATASET v1.0 Category: Firewall ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define BACKLOG 5

int main(int argc, char **argv) {
    int listen_fd, conn_fd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t cli_size;
    char buffer[MAX_LINE];
    int opt = 1;
    int addrlen = sizeof(cli_addr);
    int yes = 1;

    if (argc < 3) {
        printf("Usage: %s <port> <log_file>\n", argv[0]);
        exit(1);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket failed");
        exit(1);
    }

    setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        cli_size = sizeof(cli_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&cli_addr, &cli_size);
        if (conn_fd < 0) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s on port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        FILE *log_file = fopen(argv[2], "a");
        if (log_file == NULL) {
            perror("fopen");
            exit(1);
        }

        fprintf(log_file, "Connection from %s on port %d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
        fclose(log_file);

        char host[NI_MAXHOST];
        char service[NI_MAXSERV];
        memset(host, 0, NI_MAXHOST);
        memset(service, 0, NI_MAXSERV);

        if (getnameinfo((struct sockaddr *)&cli_addr, sizeof(cli_addr), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0) {
            printf("Hostname: %s\n", host);
        } else {
            printf("Failed to get hostname\n");
        }

        close(conn_fd);
    }

    return 0;
}