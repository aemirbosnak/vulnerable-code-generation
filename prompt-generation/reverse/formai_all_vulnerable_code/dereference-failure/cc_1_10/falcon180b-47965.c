//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname> <port_range>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *port_range = argv[2];

    int start_port, end_port;
    sscanf(port_range, "%d-%d", &start_port, &end_port);

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    char port[6];
    for (int i = start_port; i <= end_port; i++) {
        sprintf(port, "%d", i);
        getaddrinfo(hostname, port, &hints, &res);

        int sock = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
        if (sock == -1) {
            perror("socket");
            continue;
        }

        if (connect(sock, res->ai_addr, res->ai_addrlen) == 0) {
            printf("Port %d is open\n", i);
            close(sock);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", i);
        } else {
            printf("Error on port %d: %s\n", i, strerror(errno));
        }
    }

    return 0;
}