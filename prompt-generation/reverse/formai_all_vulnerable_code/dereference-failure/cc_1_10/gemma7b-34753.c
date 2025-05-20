//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question {
    char *question;
    int answer;
    struct Question *next;
} Question;

int main() {
    Question *head = NULL;

    // Create a few questions
    Question *q1 = malloc(sizeof(Question));
    q1->question = "What is the meaning of the word 'entrepreneur'?";
    q1->answer = 3;
    q1->next = head;
    head = q1;

    Question *q2 = malloc(sizeof(Question));
    q2->question = "Who invented the telephone?";
    q2->answer = 2;
    q2->next = head;
    head = q2;

    Question *q3 = malloc(sizeof(Question));
    q3->question = "What is the capital of France?";
    q3->answer = 1;
    q3->next = head;
    head = q3;

    // Let's see if the user can answer the questions
    int score = 0;
    char answer;

    // Loop through the questions
    for (Question *curr = head; curr; curr = curr->next) {
        printf("%s", curr->question);
        scanf(" %c", &answer);

        if (answer == curr->answer) {
            score++;
        }
    }

    // Print the user's score
    printf("Your score: %d", score);

    return 0;
}