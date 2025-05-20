//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_GRADE_LENGTH 5

/* Define a structure to represent student data */
typedef struct {
    char name[MAX_NAME_LENGTH];
    int grade;
} Student;

/* Read in student data from a CSV file */
void readCSV(char *filename, Student *students, int *num_students) {
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;

    file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    /* Read in each line of the file and split into name and grade */
    while ((read = getline(&line, &len, file)) != -1) {
        char *token;
        token = strtok(line, ",");
        strcpy(students[i].name, token);
        token = strtok(NULL, ",");
        students[i].grade = atoi(token);
        i++;
    }

    *num_students = i;
    printf("Successfully read in %d students from file '%s'\n", *num_students, filename);

    fclose(file);
    if (line) {
        free(line);
    }
}

/* Print out all student data */
void printStudents(Student *students, int num_students) {
    printf("\n-------------\n");
    for (int i = 0; i < num_students; i++) {
        printf("Name: %s\nGrade: %d\n", students[i].name, students[i].grade);
    }
}

int main() {
    /* Allocate memory for maximum number of students */
    Student *students = (Student*) malloc(sizeof(Student) * 100);
    int num_students = 0;

    /* Read in student data */
    readCSV("students.csv", students, &num_students);

    /* Print out all student data */
    printStudents(students, num_students);

    /* Free dynamically allocated memory */
    free(students);

    return 0;
}