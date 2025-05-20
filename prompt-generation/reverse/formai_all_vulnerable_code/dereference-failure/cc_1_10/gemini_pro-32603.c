//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 4

// Define the structure of a question
typedef struct {
  char question[100];
  char choices[MAX_CHOICES][100];
  int correct_choice;
} Question;

// Define the structure of an examination
typedef struct {
  Question questions[MAX_QUESTIONS];
  int num_questions;
} Examination;

// Create a new examination
Examination *new_examination() {
  Examination *exam = (Examination *)malloc(sizeof(Examination));
  for (int i = 0; i < MAX_QUESTIONS; i++) {
    exam->questions[i] = (Question){0};
  }
  exam->num_questions = 0;
  return exam;
}

// Add a question to the examination
void add_question(Examination *exam, Question question) {
  if (exam->num_questions == MAX_QUESTIONS) {
    printf("Error: The examination is full.\n");
    return;
  }
  exam->questions[exam->num_questions++] = question;
}

// Print the examination
void print_examination(const Examination *exam) {
  for (int i = 0; i < exam->num_questions; i++) {
    const Question *question = &exam->questions[i];
    printf("%d. ", i + 1);
    printf("%s\n", question->question);
    for (int j = 0; j < MAX_CHOICES; j++) {
      printf("  %c. %s\n", 'A' + j, question->choices[j]);
    }
  }
}

// Take the examination
int take_examination(const Examination *exam) {
  int score = 0;
  for (int i = 0; i < exam->num_questions; i++) {
    const Question *question = &exam->questions[i];
    char answer;
    printf("What is your answer to question %d? ", i + 1);
    scanf(" %c", &answer);
    answer = toupper(answer);
    if (answer == 'A' + question->correct_choice) {
      score++;
    }
  }
  return score;
}

// Free the memory used by the examination
void free_examination(Examination *exam) {
  free(exam);
}

// Main function
int main() {
  // Create a new examination
  Examination *exam = new_examination();

  // Add questions to the examination
  add_question(exam, (Question){
    "Who invented the telephone?",
    {"Alexander Graham Bell", "Thomas Edison", "Nikola Tesla", "Guglielmo Marconi"},
    0
  });
  add_question(exam, (Question){
    "What is the capital of France?",
    {"Paris", "London", "Rome", "Madrid"},
    0
  });
  add_question(exam, (Question){
    "What is the largest planet in the solar system?",
    {"Jupiter", "Saturn", "Uranus", "Neptune"},
    0
  });

  // Print the examination
  print_examination(exam);

  // Take the examination
  int score = take_examination(exam);

  // Print the score
  printf("Your score is %d out of %d.\n", score, exam->num_questions);

  // Free the memory used by the examination
  free_examination(exam);

  return 0;
}