//FormAI DATASET v1.0 Category: Online Examination System ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to hold student details
struct student{
    char name[100];
    int marks;
    char grade;
};

// Function to generate random numbers
int generateRandomNumber(){
    return rand()%100;
}

// Function to calculate grade
char calculateGrade(int marks){
    if(marks >= 90){
        return 'A';
    }
    else if(marks >= 80){
        return 'B';
    }
    else if(marks >= 70){
        return 'C';
    }
    else if(marks >= 60){
        return 'D';
    }
    else{
        return 'F';
    }
}

int main(){
    int numStudents, maxMarks;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    printf("Enter the maximum marks: ");
    scanf("%d", &maxMarks);
    // Array of structures
    struct student students[numStudents];
    // Loop through each student to store their details
    for(int i=0; i<numStudents; i++){
        printf("Enter the name of student %d: ", i+1);
        scanf("%s", students[i].name);
        students[i].marks = generateRandomNumber();
        students[i].grade = calculateGrade(students[i].marks);
    }
    // Print the details of all students
    printf("\n\nName\tMarks\tGrade\n");
    printf("=======================\n");
    for(int i=0; i<numStudents; i++){
        printf("%s\t%d\t%c\n", students[i].name, students[i].marks, students[i].grade);
    }
    return 0;
}