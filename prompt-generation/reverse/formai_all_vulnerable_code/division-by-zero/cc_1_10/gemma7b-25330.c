//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sides, rolls, total = 0, face, result;
    char character;

    printf("Welcome to the Dice Roller!\n");
    printf("Please choose a number of sides for the die: ");
    scanf("%d", &sides);

    printf("How many rolls do you want? ");
    scanf("%d", &rolls);

    for (int i = 0; i < rolls; i++)
    {
        face = rand() % sides + 1;
        result = face;

        switch (face)
        {
            case 1:
                character = 'A';
                break;
            case 2:
                character = 'B';
                break;
            case 3:
                character = 'C';
                break;
            case 4:
                character = 'D';
                break;
            case 5:
                character = 'E';
                break;
            case 6:
                character = 'F';
                break;
        }

        printf("Roll %d: You rolled a %d and it is represented by the letter %c\n", i + 1, result, character);
        total += result;
    }

    printf("Total Roll: %d\n", total);

    return 0;
}