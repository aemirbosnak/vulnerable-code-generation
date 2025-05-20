//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the maximum number of questions
#define MAX_QUESTIONS 25

// Define the number of elements in the periodic table
#define NUM_ELEMENTS 118

// Define the struct that represents an element in the periodic table
typedef struct {
    char name[30];
    char symbol[3];
    int atomic_number;
} Element;

// Define the array that will hold all of the elements in the periodic table
Element elements[NUM_ELEMENTS];

// Define the struct that represents a question and answer
typedef struct {
    char question[100];
    char answer[30];
} Question;

// Define the array that will hold all of the questions
Question questions[MAX_QUESTIONS];

// Declare the function that will populate the array of elements
void populate_elements();

// Declare the function that will return a random number between min and max (inclusive)
int get_random_number(int min, int max);

// Declare the function that will create a random question
Question generate_question();

// Declare the function that will start the quiz
void start_quiz(int num_questions);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Populate the array of elements
    populate_elements();

    // Start the quiz with 10 questions
    start_quiz(10);

    return 0;
}

void populate_elements() {
    // Open the file containing the periodic table data
    FILE *fp = fopen("periodic_table.txt", "r");

    // Make sure the file was opened successfully
    if (fp == NULL) {
        printf("Could not open file\n");
        exit(1);
    }

    // Declare a variable to hold a line of data from the file
    char line[100];

    // Loop through the file, reading each line and adding the element to the array
    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL) {
        // Remove trailing newline character
        line[strcspn(line, "\n")] = 0;

        // Split the line into its components (name, symbol, atomic number)
        char *name = strtok(line, ",");
        char *symbol = strtok(NULL, ",");
        int atomic_number = atoi(strtok(NULL, ","));

        // Create a new element and add it to the array
        Element element = {0};
        strcpy(element.name, name);
        strcpy(element.symbol, symbol);
        element.atomic_number = atomic_number;
        elements[i] = element;
        i++;
    }

    // Close the file
    fclose(fp);
}

int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

Question generate_question() {
    // Choose a random element from the array of elements
    Element element = elements[get_random_number(0, NUM_ELEMENTS - 1)];

    // Choose a random property to ask about (name, symbol, or atomic number)
    int property_index = get_random_number(0, 2);

    // Create a new question based on the chosen property
    Question question = {0};
    switch (property_index) {
        case 0:
            sprintf(question.question, "What is the name of the element with atomic number %d?", element.atomic_number);
            sprintf(question.answer, "%s", element.name);
            break;
        case 1:
            sprintf(question.question, "What is the symbol of the element with atomic number %d?", element.atomic_number);
            sprintf(question.answer, "%s", element.symbol);
            break;
        case 2:
            sprintf(question.question, "What is the atomic number of the element %s?", element.name);
            sprintf(question.answer, "%d", element.atomic_number);
            break;
    }

    return question;
}

void start_quiz(int num_questions) {
    // Generate a list of random questions
    for (int i = 0; i < num_questions; i++) {
        questions[i] = generate_question();
    }

    // Loop through each question and ask the user
    int num_correct = 0;
    for (int i = 0; i < num_questions; i++) {
        // Print the question
        printf("%s\n", questions[i].question);

        // Get the user's answer
        char user_answer[30];
        scanf("%s", user_answer);

        // Check if the answer is correct
        if (strcmp(user_answer, questions[i].answer) == 0) {
            printf("Correct!\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %s.\n", questions[i].answer);
        }
    }

    // Print the user's score
    printf("You got %d out of %d questions correct.\n", num_correct, num_questions);
}