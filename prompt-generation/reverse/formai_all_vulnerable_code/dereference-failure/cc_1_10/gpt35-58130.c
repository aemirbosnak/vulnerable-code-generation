//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum length for element names
#define MAX_NAME_LENGTH 20

// Struct to store each element's information
typedef struct {
    char symbol[3];
    char name[MAX_NAME_LENGTH];
    int atomic_number;
    double atomic_mass;
} Element;

// Function to generate a unique random number within a range
int generate_random_number(int min, int max) {
    srand(time(NULL));
    int range = max - min + 1;
    int rand_num = (rand() % range) + min;
    return rand_num;
}

// Function to create an array of 118 elements
Element *create_periodic_table() {
    // Allocate memory for 118 elements
    Element *table = malloc(118 * sizeof(Element));

    // Load in element data from a file
    FILE *fp = fopen("periodic_table.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file\n");
        exit(1);
    }

    char buffer[100];
    char *token;
    int index = 0;

    // Loop through file and load each element into the array
    while (fgets(buffer, 100, fp)) {
        token = strtok(buffer, ",");
        strcpy(table[index].symbol, token);

        token = strtok(NULL, ",");
        strcpy(table[index].name, token);

        token = strtok(NULL, ",");
        table[index].atomic_number = atoi(token);

        token = strtok(NULL, ",");
        table[index].atomic_mass = atof(token);

        index++;
    }

    fclose(fp);

    return table;
}

// Function to print the quiz instructions to the user
void print_quiz_instructions() {
    printf("Welcome to the C Periodic Table Quiz!\n\n");
    printf("Please type the atomic symbol or name of the element\n");
    printf("that corresponds to the given atomic number.\n");
    printf("You will have 10 seconds to answer each question.\n\n");
}

// Function to run the periodic table quiz
void run_periodic_table_quiz() {
    Element *table = create_periodic_table();
    int score = 0;
    clock_t start_time, end_time;

    print_quiz_instructions();

    // Loop through 10 random elements
    for (int i = 0; i < 10; i++) {
        int random_index = generate_random_number(0, 117);
        Element question = table[random_index];

        printf("Question %d: What element corresponds to atomic number %d?\n", i+1, question.atomic_number);

        start_time = clock();

        // Accept user input
        char user_input[MAX_NAME_LENGTH];
        fgets(user_input, sizeof(user_input), stdin);
        user_input[strcspn(user_input, "\n")] = 0; // Remove newline character

        end_time = clock();

        // Check if answer is correct
        if (strcmp(user_input, question.symbol) == 0 || strcmp(user_input, question.name) == 0) {
            double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;
            score++;
            printf("Correct! It took you %.2f seconds.\n\n", time_taken);
        } else {
            printf("Sorry, the correct answer is %s or %s.\n\n", question.symbol, question.name);
        }
    }

    free(table);

    printf("Quiz complete! You scored %d out of 10.\n", score);
}

// Main function to run the program
int main() {
    run_periodic_table_quiz();
    return 0;
}