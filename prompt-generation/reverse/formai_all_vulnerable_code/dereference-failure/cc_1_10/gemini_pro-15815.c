//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 100

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <ip address> <port1> [port2] ... [portN]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *ip_address = argv[1];
    int ports[MAX_PORTS];
    int num_ports = 0;

    for (int i = 2; i < argc; i++) {
        if (num_ports >= MAX_PORTS) {
            break;
        }

        ports[num_ports++] = atoi(argv[i]);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int i = 0; i < num_ports; i++) {
        server_addr.sin_port = htons(ports[i]);

        int connfd = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (connfd == -1) {
            printf("Port %d: Closed\n", ports[i]);
        } else {
            printf("Port %d: Open\n", ports[i]);
            close(connfd);
        }
    }

    close(sockfd);
    return 0;
}