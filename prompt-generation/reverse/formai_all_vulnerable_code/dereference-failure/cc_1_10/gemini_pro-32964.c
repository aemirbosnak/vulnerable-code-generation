//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *create_list(int *data, int size) {
    node *head = NULL;
    node *current = NULL;

    for (int i = 0; i < size; i++) {
        node *new_node = (node *)malloc(sizeof(node));
        new_node->data = data[i];
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            current->next = new_node;
        }

        current = new_node;
    }

    return head;
}

void print_list(node *head) {
    node *current = head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int get_size(node *head) {
    int size = 0;
    node *current = head;

    while (current != NULL) {
        size++;
        current = current->next;
    }

    return size;
}

double get_mean(node *head) {
    int sum = 0;
    int size = get_size(head);
    node *current = head;

    while (current != NULL) {
        sum += current->data;
        current = current->next;
    }

    return (double)sum / size;
}

double get_variance(node *head) {
    double mean = get_mean(head);
    int size = get_size(head);
    double sum_of_squared_differences = 0;
    node *current = head;

    while (current != NULL) {
        sum_of_squared_differences += (current->data - mean) * (current->data - mean);
        current = current->next;
    }

    return sum_of_squared_differences / (size - 1);
}

double get_standard_deviation(node *head) {
    return sqrt(get_variance(head));
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(data) / sizeof(data[0]);
    node *head = create_list(data, size);

    print_list(head);

    printf("Size: %d\n", get_size(head));
    printf("Mean: %.2f\n", get_mean(head));
    printf("Variance: %.2f\n", get_variance(head));
    printf("Standard deviation: %.2f\n", get_standard_deviation(head));

    return 0;
}