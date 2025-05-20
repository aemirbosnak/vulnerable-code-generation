//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DISKS 10
#define SOURCE 1
#define AUX 2
#define DEST 3

typedef struct {
    int top;
    int capacity;
    int *array;
} Stack;

void initializeStacks(Stack *source, Stack *aux, Stack *dest) {
    source->top = -1;
    source->capacity = DISKS;
    source->array = calloc(DISKS, sizeof(int));

    aux->top = -1;
    aux->capacity = DISKS;
    aux->array = calloc(DISKS, sizeof(int));

    dest->top = -1;
    dest->capacity = DISKS;
    dest->array = calloc(DISKS, sizeof(int));
}

void printStacks(Stack source, Stack aux, Stack dest) {
    printf("Source: ");
    for (int i = source.top; i >= 0; i--) {
        printf("%d ", source.array[i]);
    }
    printf("\n");

    printf("Aux: ");
    for (int i = aux.top; i >= 0; i--) {
        printf("%d ", aux.array[i]);
    }
    printf("\n");

    printf("Dest: ");
    for (int i = dest.top; i >= 0; i--) {
        printf("%d ", dest.array[i]);
    }
    printf("\n");
}

void hanoi(int n, Stack source, Stack aux, Stack dest) {
    if (n > 0) {
        int diskToMove = source.array[source.top--];

        if (n > 1) {
            hanoi(n - 1, dest, source, aux);
        }

        dest.array[dest.top++] = diskToMove;

        if (n > 1) {
            hanoi(n - 1, aux, source, dest);
        }
    }
}

int main() {
    srand(time(NULL));

    Stack source, aux, dest;
    initializeStacks(&source, &aux, &dest);

    for (int i = DISKS; i > 0; i--) {
        source.array[source.top++] = i;
    }

    printf("Initial configuration:\n");
    printStacks(source, aux, dest);

    printf("\nMoving disks from source to destination in a futuristic way...\n");

    hanoi(DISKS, source, aux, dest);

    printf("\nFinal configuration:\n");
    printStacks(source, aux, dest);

    free(source.array);
    free(aux.array);
    free(dest.array);

    return 0;
}