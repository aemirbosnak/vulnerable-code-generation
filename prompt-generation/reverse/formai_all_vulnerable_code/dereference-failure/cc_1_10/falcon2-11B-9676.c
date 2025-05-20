//Falcon2-11B DATASET v1.0 Category: Pattern printing ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
int main()
{
    //Create a structure named student
    struct student
    {
        int rollno;
        char name[20];
        float marks;
    };

    //Create an array of 20 student structures
    struct student s[20];

    //Declare a pointer to student structure
    struct student *p;

    //Create 20 student structures
    for(int i=0;i<20;i++)
    {
        //Assign values to each structure
        p=(struct student *)malloc(sizeof(struct student));
        p->rollno=i+1;
        p->name[i]=p->name[i+1]=0;
        printf("Enter the name of the student %d: ",i+1);
        scanf("%s",p->name);
        printf("Enter the marks of the student %d: ",i+1);
        scanf("%f",&p->marks);

        //Display the structure
        printf("\nStudent %d:",i+1);
        printf("Roll No: %d",p->rollno);
        printf("Name: %s",p->name);
        printf("Marks: %f",p->marks);

        //Display the structure
        printf("\nStudent %d:",i+1);
        printf("Roll No: %d",p->rollno);
        printf("Name: %s",p->name);
        printf("Marks: %f",p->marks);
    }

    //Free the memory allocated
    for(int i=0;i<20;i++)
        free(p);

    //Return 0 on successful execution
    return 0;
}