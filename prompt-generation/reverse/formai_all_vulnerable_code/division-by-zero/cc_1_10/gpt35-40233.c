//FormAI DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student details
struct student {
    char name[50];
    int rollNo;
    int marks;
};

int main() {
    int numOfStudents, i, totalMarks = 0, averageMarks;
    
    // Prompt user to enter the number of students
    printf("Enter the number of students: ");
    scanf("%d", &numOfStudents);
    
    // Dynamically allocate array of student structures
    struct student *students = (struct student*) malloc(numOfStudents * sizeof(struct student));
    
    // Prompt user to enter student details
    for (i = 0; i < numOfStudents; i++) {
        printf("Enter student %d name: ", i+1);
        scanf("%s", students[i].name);
        
        printf("Enter student %d roll number: ", i+1);
        scanf("%d", &students[i].rollNo);
        
        printf("Enter student %d marks: ", i+1);
        scanf("%d", &students[i].marks);
        
        totalMarks += students[i].marks;
    }
    
    // Calculate average marks
    averageMarks = totalMarks / numOfStudents;
    
    // Print a table displaying the student details
    printf("\n\n-------------------------------------------------------\n");
    printf("|  Name                |  Roll No.   |  Marks           |\n");
    printf("-------------------------------------------------------\n");
    for (i = 0; i < numOfStudents; i++) {
        printf("|  %-20s|  %-10d|  %-15d|\n", students[i].name, students[i].rollNo, students[i].marks);
    }
    printf("-------------------------------------------------------\n\n");
    
    // Print the average marks
    printf("Average marks of all students: %d\n", averageMarks);
    
    // Deallocate memory
    free(students);
    
    return 0;
}