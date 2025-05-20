//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10
#define MAX_NEIGHBORS 5
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* neighbors[MAX_NEIGHBORS];
    int neighbor_count;
} Node;

typedef struct Kingdom {
    Node* nodes[MAX_NODES];
    int node_count;
} Kingdom;

Kingdom* create_kingdom() {
    Kingdom* kingdom = malloc(sizeof(Kingdom));
    kingdom->node_count = 0;
    return kingdom;
}

Node* create_node(const char* name) {
    Node* node = malloc(sizeof(Node));
    strncpy(node->name, name, MAX_NAME_LENGTH);
    node->neighbor_count = 0;
    return node;
}

void add_node(Kingdom* kingdom, Node* node) {
    if (kingdom->node_count < MAX_NODES) {
        kingdom->nodes[kingdom->node_count++] = node;
    } else {
        printf("Alas! The kingdom cannot hold more nodes!\n");
    }
}

void add_edge(Node* from, Node* to) {
    if (from->neighbor_count < MAX_NEIGHBORS) {
        from->neighbors[from->neighbor_count++] = to;
    } else {
        printf("The noble %s hath reached his limit in neighbors!\n", from->name);
    }
}

void display_kingdom(Kingdom* kingdom) {
    printf("Behold the grand kingdom of nodes!\n");
    for (int i = 0; i < kingdom->node_count; i++) {
        Node* node = kingdom->nodes[i];
        printf("Node: %s, connected to: ", node->name);
        for (int j = 0; j < node->neighbor_count; j++) {
            printf("%s ", node->neighbors[j]->name);
        }
        printf("\n");
    }
}

void destroy_kingdom(Kingdom* kingdom) {
    for (int i = 0; i < kingdom->node_count; i++) {
        free(kingdom->nodes[i]);
    }
    free(kingdom);
}

int main() {
    Kingdom* my_kingdom = create_kingdom();

    Node* castle = create_node("Castle");
    Node* village = create_node("Village");
    Node* tavern = create_node("Tavern");
    Node* farm = create_node("Farm");
    Node* forest = create_node("Forest");

    add_node(my_kingdom, castle);
    add_node(my_kingdom, village);
    add_node(my_kingdom, tavern);
    add_node(my_kingdom, farm);
    add_node(my_kingdom, forest);

    add_edge(castle, village);
    add_edge(castle, tavern);
    add_edge(village, farm);
    add_edge(village, tavern);
    add_edge(farm, forest);

    display_kingdom(my_kingdom);

    destroy_kingdom(my_kingdom);
    return 0;
}