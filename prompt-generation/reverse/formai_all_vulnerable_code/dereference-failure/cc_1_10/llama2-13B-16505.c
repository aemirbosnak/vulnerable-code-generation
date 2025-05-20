//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define MAX_HOST_LEN 100

struct host_info {
    int port;
    char host[MAX_HOST_LEN];
};

void init_host_info(struct host_info *host_info, int port) {
    host_info->port = port;
    memset(host_info->host, 0, MAX_HOST_LEN);
}

void print_host_info(struct host_info *host_info) {
    printf("Host: %s, Port: %d\n", host_info->host, host_info->port);
}

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct host_info host_info;
    init_host_info(&host_info, 22); // default port 22 for SSH

    // scan hosts in range [1-65535]
    for (int i = 1; i < 65536; i++) {
        char host[MAX_HOST_LEN];
        snprintf(host, MAX_HOST_LEN, "%d.%d.%d.%d", i / 256, (i / 256) % 256, i % 256, 0);
        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(host_info.port);
        memcpy(&serv_addr.sin_addr, host, MAX_HOST_LEN);

        int result = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
        if (result < 0) {
            perror("connect failed");
            continue;
        }

        print_host_info(&host_info);
        close(sock);
    }

    return 0;
}