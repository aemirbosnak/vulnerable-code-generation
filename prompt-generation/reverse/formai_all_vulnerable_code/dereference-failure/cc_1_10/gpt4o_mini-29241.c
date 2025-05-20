//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

typedef struct Node {
    char name[50];
    struct Node* connections[MAX_NODES];
    int connection_count;
} Node;

typedef struct Kingdom {
    Node* nodes[MAX_NODES];
    int node_count;
} Kingdom;

void init_kingdom(Kingdom* kingdom) {
    kingdom->node_count = 0;
}

Node* create_node(const char* name) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->connection_count = 0;
    return new_node;
}

void add_node(Kingdom* kingdom, const char* name) {
    if (kingdom->node_count < MAX_NODES) {
        Node* new_node = create_node(name);
        kingdom->nodes[kingdom->node_count] = new_node;
        kingdom->node_count++;
    } else {
        printf("Dost thou have too many realms! Cannot add more nodes.\n");
    }
}

void connect_nodes(Node* node1, Node* node2) {
    if (node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
        node1->connections[node1->connection_count++] = node2;
        node2->connections[node2->connection_count++] = node1;
    } else {
        printf("Alas! The knights of this realm cannot connect further.\n");
    }
}

void display_kingdom(Kingdom* kingdom) {
    printf("In this grand kingdom:\n");
    for (int i = 0; i < kingdom->node_count; i++) {
        Node* node = kingdom->nodes[i];
        printf(" - %s (Connected to: ", node->name);
        for (int j = 0; j < node->connection_count; j++) {
            printf("%s", node->connections[j]->name);
            if (j < node->connection_count - 1) {
                printf(", ");
            }
        }
        printf(")\n");
    }
}

void free_kingdom(Kingdom* kingdom) {
    for (int i = 0; i < kingdom->node_count; i++) {
        free(kingdom->nodes[i]);
    }
}

int main() {
    Kingdom my_kingdom;
    init_kingdom(&my_kingdom);

    add_node(&my_kingdom, "The Castle of Light");
    add_node(&my_kingdom, "The Village of Shadows");
    add_node(&my_kingdom, "The Forest of Whispers");
    add_node(&my_kingdom, "The Mountain of Echoes");

    connect_nodes(my_kingdom.nodes[0], my_kingdom.nodes[1]); // Castle with Village
    connect_nodes(my_kingdom.nodes[1], my_kingdom.nodes[2]); // Village with Forest
    connect_nodes(my_kingdom.nodes[2], my_kingdom.nodes[3]); // Forest with Mountain
    connect_nodes(my_kingdom.nodes[0], my_kingdom.nodes[3]); // Castle with Mountain

    display_kingdom(&my_kingdom);

    free_kingdom(&my_kingdom);
    return 0;
}