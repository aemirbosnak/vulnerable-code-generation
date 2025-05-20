//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];

    int start_port = atoi(port_range);
    int end_port = 0;

    if (strchr(port_range, '-')) {
        char *port_end = strchr(port_range, '-');
        *port_end = '\0';
        end_port = atoi(port_end + 1);
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip_address);

    for (int port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            perror("socket");
            continue;
        }

        struct sockaddr_in server;
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        inet_pton(AF_INET, ip_address, &server.sin_addr);

        if (connect(sock, (struct sockaddr *)&server, sizeof(server))!= -1) {
            printf("Port %d is open\n", port);
            close(sock);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    return 0;
}