//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Create a list of suspects
    char **suspect_list = malloc(10 * sizeof(char *));
    suspect_list[0] = "Mr. Clean";
    suspect_list[1] = "Ms. Trustworthy";
    suspect_list[2] = "Mr. Sneaky";
    suspect_list[3] = "The Ghost";
    suspect_list[4] = "The Oracle";
    suspect_list[5] = "The Mastermind";
    suspect_list[6] = "The Fence";
    suspect_list[7] = "The Spy";
    suspect_list[8] = "The Hacker";
    suspect_list[9] = "The Gambler";

    // Create a list of potential motives
    char **motive_list = malloc(10 * sizeof(char *));
    motive_list[0] = "Revenge";
    motive_list[1] = "Power";
    motive_list[2] = "Money";
    motive_list[3] = "Fear";
    motive_list[4] = "Love";
    motive_list[5] = "Self-preservation";
    motive_list[6] = "To save the world";
    motive_list[7] = "To expose the truth";
    motive_list[8] = "To gain recognition";
    motive_list[9] = "To protect their loved ones";

    // Generate a random conspiracy theory
    int theory_number = rand() % 10;
    char *theory = malloc(200 * sizeof(char));
    theory[0] = '\0';

    for (int i = 0; i < 200; i++)
    {
        theory[i] = suspect_list[rand() % 10] + ' ';
    }

    theory[199] = '\0';

    printf("Your conspiracy theory:\n\n%s", theory);

    free(suspect_list);
    free(motive_list);
    free(theory);

    return 0;
}