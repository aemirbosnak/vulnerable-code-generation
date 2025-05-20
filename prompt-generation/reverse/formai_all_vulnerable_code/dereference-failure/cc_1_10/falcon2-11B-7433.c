//Falcon2-11B DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Bag {
    int id;
    struct Bag* next;
};

struct Stack {
    struct Bag* top;
};

struct Plane {
    struct Bag* bags;
};

struct Bag* create_bag(int id) {
    struct Bag* bag = (struct Bag*)malloc(sizeof(struct Bag));
    bag->id = id;
    bag->next = NULL;
    return bag;
}

void add_to_stack(struct Stack* stack, struct Bag* bag) {
    if (stack->top!= NULL) {
        stack->top->next = bag;
    } else {
        stack->top = bag;
    }
}

void add_to_plane(struct Plane* plane, struct Bag* bag) {
    if (plane->bags!= NULL) {
        plane->bags->next = bag;
    } else {
        plane->bags = bag;
    }
}

void print_stack(struct Stack* stack) {
    struct Bag* bag = stack->top;
    while (bag!= NULL) {
        printf("Bag %d: ", bag->id);
        bag = bag->next;
    }
    printf("\n");
}

void print_plane(struct Plane* plane) {
    struct Bag* bag = plane->bags;
    while (bag!= NULL) {
        printf("Bag %d: ", bag->id);
        bag = bag->next;
    }
    printf("\n");
}

int main() {
    struct Stack stack;
    struct Plane plane;
    struct Bag* bag;
    int n = 10; // Number of bags to simulate

    for (int i = 0; i < n; i++) {
        bag = create_bag(i + 1);
        add_to_stack(&stack, bag);
        if (i % 2 == 0) {
            add_to_plane(&plane, bag);
        }
    }

    if (stack.top!= NULL) {
        printf("Error: Bags left on the plane!\n");
    } else {
        printf("All bags loaded onto the plane!\n");
    }

    return 0;
}