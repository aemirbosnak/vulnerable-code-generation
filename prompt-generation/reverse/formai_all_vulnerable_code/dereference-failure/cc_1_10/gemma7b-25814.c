//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

struct Question {
  char question[256];
  char answer[256];
  int marks;
  struct Question* next;
};

struct Student {
  char name[256];
  int rollNo;
  int marks;
  struct Student* next;
};

void createQuestion(struct Question** head) {
  struct Question* newQuestion = (struct Question*)malloc(sizeof(struct Question));
  scanf("Enter question: ", newQuestion->question);
  scanf("Enter answer: ", newQuestion->answer);
  scanf("Enter marks: ", &newQuestion->marks);
  newQuestion->next = *head;
  *head = newQuestion;
}

void createStudent(struct Student** head) {
  struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
  scanf("Enter name: ", newStudent->name);
  scanf("Enter roll no: ", &newStudent->rollNo);
  scanf("Enter marks: ", &newStudent->marks);
  newStudent->next = *head;
  *head = newStudent;
}

int main() {
  struct Question* questions = NULL;
  struct Student* students = NULL;

  createQuestion(&questions);
  createStudent(&students);

  // Examination process
  for (struct Student* student = students; student; student = student->next) {
    for (struct Question* question = questions; question; question = question->next) {
      // Check if student has answered the question
      if (student->marks >= question->marks) {
        printf("Student %s has answered question %s\n", student->name, question->question);
      }
    }
  }

  return 0;
}