//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
    char *question;
    char *options[4];
    char *correct_answer;
};

struct Exam {
    char *name;
    int number_of_questions;
    struct Question *questions;
};

struct Student {
    char *name;
    int score;
};

void create_exam(struct Exam *exam) {
    printf("Enter the name of the exam: ");
    scanf("%s", exam->name);

    printf("Enter the number of questions in the exam: ");
    scanf("%d", &exam->number_of_questions);

    exam->questions = malloc(sizeof(struct Question) * exam->number_of_questions);

    for (int i = 0; i < exam->number_of_questions; i++) {
        printf("Enter the question %d: ", i + 1);
        scanf(" %[^\n]%*c", exam->questions[i].question);

        printf("Enter the four options for question %d: ", i + 1);
        for (int j = 0; j < 4; j++) {
            scanf(" %[^\n]%*c", exam->questions[i].options[j]);
        }

        printf("Enter the correct answer for question %d: ", i + 1);
        scanf(" %[^\n]%*c", exam->questions[i].correct_answer);
    }
}

void take_exam(struct Exam *exam, struct Student *student) {
    printf("Welcome to the exam %s, %s!\n", exam->name, student->name);

    for (int i = 0; i < exam->number_of_questions; i++) {
        printf("Question %d: %s\n", i + 1, exam->questions[i].question);

        for (int j = 0; j < 4; j++) {
            printf("Option %d: %s\n", j + 1, exam->questions[i].options[j]);
        }

        char answer;
        printf("Enter your answer: ");
        scanf(" %c", &answer);

        if (answer == exam->questions[i].correct_answer[0]) {
            student->score++;
        }
    }
}

void print_results(struct Exam *exam, struct Student *student) {
    printf("Results for the exam %s:\n", exam->name);
    printf("Student: %s\n", student->name);
    printf("Score: %d/%d\n", student->score, exam->number_of_questions);
}

int main() {
    struct Exam exam;
    create_exam(&exam);

    struct Student student;
    printf("Enter your name: ");
    scanf("%s", student.name);
    student.score = 0;

    take_exam(&exam, &student);
    print_results(&exam, &student);

    return 0;
}