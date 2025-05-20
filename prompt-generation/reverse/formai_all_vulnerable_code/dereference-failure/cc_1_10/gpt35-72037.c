//FormAI DATASET v1.0 Category: Data structures visualization ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

typedef struct student {
    char name[20];
    float grade;
    struct student *next; 
} Student;

void print_students(Student *head) {
    Student *current = head;
    printf("List of students: \n");
    while (current != NULL) {
        printf("%s: %.1f\n", current->name, current->grade);
        current = current->next;
    }
}

int main() {
    Student *head = NULL;
    Student *second = NULL;
    Student *third = NULL;

    // allocate memory for students
    head = (Student*)malloc(sizeof(Student));
    second = (Student*)malloc(sizeof(Student));
    third = (Student*)malloc(sizeof(Student));

    // assign values to students
    strcpy(head->name, "Alice");
    head->grade = 92.5;
    head->next = second;
    strcpy(second->name, "Bob");
    second->grade = 85.0;
    second->next = third;
    strcpy(third->name, "Charlie");
    third->grade = 77.2;
    third->next = NULL;

    // print list of students
    print_students(head);

    // insert new student at beginning
    Student *new_student = (Student*)malloc(sizeof(Student));
    strcpy(new_student->name, "Emily");
    new_student->grade = 91.3;
    new_student->next = head;
    head = new_student;

    // print updated list of students
    print_students(head);

    // delete last student
    Student *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;

    // print updated list of students
    print_students(head);

    // deallocate memory
    free(head);
    free(second);
    free(third);

    return 0;
}