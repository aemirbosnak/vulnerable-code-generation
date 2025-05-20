//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_CAPACITY 2
#define NAME_SIZE 50

typedef struct {
    char name[NAME_SIZE];
    int age;
    float gpa;
} Student;

typedef struct {
    Student *students;
    int size;
    int capacity;
} StudentList;

// Function prototypes
StudentList* create_student_list();
void add_student(StudentList *list, const char *name, int age, float gpa);
void resize_student_list(StudentList *list);
void print_students(const StudentList *list);
void free_student_list(StudentList *list);

// Main function
int main() {
    StudentList *list = create_student_list();
    if (list == NULL) {
        fprintf(stderr, "Failed to create student list\n");
        return EXIT_FAILURE;
    }

    add_student(list, "Alice", 20, 3.5);
    add_student(list, "Bob", 21, 3.7);
    add_student(list, "Charlie", 22, 3.9);
    print_students(list);
    
    free_student_list(list);
    return EXIT_SUCCESS;
}

// Function to create a new student list
StudentList* create_student_list() {
    StudentList *list = (StudentList*)malloc(sizeof(StudentList));
    if (list == NULL) {
        return NULL; // Memory allocation failed
    }
    list->students = (Student*)malloc(INITIAL_CAPACITY * sizeof(Student));
    if (list->students == NULL) {
        free(list);
        return NULL; // Memory allocation failed
    }
    list->size = 0;
    list->capacity = INITIAL_CAPACITY;
    return list;
}

// Function to add a student to the list
void add_student(StudentList *list, const char *name, int age, float gpa) {
    if (list->size >= list->capacity) {
        resize_student_list(list);
    }
    Student *student = &list->students[list->size++];
    strncpy(student->name, name, NAME_SIZE);
    student->age = age;
    student->gpa = gpa;
}

// Function to resize the student list when necessary
void resize_student_list(StudentList *list) {
    list->capacity *= 2; // Double the capacity
    list->students = (Student*)realloc(list->students, list->capacity * sizeof(Student));
    if (list->students == NULL) {
        fprintf(stderr, "Memory allocation failed during resizing.\n");
        exit(EXIT_FAILURE); // Exit if reallocation fails
    }
}

// Function to print all students in the list
void print_students(const StudentList *list) {
    printf("Student List:\n");
    printf("Name\tAge\tGPA\n");
    for (int i = 0; i < list->size; i++) {
        printf("%s\t%d\t%.2f\n", list->students[i].name, list->students[i].age, list->students[i].gpa);
    }
}

// Function to free the student list and all allocated memory
void free_student_list(StudentList *list) {
    if (list) {
        free(list->students);
        free(list);
    }
}