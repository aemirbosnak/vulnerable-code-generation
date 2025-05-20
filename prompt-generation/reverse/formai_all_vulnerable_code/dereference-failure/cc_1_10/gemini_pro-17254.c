//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define DEFAULT_PORT 80
#define MAX_PORTS 100

int main(int argc, char **argv) {
    int sockfd, port;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *hostname;
    int i, j, k;
    int ports[MAX_PORTS];
    int num_ports = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname [port1] [port2] ...\n", argv[0]);
        exit(1);
    }

    hostname = argv[1];

    for (i = 2; i < argc; i++) {
        port = atoi(argv[i]);
        if (port < 0 || port > 65535) {
            fprintf(stderr, "Invalid port: %s\n", argv[i]);
            exit(1);
        }
        ports[num_ports++] = port;
    }

    if (num_ports == 0) {
        ports[num_ports++] = DEFAULT_PORT;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host: %s\n", hostname);
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    for (i = 0; i < num_ports; i++) {
        serv_addr.sin_port = htons(ports[i]);

        if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == 0) {
            printf("Port %d is open\n", ports[i]);
        } else {
            printf("Port %d is closed\n", ports[i]);
        }
    }

    close(sockfd);

    return 0;
}