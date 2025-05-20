//FormAI DATASET v1.0 Category: Online Examination System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char question[100];
    char options[4][50];
    int correct_option;
};

int main() {
    int num_questions;
    printf("Enter the number of questions: ");
    scanf("%d", &num_questions);
    printf("\n");

    struct Question *questions = malloc(num_questions * sizeof(struct Question));

    for (int i = 0; i < num_questions; i++) {
        struct Question question;

        printf("Enter question %d: ", i+1);
        scanf(" %[^\n]%*c", question.question);

        printf("Enter option 1: ");
        scanf(" %[^\n]%*c", question.options[0]);

        printf("Enter option 2: ");
        scanf(" %[^\n]%*c", question.options[1]);

        printf("Enter option 3: ");
        scanf(" %[^\n]%*c", question.options[2]);

        printf("Enter option 4: ");
        scanf(" %[^\n]%*c", question.options[3]);

        printf("Enter the correct option (1-4): ");
        scanf("%d", &question.correct_option);

        questions[i] = question;
        printf("\n");
    }

    int score = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        printf("1. %s\n", questions[i].options[0]);
        printf("2. %s\n", questions[i].options[1]);
        printf("3. %s\n", questions[i].options[2]);
        printf("4. %s\n", questions[i].options[3]);

        int chosen_option;
        printf("Choose your answer: ");
        scanf("%d", &chosen_option);

        if (chosen_option == questions[i].correct_option) {
            score++;
        }

        printf("\n");
    }

    printf("You scored %d out of %d.\n", score, num_questions);

    free(questions);
    return 0;
}