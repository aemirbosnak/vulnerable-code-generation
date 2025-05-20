//FormAI DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
/************ C Online Examination System **************/
/* Created by: Your Name                                */
/* Date: Today's Date                                   */
/* License: MIT License                                 */
/* Linus Torvalds Style                                 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_QUESTIONS 10
#define MAX_ANSWER_LENGTH 50

// Structure to store a single question
typedef struct {
    char prompt[100];
    char answer[MAX_ANSWER_LENGTH];
} Question;

// Generate some example questions
Question questions[NUM_QUESTIONS] = {
    {"What is the capital of France?", "Paris"},
    {"What is the largest ocean in the world?", "Pacific"},
    {"What is the smallest country by land area?", "Vatican City"},
    {"What is the highest mountain in Africa?", "Kilimanjaro"},
    {"What is the main language spoken in Brazil?", "Portuguese"},
    {"What is the chemical symbol for gold?", "Au"},
    {"What is the largest planet in our solar system?", "Jupiter"},
    {"Who is the current Prime Minister of Canada?", "Justin Trudeau"},
    {"What is the main religion in India?", "Hinduism"},
    {"What is the main language spoken in Japan?", "Japanese"}
};

// Function to display a single question and get the user's answer
char* askQuestion(Question q) {
    printf("%s\n", q.prompt);
    char* userAnswer = (char*) malloc(MAX_ANSWER_LENGTH);
    scanf("%s", userAnswer);
    return userAnswer;
}

int main() {
    // Welcome the user
    printf("Welcome to the C Online Examination System!\n");
    printf("You will be asked %d questions. Good luck!\n\n", NUM_QUESTIONS);

    // Ask each question and grade the user's answer
    int numCorrect = 0;
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        char* userAnswer = askQuestion(questions[i]);
        if (strcmp(userAnswer, questions[i].answer) == 0) {
            printf("Correct!\n\n");
            numCorrect++;
        } else {
            printf("Incorrect. The correct answer was %s.\n\n", questions[i].answer);
        }
        free(userAnswer);
    }

    // Calculate and display the user's grade
    int gradePercentage = (int) (100.0 * numCorrect / NUM_QUESTIONS);
    printf("You got %d out of %d questions correct.\n", numCorrect, NUM_QUESTIONS);
    printf("Your grade: %d%%\n", gradePercentage);

    return 0;
}