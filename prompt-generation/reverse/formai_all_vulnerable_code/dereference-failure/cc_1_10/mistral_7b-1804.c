//MISTRAL-7B DATASET v1.0 Category: Recursive ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct Pole {
    size_t capacity;
    size_t top;
    int *disks;
} Pole;

void hanoi(size_t num, Pole *src, Pole *aux, Pole *dest) {
    if (num > 0) {
        size_t src_top = src->top;
        size_t aux_top = aux->top;
        size_t dest_top = dest->top;

        // Move the top n-1 disks from source to auxiliary, so they are out of the way
        hanoi(num - 1, src, dest, aux);

        // Move the nth disk from source to destination
        if (dest_top > 0 && src_top > 0 && src->disks[src_top - 1] < src->disks[src_top]) {
            printf("Move disk %ld from pole %p to pole %p\n", src->disks[src_top], src, dest);
            dest->disks[dest_top + 1] = src->disks[src_top];
            dest->top++;
            src->top--;
        } else {
            printf("Invalid state: cannot move disk %ld from pole %p to pole %p\n", src->disks[src_top], src, dest);
            exit(EXIT_FAILURE);
        }

        // Move the n-1 disks that were on auxiliary to destination
        hanoi(num - 1, aux, dest, src);
    }
}

void init_pole(Pole *pole, size_t capacity) {
    pole->capacity = capacity;
    pole->top = -1;
    pole->disks = calloc(capacity, sizeof(int));
}

int main() {
    size_t num_disks = 3;

    Pole source = { .capacity = num_disks, .top = num_disks - 1 };
    Pole auxiliary = { .capacity = num_disks, .top = -1 };
    Pole destination = { .capacity = num_disks, .top = -1 };

    init_pole(&source, num_disks);
    init_pole(&auxiliary, num_disks);
    init_pole(&destination, num_disks);

    for (size_t i = num_disks; i > 0; i--) {
        source.disks[source.top--] = i;
    }

    printf("Source pole:\n");
    for (size_t i = 0; i <= source.top; i++) {
        printf("Disk %ld\n", source.disks[i]);
    }

    hanoi(num_disks, &source, &auxiliary, &destination);

    printf("\nDestination pole:\n");
    for (size_t i = 0; i <= destination.top; i++) {
        printf("Disk %ld\n", destination.disks[i]);
    }

    free(source.disks);
    free(auxiliary.disks);
    free(destination.disks);
    free(&source);
    free(&auxiliary);
    free(&destination);

    return EXIT_SUCCESS;
}