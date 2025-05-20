//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <ip_address> <start_port> <end_port>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port < 0 || start_port > MAX_PORT || end_port < 0 || end_port > MAX_PORT || start_port > end_port) {
        printf("Invalid port range\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_address);

    for (int port = start_port; port <= end_port; port++) {
        server_addr.sin_port = htons(port);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            continue;
        }

        int status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (status == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }

        close(sockfd);
    }

    return 0;
}