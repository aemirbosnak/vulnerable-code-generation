//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORT_NUM 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, port, opt = 1;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int addrlen = sizeof(server_addr);

    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Port Range>\n");
        return 0;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting SO_REUSEADDR\n");
        exit(1);
    }

    strcpy(server_addr.sin_zero, "");
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    for (port = 1; port <= atoi(argv[2]); port++) {
        server_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *)&server_addr, addrlen) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sockfd);
    return 0;
}