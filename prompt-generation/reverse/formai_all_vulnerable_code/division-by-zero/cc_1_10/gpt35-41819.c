//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define MAX_ELEMENTS 118
#define MAX_NAME_LENGTH 20
#define MAX_SYMBOL_LENGTH 3
#define MAX_PROPERTIES 6

// Define struct for each element
typedef struct {
    int number;
    char name[MAX_NAME_LENGTH];
    char symbol[MAX_SYMBOL_LENGTH];
    float atomic_mass;
    int period;
    int group;
    char category[15];
} Element;

// Declare global variables
Element elements[MAX_ELEMENTS];
int num_elements = 0;

// Function to get input from user
void get_input(char *input) {
    printf("Enter your answer:\n");
    scanf("%s", input);
}

// Function to check if user input is correct
int check_answer(char *input, char *correct_answer) {
    if (strcmp(input, correct_answer) == 0) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer is %s.\n", correct_answer);
        return 0;
    }
}

// Function to generate random number
int generate_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to initialize elements array
void initialize_elements() {
    FILE *fp = fopen("periodic_table.txt", "r"); // Open file in read mode

    if (fp == NULL) { // Check if file was opened successfully
        printf("Error opening file.\n");
        exit(1);
    }

    // Loop through file and add each element to array
    while (!feof(fp) && num_elements < MAX_ELEMENTS) {
        fscanf(fp, "%d %s %s %f %d %d %s", &elements[num_elements].number, elements[num_elements].name, elements[num_elements].symbol, &elements[num_elements].atomic_mass, &elements[num_elements].period, &elements[num_elements].group, elements[num_elements].category);
        num_elements++;
    }

    fclose(fp); // Close file
}

// Function to display menu options
void display_menu() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("1. Guess the Element's Symbol\n");
    printf("2. Guess the Element's Name\n");
    printf("3. Guess the Element's Atomic Mass\n");
    printf("4. Guess the Element's Category\n");
    printf("5. Exit\n");
}

// Function to handle user choice
void handle_choice(int choice) {
    int question_number = generate_random_number(0, num_elements - 1); // Generate random number between 0 and num_elements - 1
    char input[20], correct_answer[20]; // Declare variables for user input and correct answer

    switch (choice) {
        case 1:
            printf("What is the symbol for %s?\n", elements[question_number].name);
            strcpy(correct_answer, elements[question_number].symbol);
            get_input(input);
            check_answer(input, correct_answer);
            break;
        case 2:
            printf("What is the name for the element with symbol %s?\n", elements[question_number].symbol);
            strcpy(correct_answer, elements[question_number].name);
            get_input(input);
            check_answer(input, correct_answer);
            break;
        case 3:
            printf("What is the atomic mass of %s?\n", elements[question_number].name);
            sprintf(correct_answer, "%.2f", elements[question_number].atomic_mass);
            get_input(input);
            check_answer(input, correct_answer);
            break;
        case 4:
            printf("What is the category of %s?\n", elements[question_number].name);
            strcpy(correct_answer, elements[question_number].category);
            get_input(input);
            check_answer(input, correct_answer);
            break;
        case 5:
            printf("Thank you for playing the Periodic Table Quiz!\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
    }
}

int main() {
    int choice;

    srand(time(NULL)); // Seed random number generator with current time
    initialize_elements(); // Initialize elements array with data from file

    while (1) {
        display_menu();
        printf("Enter your choice (1-5):\n");
        scanf("%d", &choice);
        handle_choice(choice);
    }

    return 0;
}