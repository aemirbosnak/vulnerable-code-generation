//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE "1-65535"
#define HOST_RANGE "localhost,127.0.0.1"

struct host_info {
    char *host;
    int port;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <host> <port_range>\n", argv[0]);
        return 1;
    }

    struct host_info *hosts = NULL;
    int num_hosts = 0;

    if (strcmp(argv[1], "localhost") == 0) {
        hosts = malloc(sizeof(struct host_info));
        hosts[0].host = strdup("localhost");
        hosts[0].port = 1;
        num_hosts = 1;
    } else {
        hosts = malloc(sizeof(struct host_info) * (strcspn(argv[1], ",") + 1));
        char *token = strtok(argv[1], ",");
        int i = 0;
        while (token != NULL && i < sizeof(hosts) / sizeof(hosts[0])) {
            hosts[i].host = strdup(token);
            token = strtok(NULL, ",");
            hosts[i].port = atoi(token);
            i++;
        }
        num_hosts = i;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(1);
    }

    for (int i = 0; i < num_hosts; i++) {
        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(hosts[i].port);
        inet_pton(AF_INET, hosts[i].host, &serv_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("connect failed");
            continue;
        }

        char buffer[1024];
        recv(sock, buffer, 1024, 0);
        printf("Received data from %s:%d: %s\n", hosts[i].host, hosts[i].port, buffer);

        close(sock);
    }

    free(hosts);
    return 0;
}