//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    char name[20];
    int num_friends;
    int *friends;
} Node;

typedef struct {
    int num_nodes;
    int *nodes;
} Graph;

void add_friend(Node *node, int friend_id) {
    node->num_friends++;
    node->friends[node->num_friends] = friend_id;
}

void view_friends(Node *node) {
    printf("Friends of %s:\n", node->name);
    for (int i = 0; i < node->num_friends; i++) {
        printf("  %d\n", node->friends[i]);
    }
}

void remove_friend(Node *node, int friend_id) {
    for (int i = 0; i < node->num_friends; i++) {
        if (node->friends[i] == friend_id) {
            for (int j = i; j < node->num_friends - 1; j++) {
                node->friends[j] = node->friends[j + 1];
            }
            node->num_friends--;
            break;
        }
    }
}

int main() {
    Graph graph;
    Node *nodes[MAX_NODES];

    graph.num_nodes = 0;
    graph.nodes = nodes;

    Node *node1, *node2, *node3;

    node1 = (Node *)malloc(sizeof(Node));
    node1->id = 1;
    strcpy(node1->name, "Alice");
    node1->num_friends = 0;
    node1->friends = (int *)malloc(MAX_EDGES * sizeof(int));
    nodes[0] = node1;

    node2 = (Node *)malloc(sizeof(Node));
    node2->id = 2;
    strcpy(node2->name, "Bob");
    node2->num_friends = 0;
    node2->friends = (int *)malloc(MAX_EDGES * sizeof(int));
    nodes[1] = node2;

    node3 = (Node *)malloc(sizeof(Node));
    node3->id = 3;
    strcpy(node3->name, "Charlie");
    node3->num_friends = 0;
    node3->friends = (int *)malloc(MAX_EDGES * sizeof(int));
    nodes[2] = node3;

    add_friend(node1, node2->id);
    add_friend(node2, node3->id);

    printf("Node 1's friends:\n");
    view_friends(nodes[0]);

    printf("Node 2's friends:\n");
    view_friends(nodes[1]);

    printf("Node 3's friends:\n");
    view_friends(nodes[2]);

    remove_friend(nodes[0], node2->id);
    remove_friend(nodes[2], node3->id);

    printf("Node 1's friends:\n");
    view_friends(nodes[0]);

    printf("Node 2's friends:\n");
    view_friends(nodes[1]);

    printf("Node 3's friends:\n");
    view_friends(nodes[2]);

    free(nodes[0]->friends);
    free(nodes[1]->friends);
    free(nodes[2]->friends);
    free(nodes[0]);
    free(nodes[1]);
    free(nodes[2]);

    return 0;
}