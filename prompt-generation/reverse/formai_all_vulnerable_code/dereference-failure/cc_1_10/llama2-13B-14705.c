//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024
#define HOST_RANGE 10

struct host_info {
    char *host;
    int port;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return 1;
    }

    struct host_info *hosts = malloc(HOST_RANGE * sizeof(struct host_info));
    if (hosts == NULL) {
        perror("memory allocation failed");
        return 1;
    }

    for (int i = 0; i < HOST_RANGE; i++) {
        hosts[i].host = malloc(50 * sizeof(char));
        if (hosts[i].host == NULL) {
            perror("memory allocation failed");
            return 1;
        }
        printf("Scanning host %s...\n", hosts[i].host);
    }

    for (int i = 0; i < HOST_RANGE; i++) {
        struct sockaddr_in server_addr;
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(HOST_RANGE * i + 1);
        inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
            perror("connection failed");
            continue;
        }

        printf("Connected to %s on port %d\n", hosts[i].host, server_addr.sin_port);
        sleep(1);
        close(sock);
    }

    free(hosts);
    return 0;
}