//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_QUESTIONS 5
#define MAX_WORDS 100
#define WORD_LENGTH 20

typedef struct {
    char question[WORD_LENGTH];
    char answer[WORD_LENGTH];
} QuestionAnswerPair;

QuestionAnswerPair questions[NUM_QUESTIONS];

void loadQuestions(void);
void askQuestion(void);

int main() {
    loadQuestions();
    srand(time(NULL));
    for (int i = 0; i < NUM_QUESTIONS; i++) {
        askQuestion();
    }
    return 0;
}

void loadQuestions(void) {
    FILE *fp;
    char line[WORD_LENGTH];
    int index = 0;

    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, WORD_LENGTH, fp) != NULL) {
        strcpy(questions[index].question, line);
        index++;
    }

    fclose(fp);
}

void askQuestion(void) {
    int randomIndex = rand() % NUM_QUESTIONS;
    printf("\n%s\n", questions[randomIndex].question);
    printf("The answer is: %s\n", questions[randomIndex].answer);
}