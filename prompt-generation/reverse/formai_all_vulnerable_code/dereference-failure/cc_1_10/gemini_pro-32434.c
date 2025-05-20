//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A structure to represent a tower of disks
typedef struct Tower {
    int num_disks;
    int *disks;
} Tower;

// A function to create a new tower of disks
Tower *create_tower(int num_disks) {
    Tower *tower = (Tower *)malloc(sizeof(Tower));
    tower->num_disks = num_disks;
    tower->disks = (int *)malloc(num_disks * sizeof(int));
    for (int i = 0; i < num_disks; i++) {
        tower->disks[i] = i + 1;
    }
    return tower;
}

// A function to print a tower of disks
void print_tower(Tower *tower) {
    for (int i = 0; i < tower->num_disks; i++) {
        printf("%d", tower->disks[i]);
    }
    printf("\n");
}

// A function to move a disk from one tower to another
void move_disk(Tower *source, Tower *destination) {
    int disk = source->disks[source->num_disks - 1];
    source->num_disks--;
    destination->num_disks++;
    destination->disks[destination->num_disks - 1] = disk;
}

// A function to solve the Tower of Hanoi problem
void tower_of_hanoi(Tower *source, Tower *destination, Tower *auxiliary, int num_disks) {
    if (num_disks == 1) {
        move_disk(source, destination);
    } else {
        tower_of_hanoi(source, auxiliary, destination, num_disks - 1);
        move_disk(source, destination);
        tower_of_hanoi(auxiliary, destination, source, num_disks - 1);
    }
}

int main() {
    // Create three towers
    Tower *tower1 = create_tower(3);
    Tower *tower2 = create_tower(0);
    Tower *tower3 = create_tower(0);

    // Print the initial state of the towers
    printf("Initial state:\n");
    print_tower(tower1);
    print_tower(tower2);
    print_tower(tower3);
    printf("\n");

    // Solve the Tower of Hanoi problem
    tower_of_hanoi(tower1, tower2, tower3, 3);

    // Print the final state of the towers
    printf("Final state:\n");
    print_tower(tower1);
    print_tower(tower2);
    print_tower(tower3);
    printf("\n");

    return 0;
}