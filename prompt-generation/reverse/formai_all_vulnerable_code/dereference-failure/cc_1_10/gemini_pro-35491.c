//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of questions and choices
#define MAX_QUESTIONS 10
#define MAX_CHOICES 5

// Define the structure of a question
typedef struct question {
  int id;
  char *text;
  char **choices;
  int correct_choice;
} question_t;

// Define the structure of an exam
typedef struct exam {
  int num_questions;
  question_t **questions;
} exam_t;

// Create a new question
question_t *create_question(int id, char *text, char **choices, int correct_choice) {
  question_t *question = malloc(sizeof(question_t));
  question->id = id;
  question->text = strdup(text);
  question->choices = malloc(sizeof(char *) * MAX_CHOICES);
  for (int i = 0; i < MAX_CHOICES; i++) {
    question->choices[i] = strdup(choices[i]);
  }
  question->correct_choice = correct_choice;
  return question;
}

// Create a new exam
exam_t *create_exam(int num_questions, question_t **questions) {
  exam_t *exam = malloc(sizeof(exam_t));
  exam->num_questions = num_questions;
  exam->questions = questions;
  return exam;
}

// Print the exam to the console
void print_exam(exam_t *exam) {
  for (int i = 0; i < exam->num_questions; i++) {
    question_t *question = exam->questions[i];
    printf("Question %d: %s\n", question->id, question->text);
    for (int j = 0; j < MAX_CHOICES; j++) {
      printf("\t%d. %s\n", j + 1, question->choices[j]);
    }
  }
}

// Grade the exam
int grade_exam(exam_t *exam, int *answers) {
  int score = 0;
  for (int i = 0; i < exam->num_questions; i++) {
    question_t *question = exam->questions[i];
    if (answers[i] == question->correct_choice) {
      score++;
    }
  }
  return score;
}

// Free the memory allocated for the exam
void free_exam(exam_t *exam) {
  for (int i = 0; i < exam->num_questions; i++) {
    question_t *question = exam->questions[i];
    free(question->text);
    for (int j = 0; j < MAX_CHOICES; j++) {
      free(question->choices[j]);
    }
    free(question);
  }
  free(exam);
}

// Main function
int main() {
  // Create the questions
  question_t *questions[] = {
    create_question(1, "What is the capital of France?", (char *[]){"Paris", "London", "Rome", "Madrid", "Berlin"}, 0),
    create_question(2, "Who is the author of the book \"The Catcher in the Rye\"?", (char *[]){"J.D. Salinger", "Ernest Hemingway", "F. Scott Fitzgerald", "Harper Lee", "George Orwell"}, 0),
    create_question(3, "What is the chemical symbol for gold?", (char *[]){"Au", "Ag", "Cu", "Fe", "Pb"}, 0),
    create_question(4, "What is the largest planet in the solar system?", (char *[]){"Jupiter", "Saturn", "Uranus", "Neptune", "Mars"}, 0),
    create_question(5, "Who is the current president of the United States?", (char *[]){"Joe Biden", "Donald Trump", "Barack Obama", "George W. Bush", "Bill Clinton"}, 0),
    create_question(6, "What is the name of the largest ocean in the world?", (char *[]){"Pacific Ocean", "Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Southern Ocean"}, 0),
    create_question(7, "What is the chemical formula for water?", (char *[]){"H2O", "CO2", "NH3", "CH4", "O2"}, 0),
    create_question(8, "Who is the inventor of the telephone?", (char *[]){"Alexander Graham Bell", "Thomas Edison", "Nikola Tesla", "Albert Einstein", "Marie Curie"}, 0),
    create_question(9, "What is the capital of Australia?", (char *[]){"Canberra", "Sydney", "Melbourne", "Perth", "Brisbane"}, 0),
    create_question(10, "What is the name of the highest mountain in the world?", (char *[]){"Mount Everest", "K2", "Kangchenjunga", "Lhotse", "Makalu"}, 0),
  };

  // Create the exam
  exam_t *exam = create_exam(10, questions);

  // Print the exam to the console
  print_exam(exam);

  // Get the answers from the user
  int answers[MAX_QUESTIONS];
  for (int i = 0; i < exam->num_questions; i++) {
    printf("Enter the answer to question %d: ", i + 1);
    scanf("%d", &answers[i]);
  }

  // Grade the exam
  int score = grade_exam(exam, answers);

  // Print the score to the console
  printf("Your score is: %d\n", score);

  // Free the memory allocated for the exam
  free_exam(exam);

  return 0;
}