//FormAI DATASET v1.0 Category: File handling ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int roll;
    float marks;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocating memory for array of struct students
    struct student *students = malloc(n * sizeof(struct student));

    // Getting student details from user
    for (int i = 0; i < n; i++) {
        printf("Enter details for student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Roll number: ");
        scanf("%d", &students[i].roll);
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Creating file pointer and opening file in write mode
    FILE *fptr = fopen("student.txt", "w");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    // Writing student details to file
    for (int i = 0; i < n; i++) {
        fprintf(fptr, "%s,%d,%.2f\n", students[i].name, students[i].roll, students[i].marks);
    }

    printf("Successfully wrote student details to file.\n");

    // Closing file and freeing dynamically allocated memory
    fclose(fptr);
    free(students);

    // Opening file in read mode and printing student details
    fptr = fopen("student.txt", "r");

    if (fptr == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    printf("\nStudent details:\n");
    char line[100];
    while (fgets(line, 100, fptr)) {
        printf("%s", line);
    }

    // Closing file
    fclose(fptr);

    return 0;
}