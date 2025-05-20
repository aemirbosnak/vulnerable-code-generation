//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535

void die(const char *s)
{
    perror(s);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    int sock, port, max_fd, client_fd, addrlen;
    char *ip_addr;
    struct sockaddr_in server_addr, client_addr;
    fd_set master_fds, read_fds;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    ip_addr = argv[1];
    max_fd = atoi(argv[2]) + 1;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        die("socket");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    inet_pton(AF_INET, ip_addr, &server_addr.sin_addr);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        die("bind");

    if (listen(sock, 5) == -1)
        die("listen");

    FD_ZERO(&master_fds);
    FD_SET(sock, &master_fds);
    max_fd = sock;

    while (1) {
        read_fds = master_fds;
        if (select(max_fd, &read_fds, NULL, NULL, NULL) == -1)
            die("select");

        for (port = 1; port <= MAX_PORTS; port++) {
            if (FD_ISSET(port, &read_fds)) {
                client_fd = accept(sock, (struct sockaddr *)&client_addr, &addrlen);
                if (client_fd == -1)
                    die("accept");

                printf("Connection on port %d\n", port);

                close(client_fd);
            }
        }
    }

    close(sock);
    return 0;
}