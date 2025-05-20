//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535
#define MAX_HOSTS 255

struct host {
    char *ip;
    int num_ports;
    int *ports;
};

struct host *hosts[MAX_HOSTS];
int num_hosts = 0;

void add_host(char *ip, int num_ports, int *ports) {
    if (num_hosts >= MAX_HOSTS) {
        fprintf(stderr, "Error: too many hosts\n");
        return;
    }

    hosts[num_hosts] = malloc(sizeof(struct host));
    if (hosts[num_hosts] == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        return;
    }

    hosts[num_hosts]->ip = strdup(ip);
    if (hosts[num_hosts]->ip == NULL) {
        fprintf(stderr, "Error: strdup failed\n");
        return;
    }

    hosts[num_hosts]->num_ports = num_ports;
    hosts[num_hosts]->ports = malloc(sizeof(int) * num_ports);
    if (hosts[num_hosts]->ports == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        return;
    }

    memcpy(hosts[num_hosts]->ports, ports, sizeof(int) * num_ports);

    num_hosts++;
}

void free_hosts() {
    for (int i = 0; i < num_hosts; i++) {
        free(hosts[i]->ip);
        free(hosts[i]->ports);
        free(hosts[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <ip> <port1> <port2> ...\n", argv[0]);
        return 1;
    }

    int num_ports = argc - 1;
    int ports[num_ports];

    for (int i = 1; i < argc; i++) {
        ports[i - 1] = atoi(argv[i]);
        if (ports[i - 1] < 0 || ports[i - 1] > MAX_PORTS) {
            fprintf(stderr, "Error: invalid port\n");
            return 1;
        }
    }

    add_host(argv[1], num_ports, ports);

    // Scan the hosts
    for (int i = 0; i < num_hosts; i++) {
        struct host *host = hosts[i];

        for (int j = 0; j < host->num_ports; j++) {
            int port = host->ports[j];

            // Create a socket
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd == -1) {
                fprintf(stderr, "Error: socket failed\n");
                continue;
            }

            // Connect to the host and port
            struct sockaddr_in addr;
            memset(&addr, 0, sizeof(addr));
            addr.sin_family = AF_INET;
            addr.sin_port = htons(port);
            addr.sin_addr.s_addr = inet_addr(host->ip);

            int ret = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr));
            if (ret == -1) {
                fprintf(stderr, "Error: connect failed\n");
                close(sockfd);
                continue;
            }

            // The port is open
            printf("%s:%d is open\n", host->ip, port);

            close(sockfd);
        }
    }

    // Free the hosts
    free_hosts();

    return 0;
}