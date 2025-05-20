//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a structure to store the question and answer
typedef struct question {
    char question[256];
    char answer[256];
    int score;
} question;

// Create an array of questions
question questions[] = {
    {"What is the capital of France?", "Paris", 1},
    {"What is the largest ocean in the world?", "Pacific Ocean", 1},
    {"What is the name of the tallest mountain in the world?", "Mount Everest", 1},
    {"What is the name of the longest river in the world?", "Nile River", 1},
    {"What is the name of the largest country in the world?", "Russia", 1},
};

// Create a function to print the questions and answers
void print_questions() {
    // Loop through the questions
    for (int i = 0; i < sizeof(questions) / sizeof(question); i++) {
        // Print the question
        printf("%s", questions[i].question);

        // Print the answer
        printf("%s", questions[i].answer);

        // Print the score
        printf("%d\n", questions[i].score);
    }
}

// Create a function to get the user's input
char *get_input() {
    // Create a buffer to store the user's input
    char *input = malloc(256);

    // Get the user's input
    fgets(input, 256, stdin);

    // Return the user's input
    return input;
}

// Create a function to check the user's answer
int check_answer(char *input, char *answer) {
    // Compare the user's input to the correct answer
    if (strcmp(input, answer) == 0) {
        // Return 1 if the answer is correct
        return 1;
    } else {
        // Return 0 if the answer is incorrect
        return 0;
    }
}

// Create a function to calculate the score
int calculate_score(int *answers) {
    // Create a variable to store the score
    int score = 0;

    // Loop through the answers
    for (int i = 0; i < sizeof(questions) / sizeof(question); i++) {
        // Add the score for each correct answer
        score += answers[i];
    }

    // Return the score
    return score;
}

// Create a function to print the results
void print_results(int score) {
    // Print the score
    printf("Your score is: %d\n", score);
}

// Create a function to start the exam
void start_exam() {
    // Print the questions and answers
    print_questions();

    // Get the user's input
    char *input = get_input();

    // Check the user's answer
    int answers[sizeof(questions) / sizeof(question)];
    for (int i = 0; i < sizeof(questions) / sizeof(question); i++) {
        answers[i] = check_answer(input, questions[i].answer);
    }

    // Calculate the score
    int score = calculate_score(answers);

    // Print the results
    print_results(score);
}

// Create a function to main
int main() {
    // Start the exam
    start_exam();

    return 0;
}