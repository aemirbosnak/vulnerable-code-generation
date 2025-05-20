//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORT_RANGE 65536
#define MAX_HOSTNAME_LENGTH 256

struct host_info {
    int port;
    char hostname[MAX_HOSTNAME_LENGTH];
};

void init_host_info(struct host_info *hosts, int num_hosts) {
    int i;
    for (i = 0; i < num_hosts; i++) {
        hosts[i].port = 0;
        hosts[i].hostname[0] = '\0';
    }
}

void scan_ports(struct host_info *hosts, int num_hosts, int start_port, int end_port) {
    int i, j, port;
    for (i = start_port; i <= end_port; i++) {
        for (j = 0; j < num_hosts; j++) {
            port = htons(i);
            if (connect(hosts[j].port, (struct sockaddr *)&hosts[j].hostname, sizeof(hosts[j].hostname)) == 1) {
                hosts[j].port = i;
                break;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int num_hosts = 10;
    struct host_info hosts[num_hosts];

    init_host_info(hosts, num_hosts);

    if (argc > 1) {
        num_hosts = atoi(argv[1]);
    }

    scan_ports(hosts, num_hosts, 1, 65535);

    for (int i = 0; i < num_hosts; i++) {
        printf("Host: %s, Port: %d\n", hosts[i].hostname, hosts[i].port);
    }

    return 0;
}