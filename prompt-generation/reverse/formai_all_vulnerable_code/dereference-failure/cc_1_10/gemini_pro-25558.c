//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and answer
typedef struct {
    char question[256];
    char answer[128];
} Question;

// Array of questions and answers
Question questions[] = {
    {"What is the capital of France?", "Paris"},
    {"Who is the author of Hamlet?", "William Shakespeare"},
    {"What is the chemical symbol for gold?", "Au"},
    {"What is the largest planet in the solar system?", "Jupiter"},
    {"What is the name of the ancient Egyptian writing system?", "Hieroglyphics"}
};

// Function to print a question and get the user's answer
char *getAnswer(Question question) {
    // Print the question
    printf("%s\n", question.question);

    // Allocate memory for the user's answer
    char *answer = malloc(128);

    // Get the user's answer
    scanf("%s", answer);

    // Return the user's answer
    return answer;
}

// Function to check if the user's answer is correct
int isCorrect(char *answer, char *correctAnswer) {
    // Compare the user's answer to the correct answer
    return strcmp(answer, correctAnswer) == 0;
}

// Function to print the results of the exam
void printResults(int score, int totalQuestions) {
    // Calculate the percentage score
    float percentage = (float)score / totalQuestions * 100;

    // Print the results
    printf("Your score is %d out of %d (%0.2f%%)\n", score, totalQuestions, percentage);
}

// Main function
int main() {
    // Get the number of questions in the exam
    int numQuestions = sizeof(questions) / sizeof(Question);

    // Initialize the user's score to 0
    int score = 0;

    // Loop through the questions
    for (int i = 0; i < numQuestions; i++) {
        // Get the user's answer
        char *answer = getAnswer(questions[i]);

        // Check if the user's answer is correct
        if (isCorrect(answer, questions[i].answer)) {
            // Increment the user's score
            score++;
        }

        // Free the memory allocated for the user's answer
        free(answer);
    }

    // Print the results of the exam
    printResults(score, numQuestions);

    return 0;
}