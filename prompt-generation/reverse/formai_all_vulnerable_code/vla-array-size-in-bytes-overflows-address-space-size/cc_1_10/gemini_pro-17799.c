//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Structure to store student information
struct student {
    int id;
    char name[50];
    int marks[5];
    float average;
};

// Function to read student information from a file
void readStudents(struct student students[], int numStudents) {
    FILE *fp;
    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }
    for (int i = 0; i < numStudents; i++) {
        fscanf(fp, "%d %s", &students[i].id, students[i].name);
        for (int j = 0; j < 5; j++) {
            fscanf(fp, "%d", &students[i].marks[j]);
        }
    }
    fclose(fp);
}

// Function to calculate the average marks of a student
void calculateAverage(struct student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        float sum = 0;
        for (int j = 0; j < 5; j++) {
            sum += students[i].marks[j];
        }
        students[i].average = sum / 5;
    }
}

// Function to print the student information
void printStudents(struct student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printf("Student ID: %d\n", students[i].id);
        printf("Student Name: %s\n", students[i].name);
        printf("Marks: ");
        for (int j = 0; j < 5; j++) {
            printf("%d ", students[i].marks[j]);
        }
        printf("\nAverage: %.2f\n", students[i].average);
        printf("\n");
    }
}

int main() {
    int numStudents;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    struct student students[numStudents];

    readStudents(students, numStudents);
    calculateAverage(students, numStudents);
    printStudents(students, numStudents);

    return 0;
}