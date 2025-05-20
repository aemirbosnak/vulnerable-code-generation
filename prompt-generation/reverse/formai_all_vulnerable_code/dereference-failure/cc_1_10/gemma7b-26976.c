//Gemma-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(NULL));

    // Create an array of suspects
    char** suspects = malloc(10 * sizeof(char*));
    for (int i = 0; i < 10; i++)
    {
        suspects[i] = malloc(20 * sizeof(char));
    }

    // Fill the suspects with random names
    for (int i = 0; i < 10; i++)
    {
        sprintf(suspects[i], "Suspect %d", i + 1);
    }

    // Create a list of potential crimes
    char** crimes = malloc(5 * sizeof(char*));
    for (int i = 0; i < 5; i++)
    {
        crimes[i] = malloc(20 * sizeof(char));
    }

    // Fill the crimes with random descriptions
    for (int i = 0; i < 5; i++)
    {
        sprintf(crimes[i], "Crime %d: %s", i + 1, "A nefarious act of grand proportions");
    }

    // Assign a random crime to each suspect
    for (int i = 0; i < 10; i++)
    {
        suspects[i][0] = crimes[rand() % 5][0];
    }

    // Print the suspects and their assigned crimes
    for (int i = 0; i < 10; i++)
    {
        printf("%s committed the crime of %s.\n", suspects[i], crimes[suspects[i][0] - 1]);
    }

    // Free the memory allocated for the suspects and crimes arrays
    for (int i = 0; i < 10; i++)
    {
        free(suspects[i]);
    }
    free(suspects);
    for (int i = 0; i < 5; i++)
    {
        free(crimes[i]);
    }
    free(crimes);

    return 0;
}