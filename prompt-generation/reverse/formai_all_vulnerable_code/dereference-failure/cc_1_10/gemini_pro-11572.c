//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 4

// Define the data structure for a question
typedef struct {
  char question[256];
  char choices[MAX_CHOICES][256];
  int correct_answer;
} Question;

// Define the data structure for an examination
typedef struct {
  Question questions[MAX_QUESTIONS];
  int num_questions;
} Examination;

// Create a new examination
Examination* create_examination() {
  Examination* exam = malloc(sizeof(Examination));
  exam->num_questions = 0;
  return exam;
}

// Add a question to an examination
void add_question(Examination* exam, char* question, char* choices[], int correct_answer) {
  strcpy(exam->questions[exam->num_questions].question, question);
  for (int i = 0; i < MAX_CHOICES; i++) {
    strcpy(exam->questions[exam->num_questions].choices[i], choices[i]);
  }
  exam->questions[exam->num_questions].correct_answer = correct_answer;
  exam->num_questions++;
}

// Generate a random examination
Examination* generate_random_examination() {
  Examination* exam = create_examination();

  // Seed the random number generator
  srand(time(NULL));

  // Generate a random number of questions
  int num_questions = rand() % MAX_QUESTIONS + 1;

  // Generate a random set of questions
  for (int i = 0; i < num_questions; i++) {
    char question[256];
    char choices[MAX_CHOICES][256];
    int correct_answer = rand() % MAX_CHOICES;

    // Generate a random question
    sprintf(question, "Question %d:", i + 1);

    // Generate a random set of choices
    for (int j = 0; j < MAX_CHOICES; j++) {
      sprintf(choices[j], "Choice %d:", j + 1);
    }

    // Add the question to the examination
    add_question(exam, question, choices, correct_answer);
  }

  return exam;
}

// Print an examination
void print_examination(Examination* exam) {
  for (int i = 0; i < exam->num_questions; i++) {
    printf("%s\n", exam->questions[i].question);
    for (int j = 0; j < MAX_CHOICES; j++) {
      printf("%s\n", exam->questions[i].choices[j]);
    }
  }
}

// Grade an examination
int grade_examination(Examination* exam, int answers[]) {
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
  // Generate a random examination
  Examination* exam = generate_random_examination();

  // Print the examination
  print_examination(exam);

  // Get the user's answers
  int answers[MAX_QUESTIONS];
  for (int i = 0; i < exam->num_questions; i++) {
    printf("Enter your answer for question %d: ", i + 1);
    scanf("%d", &answers[i]);
  }

  // Grade the examination
  int score = grade_examination(exam, answers);

  // Print the score
  printf("Your score is: %d\n", score);

  return 0;
}