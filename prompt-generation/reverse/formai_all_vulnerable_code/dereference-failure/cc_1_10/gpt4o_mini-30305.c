//GPT-4o-mini DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    struct Node* connections[MAX_NODES];
    int connection_count;
} Node;

Node* create_node(const char* name) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    strncpy(new_node->name, name, MAX_NAME_LENGTH);
    new_node->connection_count = 0;
    return new_node;
}

void connect_nodes(Node* node1, Node* node2) {
    if(node1->connection_count < MAX_NODES && node2->connection_count < MAX_NODES) {
        node1->connections[node1->connection_count++] = node2;
        node2->connections[node2->connection_count++] = node1;  // bidirectional
    }
}

void print_topology(Node* nodes[], int count) {
    printf("Network Topology:\n");
    for(int i = 0; i < count; i++) {
        printf("%s:\n", nodes[i]->name);
        for(int j = 0; j < nodes[i]->connection_count; j++) {
            printf("  - %s\n", nodes[i]->connections[j]->name);
        }
    }
}

void free_nodes(Node* nodes[], int count) {
    for(int i = 0; i < count; i++) {
        free(nodes[i]);
    }
}

Node* find_node(Node* nodes[], int count, const char* name) {
    for(int i = 0; i < count; i++) {
        if(strcmp(nodes[i]->name, name) == 0) {
            return nodes[i];
        }
    }
    return NULL;
}

int main() {
    Node* nodes[MAX_NODES];
    int node_count = 0;

    while(1) {
        printf("Enter node name (or type 'exit' to quit): ");
        char input[MAX_NAME_LENGTH];
        scanf("%s", input);
        if(strcmp(input, "exit") == 0) {
            break;
        }

        if(find_node(nodes, node_count, input) != NULL) {
            printf("Node '%s' already exists. Try another name or connect existing nodes.\n", input);
            continue;
        }

        nodes[node_count++] = create_node(input);

        char connection_input[MAX_NODES * MAX_NAME_LENGTH];
        printf("Enter names of nodes to connect with '%s' (comma-separated): ", input);
        scanf("%s", connection_input);

        char* token = strtok(connection_input, ",");
        while(token != NULL) {
            token[strcspn(token, "\n")] = '\0'; // Remove newline character
            Node* connected_node = find_node(nodes, node_count, token);
            if (connected_node) {
                connect_nodes(nodes[node_count - 1], connected_node);
            }
            token = strtok(NULL, ",");
        }
    }

    print_topology(nodes, node_count);
    free_nodes(nodes, node_count);

    return 0;
}