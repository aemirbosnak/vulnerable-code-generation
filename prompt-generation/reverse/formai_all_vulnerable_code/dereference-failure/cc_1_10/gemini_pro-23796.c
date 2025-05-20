//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <hostname> <port1> <port2>\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    unsigned short port1 = atoi(argv[2]);
    unsigned short port2 = atoi(argv[3]);

    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        fprintf(stderr, "Error: could not resolve hostname '%s'\n", hostname);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error: could not create socket");
        return 1;
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_port = htons(port1);
    memcpy(&sin.sin_addr, host->h_addr, host->h_length);

    if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        printf("Port %d is closed\n", port1);
    } else {
        printf("Port %d is open\n", port1);
    }

    for (unsigned short port = port1 + 1; port <= port2; port++) {
        sin.sin_port = htons(port);
        if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
            printf("Port %d is closed\n", port);
        } else {
            printf("Port %d is open\n", port);
        }
    }

    close(sock);
    return 0;
}