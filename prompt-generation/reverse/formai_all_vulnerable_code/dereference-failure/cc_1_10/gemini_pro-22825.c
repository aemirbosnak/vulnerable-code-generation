//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *nums;
    int len;
} array;

array *
create_array(int len) {
    array *a = malloc(sizeof(array));
    a->len = len;
    a->nums = malloc(sizeof(int) * len);
    return a;
}

void
free_array(array *a) {
    free(a->nums);
    free(a);
}

void
print_array(array *a) {
    for (int i = 0; i < a->len; i++) {
        printf("%d ", a->nums[i]);
    }
    printf("\n");
}

void
swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void
sort_array(array *a) {
    for (int i = 0; i < a->len - 1; i++) {
        for (int j = i + 1; j < a->len; j++) {
            if (a->nums[i] > a->nums[j]) {
                swap(&a->nums[i], &a->nums[j]);
            }
        }
    }
}

int
main(void) {
    array *a = create_array(10);
    for (int i = 0; i < a->len; i++) {
        a->nums[i] = rand() % 100;
    }
    print_array(a);
    sort_array(a);
    print_array(a);
    free_array(a);
    return 0;
}