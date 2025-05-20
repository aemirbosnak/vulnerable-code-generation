//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// Function to add a new student
void add_student(Student **students, int *count) {
    (*count)++;
    *students = realloc(*students, (*count) * sizeof(Student));
    if (*students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    Student *new_student = &(*students)[(*count) - 1];
    printf("Enter student ID: ");
    scanf("%d", &new_student->id);
    printf("Enter student name: ");
    getchar();  // Clear newline from the buffer
    fgets(new_student->name, sizeof(new_student->name), stdin);
    strtok(new_student->name, "\n");  // Remove newline character
    printf("Enter student grade: ");
    scanf("%f", &new_student->grade);
    
    printf("Student %s added successfully!\n", new_student->name);
}

// Function to display all students
void display_students(Student *students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

// Function to delete a student by ID
void delete_student(Student **students, int *count, int id) {
    int found = 0;
    for (int i = 0; i < *count; i++) {
        if ((*students)[i].id == id) {
            found = 1;
            for (int j = i; j < (*count) - 1; j++) {
                (*students)[j] = (*students)[j + 1];  // Shift students up
            }
            (*count)--;
            *students = realloc(*students, (*count) * sizeof(Student));
            if (*students == NULL && *count > 0) {
                fprintf(stderr, "Memory reallocation failed!\n");
                exit(EXIT_FAILURE);
            }
            printf("Student with ID %d deleted successfully!\n", id);
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

// Function to free the allocated memory
void free_memory(Student *students) {
    free(students);
}

int main() {
    Student *students = NULL;
    int count = 0;
    int choice, id;

    while (1) {
        printf("\n1. Add Student\n2. Display Students\n3. Delete Student\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student(&students, &count);
                break;
            case 2:
                display_students(students, count);
                break;
            case 3:
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                delete_student(&students, &count, id);
                break;
            case 4:
                free_memory(students);
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}