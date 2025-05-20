//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void game(int level)
{
    system("clear");
    printf("Level: %d\n", level);

    // Logic to play the game at this level
    switch (level)
    {
        case 1:
            printf("Solve the puzzle: 5 + 3 =?\n");
            int answer1 = atoi(gets(NULL));
            if (answer1 == 8)
            {
                printf("You win!\n");
                game(2);
            }
            else
            {
                printf("Wrong answer.\n");
                game(level);
            }
            break;
        case 2:
            printf("Solve the puzzle: 8 - 2 =?\n");
            int answer2 = atoi(gets(NULL));
            if (answer2 == 6)
            {
                printf("You win!\n");
                game(3);
            }
            else
            {
                printf("Wrong answer.\n");
                game(level);
            }
            break;
        case 3:
            printf("Solve the puzzle: 6 * 2 =?\n");
            int answer3 = atoi(gets(NULL));
            if (answer3 == 12)
            {
                printf("You win!\n");
                game(4);
            }
            else
            {
                printf("Wrong answer.\n");
                game(level);
            }
            break;
        case 4:
            printf("Solve the puzzle: 12 / 2 =?\n");
            int answer4 = atoi(gets(NULL));
            if (answer4 == 6)
            {
                printf("You win!\n");
                game(5);
            }
            else
            {
                printf("Wrong answer.\n");
                game(level);
            }
            break;
        case 5:
            printf("You have completed the game!\n");
            break;
    }
}

int main()
{
    game(1);

    return 0;
}