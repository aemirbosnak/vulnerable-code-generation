//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    char ip_address[16];
    char hostname[256];
    int port_number;
    int socket_fd;
    struct sockaddr_in server_addr;
    struct hostent *host_info;

    if (argc!= 3) {
        printf("Usage:./port_scanner <IP Address> <Port Number>\n");
        return 1;
    }

    strcpy(ip_address, argv[1]);
    port_number = atoi(argv[2]);

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        printf("Error: Failed to create socket.\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);

    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        printf("Error: Invalid IP Address.\n");
        close(socket_fd);
        return 1;
    }

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Port %d is closed.\n", port_number);
        close(socket_fd);
        return 0;
    }

    printf("Port %d is open.\n", port_number);
    close(socket_fd);
    return 0;
}