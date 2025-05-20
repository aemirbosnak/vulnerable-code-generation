//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct student {
    char name[50];
    int age;
    struct student* next;
} student;

student* head = NULL;

void addStudent(student* head, const char* name, int age) {
    student* newStudent = (student*)malloc(sizeof(student));
    strcpy(newStudent->name, name);
    newStudent->age = age;
    newStudent->next = head;
    head = newStudent;
}

void removeStudentByName(student* head, const char* name) {
    student* current = head;
    student* previous = NULL;

    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }
}

void displayList(student* head) {
    student* current = head;

    printf("\nStudent List:\n");
    while (current != NULL) {
        printf("%s (%d years old)\n", current->name, current->age);
        current = current->next;
    }
}

int main() {
    addStudent(head, "Alice", 23);
    addStudent(head, "Bob", 25);
    addStudent(head, "Charlie", 19);

    displayList(head);

    removeStudentByName(head, "Bob");

    displayList(head);

    free(head);

    return 0;
}