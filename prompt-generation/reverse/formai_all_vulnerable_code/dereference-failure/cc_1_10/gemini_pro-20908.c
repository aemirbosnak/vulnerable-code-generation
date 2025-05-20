//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: futuristic
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PORTS 1000

int main(int argc, char **argv)
{
    if (argc < 3) {
        printf("Usage: %s <address> <port1> [port2] ...\n", argv[0]);
        return 1;
    }

    char *address = argv[1];
    int ports[MAX_PORTS];
    int numPorts = argc - 2;
    for (int i = 0; i < numPorts; i++) {
        ports[i] = atoi(argv[i + 2]);
    }

    struct hostent *host = gethostbyname(address);
    if (!host) {
        printf("Invalid address: %s\n", address);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Could not create socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    for (int i = 0; i < numPorts; i++) {
        addr.sin_port = htons(ports[i]);
        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            printf("Port %d open\n", ports[i]);
        } else {
            printf("Port %d closed\n", ports[i]);
        }
    }

    close(sock);

    return 0;
}