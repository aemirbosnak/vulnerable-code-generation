//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum size of the element name and symbol
#define MAX_NAME_SIZE 20
#define MAX_SYMBOL_SIZE 3

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the struct for each element
struct Element
{
    char name[MAX_NAME_SIZE];
    char symbol[MAX_SYMBOL_SIZE];
    int atomicNumber;
    float atomicWeight;
};

// Function to initialize the periodic table
void initializePeriodicTable(struct Element periodicTable[NUM_ELEMENTS])
{
    // Open the periodic table file
    FILE *fptr = fopen("periodic_table.txt", "r");

    // Check if the file was successfully opened
    if (fptr == NULL)
    {
        printf("Error opening periodic_table.txt\n");
        exit(EXIT_FAILURE);
    }

    // Loop through each line in the file and create a new element
    char line[100];
    int index = 0;
    while (fgets(line, 100, fptr) != NULL)
    {
        // Tokenize the line using commas as delimiters
        char *token = strtok(line, ",");

        // Create a new element and add it to the periodic table
        struct Element newElement;
        strcpy(newElement.name, token);
        token = strtok(NULL, ",");
        strcpy(newElement.symbol, token);
        token = strtok(NULL, ",");
        newElement.atomicNumber = atoi(token);
        token = strtok(NULL, ",");
        newElement.atomicWeight = atof(token);
        periodicTable[index++] = newElement;
    }

    // Close the file
    fclose(fptr);
}

// Function to shuffle the periodic table
void shufflePeriodicTable(struct Element periodicTable[NUM_ELEMENTS])
{
    // Seed the random number generator
    srand(time(NULL));

    // Loop through each element in the periodic table
    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        // Generate a random index to swap with
        int j = rand() % NUM_ELEMENTS;

        // Swap the two elements
        struct Element temp = periodicTable[i];
        periodicTable[i] = periodicTable[j];
        periodicTable[j] = temp;
    }
}

// Function to display the periodic table
void displayPeriodicTable(struct Element periodicTable[NUM_ELEMENTS])
{
    printf("Name \t\tSymbol \tNumber \tWeight\n");
    for (int i = 0; i < NUM_ELEMENTS; i++)
    {
        printf("%-10s \t%-3s \t%-3d \t%.2f\n", periodicTable[i].name, periodicTable[i].symbol, periodicTable[i].atomicNumber, periodicTable[i].atomicWeight);
    }
}

// Function to start the quiz
void startQuiz(struct Element periodicTable[NUM_ELEMENTS])
{
    // Shuffle the periodic table
    shufflePeriodicTable(periodicTable);

    // Loop through each random element and ask the user for its symbol
    int score = 0;
    for (int i = 0; i < 10; i++)
    {
        // Get a random element
        struct Element element = periodicTable[i];

        // Ask the user for the symbol
        char symbol[MAX_SYMBOL_SIZE];
        printf("What is the symbol for %s? ", element.name);
        scanf("%s", symbol);

        // Check if the user's answer is correct
        if (strcmp(symbol, element.symbol) == 0)
        {
            printf("Correct!\n");
            score++;
        }
        else
        {
            printf("Wrong! The correct symbol is %s.\n", element.symbol);
        }
    }

    // Display the final score
    printf("Your final score is %d out of 10.\n", score);
}

// Main function
int main()
{
    // Declare the periodic table
    struct Element periodicTable[NUM_ELEMENTS];

    // Initialize the periodic table
    initializePeriodicTable(periodicTable);

    // Display the periodic table
    displayPeriodicTable(periodicTable);

    // Start the quiz
    startQuiz(periodicTable);

    return 0;
}