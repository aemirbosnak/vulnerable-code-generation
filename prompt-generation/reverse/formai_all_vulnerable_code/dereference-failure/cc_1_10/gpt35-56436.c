//FormAI DATASET v1.0 Category: Online Examination System ; Style: scientific
#include<stdio.h>
#include<stdlib.h>

typedef struct question_t {
    char* question;
    char* options[4];
    int correct_option;
} question_t;

int main() {
    int num_questions;
    printf("Welcome to the Online Examination System\n");
    printf("Please enter the number of questions in the exam: ");
    scanf("%d", &num_questions);

    // Dynamically allocate memory for questions
    question_t* questions = (question_t*) malloc(num_questions * sizeof(question_t));

    // Input questions and options from user
    for(int i=0; i<num_questions; i++) {
        printf("\nEnter details for question %d:\n", i+1);
        printf("Question: ");
        questions[i].question = (char*) malloc(256 * sizeof(char));
        scanf(" %[^\n]s", questions[i].question);

        printf("Option 1: ");
        questions[i].options[0] = (char*) malloc(256 * sizeof(char));
        scanf(" %[^\n]s", questions[i].options[0]);

        printf("Option 2: ");
        questions[i].options[1] = (char*) malloc(256 * sizeof(char));
        scanf(" %[^\n]s", questions[i].options[1]);

        printf("Option 3: ");
        questions[i].options[2] = (char*) malloc(256 * sizeof(char));
        scanf(" %[^\n]s", questions[i].options[2]);

        printf("Option 4: ");
        questions[i].options[3] = (char*) malloc(256 * sizeof(char));
        scanf(" %[^\n]s", questions[i].options[3]);

        printf("Correct Option (1-4): ");
        scanf("%d", &questions[i].correct_option);
    }

    // Take test from user
    int marks = 0;
    for(int i=0; i<num_questions; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);
        printf("Option 1: %s\n", questions[i].options[0]);
        printf("Option 2: %s\n", questions[i].options[1]);
        printf("Option 3: %s\n", questions[i].options[2]);
        printf("Option 4: %s\n", questions[i].options[3]);

        int user_option;
        printf("Your Answer: ");
        scanf("%d", &user_option);

        if(user_option == questions[i].correct_option) {
            marks++;
        }
    }

    printf("Thank you for taking the exam!\n");
    printf("Your score is %d out of %d", marks, num_questions);

    // Free dynamically allocated memory
    for(int i=0; i<num_questions; i++) {
        free(questions[i].question);
        free(questions[i].options[0]);
        free(questions[i].options[1]);
        free(questions[i].options[2]);
        free(questions[i].options[3]);
    }
    free(questions);

    return 0;
}