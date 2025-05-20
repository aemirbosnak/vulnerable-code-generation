//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 100
#define MAX_OPTIONS 4
#define MAX_ANSWERS 26
#define MAX_STUDENTS 100
#define PASS_PERCENTAGE 60

typedef struct {
    char name[50];
    int score;
} Student;

typedef struct {
    char question[100];
    char options[MAX_OPTIONS][50];
    char answer[MAX_ANSWERS];
    int numOptions;
} Question;

void generateRandomQuestion(Question *q) {
    int numOptions = rand() % MAX_OPTIONS + 1;
    for (int i = 0; i < numOptions; i++) {
        strcpy(q->options[i], "Option " + (char) (rand() % 26 + 'A'));
    }
    strcpy(q->answer, "A");
}

int main() {
    srand(time(NULL));
    Question questions[MAX_QUESTIONS];
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        generateRandomQuestion(&questions[i]);
    }
    int numStudents;
    scanf("%d", &numStudents);
    Student students[MAX_STUDENTS];
    for (int i = 0; i < numStudents; i++) {
        scanf("%s", students[i].name);
    }
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < MAX_QUESTIONS; j++) {
            char answer;
            scanf("%c", &answer);
            if (answer == questions[j].answer[0]) {
                students[i].score++;
            }
        }
    }
    for (int i = 0; i < numStudents; i++) {
        if (students[i].score >= PASS_PERCENTAGE * MAX_QUESTIONS) {
            printf("%s passed the exam!\n", students[i].name);
        } else {
            printf("%s failed the exam.\n", students[i].name);
        }
    }
    return 0;
}