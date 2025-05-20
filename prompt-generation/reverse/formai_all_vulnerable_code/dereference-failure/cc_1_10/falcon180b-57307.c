//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 500
#define MAX_LINK_NAME 50

typedef struct {
    char name[MAX_LINK_NAME];
    int from_node;
    int to_node;
} link_t;

void add_link(link_t *links, int num_links, char *name, int from_node, int to_node) {
    int i;
    for (i = 0; i < num_links; i++) {
        if (strcmp(links[i].name, name) == 0) {
            printf("Link %s already exists.\n", name);
            return;
        }
    }
    strcpy(links[num_links].name, name);
    links[num_links].from_node = from_node;
    links[num_links].to_node = to_node;
    num_links++;
}

int main() {
    int num_nodes, num_links;
    char input[MAX_LINK_NAME];
    link_t links[MAX_LINKS];

    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter number of links: ");
    scanf("%d", &num_links);

    printf("Enter links (from_node to_node link_name):\n");
    while (num_links < MAX_LINKS) {
        scanf("%s", input);
        if (strcmp(input, "") == 0)
            break;
        add_link(links, num_links, input, 0, 0);
        num_links++;
    }

    printf("Network Topology:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d:\n", i);
        for (int j = 0; j < num_links; j++) {
            if (links[j].from_node == i || links[j].to_node == i) {
                printf("\t%s\n", links[j].name);
            }
        }
    }

    return 0;
}