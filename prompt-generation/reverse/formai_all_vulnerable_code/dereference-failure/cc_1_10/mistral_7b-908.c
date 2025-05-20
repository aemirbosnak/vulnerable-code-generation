//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define RANDOM(n) (rand() % (n))

void roll_dice(const char* dice_str, int rolls, int* results, int* total) {
    int faces, sum = 0;
    int i, j;

    // Parse dice notation: 'dX' or 'dXdY'
    faces = 1;
    for (i = 0; dice_str[i] != '\0'; i++) {
        if (isdigit(dice_str[i])) {
            faces = faces * 10 + (dice_str[i] - '0');
            if (dice_str[i + 1] == 'd') i++;
        }
    }

    for (i = 0; i < rolls; i++) {
        int roll = RANDOM(faces) + 1;
        results[i] = roll;
        sum += roll;
    }

    *total = sum;
}

int main() {
    const char* dice_str = "3d6, 2d20";
    int rolls = 3;
    int num_dice = strlen(dice_str) / 2 + 1;
    int* results = malloc(rolls * sizeof(int));
    int total = 0;

    srand(time(NULL));
    roll_dice(dice_str, rolls, results, &total);

    printf("Rolled dice: [");
    for (int i = 0; i < rolls; i++) {
        printf("%d ", results[i]);
    }
    printf("]\nTotal: %d\n", total);

    free(results);
    return 0;
}