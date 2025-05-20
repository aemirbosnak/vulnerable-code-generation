//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void play_haunted_house(void)
{
    int i, choice;

    // Set up the haunted house
    time_t start = time(NULL);
    srand(start);

    // Create a list of rooms
    char **rooms = malloc(10 * sizeof(char *));
    for (i = 0; i < 10; i++)
    {
        rooms[i] = malloc(20 * sizeof(char));
        rooms[i][0] = '\0';
    }

    // Fill the rooms with creepy content
    for (i = 0; i < 10; i++)
    {
        sprintf(rooms[i], "Room %d: %s", i + 1, "The smell of decay and blood fills the air.");
    }

    // Choose a room
    printf("You wake up in a dark and eerie haunted house. You have no memory of how you got here. Which room do you explore?\n");
    printf("1. The Living Room\n");
    printf("2. The Dining Room\n");
    printf("3. The Kitchen\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    // Go to the chosen room
    switch (choice)
    {
        case 1:
            printf("%s\n", rooms[0]);
            break;
        case 2:
            printf("%s\n", rooms[1]);
            break;
        case 3:
            printf("%s\n", rooms[2]);
            break;
        default:
            printf("Invalid choice.\n");
            break;
    }

    // Free the memory
    for (i = 0; i < 10; i++)
    {
        free(rooms[i]);
    }
    free(rooms);
}

int main(void)
{
    play_haunted_house();

    return 0;
}