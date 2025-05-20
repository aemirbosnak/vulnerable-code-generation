//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INDEXES 10

typedef struct {
    char *name;
    int *values;
    int num_values;
} index_t;

index_t *indexes[MAX_INDEXES];
int num_indexes = 0;

int compare_ints(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int binary_search(int *arr, int num_elements, int value) {
    int low = 0;
    int high = num_elements - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

void add_index(char *name, int *values, int num_values) {
    if (num_indexes >= MAX_INDEXES) {
        fprintf(stderr, "Error: Too many indexes\n");
        return;
    }

    index_t *index = malloc(sizeof(index_t));
    if (index == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        return;
    }

    index->name = strdup(name);
    index->values = malloc(sizeof(int) * num_values);
    if (index->values == NULL) {
        fprintf(stderr, "Error: Out of memory\n");
        free(index);
        return;
    }

    memcpy(index->values, values, sizeof(int) * num_values);
    index->num_values = num_values;

    qsort(index->values, index->num_values, sizeof(int), compare_ints);

    indexes[num_indexes++] = index;
}

int get_index(char *name) {
    for (int i = 0; i < num_indexes; i++) {
        if (strcmp(indexes[i]->name, name) == 0) {
            return i;
        }
    }

    return -1;
}

int find_value(char *index_name, int value) {
    int index = get_index(index_name);
    if (index == -1) {
        fprintf(stderr, "Error: Index not found\n");
        return -1;
    }

    int result = binary_search(indexes[index]->values, indexes[index]->num_values, value);

    return result;
}

int main(int argc, char **argv) {
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    add_index("primary", values, 10);

    int result = find_value("primary", 5);
    if (result == -1) {
        fprintf(stderr, "Error: Value not found\n");
        return 1;
    }

    printf("Found value at index %d\n", result);

    return 0;
}