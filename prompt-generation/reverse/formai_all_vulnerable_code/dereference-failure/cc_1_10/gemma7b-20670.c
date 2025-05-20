//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initialize_exam(char **exam_data, int **exam_questions) {
  *exam_data = malloc(10 * sizeof(char));
  *exam_questions = malloc(20 * sizeof(int));

  for (int i = 0; i < 10; i++) {
    (*exam_data)[i] = '\0';
  }

  for (int i = 0; i < 20; i++) {
    (*exam_questions)[i] = 0;
  }
}

int main() {
  char **exam_data;
  int **exam_questions;

  initialize_exam(&exam_data, &exam_questions);

  // Simulate some exam data
  exam_data[0] = 'A';
  exam_data[1] = 'B';
  exam_data[2] = 'C';
  exam_data[3] = 'D';

  // Simulate some exam questions
  exam_questions[0] = 10;
  exam_questions[1] = 15;
  exam_questions[2] = 20;

  // Print exam data and questions
  printf("Exam data:\n");
  for (int i = 0; i < 10; i++) {
    printf("%c ", exam_data[i]);
  }

  printf("\nExam questions:\n");
  for (int i = 0; i < 20; i++) {
    printf("%d ", exam_questions[i]);
  }

  free(exam_data);
  free(exam_questions);

  return 0;
}