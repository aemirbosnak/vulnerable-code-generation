//FormAI DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
    char name[30];
    int rollno;
    float marks;
};
void search(struct student s[], int n)
{
    int rno, found=0, i;
    printf("Enter Roll Number to Search: ");
    scanf("%d", &rno);
    for(i=0; i<n; i++)
    {
        if(s[i].rollno==rno)
        {
            printf("\nRecord Found!\nName: %s\nRoll No: %d\nMarks: %.2f\n", s[i].name, s[i].rollno, s[i].marks);
            found=1;
            break;
        }
    }
    if(found==0)
        printf("\nRecord Not Found!\n");
}
void display(struct student s[], int n)
{
    int i;
    printf("\nStudent Records:\n");
    for(i=0; i<n; i++)
    {
        printf("Name: %s\nRoll No: %d\nMarks: %.2f\n", s[i].name, s[i].rollno, s[i].marks);
        printf("\n");
    }
}
void sort(struct student s[], int n)
{
    int i, j;
    struct student temp;
    for(i=0; i<n-1; i++)
    {
        for(j=0; j<n-i-1; j++)
        {
            if(s[j].rollno>s[j+1].rollno)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n, i, choice;
    printf("Enter Number of Students: ");
    scanf("%d", &n);
    struct student s[n];
    for(i=0; i<n; i++)
    {
        printf("\nEnter Details of Student %d:\n", i+1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll No: ");
        scanf("%d", &s[i].rollno);
        printf("Marks: ");
        scanf("%f", &s[i].marks);
    }
    printf("\nMenu:\n1. Search Record\n2. Display Records\n3. Sort Records\n4. Exit\nEnter your Choice: ");
    scanf("%d", &choice);
    while(choice!=4)
    {
        switch(choice)
        {
            case 1: search(s, n);
                    break;
            case 2: display(s, n);
                    break;
            case 3: sort(s, n);
                    printf("\nRecords Sorted!\n");
                    break;
            default: printf("\nInvalid Choice!\n");
        }
        printf("\nMenu:\n1. Search Record\n2. Display Records\n3. Sort Records\n4. Exit\nEnter your Choice: ");
        scanf("%d", &choice);
    }
    printf("\nProgram Terminated!\n");
    return 0;
}