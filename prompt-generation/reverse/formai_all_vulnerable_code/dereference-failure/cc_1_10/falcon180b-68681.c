//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1000

typedef struct {
    char *name;
    int age;
    float gpa;
} Student;

void read_csv_file(FILE *file, Student **students, int *num_students) {
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            printf("Error: Invalid line format.\n");
            exit(1);
        }
        Student *new_student = malloc(sizeof(Student));
        new_student->name = strdup(token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Invalid line format.\n");
            exit(1);
        }
        new_student->age = atoi(token);
        token = strtok(NULL, ",");
        if (token == NULL) {
            printf("Error: Invalid line format.\n");
            exit(1);
        }
        new_student->gpa = atof(token);
        *num_students += 1;
        *students = realloc(*students, sizeof(Student) * (*num_students));
        (*students)[(*num_students) - 1] = *new_student;
        free(new_student);
    }
}

void print_students(Student *students, int num_students) {
    for (int i = 0; i < num_students; i++) {
        printf("%s is %d years old and has a GPA of %.2f.\n", students[i].name, students[i].age, students[i].gpa);
    }
}

int main() {
    FILE *file = fopen("students.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }
    Student *students = NULL;
    int num_students = 0;
    read_csv_file(file, &students, &num_students);
    fclose(file);
    printf("There are %d students:\n", num_students);
    print_students(students, num_students);
    for (int i = 0; i < num_students; i++) {
        free(students[i].name);
    }
    free(students);
    return 0;
}