//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_SIZE 65535

struct node {
    char *ip_addr;
    bool discovered;
    struct node *next;
};

struct adjacency_list {
    struct node *head;
};

struct graph {
    int num_vertices;
    struct adjacency_list *list;
};

void add_edge(struct graph *g, int src, int dest) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->ip_addr = (char *) malloc(INET_ADDRSTRLEN * sizeof(char));
    inet_ntop(AF_INET, htons(dest), new_node->ip_addr, INET_ADDRSTRLEN);
    new_node->discovered = false;
    new_node->next = g->list[src].head;
    g->list[src].head = new_node;
}

void print_graph(struct graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        struct node *curr_node = g->list[i].head;
        printf("Node %d: ", i+1);
        while (curr_node) {
            printf("%s ", curr_node->ip_addr);
            curr_node = curr_node->next;
        }
        printf("\n");
    }
}

void dfs(struct graph *g, int i) {
    struct node *curr_node;
    curr_node = g->list[i].head;
    g->list[i].head->discovered = true;
    while (curr_node) {
        int next_node_index = inet_addr(curr_node->ip_addr) & 0xff;
        if (!g->list[next_node_index].head->discovered) {
            dfs(g, next_node_index);
        }
        curr_node = curr_node->next;
    }
}

int main() {
    struct graph g;
    int i, src, dest, n;
    char line[MAX_SIZE], *token;

    printf("Please enter the number of nodes: ");
    fgets(line, MAX_SIZE, stdin);
    sscanf(line, "%d", &n);

    g.num_vertices = n;
    g.list = (struct adjacency_list *) malloc(n * sizeof(struct adjacency_list));
    for (i = 0; i < n; i++) {
        g.list[i].head = NULL;
    }

    while (1) {
        printf("Enter the source and destination IP addresses separated by a space (or press enter to finish) :");
        fgets(line, MAX_SIZE, stdin);
        if (strlen(line) == 1) {
            break;
        }
        token = strtok(line, " \n");
        src = inet_addr(token) & 0xff;
        token = strtok(NULL, " \n");
        dest = inet_addr(token) & 0xff;
        add_edge(&g, src, dest);
    }

    printf("The adjacency list for the network is:\n");
    print_graph(&g);

    dfs(&g, 0);

    int count = 0;
    for (int i = 0; i < g.num_vertices; i++) {
        if (g.list[i].head->discovered) {
            count++;
        }
    }

    printf("The number of nodes discovered from Node 1 is %d.\n", count);

    return 0;
}