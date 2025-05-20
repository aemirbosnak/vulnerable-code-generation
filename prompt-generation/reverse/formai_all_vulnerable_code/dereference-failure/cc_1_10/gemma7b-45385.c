//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

struct Question {
    char question[255];
    char answer[255];
    int marks;
    struct Question* next;
};

struct Student {
    char name[255];
    int rollNo;
    struct Student* next;
    int marksObtained;
    int totalMarks;
    struct Question* currentQuestion;
};

void createQuestion(struct Question** head) {
    struct Question* newQuestion = (struct Question*)malloc(sizeof(struct Question));
    printf("Enter the question: ");
    scanf("%s", newQuestion->question);
    printf("Enter the answer: ");
    scanf("%s", newQuestion->answer);
    printf("Enter the marks: ");
    scanf("%d", &newQuestion->marks);
    newQuestion->next = NULL;
    if (*head == NULL) {
        *head = newQuestion;
    } else {
        (*head)->next = newQuestion;
    }
}

void createStudent(struct Student** head) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    printf("Enter the name: ");
    scanf("%s", newStudent->name);
    printf("Enter the roll no: ");
    scanf("%d", &newStudent->rollNo);
    newStudent->next = NULL;
    if (*head == NULL) {
        *head = newStudent;
    } else {
        (*head)->next = newStudent;
    }
}

void startExam(struct Student* student) {
    struct Question* questionHead = student->currentQuestion;
    while (questionHead) {
        printf("%s", questionHead->question);
        printf("\n");
        printf("Enter your answer: ");
        char answer[255];
        scanf("%s", answer);
        if (strcmp(answer, questionHead->answer) == 0) {
            student->marksObtained++;
        }
        questionHead = questionHead->next;
    }
}

int main() {
    struct Student* studentHead = NULL;
    struct Question* questionHead = NULL;
    createStudent(&studentHead);
    createQuestion(&questionHead);
    startExam(studentHead);
    printf("Your total marks obtained: %d", studentHead->marksObtained);
    return 0;
}