//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_ghost_simulator()
{
    int i, j, r, t, b, n;
    char ch;

    // Create a haunted house
    int **house = (int **)malloc(10 * sizeof(int *));
    for (i = 0; i < 10; i++)
    {
        house[i] = (int *)malloc(10 * sizeof(int));
        for (j = 0; j < 10; j++)
        {
            house[i][j] = 0;
        }
    }

    // Place ghosts in the house
    house[5][5] = 1;
    house[2][3] = 1;
    house[3][8] = 1;

    // Set the timer
    time_t start = time(NULL);

    // Play the game
    while (1)
    {
        // Get the player's input
        printf("Enter a command (move, listen, exit): ");
        scanf(" %c", &ch);

        // Check if the player wants to move
        if (ch == 'm')
        {
            // Get the player's movement
            printf("Enter the direction you want to move (N, S, E, W): ");
            scanf(" %d %d ", &r, &t);

            // Check if the player has moved into a haunted room
            if (house[r][t] == 1)
            {
                printf("BOO! You have been haunted by a ghost.\n");
            }
        }

        // Check if the player wants to listen
        else if (ch == 'l')
        {
            // Listen for ghostly voices
            printf("You hear a whisper in the wind...\n");
            sleep(1);
            printf("You hear a door slamming shut...\n");
            sleep(1);
            printf("You hear a child's cry...\n");
            sleep(1);
        }

        // Check if the player wants to exit
        else if (ch == 'e')
        {
            printf("Thank you for playing the haunted house simulator.\n");
            break;
        }

        // Update the timer
        time_t end = time(NULL);
        n = end - start;
        start = end;

        // If the player has been in the house for more than 5 seconds, they have won
        if (n > 5)
        {
            printf("You have survived the haunted house! Congratulations!\n");
            break;
        }
    }

    // Free the memory used for the haunted house
    for (i = 0; i < 10; i++)
    {
        free(house[i]);
    }
    free(house);
}

int main()
{
    play_ghost_simulator();

    return 0;
}