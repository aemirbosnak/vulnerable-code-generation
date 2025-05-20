//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
    char *question;
    char **answers;
    int answerIndex;
} Question;

Question questions[MAX_QUESTIONS];

void generateQuestions() {
    // Generate questions and answers
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        questions[i].question = malloc(20);
        sprintf(questions[i].question, "Question %d:", i + 1);

        questions[i].answers = malloc(MAX_ANSWERS * sizeof(char *));
        for (int j = 0; j < MAX_ANSWERS; j++) {
            questions[i].answers[j] = malloc(20);
            sprintf(questions[i].answers[j], "Answer %d:", j + 1);
        }

        questions[i].answerIndex = rand() % MAX_ANSWERS;
    }
}

int main() {
    generateQuestions();

    // Start the exam
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%s\n", questions[i].question);

        for (int j = 0; j < MAX_ANSWERS; j++) {
            printf("%s\n", questions[i].answers[j]);
        }

        printf("Enter your answer: ");
        char answer[20];
        scanf("%s", answer);

        if (strcmp(answer, questions[i].answers[questions[i].answerIndex]) == 0) {
            printf("Correct!\n");
        } else {
            printf("Incorrect. The answer is: %s\n", questions[i].answers[questions[i].answerIndex]);
        }
    }

    return 0;
}