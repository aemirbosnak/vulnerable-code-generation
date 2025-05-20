//FormAI DATASET v1.0 Category: Online Examination System ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char question[100];
    char options[4][50];
    char answer;
} question_t;

int main() {
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    question_t questions[num_questions];

    // Get questions and options from user
    for(int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        printf("Enter the question: ");
        scanf(" %[^\n]", questions[i].question);

        printf("Enter Option A: ");
        scanf(" %[^\n]", questions[i].options[0]);

        printf("Enter Option B: ");
        scanf(" %[^\n]", questions[i].options[1]);

        printf("Enter Option C: ");
        scanf(" %[^\n]", questions[i].options[2]);

        printf("Enter Option D: ");
        scanf(" %[^\n]", questions[i].options[3]);

        printf("Enter the correct answer (A/B/C/D): ");
        scanf(" %c", &questions[i].answer);
    }

    // Conduct Exam
    int score = 0;
    for(int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n%s\nA. %s\nB. %s\nC. %s\nD. %s\n", 
        i+1, questions[i].question, questions[i].options[0], 
        questions[i].options[1], questions[i].options[2], 
        questions[i].options[3]);

        char user_choice;
        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &user_choice);

        if(user_choice == questions[i].answer) {
            score++;
        }
    }

    // Display Results
    printf("\nYour final score is %d/%d\n", score, num_questions);

    return 0;
}