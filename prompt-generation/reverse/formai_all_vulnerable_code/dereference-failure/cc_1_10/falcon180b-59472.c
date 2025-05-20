//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: standalone
#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

// Function to print the tower of Hanoi problem
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

// Function to check if a move is valid
bool isValidMove(char **tower, int n, int from, int to) {
    if (from < 0 || from >= n || to < 0 || to >= n || from == to)
        return false;
    if (tower[from] == NULL || tower[to] == NULL || tower[from][0] == '\0')
        return false;
    for (int i = 0; i < from; i++) {
        if (tower[to]!= NULL && tower[to][0] == '*')
            return false;
    }
    return true;
}

// Function to move the disk
void moveDisk(char **tower, int n, int from, int to) {
    if (from!= to) {
        char temp = tower[from][0];
        tower[from][0] = '\0';
        tower[to][0] = temp;
    }
}

// Main function
int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    char **tower = malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        tower[i] = malloc(2 * sizeof(char));
        sprintf(tower[i], "%d", i + 1);
    }
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\n");
    while (true) {
        printf("Enter a valid move (e.g. A->C): ");
        char from, to;
        scanf("%c%c", &from, &to);
        if (isValidMove(tower, n, from - 'A', to - 'A')) {
            moveDisk(tower, n, from - 'A', to - 'A');
            towerOfHanoi(n, 'A', 'C', 'B');
        }
    }
    for (int i = 0; i < n; i++) {
        free(tower[i]);
    }
    free(tower);
    return 0;
}