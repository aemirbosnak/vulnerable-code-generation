//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

typedef struct Student {
  char name[20];
  int rollno;
  float marks;
  struct Student* next;
} Student;

Student* insertAtTail(Student* head)
{
  Student* newNode = (Student*)malloc(sizeof(Student));
  scanf("Enter student name: ", newNode->name);
  scanf("Enter student roll no: ", &newNode->rollno);
  scanf("Enter student marks: ", &newNode->marks);

  if (head == NULL)
  {
    head = newNode;
  }
  else
  {
    head->next = newNode;
  }

  return head;
}

void printStudents(Student* head)
{
  Student* current = head;

  while (current)
  {
    printf("Name: %s\n", current->name);
    printf("Roll No: %d\n", current->rollno);
    printf("Marks: %.2f\n", current->marks);
    printf("\n");
    current = current->next;
  }
}

int main()
{
  Student* head = NULL;

  while (1)
  {
    char choice;

    printf("Enter choice: (i) insert, (p) print, (q) quit\n");
    scanf(" ", &choice);

    switch (choice)
    {
      case 'i':
        head = insertAtTail(head);
        break;
      case 'p':
        printStudents(head);
        break;
      case 'q':
        exit(0);
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}