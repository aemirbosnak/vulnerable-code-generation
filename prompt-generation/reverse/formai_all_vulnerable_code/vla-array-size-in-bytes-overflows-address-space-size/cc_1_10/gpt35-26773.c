//FormAI DATASET v1.0 Category: File handling ; Style: relaxed
#include <stdio.h>

// Define a structure to represent a student
struct student {
    char name[50];
    int roll_number;
    float marks;
};

int main() {
    int n, i;

    // Ask the user how many students they want to add
    printf("How many students do you want to add?\n");
    scanf("%d", &n);

    // Create an array of structures to store students
    struct student students[n];

    // Ask the user to input details for each student
    for (i = 0; i < n; i++) {
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", students[i].name);
        printf("Enter the roll number of student %d: ", i+1);
        scanf("%d", &students[i].roll_number);
        printf("Enter the marks of student %d: ", i+1);
        scanf("%f", &students[i].marks);
    }

    // Create a file for storing the student details
    FILE *file = fopen("students.txt", "w");

    // Write the student details to the file
    for (i = 0; i < n; i++) {
        fprintf(file, "Name: %s\n", students[i].name);
        fprintf(file, "Roll Number: %d\n", students[i].roll_number);
        fprintf(file, "Marks: %f\n", students[i].marks);
        fprintf(file, "\n");
    }

    // Close the file
    fclose(file);

    // Open the file again and read the contents
    file = fopen("students.txt", "r");

    // Print the student details from the file
    printf("\nStudent details stored in file:\n\n");
    while (!feof(file)) {
        char c = fgetc(file);
        printf("%c", c);
    }

    // Close the file again
    fclose(file);

    return 0;
}