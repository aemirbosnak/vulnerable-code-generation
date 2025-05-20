//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of questions in the exam
#define NUM_QUESTIONS 10

// Define the maximum score for the exam
#define MAX_SCORE 100

// Define the passing score for the exam
#define PASSING_SCORE 60

// Define the structure of a question
typedef struct {
    char question[100];
    char options[4][50];
    int correct_answer;
} Question;

// Define the structure of an exam
typedef struct {
    Question questions[NUM_QUESTIONS];
    int score;
} Exam;

// Function to generate a random number between 0 and n-1
int random_number(int n) {
    return rand() % n;
}

// Function to create a new exam
Exam *create_exam() {
    Exam *exam = malloc(sizeof(Exam));
    
    // Generate the questions for the exam
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Generate the question text
        sprintf(exam->questions[i].question, "Question %d:", i + 1);

        // Generate the options for the question
        for (int j = 0; j < 4; j++) {
            sprintf(exam->questions[i].options[j], "Option %d", j + 1);
        }

        // Generate the correct answer for the question
        exam->questions[i].correct_answer = random_number(4);
    }

    // Set the score for the exam to 0
    exam->score = 0;

    return exam;
}

// Function to administer the exam
void administer_exam(Exam *exam) {
    // Print the instructions for the exam
    printf("Instructions:");
    printf("You have %d minutes to complete the exam.", 60);
    printf("Each question has 4 options. Choose the best option for each question.");
    printf("Your score will be displayed at the end of the exam.\n\n");

    // Loop through the questions in the exam
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        // Print the question
        printf("%s\n", exam->questions[i].question);

        // Print the options for the question
        for (int j = 0; j < 4; j++) {
            printf("%s\n", exam->questions[i].options[j]);
        }

        // Get the user's answer to the question
        int answer;
        printf("Enter your answer (1-4): ");
        scanf("%d", &answer);

        // Check if the user's answer is correct
        if (answer == exam->questions[i].correct_answer) {
            // Increment the user's score
            exam->score++;
        }
    }

    // Print the user's score
    printf("Your score is: %d\n", exam->score);

    // Check if the user passed the exam
    if (exam->score >= PASSING_SCORE) {
        printf("Congratulations! You passed the exam.\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new exam
    Exam *exam = create_exam();

    // Administer the exam
    administer_exam(exam);

    // Free the memory allocated for the exam
    free(exam);

    return 0;
}