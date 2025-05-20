//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

void print_tower(int tower[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", tower[i]);
    }
    printf("\n");
}

void move_disk(int tower[], int n, int from, int to) {
    if (n == 1) {
        printf("Move disk 1 from rod %d to rod %d\n", from, to);
    } else {
        int temp[MAX_DISKS];
        int top = from;
        for (int i = n - 1; i >= 0; i--) {
            temp[i] = tower[top];
            top--;
        }
        temp[0] = tower[from];
        for (int i = 0; i < n - 1; i++) {
            tower[top] = temp[i];
            top++;
        }
        tower[to] = temp[n - 1];
    }
}

int main() {
    srand(time(NULL));
    int n = rand() % (MAX_DISKS + 1);
    int *tower = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        tower[i] = i + 1;
    }
    printf("Tower of Hanoi with %d disks:\n", n);
    print_tower(tower, n);
    move_disk(tower, n, 0, 2);
    print_tower(tower, n);
    move_disk(tower, n, 0, 1);
    print_tower(tower, n);
    move_disk(tower, n, 2, 1);
    print_tower(tower, n);
    free(tower);
    return 0;
}