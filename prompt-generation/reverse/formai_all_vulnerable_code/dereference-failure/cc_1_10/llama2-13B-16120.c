//LLAMA2-13B DATASET v1.0 Category: CPU usage monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define MAX_NODES 10
#define MAX_CPU_USAGE 100

struct node {
    int sock;
    int pid;
    int cpu_usage;
};

struct node *nodes;
int node_count;

void init_nodes(void) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        nodes[i].sock = -1;
        nodes[i].pid = -1;
        nodes[i].cpu_usage = -1;
    }
}

void add_node(int sock, int pid) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i].sock == -1) {
            nodes[i].sock = sock;
            nodes[i].pid = pid;
            nodes[i].cpu_usage = -1;
            break;
        }
    }
}

void update_cpu_usage(int sock, int cpu_usage) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i].sock == sock) {
            nodes[i].cpu_usage = cpu_usage;
            break;
        }
    }
}

void display_cpu_usage(void) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i].cpu_usage != -1) {
            printf("%d: %d%%\n", nodes[i].pid, nodes[i].cpu_usage);
        }
    }
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;

    init_nodes();

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(1234);

    if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(1);
    }

    listen(sock, 5);

    while (1) {
        int client_sock;
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);

        client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept failed");
            exit(1);
        }

        add_node(client_sock, getpid());

        char buffer[1024];
        read(client_sock, buffer, 1024);
        int cpu_usage = atoi(buffer);
        update_cpu_usage(client_sock, cpu_usage);

        display_cpu_usage();

        close(client_sock);
    }

    return 0;
}