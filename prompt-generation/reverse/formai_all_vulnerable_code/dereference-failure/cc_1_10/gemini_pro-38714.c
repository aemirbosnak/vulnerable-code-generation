//GEMINI-pro DATASET v1.0 Category: Periodic Table Quiz ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Constants
#define NUM_QUESTIONS 10
#define MAX_NAME_LENGTH 100
#define MAX_SYMBOL_LENGTH 2
#define MAX_ATOMIC_NUMBER 118

// Quiz data
char* questions[NUM_QUESTIONS] = {
    "What is the name of the element with atomic number 1?",
    "What is the symbol of the element hydrogen?",
    "What is the atomic number of the element helium?",
    "What is the name of the element with symbol Au?",
    "What is the symbol of the element sodium?",
    "What is the atomic number of the element chlorine?",
    "What is the name of the element with symbol Fe?",
    "What is the symbol of the element potassium?",
    "What is the atomic number of the element bromine?",
    "What is the name of the element with symbol Sn?"
};
char* answers[NUM_QUESTIONS] = {
    "Hydrogen",
    "H",
    "2",
    "Gold",
    "Na",
    "17",
    "Iron",
    "K",
    "35",
    "Tin"
};

// Function to print the welcome message
void print_welcome_message() {
    printf("Welcome to the Periodic Table Quiz!\n");
    printf("You will be asked %d questions about the periodic table.\n", NUM_QUESTIONS);
    printf("Good luck!\n\n");
}

// Function to get the user's answer to a question
char* get_answer(char* question) {
    char* answer = malloc(MAX_NAME_LENGTH * sizeof(char));
    printf("%s", question);
    scanf("%s", answer);
    return answer;
}

// Function to check if the user's answer is correct
int check_answer(char* answer, char* correct_answer) {
    return strcmp(answer, correct_answer) == 0;
}

// Function to print the results of the quiz
void print_results(int score) {
    printf("\nYour score is %d out of %d.\n", score, NUM_QUESTIONS);
    if (score == NUM_QUESTIONS) {
        printf("Congratulations! You are a periodic table expert!\n");
    } else if (score >= 7) {
        printf("Good job! You know your periodic table well.\n");
    } else if (score >= 5) {
        printf("Not bad! You have a good understanding of the periodic table.\n");
    } else {
        printf("Don't worry! You can always learn more about the periodic table.\n");
    }
}

// Main function
int main() {
    // Print the welcome message
    print_welcome_message();

    // Declare variables
    int score = 0;
    char* answer;

    // Ask the questions
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        answer = get_answer(questions[i]);
        if (check_answer(answer, answers[i])) {
            score++;
        }
        free(answer);
    }

    // Print the results
    print_results(score);

    return 0;
}