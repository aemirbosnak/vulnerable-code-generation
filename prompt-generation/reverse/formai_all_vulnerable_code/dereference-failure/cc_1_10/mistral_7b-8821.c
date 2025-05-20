//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>

// Define constants
#define TOWER_COUNT 3
#define DISK_COUNT 10
#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ASCII_MINUS '-'
#define ASCII_SPACE ' '

// Define structures
typedef struct {
    int size;
    int *data;
} stack;

// Function prototypes
void print_towers(stack towers[TOWER_COUNT]);
int is_valid_move(stack towers[TOWER_COUNT], int from, int to);
void hanoi(stack towers[TOWER_COUNT], int n, int source, int target, int auxiliary);

// Function definitions
void print_towers(stack towers[TOWER_COUNT]) {
    int i;
    printf("Towers:\n");
    for (i = 0; i < TOWER_COUNT; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = 0; j < towers[i].size; j++) {
            printf("%c ", towers[i].data[j] + ASCII_MINUS);
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid_move(stack towers[TOWER_COUNT], int from, int to) {
    if (from < 0 || from >= TOWER_COUNT || to < 0 || to >= TOWER_COUNT) {
        return 0;
    }
    if (towers[from].size == 0) {
        return 1;
    }
    if (towers[to].size == 0 || towers[from].data[towers[from].size - 1] < towers[to].data[towers[to].size - 1]) {
        return 1;
    }
    return 0;
}

void hanoi(stack towers[TOWER_COUNT], int n, int source, int target, int auxiliary) {
    if (n > 0) {
        hanoi(towers, n - 1, source, auxiliary, target);
        if (is_valid_move(towers, source, target)) {
            int disk = towers[source].data[--towers[source].size];
            towers[target].data[towers[target].size++] = disk;
            print_towers(towers);
        } else {
            hanoi(towers, n - 1, auxiliary, target, source);
        }
        hanoi(towers, n - 1, auxiliary, source, target);
    }
}

// Main function
int main() {
    stack towers[TOWER_COUNT];

    // Initialize towers with disks
    for (int i = 0; i < TOWER_COUNT; i++) {
        towers[i].size = DISK_COUNT;
        towers[i].data = (int *) mmap(NULL, sizeof(int) * DISK_COUNT, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        for (int j = 0; j < DISK_COUNT; j++) {
            towers[i].data[j] = DISK_COUNT - j;
        }
    }

    // Start Hanoi tower problem
    hanoi(towers, DISK_COUNT, 0, 2, 1);

    // Free memory
    for (int i = 0; i < TOWER_COUNT; i++) {
        munmap(towers[i].data, sizeof(int) * DISK_COUNT);
    }

    return 0;
}