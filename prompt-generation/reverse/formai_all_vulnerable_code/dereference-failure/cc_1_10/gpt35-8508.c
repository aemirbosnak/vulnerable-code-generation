//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of elements
#define MAX_ELEMENTS 118

int main()
{
    // Open the element data file
    FILE* dataFile = fopen("elements.txt", "r");

    // If the file could not be opened, print an error message and exit the program
    if (dataFile == NULL)
    {
        printf("Error: Could not open element data file.\n");
        return 1;
    }

    // Allocate memory for the element array
    char** elements = (char**)malloc(MAX_ELEMENTS * sizeof(char*));
    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        elements[i] = (char*)malloc(3 * sizeof(char));
    }

    // Read the element data from the file
    int index = 0;
    char line[10];
    while (fgets(line, 10, dataFile) != NULL)
    {
        strcpy(elements[index], strtok(line, "\n"));
        index++;
    }
    fclose(dataFile);

    // Seed the random number generator
    srand(time(NULL));

    // Print a welcome message and instructions for the quiz
    printf("Welcome to the Periodic Table Quiz! You will be shown a symbol and\n"
           "you must enter the name of the corresponding element. Type 'quit' to exit.\n\n");

    // Define variables for keeping score and counting the number of questions
    int score = 0;
    int questions = 0;

    // Main quiz loop
    while (1)
    {
        // Generate a random index for the element
        int randomIndex = rand() % MAX_ELEMENTS;

        // Get the symbol for the element at the random index
        char* symbol = elements[randomIndex];

        // Print the symbol and prompt the user for the element name
        printf("Symbol: %s\n", symbol);
        char guess[50];
        printf("Enter the name of the element: ");
        fgets(guess, 50, stdin);

        // Remove the newline character from the guess string
        guess[strcspn(guess, "\n")] = 0;

        // If the guess is 'quit', exit the program
        if (strcmp(guess, "quit") == 0)
        {
            break;
        }

        // Check if the guess is correct and update the score and question count accordingly
        if (strcmp(guess, elements[randomIndex] + 3) == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Incorrect. The correct answer is %s.\n", elements[randomIndex] + 3);
        }
        questions++;

        // Print the current score and number of questions answered
        printf("Score: %d/%d\n\n", score, questions);
    }

    // Print a message with the final score and exit the program
    printf("Thanks for playing! Final score: %d/%d\n", score, questions);

    // Free the memory used by the element array
    for (int i = 0; i < MAX_ELEMENTS; i++)
    {
        free(elements[i]);
    }
    free(elements);

    return 0;
}