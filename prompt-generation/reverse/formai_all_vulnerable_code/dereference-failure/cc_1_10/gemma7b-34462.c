//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

struct Question {
  char question[256];
  int answer;
  struct Question* next;
};

struct Student {
  char name[256];
  int score;
  struct Student* next;
};

void insertQuestion(struct Question** head, char* question, int answer) {
  struct Question* newQuestion = malloc(sizeof(struct Question));
  strcpy(newQuestion->question, question);
  newQuestion->answer = answer;
  newQuestion->next = NULL;

  if (*head == NULL) {
    *head = newQuestion;
  } else {
    (*head)->next = newQuestion;
  }
}

void insertStudent(struct Student** head, char* name, int score) {
  struct Student* newStudent = malloc(sizeof(struct Student));
  strcpy(newStudent->name, name);
  newStudent->score = score;
  newStudent->next = NULL;

  if (*head == NULL) {
    *head = newStudent;
  } else {
    (*head)->next = newStudent;
  }
}

void takeExam(struct Student* student, struct Question** questions) {
  int i = 0;
  for (struct Question* question = *questions; question; question = question->next) {
    printf("%s\n", question->question);
    int answer = getchar();
    if (answer == question->answer) {
      student->score++;
    }
    i++;
  }
}

int main() {
  struct Question* questions = NULL;
  insertQuestion(&questions, "What is the meaning of life?", 4);
  insertQuestion(&questions, "Who invented the telephone?", 2);
  insertQuestion(&questions, "What is the capital of France?", 1);

  struct Student* student = NULL;
  insertStudent(&student, "John Doe", 0);
  insertStudent(&student, "Jane Doe", 0);

  takeExam(student, &questions);

  printf("Your score is: %d\n", student->score);

  return 0;
}