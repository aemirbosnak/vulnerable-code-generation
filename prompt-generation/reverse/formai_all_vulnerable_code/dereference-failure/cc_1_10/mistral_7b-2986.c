//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BINS 10
#define BIN_WIDTH 5

typedef struct HistogramNode {
    int key;
    int count;
    struct HistogramNode *next;
} HistogramNode;

void print_histogram(HistogramNode *head) {
    int i, bin;
    HistogramNode *current;

    printf("\nHistogram:\n");
    for (i = 0; i < MAX_BINS; i++) {
        printf("%3d: ", i * BIN_WIDTH);
        for (bin = i * BIN_WIDTH; bin < (i + 1) * BIN_WIDTH && current != NULL; bin++) {
            if (current->key == bin) {
                printf("%3d", current->count);
                current = current->next;
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}

void create_histogram(int *data, int size) {
    int i;
    HistogramNode *head = NULL, *new_node;

    for (i = 0; i < size; i++) {
        new_node = (HistogramNode *) malloc(sizeof(HistogramNode));
        new_node->key = data[i];
        new_node->count = 1;
        new_node->next = head;
        head = new_node;

        if (head->key < 0 || head->key >= MAX_BINS * BIN_WIDTH) {
            printf("\nInvalid data value: %d\n", data[i]);
            exit(EXIT_FAILURE);
        }

        while (head->next != NULL && head->next->key == head->key) {
            head->next->count++;
            head = head->next;
        }
    }
}

int main() {
    int data[] = {2, 5, 8, 10, 12, 15, 17, 20, 22, 25};
    int size = sizeof(data) / sizeof(data[0]);

    create_histogram(data, size);
    print_histogram(data == NULL ? NULL : (HistogramNode *) data);

    return 0;
}