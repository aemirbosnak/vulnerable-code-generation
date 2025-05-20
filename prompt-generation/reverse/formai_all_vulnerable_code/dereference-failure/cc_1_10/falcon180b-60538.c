//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/sysinfo.h>

#define MAX_NODES 10
#define NODE_NAME_LEN 64

typedef struct {
    char name[NODE_NAME_LEN];
    int pid;
    int ram_usage;
} node_t;

int main() {
    int num_nodes = 0;
    node_t nodes[MAX_NODES];
    char *token;
    FILE *fp;

    // Read in the list of nodes from a file
    fp = fopen("nodes.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open nodes.txt\n");
        exit(1);
    }

    while (fgets(nodes[num_nodes].name, NODE_NAME_LEN, fp)!= NULL) {
        token = strtok(nodes[num_nodes].name, " ");
        nodes[num_nodes].pid = atoi(token);
        num_nodes++;
        if (num_nodes >= MAX_NODES) {
            break;
        }
    }
    fclose(fp);

    // Get the initial RAM usage for each node
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].ram_usage = get_ram_usage(nodes[i].pid);
    }

    // Monitor RAM usage
    while (1) {
        sleep(5); // Sleep for 5 seconds between updates
        for (int i = 0; i < num_nodes; i++) {
            nodes[i].ram_usage = get_ram_usage(nodes[i].pid);
            printf("Node %s (PID %d) is using %d bytes of RAM\n", nodes[i].name, nodes[i].pid, nodes[i].ram_usage);
        }
    }

    return 0;
}

// Get the RAM usage of a process
int get_ram_usage(int pid) {
    struct sysinfo info;
    FILE *fp;
    char path[64];
    int ret;

    snprintf(path, 64, "/proc/%d/statm", pid);
    fp = fopen(path, "r");
    if (fp == NULL) {
        printf("Error: could not open %s\n", path);
        exit(1);
    }

    ret = fscanf(fp, "%*d %*d %*d %*d %*d %*d %d", &info.totalram);
    fclose(fp);

    return info.totalram;
}