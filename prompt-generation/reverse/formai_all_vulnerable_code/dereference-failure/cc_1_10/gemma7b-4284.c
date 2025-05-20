//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

#define NUM_QUESTIONS 10

struct Question {
    char question[255];
    int answer;
    struct Question* next;
};

struct Student {
    char name[255];
    int roll_no;
    struct Student* next;
    struct Answer* answer_sheet;
};

struct Answer {
    int question_no;
    int answer;
    struct Answer* next;
};

void create_question(struct Question** head) {
    *head = (struct Question*)malloc(sizeof(struct Question));
    (*head)->question[0] = '\0';
    (*head)->answer = 0;
    (*head)->next = NULL;
}

void add_question(struct Question** head, char* question, int answer) {
    struct Question* new_question = (struct Question*)malloc(sizeof(struct Question));
    new_question->question[0] = '\0';
    new_question->answer = answer;
    new_question->next = NULL;

    if (*head == NULL) {
        *head = new_question;
    } else {
        (*head)->next = new_question;
        *head = new_question;
    }
}

void create_student(struct Student** head) {
    *head = (struct Student*)malloc(sizeof(struct Student));
    (*head)->name[0] = '\0';
    (*head)->roll_no = 0;
    (*head)->next = NULL;
    (*head)->answer_sheet = NULL;
}

void add_student(struct Student** head, char* name, int roll_no) {
    struct Student* new_student = (struct Student*)malloc(sizeof(struct Student));
    new_student->name[0] = '\0';
    new_student->roll_no = roll_no;
    new_student->next = NULL;
    new_student->answer_sheet = NULL;

    if (*head == NULL) {
        *head = new_student;
    } else {
        (*head)->next = new_student;
        *head = new_student;
    }
}

void create_answer(struct Answer** head) {
    *head = (struct Answer*)malloc(sizeof(struct Answer));
    (*head)->question_no = 0;
    (*head)->answer = 0;
    (*head)->next = NULL;
}

void add_answer(struct Answer** head, int question_no, int answer) {
    struct Answer* new_answer = (struct Answer*)malloc(sizeof(struct Answer));
    new_answer->question_no = question_no;
    new_answer->answer = answer;
    new_answer->next = NULL;

    if (*head == NULL) {
        *head = new_answer;
    } else {
        (*head)->next = new_answer;
        *head = new_answer;
    }
}

int main() {
    struct Question* questions = NULL;
    struct Student* students = NULL;
    struct Answer* answers = NULL;

    // Create and add questions
    create_question(&questions);
    add_question(&questions, "What is the capital of France?", 1);
    add_question(&questions, "Who invented the telephone?", 2);
    add_question(&questions, "Which planet is the largest?", 3);

    // Create and add students
    create_student(&students);
    add_student(&students, "John Doe", 123);
    add_student(&students, "Jane Doe", 456);

    // Create and add answers
    create_answer(&answers);
    add_answer(&answers, 1, 2);
    add_answer(&answers, 2, 3);
    add_answer(&answers, 3, 1);

    // Print the student's answers
    struct Student* current_student = students;
    while (current_student) {
        printf("Student: %s, Roll No: %d\n", current_student->name, current_student->roll_no);
        struct Answer* current_answer = current_student->answer_sheet;
        while (current_answer) {
            printf("Question No: %d, Answer: %d\n", current_answer->question_no, current_answer->answer);
            current_answer = current_answer->next;
        }
        current_student = current_student->next;
    }

    return 0;
}