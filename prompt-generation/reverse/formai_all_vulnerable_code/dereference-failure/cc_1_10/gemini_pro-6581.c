//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question {
    char *question;
    char **options;
    int num_options;
    int correct_answer;
};

struct exam {
    char *name;
    struct question *questions;
    int num_questions;
};

struct student {
    char *name;
    int score;
};

void create_question(struct question *question, char *question_text, char **options, int num_options, int correct_answer) {
    question->question = strdup(question_text);
    question->options = malloc(sizeof(char *) * num_options);
    for (int i = 0; i < num_options; i++) {
        question->options[i] = strdup(options[i]);
    }
    question->num_options = num_options;
    question->correct_answer = correct_answer;
}

void create_exam(struct exam *exam, char *exam_name, struct question *questions, int num_questions) {
    exam->name = strdup(exam_name);
    exam->questions = questions;
    exam->num_questions = num_questions;
}

void take_exam(struct student *student, struct exam *exam) {
    student->score = 0;
    for (int i = 0; i < exam->num_questions; i++) {
        struct question *question = &exam->questions[i];
        printf("%s\n", question->question);
        for (int j = 0; j < question->num_options; j++) {
            printf("%d. %s\n", j + 1, question->options[j]);
        }
        int answer;
        scanf("%d", &answer);
        if (answer == question->correct_answer) {
            student->score++;
        }
    }
}

void print_results(struct student *student, struct exam *exam) {
    printf("%s scored %d out of %d on the %s exam.\n", student->name, student->score, exam->num_questions, exam->name);
}

int main() {
    struct question questions[] = {
        {"What is the capital of France?", {"Paris", "London", "Rome", "Madrid"}, 4, 1},
        {"What is the largest ocean in the world?", {"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean"}, 4, 1},
        {"What is the name of the largest planet in the solar system?", {"Jupiter", "Saturn", "Uranus", "Neptune"}, 4, 1},
    };

    struct exam exam = {"World Geography Exam", questions, sizeof(questions) / sizeof(struct question)};

    struct student student = {"John Doe", 0};

    take_exam(&student, &exam);

    print_results(&student, &exam);

    return 0;
}