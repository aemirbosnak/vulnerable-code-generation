//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and answer
typedef struct Question {
    char question[256];
    char answer[256];
} Question;

// Function to load questions from a file
Question* loadQuestions(char* filename, int* numQuestions) {
    // Open the file
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Count the number of questions in the file
    *numQuestions = 0;
    char line[256];
    while (fgets(line, 256, fp) != NULL) {
        (*numQuestions)++;
    }

    // Rewind the file pointer to the beginning of the file
    rewind(fp);

    // Allocate memory for the questions
    Question* questions = malloc(*numQuestions * sizeof(Question));

    // Read the questions from the file
    int i = 0;
    while (fgets(line, 256, fp) != NULL) {
        // Parse the question and answer from the line
        char* question = strtok(line, "|");
        char* answer = strtok(NULL, "|");

        // Copy the question and answer into the question struct
        strcpy(questions[i].question, question);
        strcpy(questions[i].answer, answer);

        i++;
    }

    // Close the file
    fclose(fp);

    // Return the questions
    return questions;
}

// Function to take the exam
int takeExam(Question* questions, int numQuestions) {
    // Initialize the score to 0
    int score = 0;

    // Loop through each question
    for (int i = 0; i < numQuestions; i++) {
        // Print the question
        printf("%s\n", questions[i].question);

        // Get the user's answer
        char answer[256];
        scanf("%s", answer);

        // Check if the answer is correct
        if (strcmp(answer, questions[i].answer) == 0) {
            // Increment the score
            score++;
        }
    }

    // Return the score
    return score;
}

// Main function
int main() {
    // Load the questions from the file
    char* filename = "questions.txt";
    int numQuestions;
    Question* questions = loadQuestions(filename, &numQuestions);

    // Take the exam
    int score = takeExam(questions, numQuestions);

    // Print the score
    printf("Your score is %d\n", score);

    // Free the memory for the questions
    free(questions);

    return 0;
}