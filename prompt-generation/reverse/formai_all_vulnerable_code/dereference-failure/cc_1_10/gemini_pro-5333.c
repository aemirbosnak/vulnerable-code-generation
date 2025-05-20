//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// Define the number of disks
#define NUM_DISKS 3

// Define the tower names
#define TOWER_A "A"
#define TOWER_B "B"
#define TOWER_C "C"

// Define the maximum number of moves
#define MAX_MOVES 7

// Define the data structure for a tower
typedef struct tower {
    char name;
    int num_disks;
    int disks[NUM_DISKS];
} tower_t;

// Define the data structure for a move
typedef struct move {
    tower_t *from;
    tower_t *to;
    int disk;
} move_t;

// Create a new tower
tower_t *create_tower(char name) {
    tower_t *tower = malloc(sizeof(tower_t));
    if (tower == NULL) {
        return NULL;
    }
    
    tower->name = name;
    tower->num_disks = 0;
    
    return tower;
}

// Add a disk to a tower
bool add_disk(tower_t *tower, int disk) {
    if (tower->num_disks >= NUM_DISKS) {
        return false;
    }
    
    tower->disks[tower->num_disks++] = disk;
    
    return true;
}

// Remove a disk from a tower
bool remove_disk(tower_t *tower) {
    if (tower->num_disks == 0) {
        return false;
    }
    
    tower->num_disks--;
    
    return true;
}

// Create a new move
move_t *create_move(tower_t *from, tower_t *to, int disk) {
    move_t *move = malloc(sizeof(move_t));
    if (move == NULL) {
        return NULL;
    }
    
    move->from = from;
    move->to = to;
    move->disk = disk;
    
    return move;
}

// Solve the Tower of Hanoi problem
bool solve_tower_of_hanoi(tower_t *tower_a, tower_t *tower_b, tower_t *tower_c, int num_disks) {
    // If there are no disks, then we are done
    if (num_disks == 0) {
        return true;
    }
    
    // Move the top disk from tower A to tower B
    move_t *move_ab = create_move(tower_a, tower_b, tower_a->disks[tower_a->num_disks - 1]);
    if (move_ab == NULL) {
        return false;
    }
    
    // Recursively solve the Tower of Hanoi problem for the remaining disks on tower A
    if (!solve_tower_of_hanoi(tower_a, tower_c, tower_b, num_disks - 1)) {
        return false;
    }
    
    // Move the top disk from tower B to tower C
    move_t *move_bc = create_move(tower_b, tower_c, tower_b->disks[tower_b->num_disks - 1]);
    if (move_bc == NULL) {
        return false;
    }
    
    // Recursively solve the Tower of Hanoi problem for the remaining disks on tower B
    if (!solve_tower_of_hanoi(tower_b, tower_a, tower_c, num_disks - 1)) {
        return false;
    }
    
    return true;
}

// Print the towers
void print_towers(tower_t *tower_a, tower_t *tower_b, tower_t *tower_c) {
    printf("Tower A: ");
    for (int i = 0; i < tower_a->num_disks; i++) {
        printf("%d ", tower_a->disks[i]);
    }
    printf("\n");
    
    printf("Tower B: ");
    for (int i = 0; i < tower_b->num_disks; i++) {
        printf("%d ", tower_b->disks[i]);
    }
    printf("\n");
    
    printf("Tower C: ");
    for (int i = 0; i < tower_c->num_disks; i++) {
        printf("%d ", tower_c->disks[i]);
    }
    printf("\n");
}

int main() {
    // Create the towers
    tower_t *tower_a = create_tower(TOWER_A);
    if (tower_a == NULL) {
        return EXIT_FAILURE;
    }
    
    tower_t *tower_b = create_tower(TOWER_B);
    if (tower_b == NULL) {
        return EXIT_FAILURE;
    }
    
    tower_t *tower_c = create_tower(TOWER_C);
    if (tower_c == NULL) {
        return EXIT_FAILURE;
    }
    
    // Add the disks to tower A
    for (int i = NUM_DISKS; i > 0; i--) {
        if (!add_disk(tower_a, i)) {
            return EXIT_FAILURE;
        }
    }
    
    // Print the initial state of the towers
    print_towers(tower_a, tower_b, tower_c);
    
    // Solve the Tower of Hanoi problem
    if (!solve_tower_of_hanoi(tower_a, tower_b, tower_c, NUM_DISKS)) {
        return EXIT_FAILURE;
    }
    
    // Print the final state of the towers
    print_towers(tower_a, tower_b, tower_c);
    
    return EXIT_SUCCESS;
}