//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for Quiz Question
typedef struct Question {
    char *question;           // Question Text
    char *options[4];        // Answer Options
    int answer;              // Correct Answer index (0-3)
} Question;

// Function to create a new question
Question *createQuestion(char *text, char *opt1, char *opt2, char *opt3, char *opt4, int correct) {
    Question *q = (Question *)malloc(sizeof(Question)); // Allocate memory for a Question
    if (!q) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    q->question = (char *)malloc(strlen(text) + 1); // Allocate memory for question text
    strcpy(q->question, text);
    
    q->options[0] = (char *)malloc(strlen(opt1) + 1); // Allocate memory for each option
    strcpy(q->options[0], opt1);
    q->options[1] = (char *)malloc(strlen(opt2) + 1);
    strcpy(q->options[1], opt2);
    q->options[2] = (char *)malloc(strlen(opt3) + 1);
    strcpy(q->options[2], opt3);
    q->options[3] = (char *)malloc(strlen(opt4) + 1);
    strcpy(q->options[3], opt4);
    
    q->answer = correct; // Set the correct answer index
    return q; // Return the created question
}

// Function to free memory allocated for a question
void freeQuestion(Question *q) {
    free(q->question); // Free question text
    for (int i = 0; i < 4; i++) {
        free(q->options[i]); // Free each option
    }
    free(q); // Free the question structure itself
}

// Function to administer the quiz
void administerQuiz(Question *questions[], int count) {
    int score = 0; // Initialize score
    for (int i = 0; i < count; i++) {
        printf("Q%d: %s\n", i + 1, questions[i]->question); // Print question
        for (int j = 0; j < 4; j++) {
            printf("   %d. %s\n", j + 1, questions[i]->options[j]); // Print options
        }
        printf("Your answer (1-4): ");
        int answer;
        scanf("%d", &answer);
        
        if (answer - 1 == questions[i]->answer) { // Check if the answer is correct
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Incorrect. The correct answer was option %d.\n\n", questions[i]->answer + 1);
        }
    }
    printf("Your total score is: %d out of %d\n", score, count); // Print score
}

// Main function
int main() {
    const int numQuestions = 3; // Set number of questions
    Question *questions[numQuestions]; // Array to hold questions

    // Create quiz questions
    questions[0] = createQuestion("What is the capital of France?", "Berlin", "Madrid", "Paris", "Rome", 2);
    questions[1] = createQuestion("Which planet is known as the Red Planet?", "Earth", "Mars", "Jupiter", "Saturn", 1);
    questions[2] = createQuestion("What is 2 + 2?", "3", "4", "5", "6", 1);

    // Administer the quiz
    administerQuiz(questions, numQuestions);

    // Freeing allocated memory
    for (int i = 0; i < numQuestions; i++) {
        freeQuestion(questions[i]);
    }

    return 0; // Exit the program successfully
}