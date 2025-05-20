//Gemma-7B DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Student
{
    char name[MAX_SIZE];
    int age;
    float height;
    int weight;
    struct Student *next;
} Student;

void insert(Student **head, char *name, int age, float height, int weight)
{
    Student *new_node = (Student *)malloc(sizeof(Student));
    strcpy(new_node->name, name);
    new_node->age = age;
    new_node->height = height;
    new_node->weight = weight;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        (*head)->next = new_node;
    }
}

void print_list(Student *head)
{
    while (head)
    {
        printf("%s, %d, %.2f, %d\n", head->name, head->age, head->height, head->weight);
        head = head->next;
    }
}

int main()
{
    Student *head = NULL;

    insert(&head, "John Doe", 20, 1.75, 80);
    insert(&head, "Jane Doe", 25, 1.60, 60);
    insert(&head, "Peter Pan", 12, 1.50, 40);

    print_list(head);

    return 0;
}