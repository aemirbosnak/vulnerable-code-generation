//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

void print_ports(int ports[], int num_ports) {
    printf("Open ports:\n");
    for (int i = 0; i < num_ports; i++) {
        printf("%d\n", ports[i]);
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + 1; // scan only one port

    int num_ports = 0;
    int ports[MAX_PORTS];

    for (int i = start_port; i <= end_port; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error creating socket: %s\n", strerror(errno));
            return 1;
        }

        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(i);
        inet_pton(AF_INET, ip, &addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            close(sock);
            ports[num_ports++] = i;
        } else {
            close(sock);
        }
    }

    print_ports(ports, num_ports);

    return 0;
}