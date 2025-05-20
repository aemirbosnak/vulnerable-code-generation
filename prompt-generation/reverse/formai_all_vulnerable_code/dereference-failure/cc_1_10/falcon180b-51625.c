//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sock, port_num, bytes_recv, i, j;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    int opt = 1;

    if (argc!= 4) {
        printf("Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    for (port_num = atoi(argv[2]); port_num <= atoi(argv[3]); port_num++) {
        server_addr.sin_port = htons(port_num);
        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", port_num);
            close(sock);
            sock = socket(AF_INET, SOCK_STREAM, 0);
            if (sock == -1) {
                perror("socket");
                exit(1);
            }
            if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
                perror("setsockopt");
                exit(1);
            }
        } else {
            printf("Port %d is closed\n", port_num);
        }
    }

    close(sock);
    return 0;
}