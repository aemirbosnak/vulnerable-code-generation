//FormAI DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define a structure for the question and answer
typedef struct {
    char question[500];
    char answers[4][100];
    int correct_answer;
} Question;

// Define a function to load the questions from a file
void load_questions(Question* questions, int num_questions) {
    FILE* fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: Could not load questions.\n");
        exit(1);
    }

    // Keep track of which question we are on
    int current_question = 0;

    // Loop through the file and read in the questions
    char buffer[1000];
    while (fgets(buffer, 1000, fp) != NULL && current_question < num_questions) {
        strcpy(questions[current_question].question, buffer);
        for (int i = 0; i < 4; i++) {
            fgets(buffer, 1000, fp);
            strcpy(questions[current_question].answers[i], buffer);
        }
        fscanf(fp, "%d\n", &questions[current_question].correct_answer);
        current_question++;
    }

    // Close the file
    fclose(fp);
}

int main() {

    // Set up the random number generator
    srand(time(NULL));

    // Define the number of questions we want to use
    const int NUM_QUESTIONS = 5;

    // Allocate memory for the questions
    Question* questions = (Question*) malloc(NUM_QUESTIONS * sizeof(Question));

    // Load the questions from a file
    load_questions(questions, NUM_QUESTIONS);

    // Initialize the score to 0
    int score = 0;

    // Loop through each question
    for (int i = 0; i < NUM_QUESTIONS; i++) {

        // Print the question
        printf("\nQuestion %d:\n%s\n\n", i+1, questions[i].question);

        // Print the answers
        for (int j = 0; j < 4; j++) {
            printf("%d) %s", j+1, questions[i].answers[j]);
        }

        // Get the user's answer
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);

        // Check if the answer is correct
        if (answer == questions[i].correct_answer) {
            printf("You are correct!\n");
            score++;
        } else {
            printf("Sorry, that is incorrect.\n");
        }
    }

    // Print the final score
    printf("\n\nYour score is %d out of %d.\n", score, NUM_QUESTIONS);

    // Free the memory
    free(questions);

    return 0;
}