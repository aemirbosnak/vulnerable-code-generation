//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to hold a Bingo card
struct card {
    int **board;
    int size;
};

// Function to initialize a Bingo card
void init_card(struct card *c, int size) {
    c->board = malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        c->board[i] = malloc(size * sizeof(int));
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            c->board[i][j] = rand() % size + 1;
        }
    }
    c->size = size;
}

// Function to print a Bingo card
void print_card(struct card *c) {
    for (int i = 0; i < c->size; i++) {
        for (int j = 0; j < c->size; j++) {
            printf("%d ", c->board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a Bingo card has a winner
int check_win(struct card *c) {
    int count = 0;
    for (int i = 0; i < c->size; i++) {
        for (int j = 0; j < c->size; j++) {
            if (c->board[i][j] == 0) {
                count++;
            } else if (c->board[i][j] == c->board[i - 1][j] || c->board[i][j] == c->board[i][j - 1] || c->board[i][j] == c->board[i - 1][j - 1]) {
                count++;
            }
        }
    }
    if (count == c->size) {
        return 1;
    }
    return 0;
}

// Main function
int main() {
    int size = 5;
    struct card c;
    init_card(&c, size);
    printf("Bingo card:\n");
    print_card(&c);
    if (check_win(&c)) {
        printf("Bingo!\n");
    } else {
        printf("No Bingo.\n");
    }
    return 0;
}