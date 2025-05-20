//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10
#define DELAY 1000

void tower_of_hanoi(int num_disks, char source, char destination, char auxiliary) {
    int top = num_disks - 1;
    char from = source;
    char to = destination;
    char temp = auxiliary;

    while (top >= 0) {
        if (top == 0) {
            printf("Move disk %d from %c to %c\n", top + 1, from, to);
        } else {
            printf("Move disk %d from %c to %c\n", top + 1, from, temp);
        }
        usleep(DELAY);
        top--;
        from = temp;
        temp = to;
        to = from;
    }
}

int main() {
    int num_disks;
    char source, destination;
    char auxiliary = 'C';

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    printf("Enter the source peg: ");
    scanf(" %c", &source);

    printf("Enter the destination peg: ");
    scanf(" %c", &destination);

    printf("Solving Tower of Hanoi problem with %d disks\n", num_disks);
    printf("Moving disks from %c to %c using %c as auxiliary peg\n", source, destination, auxiliary);

    srand(time(NULL));
    int random_move = rand() % (num_disks * 2);

    printf("\nRandom move: %d\n", random_move);

    if (random_move == 0) {
        tower_of_hanoi(num_disks, source, destination, auxiliary);
    } else {
        tower_of_hanoi(num_disks - 1, source, auxiliary, destination);
        tower_of_hanoi(1, source, destination, auxiliary);
        tower_of_hanoi(num_disks - 1, auxiliary, destination, source);
    }

    return 0;
}