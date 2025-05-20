//Falcon-180B DATASET v1.0 Category: Greedy Algorithms ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

typedef struct node {
    int value;
    int index;
} Node;

Node* create_node(int value, int index) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->index = index;
    return node;
}

void delete_node(Node* node) {
    free(node);
}

void swap_nodes(Node** node1, Node** node2) {
    Node* temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

int compare_nodes(const void* node1, const void* node2) {
    Node* n1 = *(Node**) node1;
    Node* n2 = *(Node**) node2;
    return n1->value - n2->value;
}

void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int* greedy_algorithm(int* array, int size, int target_sum) {
    qsort(array, size, sizeof(int), compare_nodes);
    Node* nodes[MAX_SIZE];
    int num_nodes = 0;
    for (int i = 0; i < size; i++) {
        Node* node = create_node(array[i], i);
        if (num_nodes < MAX_SIZE) {
            nodes[num_nodes++] = node;
        } else {
            delete_node(nodes[0]);
            nodes[0] = node;
        }
    }
    int* result = (int*) malloc(sizeof(int) * num_nodes);
    int num_result = 0;
    int current_sum = 0;
    while (num_result < num_nodes && current_sum < target_sum) {
        int max_value = 0;
        int max_index = 0;
        for (int i = 0; i < num_nodes; i++) {
            if (nodes[i]->value > max_value) {
                max_value = nodes[i]->value;
                max_index = i;
            }
        }
        result[num_result++] = nodes[max_index]->value;
        current_sum += nodes[max_index]->value;
        swap_nodes(&nodes[max_index], &nodes[--num_nodes]);
    }
    return result;
}

int main() {
    int array[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
    int target_sum = 150;
    int* result = greedy_algorithm(array, sizeof(array) / sizeof(array[0]), target_sum);
    printf("Result: ");
    print_array(result, target_sum);
    free(result);
    return 0;
}