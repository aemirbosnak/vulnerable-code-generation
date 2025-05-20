//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_OPTIONS 4
#define MAX_ANSWER_LENGTH 100
#define PASSING_SCORE 70

typedef struct {
    char question[MAX_ANSWER_LENGTH];
    char options[MAX_OPTIONS][MAX_ANSWER_LENGTH];
    int correct_answer;
} question_t;

void print_question(question_t *question) {
    printf("%s\n", question->question);
    for (int i = 0; i < MAX_OPTIONS; i++) {
        printf("%d. %s\n", i+1, question->options[i]);
    }
}

int main() {
    question_t questions[MAX_QUESTIONS];
    int num_questions = 0;

    // Load questions from file
    FILE *fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open questions file.\n");
        return 1;
    }

    char line[MAX_ANSWER_LENGTH];
    while (fgets(line, MAX_ANSWER_LENGTH, fp)!= NULL) {
        if (num_questions >= MAX_QUESTIONS) {
            printf("Error: too many questions in file.\n");
            fclose(fp);
            return 2;
        }

        char *question_ptr = strtok(line, ":");
        strcpy(questions[num_questions].question, question_ptr);

        int num_options = 0;
        while (num_options < MAX_OPTIONS && (question_ptr = strtok(NULL, ":"))!= NULL) {
            strcpy(questions[num_questions].options[num_options], question_ptr);
            num_options++;
        }

        questions[num_questions].correct_answer = atoi(strtok(NULL, ":"));
        num_questions++;
    }

    fclose(fp);

    // Take exam
    int num_correct = 0;
    for (int i = 0; i < num_questions; i++) {
        int user_answer = 0;
        printf("Question %d:\n", i+1);
        print_question(&questions[i]);
        scanf("%d", &user_answer);

        if (user_answer == questions[i].correct_answer) {
            num_correct++;
        }
    }

    printf("You got %d out of %d correct.\n", num_correct, num_questions);

    return 0;
}