//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *question;
    char *answers[4];
    int correct;
} question_t;

void load_questions(question_t **questions, int *num_questions) {
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp) != NULL) {
        question_t *question = malloc(sizeof(question_t));

        char *token = strtok(line, "|");
        question->question = strdup(token);

        for (int i = 0; i < 4; i++) {
            token = strtok(NULL, "|");
            question->answers[i] = strdup(token);
        }

        token = strtok(NULL, "|");
        question->correct = atoi(token);

        (*questions) = realloc(*questions, sizeof(question_t) * (*num_questions + 1));
        (*questions)[*num_questions] = *question;
        (*num_questions)++;
    }

    fclose(fp);
}

void take_test(question_t *questions, int num_questions) {
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%d. %s\n", j + 1, questions[i].answers[j]);
        }

        int answer;
        printf("Enter your answer: ");
        scanf("%d", &answer);

        if (answer == questions[i].correct) {
            score++;
        }
    }

    printf("Your score is %d/%d\n", score, num_questions);
}

int main() {
    question_t *questions = NULL;
    int num_questions = 0;

    load_questions(&questions, &num_questions);
    take_test(questions, num_questions);

    for (int i = 0; i < num_questions; i++) {
        free(questions[i].question);
        for (int j = 0; j < 4; j++) {
            free(questions[i].answers[j]);
        }
        free(&questions[i]);
    }
    free(questions);

    return 0;
}