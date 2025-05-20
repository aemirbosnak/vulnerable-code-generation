//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

struct Question {
    char question[256];
    char answer[256];
    int marks;
    struct Question* next;
};

struct Student {
    char name[256];
    int rollNo;
    struct Student* next;
    struct Score* scoreList;
};

struct Score {
    int marks;
    struct Score* next;
};

void createQuestion(struct Question** head) {
    struct Question* newQuestion = (struct Question*)malloc(sizeof(struct Question));
    newQuestion->marks = 0;
    newQuestion->next = NULL;
    *head = newQuestion;
}

void addQuestion(struct Question* head, char* question, char* answer, int marks) {
    struct Question* newQuestion = (struct Question*)malloc(sizeof(struct Question));
    newQuestion->marks = marks;
    strcpy(newQuestion->question, question);
    strcpy(newQuestion->answer, answer);
    newQuestion->next = NULL;
    if (head) {
        head->next = newQuestion;
    } else {
        head = newQuestion;
    }
}

void createStudent(struct Student** head) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->next = NULL;
    newStudent->scoreList = NULL;
    *head = newStudent;
}

void addStudent(struct Student* head, char* name, int rollNo) {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    newStudent->rollNo = rollNo;
    strcpy(newStudent->name, name);
    newStudent->next = NULL;
    if (head) {
        head->next = newStudent;
    } else {
        head = newStudent;
    }
}

void createScore(struct Score** head) {
    struct Score* newScore = (struct Score*)malloc(sizeof(struct Score));
    newScore->next = NULL;
    *head = newScore;
}

void addScore(struct Score* head, int marks) {
    struct Score* newScore = (struct Score*)malloc(sizeof(struct Score));
    newScore->marks = marks;
    newScore->next = NULL;
    if (head) {
        head->next = newScore;
    } else {
        head = newScore;
    }
}

int main() {
    struct Question* questions = NULL;
    createQuestion(&questions);
    addQuestion(questions, "What is the meaning of life?", "To be happy", 5);
    addQuestion(questions, "What is the sound of one hand clapping?", "Silence", 2);
    addQuestion(questions, "What is the capital of France?", "Paris", 4);

    struct Student* students = NULL;
    createStudent(&students);
    addStudent(students, "John Doe", 12);
    addStudent(students, "Jane Doe", 13);

    struct Score* scores = NULL;
    createScore(&scores);
    addScore(scores, 80);
    addScore(scores, 70);
    addScore(scores, 90);

    // Now you can use the data stored in the structures
    // For example:
    printf("Question: %s, Answer: %s, Marks: %d", questions->question, questions->answer, questions->marks);
    printf("\nStudent: %s, Roll No: %d", students->name, students->rollNo);
    printf("\nScore: %d", scores->marks);

    return 0;
}