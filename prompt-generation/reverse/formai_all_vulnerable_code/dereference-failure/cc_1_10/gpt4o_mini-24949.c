//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float grade;
} Student;

typedef struct {
    Student* students;
    size_t count;
    size_t capacity;
} StudentList;

StudentList* create_student_list(size_t initial_capacity) {
    StudentList* list = malloc(sizeof(StudentList));
    if (!list) {
        fprintf(stderr, "Error allocating memory for student list\n");
        exit(EXIT_FAILURE);
    }

    list->students = malloc(sizeof(Student) * initial_capacity);
    if (!list->students) {
        fprintf(stderr, "Error allocating memory for students\n");
        free(list);
        exit(EXIT_FAILURE);
    }

    list->count = 0;
    list->capacity = initial_capacity;
    return list;
}

void free_student_list(StudentList* list) {
    if (list) {
        free(list->students);
        free(list);
    }
}

void add_student(StudentList* list, int id, const char* name, float grade) {
    if (list->count >= list->capacity) {
        list->capacity *= 2;
        Student* new_students = realloc(list->students, sizeof(Student) * list->capacity);
        if (!new_students) {
            fprintf(stderr, "Error reallocating memory for students\n");
            free_student_list(list);
            exit(EXIT_FAILURE);
        }
        list->students = new_students;
    }

    list->students[list->count].id = id;
    strncpy(list->students[list->count].name, name, NAME_LENGTH);
    list->students[list->count].grade = grade;
    list->count++;
}

void print_students(const StudentList* list) {
    printf("ID\tName\t\tGrade\n");
    printf("-----------------------------\n");
    for (size_t i = 0; i < list->count; i++) {
        printf("%d\t%s\t%.2f\n", list->students[i].id, list->students[i].name, list->students[i].grade);
    }
}

float calculate_average_grade(const StudentList* list) {
    if (list->count == 0) return 0.0;

    float total = 0.0;
    for (size_t i = 0; i < list->count; i++) {
        total += list->students[i].grade;
    }
    return total / list->count;
}

int main() {
    StudentList* student_list = create_student_list(2);

    add_student(student_list, 1, "Alice", 85.5);
    add_student(student_list, 2, "Bob", 91.0);
    add_student(student_list, 3, "Charlie", 78.0);

    print_students(student_list);

    float average = calculate_average_grade(student_list);
    printf("\nAverage Grade: %.2f\n", average);

    free_student_list(student_list);
    return 0;
}