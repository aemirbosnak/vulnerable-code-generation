//GEMINI-pro DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
typedef struct student {
    int roll_no;
    char name[50];
    float marks;
} student;

// Function to read student data from a file
void read_students(char *filename, student *students, int *num_students) {
    FILE *fp;
    int i;

    // Open the file for reading
    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Read the number of students
    fscanf(fp, "%d", num_students);

    // Allocate memory for the students
    students = (student *)malloc(*num_students * sizeof(student));

    // Read the student data
    for (i = 0; i < *num_students; i++) {
        fscanf(fp, "%d %s %f", &students[i].roll_no, students[i].name, &students[i].marks);
    }

    // Close the file
    fclose(fp);
}

// Function to write student data to a file
void write_students(char *filename, student *students, int num_students) {
    FILE *fp;
    int i;

    // Open the file for writing
    fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    // Write the number of students
    fprintf(fp, "%d\n", num_students);

    // Write the student data
    for (i = 0; i < num_students; i++) {
        fprintf(fp, "%d %s %f\n", students[i].roll_no, students[i].name, students[i].marks);
    }

    // Close the file
    fclose(fp);
}

// Function to print student data
void print_students(student *students, int num_students) {
    int i;

    for (i = 0; i < num_students; i++) {
        printf("%d %s %f\n", students[i].roll_no, students[i].name, students[i].marks);
    }
}

// Main function
int main() {
    char filename[] = "students.txt";
    student *students;
    int num_students;

    // Read student data from the file
    read_students(filename, students, &num_students);

    // Print the student data
    print_students(students, num_students);

    // Write student data to the file
    write_students(filename, students, num_students);

    // Free the memory allocated for the students
    free(students);

    return 0;
}