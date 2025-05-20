//FormAI DATASET v1.0 Category: Port Scanner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

#define NUM_PORTS 65535

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 0;
    }

    char *host = argv[1];
    int sock, result, port;
    struct sockaddr_in target;
    struct hostent *host_info;

    host_info = gethostbyname(host);
    if (!host_info) {
        printf("Host not found: %s\n", host);
        return 0;
    }

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr = *((struct in_addr *)host_info->h_addr);

    for (port = 1; port <= NUM_PORTS; port++) {
        target.sin_port = htons(port);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            printf("Socket error\n");
            return -1;
        }

        result = connect(sock, (struct sockaddr *)&target, sizeof(target));
        if (result == 0) {
            printf("Port %d is open\n", port);
        }

        close(sock);
    }
    return 0;
}