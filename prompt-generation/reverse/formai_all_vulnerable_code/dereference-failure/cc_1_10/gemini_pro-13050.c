//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[50];
    int marks;
};

struct exam {
    int id;
    char name[50];
    int duration;
    struct student students[100];
    int num_students;
};

void create_exam(struct exam *exam) {
    printf("Enter exam ID: ");
    scanf("%d", &exam->id);
    printf("Enter exam name: ");
    scanf("%s", exam->name);
    printf("Enter exam duration: ");
    scanf("%d", &exam->duration);
}

void add_student(struct exam *exam) {
    int id, marks;
    char name[50];
    printf("Enter student ID: ");
    scanf("%d", &id);
    printf("Enter student name: ");
    scanf("%s", name);
    printf("Enter student marks: ");
    scanf("%d", &marks);
    struct student student = {
        .id = id,
        .name = name,
        .marks = marks
    };
    exam->students[exam->num_students++] = student;
}

void print_exam(struct exam *exam) {
    printf("Exam ID: %d\n", exam->id);
    printf("Exam name: %s\n", exam->name);
    printf("Exam duration: %d\n", exam->duration);
    printf("Students:\n");
    for (int i = 0; i < exam->num_students; i++) {
        printf("%d %s %d\n", exam->students[i].id, exam->students[i].name, exam->students[i].marks);
    }
}

int main() {
    struct exam exam;
    create_exam(&exam);
    int choice;
    do {
        printf("1. Add student\n");
        printf("2. Print exam\n");
        printf("0. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_student(&exam);
                break;
            case 2:
                print_exam(&exam);
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);
    return 0;
}