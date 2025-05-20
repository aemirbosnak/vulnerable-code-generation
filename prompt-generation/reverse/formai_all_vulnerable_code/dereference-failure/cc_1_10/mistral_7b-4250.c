//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINS 10

typedef struct HistogramNode {
    int data;
    int count;
    struct HistogramNode *next;
} HistogramNode;

void print_ascii_bar(int num) {
    int i;
    for (i = 0; i < num; i++)
        putchar('*');
    putchar('\n');
}

void build_histogram(HistogramNode **head, int data[], int size) {
    int i, bin;
    HistogramNode *current, *new_node;

    for (i = 0; i < size; i++) {
        bin = data[i] / (MAX_BINS / 2);
        for (current = *head; current != NULL; current = current->next) {
            if (current->data == bin) {
                current->count++;
                break;
            }
        }

        if (current == NULL) {
            new_node = (HistogramNode *)malloc(sizeof(HistogramNode));
            new_node->data = bin;
            new_node->count = 1;
            new_node->next = *head;
            *head = new_node;
        }
    }
}

void print_histogram(HistogramNode *head) {
    int i, max_count = 0;
    HistogramNode *current;

    for (current = head; current != NULL; current = current->next) {
        if (current->count > max_count)
            max_count = current->count;
    }

    for (current = head; current != NULL; current = current->next) {
        print_ascii_bar(current->count * (MAX_BINS / max_count));
        printf("Bin %d: %d\n", current->data, current->count);
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 8, 8, 9};
    int size = sizeof(data) / sizeof(data[0]);
    HistogramNode *head = NULL;

    build_histogram(&head, data, size);
    print_histogram(head);

    return 0;
}