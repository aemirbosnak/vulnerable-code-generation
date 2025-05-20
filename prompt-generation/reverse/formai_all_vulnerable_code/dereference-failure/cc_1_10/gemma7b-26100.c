//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXAMS 10

typedef struct Exam
{
    char title[50];
    int marks;
    struct Exam* next;
} Exam;

Exam* createExam(char* title, int marks)
{
    Exam* newExam = (Exam*)malloc(sizeof(Exam));
    strcpy(newExam->title, title);
    newExam->marks = marks;
    newExam->next = NULL;
    return newExam;
}

void addExam(Exam* head, char* title, int marks)
{
    Exam* newExam = createExam(title, marks);
    if (head == NULL)
    {
        head = newExam;
    }
    else
    {
        head->next = newExam;
        head = newExam;
    }
}

int main()
{
    Exam* head = NULL;
    addExam(head, "Maths", 90);
    addExam(head, "Physics", 80);
    addExam(head, "Chemistry", 70);

    Exam* currentExam = head;
    while (currentExam)
    {
        printf("Title: %s, Marks: %d\n", currentExam->title, currentExam->marks);
        currentExam = currentExam->next;
    }

    return 0;
}