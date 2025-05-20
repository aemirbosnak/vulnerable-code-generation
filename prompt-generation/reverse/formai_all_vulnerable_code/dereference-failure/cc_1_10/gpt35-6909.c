//FormAI DATASET v1.0 Category: Chess engine ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Chess Board*/
struct piece {
    char type;
    char color;
};

struct square {
    int row;
    int col;
    struct piece *p;
};

struct board {
    struct square *sq[8][8];
};

/* Function to initialize the board */
void init_board(struct board *b) {
    char pos[8][8] = { {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
                        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
                        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                        {' ', '.', ' ', '.', ' ', '.', ' ', ' '},
                        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
                        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'} };

    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            b->sq[i][j]->p->type = pos[i][j]; // Assign piece type 
            b->sq[i][j]->p->color = (i<2) ? 'w' : 'b'; // Assign piece color
        }
    }
}

/* Function to print the board */
void print_board(struct board *b) {
    printf("\n   A B C D E F G H\n");
    printf("  -----------------\n");
    for(int i=0; i<8; i++) {
        printf("%d| ", i+1);
        for(int j=0; j<8; j++) {
            printf("%c ", b->sq[i][j]->p->type);
        }
        printf("|%d\n", i+1);
    }
    printf("  -----------------\n");
    printf("   A B C D E F G H\n");
}

int main() {
    /* Create board object */
    struct board *b = malloc(sizeof(struct board));
    /* Initialize board */
    init_board(b);
    /* Print board */
    print_board(b);
    return 0;
}