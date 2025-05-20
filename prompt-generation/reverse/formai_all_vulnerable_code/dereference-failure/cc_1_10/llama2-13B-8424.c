//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAGIC_NUMBER 42

struct box {
    int value;
    struct box *next;
};

struct labyrinth {
    struct box *entry;
    struct box *exit;
};

void init_labyrinth(struct labyrinth *lab) {
    lab->entry = malloc(sizeof(struct box));
    lab->entry->value = MAGIC_NUMBER;
    lab->entry->next = NULL;
    lab->exit = NULL;
}

void push_box(struct labyrinth *lab, int value) {
    struct box *new_box = malloc(sizeof(struct box));
    new_box->value = value;
    new_box->next = lab->entry;
    lab->entry = new_box;
}

int pop_box(struct labyrinth *lab) {
    int value = lab->entry->value;
    struct box *current = lab->entry;
    lab->entry = lab->entry->next;
    free(current);
    return value;
}

int main() {
    struct labyrinth lab;
    init_labyrinth(&lab);

    push_box(&lab, 1);
    push_box(&lab, 2);
    push_box(&lab, 3);

    // Now, let's get the values in reverse order!
    while (lab.entry != NULL) {
        int value = pop_box(&lab);
        printf("Value popped: %d\n", value);
    }

    return 0;
}