//Falcon-180B DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_NUM_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
} Student;

int main() {
    int numStudents = 0;
    Student *students = NULL;

    // Allocate memory for students
    students = (Student *) malloc(MAX_NUM_STUDENTS * sizeof(Student));
    if (students == NULL) {
        printf("Error: Failed to allocate memory for students.\n");
        return 1;
    }

    // Read students from file
    FILE *fp = fopen("students.txt", "r");
    if (fp == NULL) {
        printf("Error: Failed to open students.txt file.\n");
        return 1;
    }

    char line[MAX_NAME_LENGTH + 10]; // +10 for age and newline character
    while (fgets(line, sizeof(line), fp)!= NULL) {
        numStudents++;
        if (numStudents >= MAX_NUM_STUDENTS) {
            printf("Error: Too many students in file.\n");
            return 1;
        }
        strtok(line, " ");
        strcpy(students[numStudents-1].name, line);
        students[numStudents-1].age = atoi(strtok(NULL, " "));
    }

    fclose(fp);

    // Sort students by age
    for (int i = 0; i < numStudents - 1; i++) {
        for (int j = i + 1; j < numStudents; j++) {
            if (students[i].age > students[j].age) {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    // Print students
    printf("Students:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%s %d\n", students[i].name, students[i].age);
    }

    // Free memory
    free(students);

    return 0;
}