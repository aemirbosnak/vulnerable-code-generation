//GEMINI-pro DATASET v1.0 Category: File handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// A custom data structure to represent a student.
typedef struct Student {
    int id;
    char name[50];
    float gpa;
} Student;

// A function to read student data from a file.
int readStudentsFromFile(const char *filename, Student **students) {
    // Open the file for reading in binary mode.
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Get the number of students in the file.
    int numStudents;
    fread(&numStudents, sizeof(int), 1, fp);

    // Allocate memory for the array of students.
    *students = malloc(sizeof(Student) * numStudents);
    if (*students == NULL) {
        perror("Error allocating memory");
        fclose(fp);
        return -1;
    }

    // Read the students from the file.
    for (int i = 0; i < numStudents; i++) {
        fread(&(*students)[i], sizeof(Student), 1, fp);
    }

    // Close the file.
    fclose(fp);

    return numStudents;
}

// A function to write student data to a file.
int writeStudentsToFile(const char *filename, const Student *students, int numStudents) {
    // Open the file for writing in binary mode.
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write the number of students to the file.
    fwrite(&numStudents, sizeof(int), 1, fp);

    // Write the students to the file.
    for (int i = 0; i < numStudents; i++) {
        fwrite(&students[i], sizeof(Student), 1, fp);
    }

    // Close the file.
    fclose(fp);

    return 0;
}

// A function to print student data.
void printStudents(const Student *students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("GPA: %f\n", students[i].gpa);
        printf("\n");
    }
}

int main() {
    // Read student data from a file.
    Student *students;
    int numStudents = readStudentsFromFile("students.dat", &students);
    if (numStudents == -1) {
        return EXIT_FAILURE;
    }

    // Print the student data.
    printStudents(students, numStudents);

    // Write student data to a file.
    if (writeStudentsToFile("students.dat", students, numStudents) == -1) {
        return EXIT_FAILURE;
    }

    // Free the memory allocated for the array of students.
    free(students);

    return EXIT_SUCCESS;
}