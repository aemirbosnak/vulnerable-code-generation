//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <netdb.h>
#include <netinet/in.h>

#define MAX_PORTS 65535
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    char *port_range = argv[2];
    int start_port = atoi(port_range);
    int end_port = start_port + MAX_PORTS;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    if (inet_pton(AF_INET, ip_address, &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address: %s\n", ip_address);
        close(sock);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    for (int i = start_port; i <= end_port; i++) {
        sprintf(buffer, "Port %d: ", i);
        send(sock, buffer, strlen(buffer), 0);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            fprintf(stderr, "Error receiving data: %s\n", strerror(errno));
            close(sock);
            return 1;
        }
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}