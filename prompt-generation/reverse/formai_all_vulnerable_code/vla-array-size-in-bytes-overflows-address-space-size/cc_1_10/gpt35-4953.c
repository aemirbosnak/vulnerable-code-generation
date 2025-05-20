//FormAI DATASET v1.0 Category: Online Examination System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    char question[1000];
    char options[4][1000];
    char answer;
};

int main() {
    int num_questions, score = 0;

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter the number of questions you want to attempt: ");
    scanf("%d", &num_questions);

    struct question exam[num_questions];

    printf("\nEnter the questions and options:\n");

    for(int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n", i+1);
        getchar();
        fgets(exam[i].question, 1000, stdin);
        printf("Option 1: ");
        fgets(exam[i].options[0], 1000, stdin);
        printf("Option 2: ");
        fgets(exam[i].options[1], 1000, stdin);
        printf("Option 3: ");
        fgets(exam[i].options[2], 1000, stdin);
        printf("Option 4: ");
        fgets(exam[i].options[3], 1000, stdin);
        printf("Correct Answer (a/b/c/d): ");
        scanf("%c", &exam[i].answer);
    }

    printf("\nExam begins now:\n");

    for(int i = 0; i < num_questions; i++) {
        printf("\nQuestion %d:\n%s", i+1, exam[i].question);
        printf("a. %s", exam[i].options[0]);
        printf("b. %s", exam[i].options[1]);
        printf("c. %s", exam[i].options[2]);
        printf("d. %s", exam[i].options[3]);

        char selected;
        printf("Enter your answer (a/b/c/d): ");
        scanf(" %c", &selected);

        if(selected == exam[i].answer) {
            score++;
        }
    }

    printf("\nYour score is %d out of %d", score, num_questions);
    printf("\nThank you for taking the exam!");

    return 0;
}