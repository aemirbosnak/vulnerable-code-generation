//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and answer
typedef struct {
    char question[256];
    char answer[256];
} Question;

// Function to read questions from a file
Question *readQuestions(char *filename, int *numQuestions) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return NULL;
    }

    // Get the number of questions
    fscanf(fp, "%d\n", numQuestions);

    // Allocate memory for the questions
    Question *questions = malloc(*numQuestions * sizeof(Question));

    // Read each question and answer
    for (int i = 0; i < *numQuestions; i++) {
        fgets(questions[i].question, 256, fp);
        fgets(questions[i].answer, 256, fp);
    }

    // Close the file
    fclose(fp);

    // Return the questions
    return questions;
}

// Function to print the questions and get the answers from the user
void takeExam(Question *questions, int numQuestions) {
    for (int i = 0; i < numQuestions; i++) {
        printf("%s", questions[i].question);
        char answer[256];
        fgets(answer, 256, stdin);
        if (strcmp(answer, questions[i].answer) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is %s\n", questions[i].answer);
        }
    }
}

// Main function
int main() {
    // Read the questions from the file
    char *filename = "questions.txt";
    int numQuestions;
    Question *questions = readQuestions(filename, &numQuestions);

    // Take the exam
    takeExam(questions, numQuestions);

    // Free the memory allocated for the questions
    free(questions);

    return 0;
}