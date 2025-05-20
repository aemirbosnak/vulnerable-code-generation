//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

typedef struct {
    int num_dice;
    int num_sides;
} dice_t;

void roll_dice(dice_t dice) {
    int i, j, result;
    for (i = 0; i < dice.num_dice; i++) {
        result = rand() % dice.num_sides + 1;
        printf("Roll %d: %d\n", i+1, result);
    }
}

int main() {
    dice_t dice;
    int choice;
    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n\n");
    printf("Please enter the number of dice you want to roll: ");
    scanf("%d", &dice.num_dice);

    printf("Please enter the number of sides on each die: ");
    scanf("%d", &dice.num_sides);

    printf("\n");

    do {
        printf("1. Roll the dice\n");
        printf("2. Change the number of dice\n");
        printf("3. Change the number of sides\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                roll_dice(dice);
                break;
            case 2:
                printf("Enter the new number of dice: ");
                scanf("%d", &dice.num_dice);
                break;
            case 3:
                printf("Enter the new number of sides: ");
                scanf("%d", &dice.num_sides);
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= 4);

    return 0;
}