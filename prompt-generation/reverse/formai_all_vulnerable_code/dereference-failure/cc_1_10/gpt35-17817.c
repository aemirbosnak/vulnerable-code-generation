//FormAI DATASET v1.0 Category: Online Examination System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("Welcome to the Online Examination System\n");
    printf("Please enter the number of questions:");
    int numQuestions;
    scanf("%d", &numQuestions);

    // dynamically allocate memory for question and answer arrays
    char **questions = (char **)malloc(numQuestions * sizeof(char *));
    char **answers = (char **)malloc(numQuestions * sizeof(char *));

    for (int i = 0; i < numQuestions; i++) {
        questions[i] = (char *)malloc(100 * sizeof(char));
        printf("Enter question #%d:", i+1);
        scanf(" %[^\n]s", questions[i]);

        answers[i] = (char *)malloc(20 * sizeof(char));
        printf("Enter the answer to question #%d:", i+1);
        scanf("%s", answers[i]);
    }

    int score = 0;
    printf("Begin Exam:\n");

    for (int i = 0; i < numQuestions; i++) {
        char userAnswer[20];
        printf("Question #%d: %s\n", i+1, questions[i]);
        printf("Answer: ");
        scanf("%s", userAnswer);
        if (strcmp(userAnswer, answers[i]) == 0) {
            printf("Correct!\n");
            score++;
        }
        else {
            printf("Incorrect!\n");
        }
    }

    printf("Your final score is %d out of %d\n", score, numQuestions);

    // free allocated memory
    for (int i = 0; i < numQuestions; i++) {
        free(questions[i]);
        free(answers[i]);
    }
    free(questions);
    free(answers);
    
    return 0;
}