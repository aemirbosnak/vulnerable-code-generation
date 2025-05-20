//FormAI DATASET v1.0 Category: Data mining ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to represent a student
struct student {
    char name[20];
    int age;
    float gpa;
};

// Function to read in data from a file and store it in an array of students
void read_data(char* filename, struct student* students, int num_students) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    char line[100];
    int i = 0;

    while (fgets(line, 100, file) != NULL && i < num_students) {
        // Split up the line into its components
        char* token = strtok(line, ",");
        strcpy(students[i].name, token);

        token = strtok(NULL, ",");
        students[i].age = atoi(token);

        token = strtok(NULL, ",");
        students[i].gpa = atof(token);

        i++;
    }

    fclose(file);
}

// Function to compute average GPA of all students
float average_gpa(struct student* students, int num_students) {
    float total_gpa = 0;

    for (int i = 0; i < num_students; i++) {
        total_gpa += students[i].gpa;
    }

    return total_gpa / num_students;
}

int main() {
    int num_students = 5;

    // Allocate memory for array of students
    struct student* students = (struct student*)malloc(num_students * sizeof(struct student));

    read_data("students.csv", students, num_students);

    printf("Average GPA: %.2f", average_gpa(students, num_students));

    // Free memory used by array of students
    free(students);

    return 0;
}