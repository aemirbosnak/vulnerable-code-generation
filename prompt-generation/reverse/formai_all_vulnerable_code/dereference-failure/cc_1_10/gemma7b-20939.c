//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a question
typedef struct Question {
  char question[256];
  int marks;
  struct Question* next;
} Question;

// Function to create a new question
Question* createQuestion(char* question, int marks) {
  Question* newQuestion = (Question*)malloc(sizeof(Question));
  strcpy(newQuestion->question, question);
  newQuestion->marks = marks;
  newQuestion->next = NULL;
  return newQuestion;
}

// Function to add a new question to the end of a list
void addQuestion(Question** head, char* question, int marks) {
  Question* newQuestion = createQuestion(question, marks);
  if (*head == NULL) {
    *head = newQuestion;
  } else {
    ((*head)->next = newQuestion);
    *head = newQuestion;
  }
}

// Function to take an exam
void takeExam(Question* head) {
  int marks = 0;
  while (head) {
    printf("%s", head->question);
    int answer = getchar();
    if (answer == head->marks) {
      marks++;
    }
    head = head->next;
  }
  printf("Your total marks are: %d", marks);
}

int main() {
  Question* head = NULL;
  addQuestion(&head, "What is the meaning of the word 'entrepreneur'?", 5);
  addQuestion(&head, "Who invented the telephone?", 3);
  addQuestion(&head, "What is the capital of France?", 4);

  takeExam(head);

  return 0;
}