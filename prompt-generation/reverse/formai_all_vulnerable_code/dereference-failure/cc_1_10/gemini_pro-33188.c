//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: random
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct student {
  char name[50];
  int roll_no;
  int marks[5];
};

struct question {
  char question[100];
  char options[4][50];
  int answer;
};

struct exam {
  char name[50];
  int duration;
  int num_questions;
  struct question *questions;
};

void print_student(struct student *student) {
  printf("Name: %s\n", student->name);
  printf("Roll No: %d\n", student->roll_no);
  printf("Marks:\n");
  for (int i = 0; i < 5; i++) {
    printf("%d\n", student->marks[i]);
  }
}

void print_question(struct question *question) {
  printf("%s\n", question->question);
  for (int i = 0; i < 4; i++) {
    printf("%d. %s\n", i + 1, question->options[i]);
  }
}

void print_exam(struct exam *exam) {
  printf("Name: %s\n", exam->name);
  printf("Duration: %d minutes\n", exam->duration);
  printf("Number of Questions: %d\n", exam->num_questions);
  for (int i = 0; i < exam->num_questions; i++) {
    print_question(&exam->questions[i]);
  }
}

int main() {
  struct student student1 = {"John Doe", 1, {90, 80, 70, 60, 50}};
  print_student(&student1);

  struct question question1 = {
    "What is the capital of India?",
    {"New Delhi", "Mumbai", "Kolkata", "Chennai"},
    0
  };
  print_question(&question1);

  struct exam exam1 = {"Midterm Exam", 120, 10, NULL};
  exam1.questions = (struct question *)malloc(sizeof(struct question) * 10);
  for (int i = 0; i < 10; i++) {
    exam1.questions[i] = question1;
  }
  print_exam(&exam1);

  return 0;
}