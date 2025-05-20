//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_haunted_house(void)
{
    int i, j, r, n_rooms = 5;
    char **rooms = malloc(n_rooms * sizeof(char *));
    for (i = 0; i < n_rooms; i++)
    {
        rooms[i] = malloc(20 * sizeof(char));
    }

    // Create a spooky atmosphere
    time_t t = time(NULL);
    srand(t);
    for (i = 0; i < n_rooms; i++)
    {
        for (j = 0; j < 20; j++)
        {
            rooms[i][j] = rand() % 2 ? 'A' + rand() % 26 : ' ';
        }
    }

    // Design the haunted house layout
    rooms[0] = "-----------------------\n"
                     "A A A A B B B C C\n"
                     "A A A A B B B C C\n"
                     "-----------------------";

    rooms[1] = "-----------------------\n"
                     "B B B A A A E F F\n"
                     "B B B A A A E F F\n"
                     "-----------------------";

    rooms[2] = "-----------------------\n"
                     "C C C B B A Y N N\n"
                     "C C C B B A Y N N\n"
                     "-----------------------";

    rooms[3] = "-----------------------\n"
                     "N N Y A A R T F H\n"
                     "N N Y A A R T F H\n"
                     "-----------------------";

    rooms[4] = "-----------------------\n"
                     "H T F G Y R E A D\n"
                     "H T F G Y R E A D\n"
                     "-----------------------";

    // Play the game
    printf("You are in a haunted house.\n");
    for (r = 0; r < n_rooms; r++)
    {
        printf("%s\n", rooms[r]);
    }

    free(rooms);
}

int main()
{
    play_haunted_house();

    return 0;
}