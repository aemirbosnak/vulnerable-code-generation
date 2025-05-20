//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void scan_ports(const char* host, int start_port, int end_port);

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <host> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char* host = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    scan_ports(host, start_port, end_port);

    return 0;
}

void scan_ports(const char* host, int start_port, int end_port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return;
    }

    struct addrinfo hints, *servinfo, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, NULL, &hints, &servinfo)!= 0) {
        printf("Error getting address info: %s\n", gai_strerror(gai_error()));
        close(sock);
        return;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if (p->ai_family == AF_INET) {
            struct sockaddr_in* sin = (struct sockaddr_in*)p->ai_addr;
            inet_ntop(AF_INET, &sin->sin_addr, host, sizeof(host));
            break;
        }
    }

    freeaddrinfo(servinfo);

    char buffer[BUFFER_SIZE];
    for (int port = start_port; port <= end_port; port++) {
        snprintf(buffer, BUFFER_SIZE, "Port %d is %s\n", port, (connect(sock, p->ai_addr, p->ai_addrlen) == 0)? "open" : "closed");
        write(1, buffer, strlen(buffer));
    }

    close(sock);
}