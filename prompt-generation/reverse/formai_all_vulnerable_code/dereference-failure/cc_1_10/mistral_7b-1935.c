//MISTRAL-7B DATASET v1.0 Category: Periodic Table Quiz ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define QUESTIONS_PER_ROUND 5
#define MIN_OPTIONS 2
#define MAX_OPTIONS 5

typedef struct Question {
    char description[100];
    char answer[10];
    int num_options;
    char options[MAX_OPTIONS][30];
} Question;

Question questions[MAX_QUESTIONS];
int num_questions = 0;

void load_questions() {
    FILE *fp = fopen("questions.txt", "r");
    char line[100];

    if (fp == NULL) {
        printf("Error loading questions file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        sscanf(line, "%[^:]: %[^,],%d%[^\n]", questions[num_questions].description, questions[num_questions].answer, &questions[num_questions].num_options);

        for (int i = 0; i < questions[num_questions].num_options; i++) {
            gets(questions[num_questions].options[i]);
            strcpy(questions[num_questions].options[i], strtok(NULL, "\n"));
            strcpy(questions[num_questions].options[i], strtok(NULL, "\n"));
        }

        num_questions++;
    }

    fclose(fp);
}

void print_question(Question q) {
    printf("\n%s\n", q.description);

    for (int i = 0; i < q.num_options; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
    }
}

int main() {
    int score = 0;
    int num_rounds = 1;
    int num_questions_answered = 0;

    load_questions();

    srand(time(NULL));

    while (num_questions_answered < MAX_QUESTIONS) {
        int index = rand() % num_questions;
        Question q = questions[index];

        print_question(q);

        int user_answer;
        scanf("%d", &user_answer);

        if (user_answer == q.num_options + 1) {
            user_answer--;
        }

        if (strcmp(questions[index].answer, questions[index].options[user_answer]) == 0) {
            score++;
            printf("Correct! Your score is %d.\n", score);
        } else {
            printf("Incorrect! The correct answer is %s.\n", questions[index].answer);
        }

        num_questions_answered++;

        if (num_questions_answered % QUESTIONS_PER_ROUND == 0 && num_rounds < num_questions / QUESTIONS_PER_ROUND) {
            printf("\nRound %d complete. Your score is %d.\n\n", num_rounds, score);
            num_rounds++;
        }
    }

    printf("\nYour final score is %d.\n", score);

    return 0;
}