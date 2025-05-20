//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

typedef struct {
    uint32_t size;
    uint32_t* data;
} stack_t;

static void push(stack_t* stack, uint32_t value) {
    stack->data[stack->size++] = value;
}

static uint32_t pop(stack_t* stack) {
    return stack->data[--stack->size];
}

static void tower_of_hanoi(stack_t* src, stack_t* dst, stack_t* aux, uint32_t num_disks) {
    if (num_disks == 0) {
        return;
    }

    tower_of_hanoi(src, aux, dst, num_disks - 1);
    push(dst, pop(src));
    tower_of_hanoi(aux, dst, src, num_disks - 1);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <num_disks>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    uint32_t num_disks = atoi(argv[1]);

    stack_t src = {0};
    stack_t dst = {0};
    stack_t aux = {0};

    src.data = malloc(sizeof(uint32_t) * num_disks);
    dst.data = malloc(sizeof(uint32_t) * num_disks);
    aux.data = malloc(sizeof(uint32_t) * num_disks);

    for (uint32_t i = 0; i < num_disks; i++) {
        push(&src, num_disks - i);
    }

    tower_of_hanoi(&src, &dst, &aux, num_disks);

    for (uint32_t i = 0; i < num_disks; i++) {
        printf("%u ", pop(&dst));
    }

    printf("\n");

    free(src.data);
    free(dst.data);
    free(aux.data);

    return EXIT_SUCCESS;
}