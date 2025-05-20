//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

void readFile(const char *filename, Student **students, int *numStudents) {
    FILE *file = fopen(filename, "r");
    char line[100];
    int i = 0;

    if (!file) {
        perror("Error opening file");
        return;
    }

    *students = malloc(*numStudents * sizeof(Student));

    while (fgets(line, sizeof(line), file)) {
        sscanf(line, "%s%d%f", (*students + i)->name, &((*students + i)->age), &((*students + i)->gpa));
        i++;
        *numStudents = i + 1;
        if (*numStudents > 100) {
            printf("Error: Too many students in file\n");
            free(*students);
            fclose(file);
            return;
        }
    }

    fclose(file);
}

void writeFile(const char *filename, Student *students, int numStudents) {
    FILE *file = fopen(filename, "w");

    if (!file) {
        perror("Error opening file for writing");
        return;
    }

    for (int i = 0; i < numStudents; i++) {
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }

    fclose(file);
}

void displayStudents(Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Name: %s, Age: %d, GPA: %.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
}

int main() {
    const char *filename = "students.txt";
    Student *students;
    int numStudents;

    readFile(filename, &students, &numStudents);
    displayStudents(students, numStudents);

    writeFile(filename, students, numStudents);

    free(students);

    return 0;
}