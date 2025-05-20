//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    char* ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + MAX_PORTS - 1;

    for (int port = start_port; port <= end_port; port++) {
        int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (socket_fd == -1) {
            printf("Error creating socket\n");
            exit(1);
        }

        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(port);
        server_addr.sin_addr.s_addr = inet_addr(ip_address);

        int connect_result = connect(socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
        if (connect_result == -1) {
            close(socket_fd);
            printf("%d - Closed\n", port);
        } else {
            char buffer[BUFFER_SIZE];
            int bytes_received = recv(socket_fd, buffer, BUFFER_SIZE, 0);
            if (bytes_received > 0) {
                printf("%d - Open\n", port);
                close(socket_fd);
            } else {
                close(socket_fd);
                printf("%d - Closed\n", port);
            }
        }
    }

    return 0;
}