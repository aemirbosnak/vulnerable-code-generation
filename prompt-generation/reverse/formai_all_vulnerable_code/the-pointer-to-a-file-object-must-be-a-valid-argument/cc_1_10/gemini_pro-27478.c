//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store question and answer
typedef struct {
    char question[100];
    char options[4][50];
    int correct_answer;
} Question;

// Function to read questions and answers from a file
void readQuestions(Question *questions, int *num_questions) {
    FILE *fp;
    char line[256];
    int i, j;

    // Open the file containing questions and answers
    fp = fopen("questions.txt", "r");

    // Read the number of questions from the file
    fscanf(fp, "%d", num_questions);

    // Allocate memory for the questions
    questions = (Question *)malloc(*num_questions * sizeof(Question));

    // Read each question and answer from the file
    for (i = 0; i < *num_questions; i++) {
        // Read the question
        fgets(line, sizeof(line), fp);
        strcpy(questions[i].question, line);

        // Read the options
        for (j = 0; j < 4; j++) {
            fgets(line, sizeof(line), fp);
            strcpy(questions[i].options[j], line);
        }

        // Read the correct answer
        fscanf(fp, "%d", &questions[i].correct_answer);
    }

    // Close the file
    fclose(fp);
}

// Function to display questions and options
void displayQuestions(Question *questions, int num_questions) {
    int i, j;

    // Iterate over each question
    for (i = 0; i < num_questions; i++) {
        // Display the question
        printf("%s\n", questions[i].question);

        // Display the options
        for (j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }
    }
}

// Function to check answers
int checkAnswers(Question *questions, int num_questions, int *answers) {
    int i, score = 0;

    // Iterate over each question
    for (i = 0; i < num_questions; i++) {
        // Check if the answer given by the user is correct
        if (answers[i] == questions[i].correct_answer) {
            // Increment the score
            score++;
        }
    }

    // Return the score
    return score;
}

// Main function
int main() {
    // Declare variables
    Question questions[100];
    int num_questions, answers[100], score;

    // Read questions and answers from the file
    readQuestions(questions, &num_questions);

    // Display questions and options
    displayQuestions(questions, num_questions);

    // Get answers from the user
    for (int i = 0; i < num_questions; i++) {
        printf("Enter your answer for question %d: ", i + 1);
        scanf("%d", &answers[i]);
    }

    // Check answers
    score = checkAnswers(questions, num_questions, answers);

    // Display the score
    printf("Your score is: %d\n", score);

    return 0;
}