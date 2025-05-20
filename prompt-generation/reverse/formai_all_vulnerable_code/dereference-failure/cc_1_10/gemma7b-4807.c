//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Student
{
    char name[20];
    int rollno;
    float marks[MAX];
    struct Student* next;
} Student;

void insert(Student** head, char* name, int rollno, float marks[])
{
    Student* newNode = (Student*)malloc(sizeof(Student));
    strcpy(newNode->name, name);
    newNode->rollno = rollno;
    memcpy(newNode->marks, marks, MAX * sizeof(float));

    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        (*head)->next = newNode;
    }
}

void display(Student* head)
{
    while (head)
    {
        printf("Name: %s, Roll No: %d, Marks: ", head->name, head->rollno);
        for (int i = 0; i < MAX; i++)
        {
            printf("%f ", head->marks[i]);
        }
        printf("\n");
        head = head->next;
    }
}

int main()
{
    Student* head = NULL;

    insert(&head, "John Doe", 123, (float[]){90, 80, 70, 60, 50});
    insert(&head, "Jane Doe", 456, (float[]){80, 70, 60, 50, 40});
    insert(&head, "Peter Pan", 789, (float[]){70, 60, 50, 40, 30});

    display(head);

    return 0;
}