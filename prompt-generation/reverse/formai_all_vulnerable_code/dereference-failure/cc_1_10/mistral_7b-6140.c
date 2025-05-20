//MISTRAL-7B DATASET v1.0 Category: Online Examination System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_QID 10000
#define MAX_QUESTION_LEN 256
#define MAX_ANSWERS 5
#define ANSWER_LEN 50
#define STUDENT_NAME_LEN 50

typedef struct {
    int qid;
    char question[MAX_QUESTION_LEN];
    char answers[MAX_ANSWERS][ANSWER_LEN];
    int correct_answer_index;
} Question;

Question questions[MAX_QID];
int num_questions = 0;

void load_questions() {
    FILE *fp = fopen("questions.txt", "r");
    char line[MAX_QUESTION_LEN];
    char *token, *answer_token;
    int i, qid;

    while (fgets(line, sizeof(line), fp)) {
        qid = atoi(strtok(line, ":") + 1);
        strcpy(questions[num_questions].question, line);

        i = 0;
        while (i < MAX_ANSWERS && fgets(line, sizeof(line), fp)) {
            answer_token = strtok(line, ":");
            strcpy(questions[num_questions].answers[i], answer_token + 1);
            i++;
        }

        questions[num_questions].correct_answer_index = rand() % MAX_ANSWERS;
        num_questions++;
    }

    fclose(fp);
}

void display_question(Question q) {
    int i;

    printf("\nQuestion %d:\n%s\n", q.qid, q.question);
    for (i = 0; i < MAX_ANSWERS; i++) {
        printf("%d. %s\n", i+1, q.answers[i]);
    }
}

void get_answer() {
    int answer, index;
    scanf("%d", &answer);
    index = answer - 1;

    if (index < 0 || index >= MAX_ANSWERS) {
        printf("Invalid answer. Please try again.\n");
        get_answer();
        return;
    }
}

int main() {
    int student_id, i;
    char student_name[STUDENT_NAME_LEN];

    load_questions();

    printf("Enter your student ID: ");
    scanf("%d", &student_id);
    printf("Enter your name: ");
    scanf("%s", student_name);

    for (i = 0; i < num_questions; i++) {
        display_question(questions[i]);
        get_answer();

        if (questions[i].correct_answer_index == index) {
            printf("Correct answer! Well done.\n");
        } else {
            printf("Incorrect answer. The correct answer was %s.\n", questions[i].answers[questions[i].correct_answer_index]);
        }
    }

    printf("Your exam is over. Your score will be calculated and displayed later.\n");

    return 0;
}