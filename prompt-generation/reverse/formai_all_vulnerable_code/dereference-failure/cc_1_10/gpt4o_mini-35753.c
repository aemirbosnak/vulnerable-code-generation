//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

// Define a structure to hold a student record
typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// Define a structure for the dynamic array of students
typedef struct {
    Student *students;
    int count;
    int capacity;
} StudentList;

// Function prototypes
StudentList* create_student_list(int capacity);
void add_student(StudentList *list, int id, const char *name, float grade);
void print_student_list(const StudentList *list);
void free_student_list(StudentList *list);
void visualize_student_grades(const StudentList *list);

// Main function
int main() {
    StudentList *studentList = create_student_list(MAX_SIZE);

    add_student(studentList, 1, "Alice", 85.5);
    add_student(studentList, 2, "Bob", 65.0);
    add_student(studentList, 3, "Charlie", 92.0);
    add_student(studentList, 4, "David", 75.0);
    add_student(studentList, 5, "Eve", 88.0);
    
    print_student_list(studentList);
    visualize_student_grades(studentList);

    free_student_list(studentList);
    return 0;
}

// Function to create a student list
StudentList* create_student_list(int capacity) {
    StudentList *list = malloc(sizeof(StudentList));
    list->capacity = capacity;
    list->count = 0;
    list->students = malloc(sizeof(Student) * capacity);
    return list;
}

// Function to add a student to the list
void add_student(StudentList *list, int id, const char *name, float grade) {
    if (list->count < list->capacity) {
        list->students[list->count].id = id;
        strcpy(list->students[list->count].name, name);
        list->students[list->count].grade = grade;
        list->count++;
    } else {
        printf("Student list is full. Unable to add student %s.\n", name);
    }
}

// Function to print the student list
void print_student_list(const StudentList *list) {
    printf("\nStudent List:\n");
    printf("ID\tName\t\tGrade\n");
    printf("--------------------------\n");
    for (int i = 0; i < list->count; i++) {
        printf("%d\t%s\t\t%.2f\n", list->students[i].id, list->students[i].name, list->students[i].grade);
    }
}

// Function to free the allocated memory for student list
void free_student_list(StudentList *list) {
    free(list->students);
    free(list);
}

// Function to visualize student grades using ASCII bars
void visualize_student_grades(const StudentList *list) {
    printf("\nVisualizing Student Grades:\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < list->count; i++) {
        int bar_length = (int)(list->students[i].grade / 100.0 * 50); // Scale to 50
        printf("%s: ", list->students[i].name);
        for (int j = 0; j < bar_length; j++) {
            printf("#");
        }
        printf(" (%.2f)\n", list->students[i].grade);
    }
}