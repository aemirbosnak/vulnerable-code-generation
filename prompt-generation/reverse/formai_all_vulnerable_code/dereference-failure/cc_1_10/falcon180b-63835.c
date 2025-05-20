//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define NUM_DISKS 5
#define STACK_SIZE 1000

typedef struct {
    int value;
    int position;
} Disk;

void push(Disk *stack, int *top, Disk disk) {
    *top += 1;
    stack[*top] = disk;
}

Disk pop(Disk *stack, int *top) {
    Disk disk = stack[*top];
    *top -= 1;
    return disk;
}

void print_stack(Disk *stack, int top) {
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i].value);
    }
    printf("\n");
}

int main() {
    Disk disks[NUM_DISKS];
    for (int i = 0; i < NUM_DISKS; i++) {
        disks[i].value = i + 1;
        disks[i].position = 0;
    }

    int source_stack_top = 0;
    int dest_stack_top = NUM_DISKS - 1;
    int aux_stack_top = NUM_DISKS - 1;

    printf("Initial state:\n");
    print_stack(disks, NUM_DISKS);

    while (source_stack_top!= dest_stack_top) {
        int min_value = disks[source_stack_top].value;
        int min_index = source_stack_top;
        for (int i = source_stack_top + 1; i <= dest_stack_top; i++) {
            if (disks[i].value < min_value) {
                min_value = disks[i].value;
                min_index = i;
            }
        }

        Disk min_disk = pop(disks, min_index);
        push(disks, aux_stack_top, min_disk);

        printf("Move disk %d from %d to %d:\n", min_disk.value, min_index, dest_stack_top);
        print_stack(disks, NUM_DISKS);

        if (min_index == source_stack_top) {
            source_stack_top += 1;
        } else if (min_index == dest_stack_top) {
            dest_stack_top -= 1;
        } else {
            aux_stack_top -= 1;
        }
    }

    printf("Final state:\n");
    print_stack(disks, NUM_DISKS);

    return 0;
}