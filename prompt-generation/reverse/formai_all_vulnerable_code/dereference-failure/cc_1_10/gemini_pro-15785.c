//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][100];
    int correct_option;
} Question;

Question questions[MAX_QUESTIONS];
int num_questions = 0;

void load_questions() {
    FILE *fp;
    char line[100];

    fp = fopen("questions.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp)) {
        if (line[0] == '#') {
            continue;
        }

        char *ptr = strtok(line, "|");
        strcpy(questions[num_questions].question, ptr);

        for (int i = 0; i < MAX_OPTIONS; i++) {
            ptr = strtok(NULL, "|");
            strcpy(questions[num_questions].options[i], ptr);
        }

        questions[num_questions].correct_option = atoi(strtok(NULL, "|"));

        num_questions++;
    }

    fclose(fp);
}

void take_test() {
    int score = 0;

    for (int i = 0; i < num_questions; i++) {
        printf("%s\n", questions[i].question);

        for (int j = 0; j < MAX_OPTIONS; j++) {
            printf("%d. %s\n", j + 1, questions[i].options[j]);
        }

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == questions[i].correct_option) {
            score++;
        }
    }

    printf("Your score is %d out of %d\n", score, num_questions);
}

int main() {
    load_questions();
    take_test();

    return 0;
}