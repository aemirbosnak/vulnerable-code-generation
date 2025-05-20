//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

void print_tower(int n, int disk_size, int* tower_A, int* tower_B, int* tower_C);
void move_disk(int disk_size, int* tower_A, int* tower_B, int* tower_C, int start_tower, int dest_tower, int n);

int main() {
    int n = 5;
    int disk_size = 1;
    int* tower_A = malloc(n * sizeof(int));
    int* tower_B = malloc(n * sizeof(int));
    int* tower_C = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        tower_A[i] = i + 1;
        tower_B[i] = i + 1;
        tower_C[i] = i + 1;
    }

    printf("Initial Tower of Hanoi: \n");
    print_tower(n, disk_size, tower_A, tower_B, tower_C);

    move_disk(disk_size, tower_A, tower_B, tower_C, 0, 1, n);

    printf("\nAfter moving disk 1 from tower A to tower B: \n");
    print_tower(n, disk_size, tower_A, tower_B, tower_C);

    move_disk(disk_size, tower_A, tower_B, tower_C, 0, 2, n);

    printf("\nAfter moving disk 1 from tower B to tower C: \n");
    print_tower(n, disk_size, tower_A, tower_B, tower_C);

    move_disk(disk_size, tower_A, tower_B, tower_C, 1, 0, n);

    printf("\nAfter moving disk 2 from tower B to tower A: \n");
    print_tower(n, disk_size, tower_A, tower_B, tower_C);

    move_disk(disk_size, tower_A, tower_B, tower_C, 1, 2, n);

    printf("\nAfter moving disk 2 from tower A to tower C: \n");
    print_tower(n, disk_size, tower_A, tower_B, tower_C);

    move_disk(disk_size, tower_A, tower_B, tower_C, 2, 1, n);

    printf("\nAfter moving disk 3 from tower C to tower A: \n");
    print_tower(n, disk_size, tower_A, tower_B, tower_C);

    move_disk(disk_size, tower_A, tower_B, tower_C, 2, 0, n);

    printf("\nAfter moving disk 3 from tower A to tower B: \n");
    print_tower(n, disk_size, tower_A, tower_B, tower_C);

    move_disk(disk_size, tower_A, tower_B, tower_C, 0, 2, n);

    printf("\nAfter moving disk 3 from tower B to tower C: \n");
    print_tower(n, disk_size, tower_A, tower_B, tower_C);

    free(tower_A);
    free(tower_B);
    free(tower_C);

    return 0;
}

void print_tower(int n, int disk_size, int* tower_A, int* tower_B, int* tower_C) {
    printf("Tower A: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tower_A[i]);
    }
    printf("\nTower B: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tower_B[i]);
    }
    printf("\nTower C: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tower_C[i]);
    }
    printf("\n");
}

void move_disk(int disk_size, int* tower_A, int* tower_B, int* tower_C, int start_tower, int dest_tower, int n) {
    if (n == 1) {
        tower_B[start_tower] = tower_A[start_tower];
        tower_C[start_tower] = tower_A[start_tower];
        tower_A[start_tower] = 0;
        return;
    }

    move_disk(disk_size, tower_A, tower_B, tower_C, start_tower, dest_tower, n - 1);

    tower_A[start_tower] = tower_B[start_tower];
    tower_B[start_tower] = tower_C[start_tower];
    tower_C[start_tower] = tower_A[start_tower];

    move_disk(disk_size, tower_A, tower_B, tower_C, start_tower, dest_tower, n - 1);
}