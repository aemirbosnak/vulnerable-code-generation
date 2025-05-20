//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 1024

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + 1023; // Scan all ports up to 1023

    int *ports = malloc(sizeof(int) * (end_port - start_port + 1));
    if (ports == NULL) {
        printf("Error: Could not allocate memory for port list.\n");
        return 1;
    }

    for (int i = 0; i < end_port - start_port + 1; i++) {
        ports[i] = start_port + i;
    }

    int max_fd = 0;
    fd_set master_fds;
    FD_ZERO(&master_fds);

    for (int i = 0; i < end_port - start_port + 1; i++) {
        int port = ports[i];
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error: Could not create socket.\n");
            return 1;
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Open Port: %d\n", port);
            close(sock);
        } else {
            printf("Closed Port: %d\n", port);
            close(sock);
        }
    }

    free(ports);
    return 0;
}