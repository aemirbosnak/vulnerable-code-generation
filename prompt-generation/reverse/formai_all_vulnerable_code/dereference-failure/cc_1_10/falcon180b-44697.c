//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 200

typedef struct {
    int id;
    char name[10];
    int links[MAX_LINKS];
    int num_links;
} Node;

void add_link(Node* node1, Node* node2) {
    int i;
    for (i = 0; i < node1->num_links; i++) {
        if (node1->links[i] == node2->id) {
            return;
        }
    }
    node1->links[i] = node2->id;
    node1->num_links++;
    node2->links[node2->num_links] = node1->id;
    node2->num_links++;
}

void print_links(Node* node) {
    int i;
    printf("Links: ");
    for (i = 0; i < node->num_links; i++) {
        printf("%d ", node->links[i]);
    }
    printf("\n");
}

int main() {
    Node nodes[MAX_NODES];
    int num_nodes = 0;
    int choice;
    char name[10];

    do {
        printf("Choose an option:\n");
        printf("1. Add node\n");
        printf("2. Add link\n");
        printf("3. Print network topology\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter node name: ");
            scanf("%s", name);
            if (num_nodes >= MAX_NODES) {
                printf("Error: Maximum number of nodes reached.\n");
            } else {
                nodes[num_nodes].id = num_nodes + 1;
                strcpy(nodes[num_nodes].name, name);
                num_nodes++;
            }
            break;
        case 2:
            printf("Enter node 1 ID: ");
            scanf("%d", &nodes[0].id);
            printf("Enter node 2 ID: ");
            scanf("%d", &nodes[1].id);
            add_link(&nodes[0], &nodes[1]);
            break;
        case 3:
            printf("Network Topology:\n");
            for (int i = 0; i < num_nodes; i++) {
                printf("Node %d: %s\n", nodes[i].id, nodes[i].name);
                print_links(&nodes[i]);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}