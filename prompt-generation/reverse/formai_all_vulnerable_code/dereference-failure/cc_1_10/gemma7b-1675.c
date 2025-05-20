//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct Student {
    char name[50];
    int roll_no;
    float marks[4];
    struct Student* next;
} Student;

Student* insertStudent(Student* head, char* name, int roll_no, float marks[]) {
    Student* newStudent = (Student*)malloc(sizeof(Student));
    strcpy(newStudent->name, name);
    newStudent->roll_no = roll_no;
    for (int i = 0; i < 4; i++) {
        newStudent->marks[i] = marks[i];
    }
    newStudent->next = NULL;

    if (head == NULL) {
        head = newStudent;
    } else {
        head->next = newStudent;
    }
    return head;
}

void printStudents(Student* head) {
    Student* currentStudent = head;
    while (currentStudent) {
        printf("Name: %s, Roll No: %d, Marks: ", currentStudent->name, currentStudent->roll_no);
        for (int i = 0; i < 4; i++) {
            printf("%f ", currentStudent->marks[i]);
        }
        printf("\n");
        currentStudent = currentStudent->next;
    }
}

int main() {
    Student* head = NULL;
    insertStudent(head, "John Doe", 123, (float[]) {80, 90, 70, 85});
    insertStudent(head, "Jane Doe", 456, (float[]) {95, 80, 75, 82});
    insertStudent(head, "Peter Pan", 789, (float[]) {85, 92, 80, 87});

    printStudents(head);

    return 0;
}