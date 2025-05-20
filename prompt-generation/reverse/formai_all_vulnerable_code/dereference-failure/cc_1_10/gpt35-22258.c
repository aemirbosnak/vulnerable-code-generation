//FormAI DATASET v1.0 Category: Online Examination System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 50
#define MAX_OPTIONS 4

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    int correctAnswer;
} Question;

int main() {
    Question questions[MAX_QUESTIONS];
    int numQuestions, numOptions, numCorrect = 0;
    char answer[5];

    printf("Welcome to the Online Examination System!\n");
    printf("Please enter the number of questions for the exam: ");
    scanf("%d", &numQuestions);

    printf("\n");

    for (int i = 0; i < numQuestions; i++) {
        printf("Enter question %d: ", i+1);
        scanf(" %[^\n]s", questions[i].question);

        printf("Enter the number of options for the question: ");
        scanf("%d", &numOptions);

        printf("Enter the options (separated by a comma): ");

        char *option, *saveptr;
        char optionsString[256];
        scanf(" %[^\n]s", optionsString);

        option = strtok_r(optionsString, ",", &saveptr);

        for (int j = 0; j < numOptions; j++) {
            strcpy(questions[i].options[j], option);
            option = strtok_r(NULL, ",", &saveptr);
        }

        printf("Enter the correct answer (1-%d): ", numOptions);
        scanf("%d", &questions[i].correctAnswer);

        printf("\n");
    }

    printf("You have completed the exam. Let's see how you did!\n");

    for (int i = 0; i < numQuestions; i++) {
        printf("\nQuestion %d: %s\n", i+1, questions[i].question);

        for (int j = 0; j < numOptions; j++) {
            printf("%d) %s ", j+1, questions[i].options[j]);
        }

        printf("\nYour answer: ");
        scanf("%s", answer);

        if (atoi(answer) == questions[i].correctAnswer) {
            numCorrect++;
            printf("Correct!\n");
        } else {
            printf("Incorrect. The correct answer is: %s\n", questions[i].options[questions[i].correctAnswer-1]);
        }
    }

    printf("\nYou scored %d out of %d.\n", numCorrect, numQuestions);

    return 0;
}