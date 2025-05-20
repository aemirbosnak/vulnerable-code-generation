//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 1024
#define MAX_HOSTNAME 1024

struct port_info {
    int port;
    char hostname[MAX_HOSTNAME];
};

void scan_ports(int sock, struct port_info *ports) {
    int i, j;
    socklen_t len = sizeof(struct sockaddr);
    struct sockaddr_in server_addr;
    char buffer[256];

    for (i = 0; i < MAX_PORTS; i++) {
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(i);
        if (connect(sock, (struct sockaddr *)&server_addr, len) == 0) {
            printf("Connected to port %d on %s\n", i, inet_ntoa(server_addr.sin_addr));
            strcpy(ports[i].hostname, inet_ntoa(server_addr.sin_addr));
            ports[i].port = i;
        }
    }
}

int main() {
    int sock;
    struct port_info ports[MAX_PORTS];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    scan_ports(sock, ports);

    for (int i = 0; i < MAX_PORTS; i++) {
        printf("Port %d on %s is open\n", ports[i].port, ports[i].hostname);
    }

    close(sock);
    return 0;
}