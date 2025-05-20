//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CSV Reader example program */

/* Struct to hold student data */
typedef struct {
    char name[50];
    int age;
    float average;
} Student;

/* Function to read a line from a CSV file */
char * readLine(FILE * file) {
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, file)) != -1) {
        /* Remove newline character from line */
        line[strcspn(line, "\n")] = 0;
        return line;
    } else {
        return NULL;
    }
}

/* Function to parse a line from a CSV file */
Student * readStudent(char * line) {
    Student * student = malloc(sizeof(Student));

    char * token = strtok(line, ",");
    strcpy(student->name, token);

    token = strtok(NULL, ",");
    student->age = atoi(token);

    token = strtok(NULL, ",");
    student->average = atof(token);

    return student;
}

int main() {
    FILE * file = fopen("students.csv", "r");
    if (file == NULL) {
        printf("Error: Could not open file.");
        return 1;
    }

    char * line;
    Student * student;

    /* Read header line */
    line = readLine(file);

    /* Print header */
    printf("%-20s %-10s %s\n", "NAME", "AGE", "AVERAGE");

    /* Read and print student data until end of file */
    while ((line = readLine(file))) {
        student = readStudent(line);
        printf("%-20s %-10d %.2f\n", student->name, student->age, student->average);
        free(student);
    }

    /* Close file */
    fclose(file);

    return 0;
}