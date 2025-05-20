//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// A random number generator function
int rng(int min, int max) {
  return (rand() % (max - min + 1)) + min;
}

// A question structure
typedef struct {
  char *question;
  int num_answers;
  char **answers;
  int correct_answer;
} Question;

// A function to create a new question
Question *create_question(char *question, int num_answers, char **answers,
                          int correct_answer) {
  Question *new_question = (Question *)malloc(sizeof(Question));
  new_question->question = question;
  new_question->num_answers = num_answers;
  new_question->answers = answers;
  new_question->correct_answer = correct_answer;
  return new_question;
}

// A function to free a question
void free_question(Question *question) {
  free(question->question);
  for (int i = 0; i < question->num_answers; i++) {
    free(question->answers[i]);
  }
  free(question->answers);
  free(question);
}

// A function to print a question
void print_question(Question *question) {
  printf("%s\n", question->question);
  for (int i = 0; i < question->num_answers; i++) {
    printf("%d. %s\n", i + 1, question->answers[i]);
  }
}

// A function to get the user's answer to a question
int get_user_answer(Question *question) {
  int answer;
  printf("Enter your answer: ");
  scanf("%d", &answer);
  return answer;
}

// A function to check if the user's answer is correct
int is_correct_answer(Question *question, int answer) {
  return answer == question->correct_answer;
}

// A function to create a new exam
typedef struct {
  char *name;
  int num_questions;
  Question **questions;
} Exam;

// A function to create a new exam
Exam *create_exam(char *name, int num_questions, Question **questions) {
  Exam *new_exam = (Exam *)malloc(sizeof(Exam));
  new_exam->name = name;
  new_exam->num_questions = num_questions;
  new_exam->questions = questions;
  return new_exam;
}

// A function to free an exam
void free_exam(Exam *exam) {
  free(exam->name);
  for (int i = 0; i < exam->num_questions; i++) {
    free_question(exam->questions[i]);
  }
  free(exam->questions);
  free(exam);
}

// A function to print an exam
void print_exam(Exam *exam) {
  printf("%s\n", exam->name);
  for (int i = 0; i < exam->num_questions; i++) {
    print_question(exam->questions[i]);
  }
}

// A function to get the user's answers to an exam
int *get_user_answers(Exam *exam) {
  int *answers = (int *)malloc(sizeof(int) * exam->num_questions);
  for (int i = 0; i < exam->num_questions; i++) {
    answers[i] = get_user_answer(exam->questions[i]);
  }
  return answers;
}

// A function to check if the user's answers to an exam are correct
int is_correct_answers(Exam *exam, int *answers) {
  for (int i = 0; i < exam->num_questions; i++) {
    if (!is_correct_answer(exam->questions[i], answers[i])) {
      return 0;
    }
  }
  return 1;
}

// A function to grade an exam
int grade_exam(Exam *exam, int *answers) {
  int score = 0;
  for (int i = 0; i < exam->num_questions; i++) {
    if (is_correct_answer(exam->questions[i], answers[i])) {
      score++;
    }
  }
  return score;
}

// A function to print the results of an exam
void print_results(Exam *exam, int *answers, int score) {
  printf("Exam: %s\n", exam->name);
  for (int i = 0; i < exam->num_questions; i++) {
    printf("Question %d: ", i + 1);
    if (is_correct_answer(exam->questions[i], answers[i])) {
      printf("Correct!\n");
    } else {
      printf("Incorrect. Correct answer: %d\n",
             exam->questions[i]->correct_answer);
    }
  }
  printf("Score: %d/%d\n", score, exam->num_questions);
}

// The main function
int main() {
  // Set up the random number generator
  srand(time(NULL));

  // Create some questions
  Question *question1 = create_question(
      "What is the capital of France?", 3,
      (char *[]){"Paris ", "London", "Rome"}, 1);
  Question *question2 = create_question("What is the largest ocean in the world?",
                                     4, (char *[]){"Pacific Ocean", "Atlantic Ocean",
                                                     "Indian Ocean",
                                                     "Arctic Ocean"},
                                     1);
  Question *question3 = create_question(
      "What is the name of the largest desert in the world?", 3,
      (char *[]){"Sahara Desert", "Gobi Desert", "Kalahari Desert"}, 1);

  // Create an exam
  Exam *exam = create_exam("Geography Exam", 3,
                          (Question *[]){question1, question2, question3});

  // Print the exam
  print_exam(exam);

  // Get the user's answers
  int *answers = get_user_answers(exam);

  // Check if the user's answers are correct
  int correct = is_correct_answers(exam, answers);

  // Grade the exam
  int score = grade_exam(exam, answers);

  // Print the results
  print_results(exam, answers, score);

  // Free the memory
  free_exam(exam);
  free_question(question1);
  free_question(question2);
  free_question(question3);
  free(answers);

  return 0;
}