//Gemma-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX 118

int main()
{
    system("clear");
    printf("Welcome to the Interactive C Periodic Table!\n");

    // Display the table header
    printf("Group\tElement\tSymbol\tAtomic Number\tMass Number\n");
    printf("----\t------\t------\t-----------\t------------\n");

    // Create a table of elements
    char **elements = (char**)malloc(MAX * sizeof(char*));
    int **atomicNumbers = (int**)malloc(MAX * sizeof(int*));
    int **massNumbers = (int**)malloc(MAX * sizeof(int*));

    for (int i = 0; i < MAX; i++)
    {
        elements[i] = (char*)malloc(20 * sizeof(char));
        atomicNumbers[i] = (int*)malloc(sizeof(int));
        massNumbers[i] = (int*)malloc(sizeof(int));
    }

    // Populate the table with data
    elements[0] = "Hydrogen";
    atomicNumbers[0] = 1;
    massNumbers[0] = 1;

    elements[1] = "Helium";
    atomicNumbers[1] = 2;
    massNumbers[1] = 4;

    // ... Fill the remaining elements with data ...

    // Display the table
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t%s\t%c\t%d\t%d\n", atomicNumbers[i], elements[i], elements[i][0], atomicNumbers[i], massNumbers[i]);
    }

    printf("\nThank you for exploring the C Periodic Table!");

    free(elements);
    free(atomicNumbers);
    free(massNumbers);

    return 0;
}