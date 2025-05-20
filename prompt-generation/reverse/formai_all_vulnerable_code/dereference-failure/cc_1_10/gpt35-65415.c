//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>

#define PORT 80

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide an IP address.\n");
        exit(1);
    }

    struct sockaddr_in addr;
    int sock = 0;
    struct hostent *server;

    memset(&addr, '0', sizeof(addr));

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Failed to create socket.\n");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error: Host not found.\n");
        return 1;
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    memcpy(&addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (connect(sock, (struct sockaddr *) &addr, sizeof(addr)) < 0) {
        printf("Failed to connect.\n");
        exit(1);
    }

    char *ip = inet_ntoa(addr.sin_addr);

    printf("Connected to %s (%s).\n", server->h_name, ip);

    close(sock);

    return 0;
}