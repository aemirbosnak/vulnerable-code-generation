//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the question and answer
struct question {
  char *question;
  char *answer;
};

// Function to create a new question
struct question *new_question(char *question, char *answer) {
  struct question *new_q = malloc(sizeof(struct question));
  new_q->question = strdup(question);
  new_q->answer = strdup(answer);
  return new_q;
}

// Function to free the memory allocated for a question
void free_question(struct question *q) {
  free(q->question);
  free(q->answer);
  free(q);
}

// Function to add a question to the exam
void add_question(struct question *q, struct question **exam, int *num_questions) {
  exam[*num_questions] = q;
  (*num_questions)++;
}

// Function to print the exam
void print_exam(struct question **exam, int num_questions) {
  for (int i = 0; i < num_questions; i++) {
    printf("%s\n", exam[i]->question);
  }
}

// Function to grade the exam
int grade_exam(struct question **exam, int num_questions, char **answers) {
  int score = 0;
  for (int i = 0; i < num_questions; i++) {
    if (strcmp(exam[i]->answer, answers[i]) == 0) {
      score++;
    }
  }
  return score;
}

// Main function
int main() {
  // Create the exam
  struct question *exam[100];
  int num_questions = 0;
  add_question(new_question("What is the capital of France?", "Paris"), exam, &num_questions);
  add_question(new_question("What is the largest ocean in the world?", "Pacific Ocean"), exam, &num_questions);
  add_question(new_question("What is the chemical symbol for gold?", "Au"), exam, &num_questions);

  // Print the exam
  print_exam(exam, num_questions);

  // Get the answers from the user
  char *answers[100];
  for (int i = 0; i < num_questions; i++) {
    printf("Enter the answer to question %d: ", i + 1);
    scanf("%s", answers[i]);
  }

  // Grade the exam
  int score = grade_exam(exam, num_questions, answers);

  // Print the score
  printf("Your score is %d out of %d\n", score, num_questions);

  // Free the memory allocated for the exam
  for (int i = 0; i < num_questions; i++) {
    free_question(exam[i]);
  }

  return 0;
}