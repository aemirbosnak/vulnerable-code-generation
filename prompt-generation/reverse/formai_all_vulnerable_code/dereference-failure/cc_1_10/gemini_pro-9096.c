//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store a question
typedef struct Question {
    char question[256];
    char options[4][64];
    int correct_option;
} Question;

// Function to read questions from a file
Question *read_questions(char *filename, int *num_questions) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // Read the number of questions
    fscanf(fp, "%d\n", num_questions);

    // Allocate memory for the questions
    Question *questions = malloc(*num_questions * sizeof(Question));
    if (questions == NULL) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Read each question
    for (int i = 0; i < *num_questions; i++) {
        // Read the question
        fgets(questions[i].question, 256, fp);

        // Read the options
        for (int j = 0; j < 4; j++) {
            fgets(questions[i].options[j], 64, fp);
            strtok(questions[i].options[j], "\n");
        }

        // Read the correct option
        fscanf(fp, "%d\n", &questions[i].correct_option);
    }

    fclose(fp);

    return questions;
}

// Function to display a question
void display_question(Question question) {
    printf("%s\n", question.question);
    for (int i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, question.options[i]);
    }
}

// Function to get the user's answer
int get_answer() {
    int answer;
    printf("Enter your answer (1-4): ");
    scanf("%d", &answer);
    return answer;
}

// Function to check if the user's answer is correct
int check_answer(Question question, int answer) {
    return answer == question.correct_option;
}

// Function to display the results
void display_results(int num_questions, int num_correct) {
    printf("You answered %d out of %d questions correctly.\n", num_correct, num_questions);
}

int main() {
    // Read the questions from the file
    int num_questions;
    Question *questions = read_questions("questions.txt", &num_questions);

    // Display each question and get the user's answer
    int num_correct = 0;
    for (int i = 0; i < num_questions; i++) {
        display_question(questions[i]);
        int answer = get_answer();
        if (check_answer(questions[i], answer)) {
            num_correct++;
        }
    }

    // Display the results
    display_results(num_questions, num_correct);

    // Free the memory allocated for the questions
    free(questions);

    return 0;
}