//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 118

// Define the structure of an element
typedef struct {
    char symbol[3];
    char name[20];
    int atomic_number;
    float atomic_weight;
} element;

// Declare the array of elements
element elements[MAX_ELEMENTS];

// Define the function to load the elements from a file
int load_elements() {
    FILE *file = fopen("periodic_table.txt", "r");
    if (file == NULL) {
        printf("Failed to open periodic_table.txt\n");
        return 0;
    }

    int index = 0;
    char line[50];

    while (fgets(line, sizeof(line), file)) {
        // Remove newline character
        strtok(line, "\n");

        // Split line into fields
        char *symbol = strtok(line, ",");
        char *name = strtok(NULL, ",");
        char *number = strtok(NULL, ",");
        char *weight = strtok(NULL, ",");

        // Convert fields to element struct
        strcpy(elements[index].symbol, symbol);
        strcpy(elements[index].name, name);
        elements[index].atomic_number = atoi(number);
        elements[index].atomic_weight = atof(weight);

        index++;
    }

    fclose(file);
    return 1;
}

// Define the function to display the quiz instructions
void display_instructions() {
    printf("*** C Periodic Table Quiz ***\n\n");
    printf("You will be asked to enter the symbol or name of an element.\n");
    printf("You will receive one point for each correct answer.\n");
    printf("You will receive negative one point for each incorrect answer.\n");
    printf("The quiz will end after 10 questions.\n\n");
    printf("Press enter to start the quiz!");
    getchar();
}

// Define the function to ask a question
int ask_question(int question_number) {
    printf("\nQuestion %d:\n", question_number);

    // Generate a random element to ask about
    int random_index = rand() % MAX_ELEMENTS;
    element random_element = elements[random_index];

    // Determine whether to ask for the symbol or name
    int ask_for_symbol = rand() % 2;

    if (ask_for_symbol) {
        printf("What is the symbol for %s? ", random_element.name);
    } else {
        printf("What is the name for %s? ", random_element.symbol);
    }

    // Get the user's answer
    char answer[20];
    scanf("%s", answer);

    // Determine whether the answer is correct
    int is_correct = 0;
    if (ask_for_symbol) {  // asking for symbol
        if (strcmp(answer, random_element.symbol) == 0) {
            is_correct = 1;
        }
    } else {  // asking for name
        if (strcmp(answer, random_element.name) == 0) {
            is_correct = 1;
        }
    }

    // Display the result
    if (is_correct) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect!\n");
        return -1;
    }
}

// Define the function to display the quiz results
void display_results(int score) {
    printf("\nQuiz complete!\n");
    printf("Your score is %d points.\n", score);
}

int main() {
    // Load the elements from file
    if (!load_elements()) {
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Display the quiz instructions
    display_instructions();

    // Ask 10 questions
    int score = 0;
    for (int i = 1; i <= 10; i++) {
        score += ask_question(i);
    }

    // Display the quiz results
    display_results(score);

    return 0;
}