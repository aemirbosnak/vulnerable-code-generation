//FormAI DATASET v1.0 Category: Online Examination System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    int qnum;
    char qtext[100];
    char options[4][50];
    char answer;
};

int main() {
    int num_questions, num_correct = 0;
    printf("Welcome to the C online examination system!\n");
    printf("Please enter the number of questions in the exam: ");
    scanf("%d", &num_questions);

    struct question* questions = (struct question*)malloc(num_questions * sizeof(struct question));

    for (int i = 0; i < num_questions; i++) {
        printf("Enter the question text for question #%d: ", i+1);
        scanf(" %[^\n]", questions[i].qtext);
        printf("Enter the options for question #%d (separated by commas): ", i+1);
        scanf(" %[^\n]", questions[i].options);
        printf("Enter the correct answer for question #%d (A/B/C/D): ", i+1);
        scanf(" %c", &questions[i].answer);
        questions[i].qnum = i+1;
    }

    printf("\nLet's begin the exam now!\n");
    for (int i = 0; i < num_questions; i++) {
        printf("\nQuestion #%d: %s\n", questions[i].qnum, questions[i].qtext);
        for (int j = 0; j < 4; j++) {
            printf("%c) %s\n", 65+j, questions[i].options[j]);
        }
        char user_answer;
        printf("Enter your answer for question #%d (A/B/C/D): ", i+1);
        scanf(" %c", &user_answer);
        if (user_answer == questions[i].answer) {
            printf("Correct! Great job.\n");
            num_correct++;
        } else {
            printf("Incorrect. The correct answer is %c.\n", questions[i].answer);
        }
    }

    printf("\nCongratulations, you have completed the exam!\n");
    int percentage_correct = (num_correct * 100) / num_questions;
    printf("You got %d/%d questions correct, which is %d%%.\n", num_correct, num_questions, percentage_correct);
    free(questions);
    return 0;
}