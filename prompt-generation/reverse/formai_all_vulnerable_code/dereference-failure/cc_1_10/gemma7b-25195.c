//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("clear");
    printf("Periodic Table Quiz!\n");
    printf("------------------------\n");

    // Create an array of elements
    char **elements = malloc(sizeof(char *) * 118);
    for (int i = 0; i < 118; i++)
    {
        elements[i] = malloc(sizeof(char) * 20);
    }

    // Fill the array with element names
    elements[0] = "Hydrogen";
    elements[1] = "Helium";
    elements[2] = "Lithium";
    // ... and so on for all 118 elements

    // Generate a random question
    int question = rand() % 10;

    // Show the question
    printf("What is the chemical symbol for %s?", elements[question]);

    // Get the user's answer
    char answer[20];
    scanf("%s", answer);

    // Check if the answer is correct
    if (strcmp(answer, elements[question]) == 0)
    {
        printf("Correct!\n");
    }
    else
    {
        printf("Incorrect. The answer is %s.\n", elements[question]);
    }

    // Free the memory
    for (int i = 0; i < 118; i++)
    {
        free(elements[i]);
    }
    free(elements);

    return 0;
}