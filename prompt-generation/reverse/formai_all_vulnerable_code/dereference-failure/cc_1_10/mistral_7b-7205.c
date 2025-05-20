//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cheerful Struct Definition 😊
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Cheerful Function Prototypes 😊
void print_menu();
void add_student(Student students[], int *size);
void display_students(Student students[], int size);
void search_student(Student students[], int size);
void delete_student(Student students[], int *size);

// Cheerful Global Variables 😊
int student_count = 0;
Student students[100];

int main() {
    int choice;

    // Cheerful Welcome Message 😊
    printf("\n-----------------------------\n");
    printf("| Welcome to Student DB!      |\n");
    printf("|-----------------------------|\n");

    while (1) {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(students, &student_count);
                printf("Student added successfully! 🤩\n");
                break;
            case 2:
                display_students(students, student_count);
                break;
            case 3:
                search_student(students, student_count);
                break;
            case 4:
                delete_student(students, &student_count);
                printf("Student deleted successfully! 💔\n");
                break;
            case 5:
                printf("Exiting the program... 🙁\n");
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again. 😕\n");
        }
    }

    return 0;
}

void print_menu() {
    printf("\n-----------------------------\n");
    printf("| Student DB Menu             |\n");
    printf("|-----------------------------|\n");
    printf("| 1. Add Student              |\n");
    printf("| 2. Display Students          |\n");
    printf("| 3. Search Student            |\n");
    printf("| 4. Delete Student            |\n");
    printf("| 5. Exit                     |\n");
    printf("|-----------------------------|\n");
}

void add_student(Student students[], int *size) {
    if (*size >= 100) {
        printf("Student DB is full! Can't add student. 🙁\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &students[*size].id);

    printf("Enter student name: ");
    scanf("%s", students[*size].name);

    printf("Enter student GPA: ");
    scanf("%f", &students[*size].gpa);

    (*size)++;
}

void display_students(Student students[], int size) {
    int i;

    printf("\n-----------------------------\n");
    printf("| Student DB                  |\n");
    printf("|-----------------------------|\n");

    for (i = 0; i < size; i++) {
        printf("| ID: %d | Name: %s | GPA: %.2f |\n", students[i].id, students[i].name, students[i].gpa);
    }

    printf("|-----------------------------|\n");
}

void search_student(Student students[], int size) {
    int id;
    int i;

    printf("Enter student ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < size; i++) {
        if (students[i].id == id) {
            printf("\nStudent Found! 🥳\n");
            printf("ID: %d | Name: %s | GPA: %.2f \n", students[i].id, students[i].name, students[i].gpa);
            return;
        }
    }

    printf("Student not found! 😕\n");
}

void delete_student(Student students[], int *size) {
    int id, index;

    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *size; i++) {
        if (students[i].id == id) {
            index = i;
            break;
        }
    }

    for (int i = index; i < *size - 1; i++) {
        students[i] = students[i + 1];
    }

    (*size)--;
}