//LLAMA2-13B DATASET v1.0 Category: Searching algorithm ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct node {
    int x;
    int y;
    int distance;
    struct node* next;
};

struct node* create_node(int x, int y) {
    struct node* node = malloc(sizeof(struct node));
    node->x = x;
    node->y = y;
    node->distance = 0;
    node->next = NULL;
    return node;
}

void add_node(struct node** head_ref, int x, int y) {
    struct node* new_node = create_node(x, y);
    new_node->distance = distance(new_node->x, new_node->y);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*head_ref)->next = new_node;
    }
}

int distance(int x, int y) {
    return abs(x - y);
}

void search(struct node** head_ref, int start_x, int start_y) {
    struct node* current = *head_ref;
    struct node* previous = NULL;
    while (current != NULL) {
        if (current->x == start_x && current->y == start_y) {
            printf("Found the target point (%d, %d)\n", current->x, current->y);
            break;
        }
        previous = current;
        current = current->next;
    }
    if (previous == NULL) {
        printf("Target point not found\n");
    }
}

int main(int argc, char* argv[]) {
    struct node* head = NULL;
    int num_nodes = 5;
    int x[num_nodes], y[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        x[i] = i % 2 == 0 ? 0 : 10;
        y[i] = i % 2 == 0 ? 0 : 10;
        add_node(&head, x[i], y[i]);
    }
    search(&head, 5, 5);
    return 0;
}