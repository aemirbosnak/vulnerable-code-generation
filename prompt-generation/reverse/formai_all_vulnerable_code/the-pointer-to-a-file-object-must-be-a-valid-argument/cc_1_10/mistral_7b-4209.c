//MISTRAL-7B DATASET v1.0 Category: Database simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

// Define some structures and constants
typedef struct {
    char name[20];
    int age;
    float gpa;
} Student;

#define MAX_STUDENTS 100

// Function prototypes
void readFile(const char *filename, Student students[]);
void printStudents(Student students[], int numStudents);

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Allocate memory for students array
    Student students[MAX_STUDENTS];

    // Read data from file into students array
    readFile(argv[1], students);

    // Print out the contents of the students array
    printf("--- STUDENTS ---\n");
    printStudents(students, MAX_STUDENTS);

    // Free memory allocated for students array
    free(students);

    return 0;
}

// Function to read data from file into students array
void readFile(const char *filename, Student students[]) {
    int fd = open(filename, O_RDONLY);
    int numStudents = 0;

    // Read each line of the file and parse it into a Student struct
    char line[100];
    while (fgets(line, sizeof(line), fd) != NULL) {
        sscanf(line, "%s %d %f", students[numStudents].name, &students[numStudents].age, &students[numStudents].gpa);
        numStudents++;
    }

    // Close the file
    close(fd);
}

// Function to print out the contents of the students array
void printStudents(Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("%s (%d years old, GPA: %.2f)\n", students[i].name, students[i].age, students[i].gpa);
    }
}