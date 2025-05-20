//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Question {
  char *question;
  char **options;
  int num_options;
  int correct_option;
};

struct Exam {
  char *name;
  int num_questions;
  struct Question *questions;
};

int main() {
  // Create a new exam
  struct Exam exam;
  exam.name = "C Programming Exam";
  exam.num_questions = 10;
  exam.questions = malloc(sizeof(struct Question) * exam.num_questions);

  // Define the questions
  char *questions[] = {
    "What is the size of an int in C?",
    "Which of the following is not a data type in C?",
    "What is the difference between a pointer and an array?",
    "What is the output of the following code?\nint main() { int a = 10; printf(\"%d\", a++); }",
    "What is the purpose of the 'break' statement in a switch statement?",
    "Which of the following is a valid file extension for a C program?",
    "What is the difference between a macro and a function?",
    "What is the output of the following code?\nint main() { int a = 10; a += (a++ * ++a); printf(\"%d\", a); }",
    "What is the purpose of the 'const' keyword?",
    "Which of the following is not a valid operator in C?",
  };

  // Define the options for each question
  char **options[][4] = {
    {"1 byte", "2 bytes", "4 bytes", "8 bytes"},
    {"int", "float", "char", "string"},
    {"A pointer stores the memory address of a variable, while an array stores the actual values.",
    "A pointer can be reassigned to point to a different variable, while an array cannot be reassigned.",
    "Both of the above"},
    {"10", "11", "12", "13"},
    {"Terminates the switch statement", "Skips the remaining cases", "Jumps to the next case", "None of the above"},
    {".c", ".cpp", ".java", ".py"},
    {"A macro is preprocessed before compilation, while a function is compiled at runtime.",
    "A macro does not take any arguments, while a function can take arguments.",
    "Both of the above"},
    {"22", "24", "26", "28"},
    {"To declare a constant variable", "To prevent a variable from being modified", "To make a function immutable",
    "None of the above"},
    {"*", "/", "&", "~"},
  };

  // Define the correct options for each question
  int correct_options[] = {2, 3, 1, 1, 1, 0, 2, 2, 1, 3};

  // Initialize the questions in the exam
  for (int i = 0; i < exam.num_questions; i++) {
    exam.questions[i].question = questions[i];
    exam.questions[i].options = options[i];
    exam.questions[i].num_options = 4;
    exam.questions[i].correct_option = correct_options[i];
  }

  // Administer the exam
  int score = 0;
  for (int i = 0; i < exam.num_questions; i++) {
    printf("Question %d: %s\n", i + 1, exam.questions[i].question);
    for (int j = 0; j < exam.questions[i].num_options; j++) {
      printf("%d. %s\n", j + 1, exam.questions[i].options[j]);
    }
    printf("Enter your answer (1-%d): ", exam.questions[i].num_options);
    int answer;
    scanf("%d", &answer);
    if (answer == exam.questions[i].correct_option) {
      score++;
    }
  }

  // Print the exam results
  printf("Your score is %d out of %d\n", score, exam.num_questions);

  // Free the memory allocated for the exam
  for (int i = 0; i < exam.num_questions; i++) {
    free(exam.questions[i].question);
    for (int j = 0; j < exam.questions[i].num_options; j++) {
      free(exam.questions[i].options[j]);
    }
 } 
  free(exam. questions);

  return 0;
}