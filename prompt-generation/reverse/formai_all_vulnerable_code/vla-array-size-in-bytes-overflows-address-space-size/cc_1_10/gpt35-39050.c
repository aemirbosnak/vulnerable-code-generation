//FormAI DATASET v1.0 Category: Online Examination System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENTS 100
#define QUESTIONS 50

struct Student{
    char name[50];
    int rollno;
    int marks[QUESTIONS];
    float percentage;
};

void dispResult(struct Student std){
    printf("Name            : %s\n",std.name);
    printf("Roll No.        : %d\n",std.rollno);
    printf("Marks           : ");
    for(int i=0;i<QUESTIONS;i++){
        printf("%d ",std.marks[i]);
    }
    printf("\n");
    printf("Percentage      : %.2f\n",std.percentage);
}

void calcResult(struct Student *std){
    float sum=0;
    for(int i=0;i<QUESTIONS;i++){
        sum+=std->marks[i];
    }
    std->percentage = (sum/QUESTIONS);
}

int main(){   
    int num_students,num_questions;
    printf("Enter the number of students: ");
    scanf("%d",&num_students);
    printf("Enter the number of questions: ");
    scanf("%d",&num_questions);
    
    // Limiting number of students and questions
    num_students = (num_students>STUDENTS) ? STUDENTS : num_students;
    num_questions = (num_questions>QUESTIONS) ? QUESTIONS : num_questions;
    
    struct Student students[num_students];
    
    // Accepting student Names and Roll numbers
    for(int i=0;i<num_students;i++){
        printf("\nEnter the name of student %d: ",i+1);
        scanf("%s",students[i].name);
        printf("Enter the roll number of %s: ",students[i].name);
        scanf("%d",&students[i].rollno);    
    }
    
    // Accepting marks for each student
    for(int i=0;i<num_students;i++){
        printf("\n---------------------------------------\n");
        printf("Enter marks for %s\n",students[i].name);
        for(int j=0;j<num_questions;j++){
            printf("Question %d: ",j+1);
            scanf("%d",&students[i].marks[j]);
        }
        calcResult(&students[i]);
    }
    
    // Displaying the final result
    printf("\n---------------------------------------\n");
    printf("Final Result\n");
    for(int i=0;i<num_students;i++){
        printf("\nStudent %d\n",i+1);
        dispResult(students[i]);
    }
    
    return 0;
}