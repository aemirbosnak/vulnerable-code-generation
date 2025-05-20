//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65536
#define MAX_IP_ADDR_LEN 16

struct port_scan_config {
    int start_port;
    int end_port;
    char *ip_addr;
};

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <start_port> <end_port> <ip_addr>\n", argv[0]);
        return 1;
    }

    struct port_scan_config config;
    config.start_port = atoi(argv[1]);
    config.end_port = atoi(argv[2]);
    strcpy(config.ip_addr, argv[3]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, config.ip_addr, &server_addr.sin_addr);
    server_addr.sin_port = htons(config.start_port);

    int result = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (result < 0) {
        perror("connect() failed");
        return 1;
    }

    for (int port = config.start_port; port <= config.end_port; port++) {
        struct sockaddr_in client_addr;
        client_addr.sin_family = AF_INET;
        client_addr.sin_port = htons(port);
        inet_pton(AF_INET, "0.0.0.0", &client_addr.sin_addr);

        result = connect(sock, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (result < 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sock);
    return 0;
}