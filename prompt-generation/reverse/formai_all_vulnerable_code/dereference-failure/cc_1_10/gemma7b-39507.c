//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10

struct Question {
  char question[255];
  char answer[255];
  int marks;
  struct Question* next;
};

struct Student {
  char name[255];
  int rollno;
  struct Student* next;
  struct AnswerSheet* answerSheet;
};

struct AnswerSheet {
  struct AnswerSheet* next;
  struct Question* currentQuestion;
  char answer[255];
  int marksScored;
};

void createQuestion(struct Question** head) {
  *head = (struct Question*)malloc(sizeof(struct Question));
  (*head)->question[0] = '\0';
  (*head)->answer[0] = '\0';
  (*head)->marks = 0;
  (*head)->next = NULL;
}

void createStudent(struct Student** head) {
  *head = (struct Student*)malloc(sizeof(struct Student));
  (*head)->name[0] = '\0';
  (*head)->rollno = 0;
  (*head)->next = NULL;
  (*head)->answerSheet = NULL;
}

void createAnswerSheet(struct AnswerSheet** head) {
  *head = (struct AnswerSheet*)malloc(sizeof(struct AnswerSheet));
  (*head)->next = NULL;
  (*head)->currentQuestion = NULL;
  (*head)->answer[0] = '\0';
  (*head)->marksScored = 0;
}

void addQuestion(struct Question** head, char* question, char* answer, int marks) {
  struct Question* newQuestion = (struct Question*)malloc(sizeof(struct Question));
  strcpy(newQuestion->question, question);
  strcpy(newQuestion->answer, answer);
  newQuestion->marks = marks;
  newQuestion->next = NULL;

  if (*head == NULL) {
    *head = newQuestion;
  } else {
    (*head)->next = newQuestion;
  }
}

void addStudent(struct Student** head, char* name, int rollno) {
  struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
  strcpy(newStudent->name, name);
  newStudent->rollno = rollno;
  newStudent->next = NULL;
  newStudent->answerSheet = NULL;

  if (*head == NULL) {
    *head = newStudent;
  } else {
    (*head)->next = newStudent;
  }
}

void addAnswerSheet(struct AnswerSheet** head, struct Question* currentQuestion, char* answer, int marksScored) {
  struct AnswerSheet* newAnswerSheet = (struct AnswerSheet*)malloc(sizeof(struct AnswerSheet));
  newAnswerSheet->next = NULL;
  newAnswerSheet->currentQuestion = currentQuestion;
  strcpy(newAnswerSheet->answer, answer);
  newAnswerSheet->marksScored = marksScored;

  if (*head == NULL) {
    *head = newAnswerSheet;
  } else {
    (*head)->next = newAnswerSheet;
  }
}

int main() {
  struct Question* questions = NULL;
  struct Student* students = NULL;
  struct AnswerSheet* answerSheets = NULL;

  // Create some questions
  addQuestion(&questions, "What is the meaning of life?", "To be or not to be.", 10);
  addQuestion(&questions, "What is the sound of one hand clapping?", "Silence.", 5);
  addQuestion(&questions, "What is the capital of France?", "Paris.", 8);

  // Create some students
  addStudent(&students, "John Doe", 123);
  addStudent(&students, "Jane Doe", 456);

  // Create some answer sheets
  addAnswerSheet(&answerSheets, questions->next, "The meaning of life is to be.", 8);
  addAnswerSheet(&answerSheets, questions->next, "To be or not to be is a philosophical question.", 6);

  // Print the results
  for (struct Student* student = students; student; student = student->next) {
    printf("Student name: %s, Rollno: %d\n", student->name, student->rollno);
    for (struct AnswerSheet* answerSheet = student->answerSheet; answerSheet; answerSheet = answerSheet->next) {
      printf("Question: %s, Answer: %s, Marks: %d\n", answerSheet->currentQuestion->question, answerSheet->answer, answerSheet->marksScored);
    }
  }

  return 0;
}