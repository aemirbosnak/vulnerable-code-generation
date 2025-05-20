//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

typedef struct {
    Student *students;
    int size;
    int capacity;
} StudentList;

void initStudentList(StudentList *list, int capacity) {
    list->size = 0;
    list->capacity = capacity;
    list->students = (Student *)malloc(sizeof(Student) * capacity);
}

void freeStudentList(StudentList *list) {
    free(list->students);
}

void addStudent(StudentList *list, int id, const char *name, float grade) {
    if (list->size < list->capacity) {
        list->students[list->size].id = id;
        strcpy(list->students[list->size].name, name);
        list->students[list->size].grade = grade;
        list->size++;
    } else {
        printf("Error: Student list is full!\n");
    }
}

void displayStudents(const StudentList *list) {
    printf("\nStudent List:\n");
    printf("ID\tName\t\tGrade\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < list->size; i++) {
        printf("%d\t%-15s %.2f\n", list->students[i].id, list->students[i].name, list->students[i].grade);
    }
    printf("-------------------------------------\n");
}

void sortStudents(StudentList *list) {
    for (int i = 0; i < list->size - 1; i++) {
        for (int j = 0; j < list->size - i - 1; j++) {
            if (list->students[j].grade < list->students[j + 1].grade) {
                Student temp = list->students[j];
                list->students[j] = list->students[j + 1];
                list->students[j + 1] = temp;
            }
        }
    }
}

void searchStudentById(const StudentList *list, int id) {
    for (int i = 0; i < list->size; i++) {
        if (list->students[i].id == id) {
            printf("Student found: ID: %d, Name: %s, Grade: %.2f\n", list->students[i].id, list->students[i].name, list->students[i].grade);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

int main() {
    StudentList studentList;
    initStudentList(&studentList, MAX_STUDENTS);

    addStudent(&studentList, 1, "Alice", 88.5);
    addStudent(&studentList, 2, "Bob", 91.0);
    addStudent(&studentList, 3, "Charlie", 85.0);
    addStudent(&studentList, 4, "Dana", 95.5);
    addStudent(&studentList, 5, "Eve", 78.0);

    displayStudents(&studentList);

    printf("Sorting students by grade...\n");
    sortStudents(&studentList);
    displayStudents(&studentList);

    int searchId = 3;
    printf("Searching for student with ID %d...\n", searchId);
    searchStudentById(&studentList, searchId);

    freeStudentList(&studentList);
    return 0;
}