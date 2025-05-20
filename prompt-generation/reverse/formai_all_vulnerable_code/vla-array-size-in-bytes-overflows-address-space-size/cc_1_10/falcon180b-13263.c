//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define PASS_MARK 60

struct question {
    char question[100];
    char option1[50];
    char option2[50];
    char option3[50];
    char option4[50];
    char answer[MAX_ANSWERS];
};

void main() {
    int num_questions;
    int i, j;
    char choice;
    int score = 0;

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter the number of questions: ");
    scanf("%d", &num_questions);

    struct question questions[num_questions];

    for (i = 0; i < num_questions; i++) {
        printf("Enter question %d:\n", i+1);
        scanf("%s", questions[i].question);

        printf("Enter option 1:\n");
        scanf("%s", questions[i].option1);

        printf("Enter option 2:\n");
        scanf("%s", questions[i].option2);

        printf("Enter option 3:\n");
        scanf("%s", questions[i].option3);

        printf("Enter option 4:\n");
        scanf("%s", questions[i].option4);

        printf("Enter the correct answer (A/B/C/D): ");
        scanf("%s", questions[i].answer);
    }

    printf("The exam has started. Good luck!\n");

    for (i = 0; i < num_questions; i++) {
        printf("Question %d: %s\n", i+1, questions[i].question);

        for (j = 0; j < MAX_OPTIONS; j++) {
            if (questions[i].option1[j]!= '\0') {
                printf("%c) %s\n", 'A' + j, questions[i].option1);
            }
        }

        printf("Enter your answer (A/B/C/D): ");
        scanf(" %c", &choice);

        if (choice >= 'A' && choice <= 'D') {
            if (questions[i].answer[choice - 'A'] == '*') {
                printf("Correct answer!\n");
                score++;
            } else {
                printf("Incorrect answer.\n");
            }
        } else {
            printf("Invalid answer.\n");
        }
    }

    printf("The exam has ended. Your score is %d out of %d.\n", score, num_questions);

    if (score >= PASS_MARK) {
        printf("Congratulations, you passed the exam!\n");
    } else {
        printf("Sorry, you failed the exam.\n");
    }
}