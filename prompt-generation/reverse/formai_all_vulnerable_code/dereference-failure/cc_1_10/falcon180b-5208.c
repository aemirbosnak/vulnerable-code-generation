//Falcon-180B DATASET v1.0 Category: Database querying ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define structure for student
struct student {
    int id;
    char name[50];
    float gpa;
};

// Function to read data from CSV file
void readData(struct student students[], FILE *fp) {
    int i = 0;
    while (!feof(fp)) {
        fscanf(fp, "%d,%s,%f\n", &students[i].id, students[i].name, &students[i].gpa);
        i++;
    }
}

// Function to write data to CSV file
void writeData(struct student students[], int numStudents, FILE *fp) {
    int i;
    for (i = 0; i < numStudents; i++) {
        fprintf(fp, "%d,%s,%f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

// Function to sort students by GPA
void sortStudents(struct student students[], int numStudents) {
    int i, j;
    struct student temp;
    for (i = 0; i < numStudents - 1; i++) {
        for (j = i + 1; j < numStudents; j++) {
            if (students[j].gpa > students[i].gpa) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

// Function to calculate average GPA
float calculateAverageGPA(struct student students[], int numStudents) {
    float sum = 0;
    int i;
    for (i = 0; i < numStudents; i++) {
        sum += students[i].gpa;
    }
    return sum / numStudents;
}

// Main function
int main() {
    FILE *fp;
    struct student students[100];
    int numStudents = 0;

    // Open CSV file for reading
    fp = fopen("students.csv", "r");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Read data from CSV file
    readData(students, fp);

    // Sort students by GPA
    sortStudents(students, numStudents);

    // Calculate average GPA
    float avgGPA = calculateAverageGPA(students, numStudents);

    // Print results
    printf("Number of students: %d\n", numStudents);
    printf("Average GPA: %.2f\n", avgGPA);

    // Open CSV file for writing
    fp = fopen("sorted_students.csv", "w");
    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    // Write sorted data to CSV file
    writeData(students, numStudents, fp);

    // Close CSV file
    fclose(fp);

    return 0;
}