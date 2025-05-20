//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    char* name;
    char* question;
    char* options[4];
    char* correct_option;
    int correct_index;
} ExamQuestion;

typedef struct {
    char* name;
    int num_questions;
    ExamQuestion* questions;
} Exam;

void print_menu() {
    printf("1. Register Student\n2. Create Exam\n3. Take Exam\n4. Exit\n");
}

void register_student(char* name) {
    printf("Student '%s' has been registered.\n", name);
}

void create_exam(char* name, int num_questions) {
    Exam* exam = (Exam*)malloc(sizeof(Exam));
    exam->name = name;
    exam->num_questions = num_questions;
    exam->questions = (ExamQuestion*)malloc(num_questions * sizeof(ExamQuestion));
    for (int i = 0; i < num_questions; i++) {
        ExamQuestion* question = &(exam->questions[i]);
        question->name = "Question " + i;
        question->question = "What is the capital of France?";
        question->options[0] = "London";
        question->options[1] = "Paris";
        question->options[2] = "Berlin";
        question->options[3] = "Rome";
        question->correct_option = "Paris";
        question->correct_index = 1;
    }
}

void take_exam(Exam* exam) {
    int num_questions = exam->num_questions;
    int correct = 0;
    for (int i = 0; i < num_questions; i++) {
        printf("%s.\n", exam->questions[i].name);
        printf("%s.\n", exam->questions[i].question);
        printf("A) %s\n", exam->questions[i].options[0]);
        printf("B) %s\n", exam->questions[i].options[1]);
        printf("C) %s\n", exam->questions[i].options[2]);
        printf("D) %s\n", exam->questions[i].options[3]);
        printf("Answer: ");
        char answer[5];
        scanf("%s", answer);
        if (strcmp(answer, exam->questions[i].correct_option) == 0) {
            printf("Correct!\n");
            correct++;
        } else {
            printf("Incorrect.\n");
        }
    }
    printf("You scored %d/%d.\n", correct, num_questions);
}

int main() {
    srand(time(0));
    Exam exam;
    exam.name = "My Exam";
    exam.num_questions = 4;
    create_exam(exam.name, exam.num_questions);
    take_exam(&exam);
    return 0;
}