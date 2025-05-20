//FormAI DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define TIMEOUT 1
#define MESSAGE "Hello, server!"

struct sockaddr_in server_address;

int main(int argc, char *argv[]) {
    int sockfd, port, start_port = 1, end_port = MAX_PORTS;
    char *ip_address = NULL;

    if (argc < 2) {
        printf("Usage: %s [host] [start port] [end port]\n", argv[0]);
        return 1;
    }

    ip_address = argv[1];
    if (argc >= 3) {
        start_port = atoi(argv[2]);
    }
    if (argc >= 4) {
        end_port = atoi(argv[3]);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_address.sin_addr);

    for (port = start_port; port <= end_port; port++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            perror("socket");
            return 1;
        }

        server_address.sin_port = htons(port);
        if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == 0) {
            printf("Port %d is open\n", port);
            send(sockfd, MESSAGE, strlen(MESSAGE), 0);
            char buffer[1024];
            if (recv(sockfd, buffer, sizeof(buffer), MSG_WAITALL) >= 0) {
                printf("%s\n", buffer);
            }
            close(sockfd);
        } else {
            usleep(TIMEOUT);
            close(sockfd);
        }
    }

    return 0;
}