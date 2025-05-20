//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int listen_fd, conn_fd, port, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd < 0) {
        perror("listen");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (bind(listen_fd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        conn_fd = accept(listen_fd, (struct sockaddr *) &cli_addr, (socklen_t *) &n);
        if (conn_fd < 0) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Add firewall rules here

        // Send data back to client
        n = read(conn_fd, &n, sizeof(n));
        if (n <= 0) {
            close(conn_fd);
            break;
        }

        send(conn_fd, "ACK", 4, 0);

        close(conn_fd);
    }

    close(listen_fd);
    return 0;
}