//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct Student {
    char name[20];
    int rollno;
    float marks[3];
    struct Student *next;
} Student;

Student *insertAtTail(Student *head, char *name, int rollno, float marks[]) {
    Student *newNode = (Student *)malloc(sizeof(Student));
    strcpy(newNode->name, name);
    newNode->rollno = rollno;
    newNode->marks[0] = marks[0];
    newNode->marks[1] = marks[1];
    newNode->marks[2] = marks[2];
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void printStudents(Student *head) {
    Student *current = head;
    while (current) {
        printf("%s, %d, %.1f, %.1f, %.1f\n", current->name, current->rollno, current->marks[0], current->marks[1], current->marks[2]);
        current = current->next;
    }
}

int main() {
    Student *head = NULL;

    insertAtTail(head, "John Doe", 12, (float[]){90, 80, 70});
    insertAtTail(head, "Jane Doe", 13, (float[]){80, 90, 85});
    insertAtTail(head, "Peter Pan", 14, (float[]){70, 80, 90});

    printStudents(head);

    return 0;
}