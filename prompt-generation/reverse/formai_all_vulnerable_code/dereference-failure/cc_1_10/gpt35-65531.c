//FormAI DATASET v1.0 Category: Port Scanner ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

int main(int argc, char **argv) {
    char *host = "localhost";
    int start_port = 0;
    int end_port = 65535;
    int timeout = 1;

    if (argc == 2) {
        host = argv[1];
    } else if (argc == 3) {
        host = argv[1];
        start_port = atoi(argv[2]);
    } else if (argc == 4) {
        host = argv[1];
        start_port = atoi(argv[2]);
        end_port = atoi(argv[3]);
    } else if (argc == 5) {
        host = argv[1];
        start_port = atoi(argv[2]);
        end_port = atoi(argv[3]);
        timeout = atoi(argv[4]);
    }

    printf("Starting port scanner on %s, ports %d-%d, timeout %d.\n", host, start_port, end_port, timeout);

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Failed to create socket.\n");
            continue;
        }

        struct hostent *he = gethostbyname(host);

        if (he == NULL) {
            printf("Could not resolve host %s.\n", host);
            close(sock);
            continue;
        }

        struct sockaddr_in server_address;
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(port);
        server_address.sin_addr = *((struct in_addr *) he->h_addr);
        memset(&(server_address.sin_zero), '\0', 8);

        fcntl(sock, F_SETFL, O_NONBLOCK);
        connect(sock, (struct sockaddr *) &server_address, sizeof(struct sockaddr));

        fd_set set;
        FD_ZERO(&set);
        FD_SET(sock, &set);

        struct timeval timeout_tv = {timeout, 0};
        int sel = select(sock + 1, NULL, &set, NULL, &timeout_tv);

        if (sel == -1) {
            printf("Could not establish connection on port %d.\n", port);
        }
        else if (sel == 0) {
            printf("Port %d timed out.\n", port);
        } else {
            printf("Port %d is open.\n", port);
        }

        close(sock);

    }

    printf("Finished port scanning. Have a surreal day!\n");

    return 0;
}