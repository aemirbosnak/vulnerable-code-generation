//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS;

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);
    server_addr.sin_port = htons(start_port);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    for (int i = start_port; i <= end_port; i++) {
        server_addr.sin_port = htons(i);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == 0) {
            printf("Port %d is open\n", i);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", i);
        } else {
            perror("connect");
        }

        close(sock);
        sock = socket(AF_INET, SOCK_STREAM, 0);
    }

    close(sock);
    return 0;
}