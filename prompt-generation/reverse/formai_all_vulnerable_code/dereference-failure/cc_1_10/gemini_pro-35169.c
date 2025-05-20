//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 100

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <target IP> <port1> [port2] ... [port%d]\n", argv[0], MAX_PORTS);
        exit(EXIT_FAILURE);
    }

    char *target_ip = argv[1];

    int ports[MAX_PORTS];
    int num_ports = 0;
    for (int i = 2; i < argc; i++) {
        ports[num_ports++] = atoi(argv[i]);
    }

    struct sockaddr_in target_addr;
    memset(&target_addr, 0, sizeof(target_addr));
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(target_ip);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < num_ports; i++) {
        target_addr.sin_port = htons(ports[i]);

        int result = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));
        if (result == 0) {
            printf("Port %d is open\n", ports[i]);
        } else {
            printf("Port %d is closed\n", ports[i]);
        }
    }

    close(sockfd);

    return 0;
}