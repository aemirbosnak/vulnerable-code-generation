//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_CLASSES 50

typedef struct student {
    char name[50];
    int roll_no;
    float marks[10];
    struct student *next;
} student;

typedef struct class {
    char name[50];
    int no_of_students;
    struct student **students;
    struct class *next;
} class;

void insert_student(class *cls, student *new_student) {
    new_student->next = cls->students;
    cls->students = new_student;
    cls->no_of_students++;
}

void insert_class(struct class **head, char *name) {
    struct class *new_class = malloc(sizeof(struct class));
    strcpy(new_class->name, name);
    new_class->no_of_students = 0;
    new_class->students = NULL;
    new_class->next = NULL;

    if (*head == NULL) {
        *head = new_class;
    } else {
        (*head)->next = new_class;
    }
}

int main() {
    struct class *classes = NULL;
    struct student *students = NULL;

    insert_class(&classes, "Maths");
    insert_class(&classes, "Physics");
    insert_class(&classes, "Chemistry");

    insert_student(classes->students, malloc(sizeof(struct student)));
    strcpy(students->name, "John Doe");
    students->roll_no = 1;
    students->marks[0] = 90.5;
    students->marks[1] = 80.0;

    insert_student(classes->students, malloc(sizeof(struct student)));
    strcpy(students->name, "Jane Doe");
    students->roll_no = 2;
    students->marks[0] = 75.0;
    students->marks[1] = 85.0;

    for (struct student *stud = students; stud; stud = stud->next) {
        printf("%s (%d) has marks: ", stud->name, stud->roll_no);
        for (int i = 0; i < 10; i++) {
            printf("%f ", stud->marks[i]);
        }
        printf("\n");
    }

    return 0;
}