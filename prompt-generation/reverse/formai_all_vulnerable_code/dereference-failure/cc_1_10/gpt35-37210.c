//FormAI DATASET v1.0 Category: File handling ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
    char name[50];
    int age;
    float grade;
};

int main(){
    int n, i;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocating memory for array of student structures
    struct student *students = (struct student*) malloc(n * sizeof(struct student));

    // Creating a file pointer and opening a file in write mode
    FILE *fp = fopen("students.txt", "w");

    // Writing the data of 'n' students to the file
    for(i=0; i<n; i++){
        printf("\nEnter the name of student %d: ", i+1);
        scanf("%s", students[i].name);
        printf("Enter the age of student %d: ", i+1);
        scanf("%d", &students[i].age);
        printf("Enter the grade of student %d: ", i+1);
        scanf("%f", &students[i].grade);

        fprintf(fp, "%s %d %.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    fclose(fp);

    // Clearing the memory allocated for array of student structures
    free(students);

    // Creating a new array to read the data from file
    struct student *read_students = (struct student*) malloc(n * sizeof(struct student));

    // Opening the file in read mode
    fp = fopen("students.txt", "r");

    // Reading the data of 'n' students from the file
    for(i=0; i<n; i++){
        fscanf(fp, "%s %d %f\n", read_students[i].name, &read_students[i].age, &read_students[i].grade);
    }

    fclose(fp);

    // Displaying the data of 'n' students from the file
    printf("\nData of %d students from the file:\n", n);
    for(i=0; i<n; i++){
        printf("\nName: %s\n", read_students[i].name);
        printf("Age: %d\n", read_students[i].age);
        printf("Grade: %.2f\n", read_students[i].grade);
    }

    // Clearing the memory allocated for array of read student structures
    free(read_students);

    return 0;
}