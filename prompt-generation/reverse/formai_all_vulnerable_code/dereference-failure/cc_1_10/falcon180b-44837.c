//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISK 10
#define MAX_MOVES ((MAX_DISK - 1) * 2)

typedef struct {
    int from;
    int to;
    int steps;
} Move;

void init(int n, int from, int to, int steps) {
    Move *move = (Move *)malloc(sizeof(Move) * n);
    for (int i = 0; i < n; i++) {
        move[i].from = from;
        move[i].to = to;
        move[i].steps = steps;
    }
}

void print_move(Move move) {
    printf("Move disk %d from %d to %d\n", move.steps, move.from, move.to);
}

void animate_move(int from, int to) {
    printf("Moving disk %d from %d to %d\n", from, from, to);
    sleep(1);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Invalid number of disks\n");
        return 1;
    }
    if (n > MAX_DISK) {
        printf("Number of disks too large\n");
        return 1;
    }
    srand(time(NULL));
    Move *move = (Move *)malloc(sizeof(Move) * MAX_MOVES);
    init(MAX_MOVES, 1, 3, 1);
    printf("Tower of Hanoi with %d disks:\n", n);
    for (int i = 0; i < MAX_MOVES; i++) {
        print_move(move[i]);
        animate_move(move[i].from, move[i].to);
    }
    free(move);
    return 0;
}