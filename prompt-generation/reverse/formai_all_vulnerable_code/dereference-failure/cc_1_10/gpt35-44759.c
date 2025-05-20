//FormAI DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port;

    int socket_desc;
    struct sockaddr_in server;

    for (; end_port <= 65535; end_port++) {
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_desc == -1) {
            printf("Could not create socket\n");
            return 1;
        }

        server.sin_addr.s_addr = inet_addr(ip_address);
        server.sin_family = AF_INET;
        server.sin_port = htons(end_port);

        int flags = fcntl(socket_desc, F_GETFL, 0);
        fcntl(socket_desc, F_SETFL, flags | O_NONBLOCK);

        connect(socket_desc, (struct sockaddr*)&server, sizeof(server));

        fd_set set;
        FD_ZERO(&set);
        FD_SET(socket_desc, &set);

        struct timeval timeout;
        timeout.tv_sec = 0;
        timeout.tv_usec = 1000;

        if (select(socket_desc + 1, NULL, &set, NULL, &timeout) == 1) {
            int error = 0;
            socklen_t error_len = sizeof(error);
            getsockopt(socket_desc, SOL_SOCKET, SO_ERROR, &error, &error_len);

            if (error == 0) {
                printf("Port %d is open.\n", end_port);
            }
        }

        close(socket_desc);
    }

    printf("Done.\n");
    return 0;
}