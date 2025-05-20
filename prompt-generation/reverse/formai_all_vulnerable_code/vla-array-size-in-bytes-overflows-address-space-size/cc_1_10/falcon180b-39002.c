//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 20

typedef struct {
    char question[MAX_QUESTIONS];
    char options[MAX_OPTIONS][MAX_ANSWERS];
    int correct_answer;
} Question;

void generate_question() {
    char question[MAX_QUESTIONS];
    char options[MAX_OPTIONS][MAX_ANSWERS];
    int correct_answer;

    printf("Enter the question: ");
    scanf("%s", question);

    printf("Enter the number of options: ");
    scanf("%d", &correct_answer);

    for (int i = 0; i < correct_answer; i++) {
        printf("Enter option %d: ", i + 1);
        scanf("%s", options[i]);
    }

    printf("Enter the correct answer (1-4): ");
    scanf("%d", &correct_answer);

    printf("\nQuestion: %s\n", question);

    for (int i = 0; i < correct_answer; i++) {
        printf("Option %d: %s\n", i + 1, options[i]);
    }
}

int main() {
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);

    Question questions[num_questions];

    for (int i = 0; i < num_questions; i++) {
        generate_question();
        questions[i].correct_answer = scanf("%d", &questions[i].correct_answer);
    }

    int num_correct = 0;

    for (int i = 0; i < num_questions; i++) {
        int user_answer = scanf("%d", &user_answer);

        if (user_answer == questions[i].correct_answer) {
            num_correct++;
        }
    }

    printf("\nYou got %d out of %d questions correct!\n", num_correct, num_questions);

    return 0;
}