//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the number of questions in the exam
#define NUM_QUESTIONS 10

// Define the maximum number of choices per question
#define MAX_CHOICES 4

// Define the maximum length of a question
#define MAX_QUESTION_LENGTH 100

// Define the maximum length of a choice
#define MAX_CHOICE_LENGTH 50

// Define the type of a question
typedef struct {
  char question[MAX_QUESTION_LENGTH];
  char choices[MAX_CHOICES][MAX_CHOICE_LENGTH];
  int correct_answer;
} Question;

// Define the type of an exam
typedef struct {
  Question questions[NUM_QUESTIONS];
  int num_questions;
} Exam;

// Create a new exam
Exam* create_exam() {
  Exam* exam = malloc(sizeof(Exam));
  exam->num_questions = NUM_QUESTIONS;
  for (int i = 0; i < NUM_QUESTIONS; i++) {
    // Generate a random question
    snprintf(exam->questions[i].question, MAX_QUESTION_LENGTH, "Question %d", i + 1);

    // Generate random choices
    for (int j = 0; j < MAX_CHOICES; j++) {
      snprintf(exam->questions[i].choices[j], MAX_CHOICE_LENGTH, "Choice %d", j + 1);
    }

    // Choose a random correct answer
    exam->questions[i].correct_answer = rand() % MAX_CHOICES;
  }

  return exam;
}

// Free the memory allocated for an exam
void free_exam(Exam* exam) {
  free(exam);
}

// Print an exam to the console
void print_exam(Exam* exam) {
  for (int i = 0; i < exam->num_questions; i++) {
    printf("%s\n", exam->questions[i].question);
    for (int j = 0; j < MAX_CHOICES; j++) {
      printf("%s\n", exam->questions[i].choices[j]);
    }
    printf("\n");
  }
}

// Grade an exam
int grade_exam(Exam* exam, int* answers) {
  int score = 0;
  for (int i = 0; i < exam->num_questions; i++) {
    if (answers[i] == exam->questions[i].correct_answer) {
      score++;
    }
  }

  return score;
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));

  // Create an exam
  Exam* exam = create_exam();

  // Print the exam to the console
  print_exam(exam);

  // Get the user's answers
  int answers[NUM_QUESTIONS];
  for (int i = 0; i < NUM_QUESTIONS; i++) {
    printf("Enter your answer for question %d: ", i + 1);
    scanf("%d", &answers[i]);
  }

  // Grade the exam
  int score = grade_exam(exam, answers);

  // Print the score to the console
  printf("Your score is %d\n", score);

  // Free the memory allocated for the exam
  free_exam(exam);

  return 0;
}