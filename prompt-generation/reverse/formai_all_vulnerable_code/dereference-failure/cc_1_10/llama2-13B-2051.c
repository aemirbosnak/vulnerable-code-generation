//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_ARRAY_SIZE 100
#define SWAP_THRESHOLD 20

typedef struct node {
    int data;
    struct node *next;
} node_t;

node_t *sort_array(node_t *array, int left, int right) {
    int mid = (left + right) / 2;
    if (left == right) {
        return array;
    }

    node_t *left_subarray = sort_array(array, left, mid);
    node_t *right_subarray = sort_array(array, mid + 1, right);

    if (left_subarray == NULL || right_subarray == NULL) {
        return NULL;
    }

    int i = 0;
    int j = 0;
    node_t *current = left_subarray;
    node_t *next = right_subarray;

    while (current != NULL && next != NULL) {
        if (current->data <= next->data) {
            i++;
            current = current->next;
        } else {
            j++;
            next = next->next;
        }
    }

    if (i > j) {
        return left_subarray;
    } else {
        return right_subarray;
    }
}

int main() {
    srand(time(NULL));
    int array_size = MAX_ARRAY_SIZE;
    node_t *array = malloc(array_size * sizeof(node_t));

    for (int i = 0; i < array_size; i++) {
        array[i].data = rand() % 100;
    }

    int left = 0;
    int right = array_size - 1;

    while (left < right) {
        node_t *sorted_array = sort_array(array, left, right);

        if (sorted_array == NULL) {
            break;
        }

        left = 0;
        right = sorted_array->next->next - sorted_array;

        if (right < SWAP_THRESHOLD) {
            break;
        }
    }

    printf("Sorted array: ");

    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i].data);
    }

    printf("\n");

    free(array);

    return 0;
}