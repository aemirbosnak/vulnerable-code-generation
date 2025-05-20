//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BINGO 5
#define MAX_N 100

void print_bingo(int* nums, int nums_size, int player_nums[], int player_nums_size) {
    printf("Player: ");
    for (int i = 0; i < player_nums_size; i++) {
        printf("%d ", player_nums[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int* player_nums = malloc(BINGO * sizeof(int));
    int* numbers = malloc(MAX_N * sizeof(int));
    int player_nums_size = BINGO;
    int numbers_size = MAX_N;

    // Fill player_nums and numbers
    for (int i = 0; i < BINGO; i++) {
        player_nums[i] = rand() % 100 + 1;
    }

    for (int i = 0; i < MAX_N; i++) {
        numbers[i] = rand() % 100 + 1;
    }

    printf("Player: ");
    for (int i = 0; i < BINGO; i++) {
        printf("%d ", player_nums[i]);
    }
    printf("\n");

    printf("Numbers: ");
    for (int i = 0; i < MAX_N; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Check if the player has a Bingo
    int bingo = 0;
    for (int i = 0; i < BINGO; i++) {
        if (player_nums[i] == numbers[i]) {
            bingo = 1;
            break;
        }
    }

    if (bingo) {
        printf("Bingo!\n");
    } else {
        printf("No Bingo.\n");
    }

    return 0;
}