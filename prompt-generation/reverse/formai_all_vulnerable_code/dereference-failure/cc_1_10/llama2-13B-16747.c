//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: romantic
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

struct host_info {
    int port;
    char *host;
};

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        return 1;
    }

    struct host_info *host_list = malloc(sizeof(struct host_info) * PORT_RANGE);
    if (host_list == NULL) {
        perror("malloc failed");
        return 1;
    }

    for (int i = 0; i < PORT_RANGE; i++) {
        host_list[i].port = htons(i + 1);
        host_list[i].host = malloc(INET_ADDRSTRLEN);
        if (host_list[i].host == NULL) {
            perror("malloc failed");
            return 1;
        }
    }

    for (int i = 0; i < PORT_RANGE; i++) {
        if (connect(sock, (struct sockaddr *)&host_list[i], sizeof(struct sockaddr)) < 0) {
            perror("connect failed");
            continue;
        }

        printf("Connected to %s on port %d\n", host_list[i].host, host_list[i].port);

        char buffer[1024];
        recv(sock, buffer, 1024, 0);
        printf("Received message from %s: %s\n", host_list[i].host, buffer);

        send(sock, "Hello, my love!", 12, 0);
    }

    for (int i = 0; i < PORT_RANGE; i++) {
        free(host_list[i].host);
    }

    free(host_list);
    close(sock);

    return 0;
}