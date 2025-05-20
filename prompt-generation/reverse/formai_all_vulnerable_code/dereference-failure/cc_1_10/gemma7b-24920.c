//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

typedef struct Student {
  char name[50];
  int rollno;
  float marks[MAX];
  struct Student *next;
} Student;

Student *insertAtTail(Student *head, char *name, int rollno, float marks[]) {
  Student *newNode = (Student *)malloc(sizeof(Student));
  strcpy(newNode->name, name);
  newNode->rollno = rollno;
  memcpy(newNode->marks, marks, MAX * sizeof(float));

  if (head == NULL) {
    head = newNode;
  } else {
    head->next = newNode;
  }

  return head;
}

void displayMarks(Student *head) {
  Student *curr = head;
  while (curr) {
    printf("Name: %s, Roll No: %d\n", curr->name, curr->rollno);
    for (int i = 0; i < MAX; i++) {
      printf("Marks: %.2f ", curr->marks[i]);
    }
    printf("\n");
    curr = curr->next;
  }
}

int main() {
  Student *head = NULL;

  insertAtTail(head, "John Doe", 123, (float[]){85, 90, 80});
  insertAtTail(head, "Jane Doe", 456, (float[]){95, 85, 90});
  insertAtTail(head, "Peter Pan", 789, (float[]){80, 90, 85});

  displayMarks(head);

  return 0;
}