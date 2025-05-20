//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

struct Question {
    char question[MAX_SIZE];
    char option1[MAX_SIZE];
    char option2[MAX_SIZE];
    char option3[MAX_SIZE];
    char option4[MAX_SIZE];
    char answer[MAX_SIZE];
};

void read_questions(struct Question questions[], int num_questions) {
    for (int i = 0; i < num_questions; i++) {
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
        printf("Enter answer (%d for option 1, %d for option 2, %d for option 3, %d for option 4):\n", 1, 2, 3, 4);
        scanf("%d", &questions[i].answer);
    }
}

int main() {
    int num_questions;
    printf("Enter number of questions:\n");
    scanf("%d", &num_questions);

    struct Question questions[num_questions];
    read_questions(questions, num_questions);

    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("Question %d:\n%s\n", i+1, questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j+1, questions[i].option1);
        }
        int answer;
        printf("Enter your answer:\n");
        scanf("%d", &answer);
        if (answer == questions[i].answer) {
            score += 1;
        }
    }

    printf("Your score is %d out of %d\n", score, num_questions);

    return 0;
}