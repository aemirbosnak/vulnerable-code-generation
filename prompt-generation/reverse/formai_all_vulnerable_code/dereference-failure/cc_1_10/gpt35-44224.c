//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the struct for elements in the periodic table
typedef struct Element_t {
    int atomic_num;
    char symbol[3];
    char name[20];
    double atomic_mass;
    int period;
    int group;
} Element;

// Declare the function prototypes
void fill_periodic_table(Element *table);
void print_periodic_table(Element *table);
int check_answer(char *user_ans, Element *table, int element_idx);
void shuffle_table(Element *table);
void ask_questions(Element *table);

// Main function
int main() {
    // Allocate memory for the periodic table
    Element *periodic_table = malloc(118 * sizeof(Element));

    // Fill the periodic table with data
    fill_periodic_table(periodic_table);

    // Shuffle the table to randomize the questions
    shuffle_table(periodic_table);

    // Ask the quiz questions
    ask_questions(periodic_table);

    // Free the memory for the periodic table
    free(periodic_table);

    return 0;
}

// Fill the periodic table with data
void fill_periodic_table(Element *table) {
    // Declare and initialize the data for each element
    Element hydrogen = {1, "H", "Hydrogen", 1.008, 1, 1};
    Element lithium = {3, "Li", "Lithium", 6.941, 2, 1};
    Element sodium = {11, "Na", "Sodium", 22.99, 3, 1};

    // Add each element to the table
    table[0] = hydrogen;
    table[1] = lithium;
    table[2] = sodium;

    // Add more elements here...
}

// Print the periodic table
void print_periodic_table(Element *table) {
    for (int i = 0; i < 118; i++) {
        printf("%d | %s | %s | %f | %d | %d\n", table[i].atomic_num,
            table[i].symbol, table[i].name, table[i].atomic_mass,
            table[i].period, table[i].group);
    }
}

// Check if the user's answer is correct
int check_answer(char *user_ans, Element *table, int element_idx) {
    char *correct_ans = table[element_idx].symbol;
    if (strcmp(correct_ans, user_ans) == 0) {
        printf("Correct!\n");
        return 1;
    } else {
        printf("Incorrect. The correct answer is %s.\n", correct_ans);
        return 0;
    }
}

// Shuffle the periodic table array
void shuffle_table(Element *table) {
    srand(123456);  // Set the random seed for consistency
    for (int i = 0; i < 118; i++) {
        int j = rand() % 118;
        Element temp = table[i];
        table[i] = table[j];
        table[j] = temp;
    }
}

// Ask the quiz questions
void ask_questions(Element *table) {
    char user_ans[3];  // User's answer for each question
    int correct_count = 0;  // Count of correctly answered questions
    int max_questions = 10;  // Maximum number of questions to ask

    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked to identify the element symbol for each element.\n");
    printf("You have %d chances to get %d correct answers.\n", max_questions, (int)(max_questions * 0.7));
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < max_questions; i++) {
        Element current_elem = table[i];
        printf("(%d/%d) What is the symbol for %s (atomic number %d)? ",
            i + 1, max_questions, current_elem.name, current_elem.atomic_num);
        scanf("%s", user_ans);
        correct_count += check_answer(user_ans, table, i);
        printf("You have %d correct answers so far.\n", correct_count);

        // Check if the user has answered enough questions correctly to pass the quiz
        if (correct_count >= (int)(max_questions * 0.7)) {
            printf("Congratulations! You passed the quiz.\n");
            return;
        }
    }

    printf("Sorry, you did not pass the quiz. Better luck next time!\n");
}