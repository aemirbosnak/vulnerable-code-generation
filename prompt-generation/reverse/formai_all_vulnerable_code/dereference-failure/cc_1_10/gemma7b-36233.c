//Gemma-7B DATASET v1.0 Category: Haunted House Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void haunted_house_simulator()
{
    // Set the mood
    srand(time(NULL));
    int mood = rand() % 3;

    // Choose a haunted house
    int house_num = rand() % 5;

    // Create a spooky soundtrack
    FILE* music = fopen("haunted_house.mp3", "rb");
    if (music)
    {
        // Play the music
        system("start music.bat");
    }

    // Ghostly encounter
    int encounter = rand() % 2;

    // Spooky sounds
    switch (house_num)
    {
        case 0:
            printf("CREAKING DOORBELL...\n");
            break;
        case 1:
            printf("A BLOODSHED GASH...OMG...\n");
            break;
        case 2:
            printf("A POODLE'S WHINE...\n");
            break;
        case 3:
            printf("A SCREAMING CHILD...\n");
            break;
        case 4:
            printf("A HAUNTED CROOK...\n");
            break;
    }

    // Ghostly interaction
    switch (encounter)
    {
        case 0:
            printf("The door swings open, but nothing is there...\n");
            break;
        case 1:
            printf("A ghostly figure appears, its eyes glowing...\n");
            break;
    }

    // Exit the haunted house
    printf("YOU ESCAPED THE HAUNTED HOUSE!\n");
}

int main()
{
    haunted_house_simulator();

    return 0;
}