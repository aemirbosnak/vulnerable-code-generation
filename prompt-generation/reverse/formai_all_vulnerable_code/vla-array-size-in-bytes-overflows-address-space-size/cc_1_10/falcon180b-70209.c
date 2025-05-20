//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

struct student
{
    char name[MAX];
    int rollno;
    int marks[5];
};

void addstudent(struct student *s, int count)
{
    printf("\nEnter name of student %d: ", count+1);
    scanf("%s", s->name);
    printf("Enter roll no of student %d: ", count+1);
    scanf("%d", &s->rollno);
    for(int i=0;i<5;i++)
    {
        printf("Enter marks of subject %d for student %d: ", i+1, count+1);
        scanf("%d", &s->marks[i]);
    }
}

void displaystudent(struct student s)
{
    printf("\nName: %s", s.name);
    printf("\nRoll No: %d", s.rollno);
    printf("\nMarks:\n");
    for(int i=0;i<5;i++)
    {
        printf("%d\t", s.marks[i]);
    }
}

void main()
{
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct student s[n];
    for(int i=0;i<n;i++)
    {
        addstudent(&s[i], i);
    }
    printf("\nStudents:\n");
    for(int i=0;i<n;i++)
    {
        displaystudent(s[i]);
        printf("\n");
    }
}