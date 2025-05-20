//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Ada Lovelace
// Online Examination System in the Style of Ada Lovelace

/*
 * This program is a simple online examination system that allows users to take a test and receive their results immediately.
 * The program uses a simple text-based interface and is designed to be easy to use.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions in the test
#define MAX_QUESTIONS 10

// Define the maximum number of choices for each question
#define MAX_CHOICES 4

// Define the structure of a question
typedef struct {
    char question[256];
    char choices[MAX_CHOICES][256];
    int correct_answer;
} Question;

// Define the structure of a test
typedef struct {
    Question questions[MAX_QUESTIONS];
    int num_questions;
} Test;

// Create a new test
Test *create_test() {
    Test *test = malloc(sizeof(Test));
    test->num_questions = 0;
    return test;
}

// Add a question to the test
void add_question(Test *test, char *question, char **choices, int correct_answer) {
    strcpy(test->questions[test->num_questions].question, question);
    for (int i = 0; i < MAX_CHOICES; i++) {
        strcpy(test->questions[test->num_questions].choices[i], choices[i]);
    }
    test->questions[test->num_questions].correct_answer = correct_answer;
    test->num_questions++;
}

// Print the test to the console
void print_test(Test *test) {
    for (int i = 0; i < test->num_questions; i++) {
        printf("%s\n", test->questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("    %d. %s\n", j + 1, test->questions[i].choices[j]);
        }
    }
}

// Take the test
int take_test(Test *test) {
    int score = 0;
    for (int i = 0; i < test->num_questions; i++) {
        int answer;
        printf("Question %d: %s\n", i + 1, test->questions[i].question);
        for (int j = 0; j < MAX_CHOICES; j++) {
            printf("    %d. %s\n", j + 1, test->questions[i].choices[j]);
        }
        scanf("%d", &answer);
        if (answer == test->questions[i].correct_answer) {
            score++;
        }
    }
    return score;
}

// Print the results of the test
void print_results(int score, int num_questions) {
    printf("Your score is %d out of %d.\n", score, num_questions);
}

// Main function
int main() {
    // Create a new test
    Test *test = create_test();

    // Add questions to the test
    add_question(test, "What is the capital of France?", (char *[]){"Paris", "London", "Rome", "Berlin"}, 0);
    add_question(test, "What is the largest ocean in the world?", (char *[]){"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 0);
    add_question(test, "Who was the first president of the United States?", (char *[]){"George Washington", "Abraham Lincoln", "Thomas Jefferson", "John Adams"}, 0);

    // Print the test to the console
    print_test(test);

    // Take the test
    int score = take_test(test);

    // Print the results of the test
    print_results(score, test->num_questions);

    return 0;
}