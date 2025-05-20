//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXAMS 10

struct Exam {
    char title[50];
    char syllabus[200];
    int marks;
    struct Exam* next;
};

void createExam(struct Exam** head) {
    *head = malloc(sizeof(struct Exam));
    (*head)->next = NULL;
    return;
}

void addExam(struct Exam** head, char* title, char* syllabus, int marks) {
    struct Exam* newExam = malloc(sizeof(struct Exam));
    strcpy(newExam->title, title);
    strcpy(newExam->syllabus, syllabus);
    newExam->marks = marks;
    newExam->next = NULL;

    if (*head) {
        (*head)->next = newExam;
    } else {
        *head = newExam;
    }
}

void printExams(struct Exam* head) {
    while (head) {
        printf("Title: %s\n", head->title);
        printf("Syllabus: %s\n", head->syllabus);
        printf("Marks: %d\n", head->marks);
        printf("\n");
        head = head->next;
    }
}

int main() {
    struct Exam* head = NULL;

    createExam(&head);
    addExam(&head, "Calculus", "Differential Equations, Integration, Limits", 80);
    addExam(&head, "Physics", "Mechanics, Electricity, Thermodynamics", 90);
    addExam(&head, "English", "Literature, Grammar, Composition", 70);

    printExams(head);

    return 0;
}