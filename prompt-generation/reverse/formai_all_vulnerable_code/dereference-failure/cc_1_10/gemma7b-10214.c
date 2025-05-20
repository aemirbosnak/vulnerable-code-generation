//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_HOSTS 10

typedef struct Host {
    char name[25];
    int num_ports;
    struct Host **connections;
} Host;

Host **hosts = NULL;

void map_topology() {
    int i, j, k;
    Host *host, *conn;

    for (i = 0; i < MAX_HOSTS; i++) {
        host = hosts[i];

        printf("%s has %d ports:\n", host->name, host->num_ports);

        for (j = 0; j < host->num_ports; j++) {
            for (k = 0; k < host->num_ports; k++) {
                if (j != k) {
                    conn = host->connections[k];

                    if (conn) {
                        printf("%s is connected to %s on port %d\n", host->name, conn->name, conn->num_ports);
                    }
                }
            }
        }
    }
}

int main() {
    int i;
    Host *new_host;

    hosts = malloc(MAX_HOSTS * sizeof(Host));

    for (i = 0; i < MAX_HOSTS; i++) {
        new_host = hosts[i] = malloc(sizeof(Host));
        strcpy(new_host->name, "Host " + i);
        new_host->num_ports = i + 1;
        new_host->connections = NULL;
    }

    hosts[0]->connections = malloc(sizeof(Host *) * 2);
    hosts[0]->connections[0] = hosts[1];
    hosts[0]->connections[1] = hosts[2];

    hosts[1]->connections = malloc(sizeof(Host *) * 1);
    hosts[1]->connections[0] = hosts[0];

    hosts[2]->connections = malloc(sizeof(Host *) * 1);
    hosts[2]->connections[0] = hosts[0];

    map_topology();

    return 0;
}