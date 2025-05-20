//FormAI DATASET v1.0 Category: Database simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold student information
struct student {
    int id;
    char name[50];
    float gpa;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct student* students = malloc(sizeof(struct student) * n);

    // Populate student information
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d\n", i+1);
        printf("Enter ID: ");
        scanf("%d", &(students[i].id));
        printf("Enter name: ");
        scanf("%s", students[i].name);
        printf("Enter GPA: ");
        scanf("%f", &(students[i].gpa));
    }

    // Write student information to file
    FILE* f = fopen("students.txt", "w");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %s %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }

    fclose(f);

    // Read student information from file
    f = fopen("students.txt", "r");
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    struct student* students_read = malloc(sizeof(struct student) * n);

    int id;
    char name[50];
    float gpa;

    for (int i = 0; i < n; i++) {
        fscanf(f, "%d %s %f\n", &id, name, &gpa);
        students_read[i].id = id;
        strcpy(students_read[i].name, name);
        students_read[i].gpa = gpa;
    }

    fclose(f);

    // Print student information
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Student %d\n", i+1);
        printf("ID: %d\n", students_read[i].id);
        printf("Name: %s\n", students_read[i].name);
        printf("GPA: %.2f\n", students_read[i].gpa);
        printf("\n");
    }

    // Free allocated memory
    free(students);
    free(students_read);

    return 0;
}