//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_BINGO_LINES 5
#define NUM_BINGO_CARD_SLOTS 25

int main() {
    srand(time(NULL));

    int* bingo_lines = malloc(sizeof(int) * NUM_BINGO_LINES);
    int* bingo_card_slots = malloc(sizeof(int) * NUM_BINGO_CARD_SLOTS);
    int i;

    for (i = 0; i < NUM_BINGO_LINES; i++) {
        bingo_lines[i] = rand() % 75;
    }

    for (i = 0; i < NUM_BINGO_CARD_SLOTS; i++) {
        bingo_card_slots[i] = rand() % 75;
    }

    // Print bingo lines
    printf("Bingo lines: \n");
    for (i = 0; i < NUM_BINGO_LINES; i++) {
        printf("%d ", bingo_lines[i]);
    }
    printf("\n");

    // Print bingo card slots
    printf("Bingo card slots: \n");
    for (i = 0; i < NUM_BINGO_CARD_SLOTS; i++) {
        printf("%d ", bingo_card_slots[i]);
    }
    printf("\n");

    // Print the result of the game
    if (is_bingo(bingo_lines, bingo_card_slots)) {
        printf("You win!\n");
    } else {
        printf("You lose.\n");
    }

    free(bingo_lines);
    free(bingo_card_slots);

    return 0;
}

int is_bingo(int* bingo_lines, int* bingo_card_slots) {
    int i, j, k, l;
    int line_index;
    int card_index;
    int line_matches;

    for (i = 0; i < NUM_BINGO_LINES; i++) {
        line_index = i;
        line_matches = 0;
        for (j = 0; j < NUM_BINGO_CARD_SLOTS; j++) {
            card_index = j;
            if (bingo_lines[line_index] == bingo_card_slots[card_index]) {
                line_matches++;
            }
        }
        if (line_matches == NUM_BINGO_CARD_SLOTS) {
            return 1;
        }
    }
    return 0;
}