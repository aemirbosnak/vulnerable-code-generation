//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 100
#define DELAY 100000 // Delay in microseconds

// Function to print the current state of the towers
void print_towers(int n, int *a, int *b, int *c) {
    printf("Current state:\n");
    printf("A: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("B: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    printf("C: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }
    printf("\n\n");
}

// Function to check if the given move is valid or not
int is_valid_move(int n, int from, int to, int *b, int *c) {
    // Check if the disk can be moved from the source tower
    if (from < 0 || from >= n) {
        return 0;
    }

    // Check if the destination tower has enough space to hold the disk
    if (to < 0 || to >= n) {
        return 0;
    }

    if (to == 0 || b[to] > b[from]) {
        return 1;
    }

    return 0;
}

// Function to move the disk from one tower to another
void move_disk(int n, int from, int to, int *a, int *b, int *c) {
    if (from!= to && is_valid_move(n, from, to, b, c)) {
        printf("Moving disk %d from tower %d to tower %d\n", a[from], from + 1, to + 1);
        b[to] = b[to] + a[from];
        a[from] = -1;
        c[to] = c[to] + 1;
        a[to] = a[from];
        print_towers(n, a, b, c);
        usleep(DELAY);
    }
}

// Function to solve the Tower of Hanoi problem using recursion
void tower_of_hanoi(int n, int from, int to, int *a, int *b, int *c) {
    if (n == 1) {
        move_disk(n, from, to, a, b, c);
        return;
    }

    tower_of_hanoi(n - 1, from, c[n - 1], a, c, b);
    tower_of_hanoi(n - 1, c[n - 1], to, b, a, c);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Initialize the towers
    int a[n], b[n], c[n];
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
        b[i] = 0;
        c[i] = 0;
    }

    // Solve the Tower of Hanoi problem
    tower_of_hanoi(n, 0, 2, a, b, c);

    return 0;
}