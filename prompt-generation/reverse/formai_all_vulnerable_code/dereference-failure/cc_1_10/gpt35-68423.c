//FormAI DATASET v1.0 Category: Port Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/time.h>
#include <unistd.h>

#define MAXPORT 65535

int main(int argc, char *argv[]) {
    int socket_desc = 0;
    struct sockaddr_in server;
    struct timeval timeout;
    fd_set fds;
    int port = 0;
    int i = 0;
    char *hostname = NULL;

    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return -1;
    }

    hostname = argv[1];

    printf("\n[*] Scanning %s for open ports...\n", hostname);
    for (port = 1; port <= MAXPORT; port++) {
        socket_desc = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_desc == -1) {
            printf("[-] Could not create socket.\n");
            return -1;
        }
        
        server.sin_addr.s_addr = inet_addr(hostname);
        server.sin_family = AF_INET;
        server.sin_port = htons(port);

        timeout.tv_sec = 2;
        timeout.tv_usec = 0;

        fcntl(socket_desc, F_SETFL, O_NONBLOCK);

        connect(socket_desc, (struct sockaddr*)&server, sizeof(server));
        FD_ZERO(&fds);
        FD_SET(socket_desc, &fds);

        if (select(socket_desc+1, NULL, &fds, NULL, &timeout) == 1) {
            int sock_error = 0;
            socklen_t len = sizeof(sock_error);
            getsockopt(socket_desc, SOL_SOCKET, SO_ERROR, &sock_error, &len);
            if (sock_error == 0) {
                printf("[+] %d/TCP Open\n", port);
            }
        }

        close(socket_desc);
    }

    printf("\n[*] Scan completed.\n");
    return 0;
}