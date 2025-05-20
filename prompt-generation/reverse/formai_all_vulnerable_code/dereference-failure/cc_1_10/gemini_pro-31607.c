//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <host> <port1> [port2] ...\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *host = argv[1];
    int ports[MAX_PORTS];
    int num_ports = argc - 2;
    for (int i = 0; i < num_ports; i++) {
        ports[i] = atoi(argv[i + 2]);
    }

    struct hostent *host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        fprintf(stderr, "Error: Could not resolve host %s\n", host);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_ports; i++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("Error: Could not create socket");
            continue;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(ports[i]);
        memcpy(&server_addr.sin_addr.s_addr, host_entry->h_addr, host_entry->h_length);

        int conn_res = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (conn_res == 0) {
            printf("Port %d is open on host %s\n", ports[i], host);
        } else {
            printf("Port %d is closed on host %s\n", ports[i], host);
        }

        close(sockfd);
    }

    return EXIT_SUCCESS;
}