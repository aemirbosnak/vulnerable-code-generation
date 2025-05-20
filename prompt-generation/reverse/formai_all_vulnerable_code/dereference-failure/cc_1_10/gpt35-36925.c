//FormAI DATASET v1.0 Category: Memory management ; Style: complex
#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_SIZE 10

/* defines a custom struct to hold an integer value */
typedef struct my_int_t {
    int *value;
} my_int;

/* creates a new integer and initializes it to zero */
my_int *new_my_int() {
    my_int *mi = malloc(sizeof(my_int));
    mi->value = calloc(1, sizeof(int));
    return mi;
}

/* frees the memory occupied by the integer */
void free_my_int(my_int *mi) {
    free(mi->value);
    free(mi);
}

/* creates an array of integers and initializes them to zero */
my_int **new_my_int_array(int size) {
    my_int **arr = malloc(sizeof(my_int*) * size);
    for(int i = 0; i < size; i++) {
        arr[i] = new_my_int();
    }
    return arr;
}

/* frees the memory occupied by the array */
void free_my_int_array(my_int **arr, int size) {
    for(int i = 0; i < size; i++) {
        free_my_int(arr[i]);
    }
    free(arr);
}

int main() {
    int size = DEFAULT_SIZE;
    my_int **arr = new_my_int_array(size);

    /* use the array */

    free_my_int_array(arr, size);

    return 0;
}