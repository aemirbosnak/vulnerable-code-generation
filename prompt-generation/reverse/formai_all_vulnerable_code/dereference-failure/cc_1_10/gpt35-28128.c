//FormAI DATASET v1.0 Category: Online Examination System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char name[30];
    char course[50];
    int score;
} Student;

int main()
{
    int numStudents = 0;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);

    Student *students = (Student *)malloc(numStudents * sizeof(Student));
    int i, j;

    for (i = 0; i < numStudents; i++)
    {
        printf("\nEnter details of Student %d\n", i + 1);
        printf("ID: ");
        scanf("%d", &(students[i].id));
        printf("Name: ");
        scanf("%s", students[i].name);
        printf("Course: ");
        scanf("%s", students[i].course);
        printf("Score: ");
        scanf("%d", &(students[i].score));
    }

    printf("\nStudent Details\n");
    printf("ID  |  Name  |  Course  |  Score  \n");
    printf("---------------------------------\n");
    for (i = 0; i < numStudents; i++)
    {
        printf("%d  |  %s  |  %s  |  %d\n", students[i].id, students[i].name, students[i].course, students[i].score);
    }

    int maxScore = students[0].score;
    for (i = 1; i < numStudents; i++)
    {
        if (students[i].score > maxScore)
        {
            maxScore = students[i].score;
        }
    }
    printf("Highest Score: %d\n", maxScore);

    printf("\nStudents who scored highest marks\n");
    printf("ID  |  Name  |  Course  |  Score  \n");
    printf("---------------------------------\n");
    for (i = 0; i < numStudents; i++)
    {
        if (students[i].score == maxScore)
        {
            printf("%d  |  %s  |  %s  |  %d\n", students[i].id, students[i].name, students[i].course, students[i].score);
        }
    }

    free(students);
    return 0;
}