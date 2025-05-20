//Code Llama-13B DATASET v1.0 Category: Online Examination System ; Style: Ken Thompson
// Online Examination System
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Question struct
typedef struct {
  char question[100];
  char options[4][100];
  char answer[100];
} Question;

// Student struct
typedef struct {
  char name[50];
  int score;
} Student;

// Function to generate random question
void generate_question(Question *q) {
  // Generate random numbers for question and options
  int num1 = rand() % 100;
  int num2 = rand() % 100;
  int num3 = rand() % 100;
  int num4 = rand() % 100;

  // Generate random operation
  char operation = '+';
  if (rand() % 2 == 0) operation = '-';

  // Generate question and options
  sprintf(q->question, "%d %c %d = ?", num1, operation, num2);
  sprintf(q->options[0], "%d", num1 + num2);
  sprintf(q->options[1], "%d", num1 - num2);
  sprintf(q->options[2], "%d", num1 * num2);
  sprintf(q->options[3], "%d", num1 / num2);

  // Generate answer
  sprintf(q->answer, "%d", num1 + num2);
}

// Function to display question
void display_question(Question *q) {
  printf("Question: %s\n", q->question);
  printf("Options:\n");
  for (int i = 0; i < 4; i++) {
    printf("%d. %s\n", i + 1, q->options[i]);
  }
}

// Function to check answer
int check_answer(Question *q, char *answer) {
  return strcmp(q->answer, answer) == 0;
}

// Function to display result
void display_result(Student *s, int correct) {
  if (correct) {
    printf("Correct!\n");
    s->score++;
  } else {
    printf("Wrong!\n");
  }
}

// Main function
int main() {
  // Initialize question and student structs
  Question q;
  Student s;

  // Initialize score
  s.score = 0;

  // Generate question
  generate_question(&q);

  // Display question
  display_question(&q);

  // Get answer from user
  char answer[100];
  printf("Answer: ");
  scanf("%s", answer);

  // Check answer
  int correct = check_answer(&q, answer);

  // Display result
  display_result(&s, correct);

  // Display score
  printf("Score: %d\n", s.score);

  return 0;
}