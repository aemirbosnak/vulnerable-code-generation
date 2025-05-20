//GEMINI-pro DATASET v1.0 Category: Online Examination System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store questions and answers
typedef struct {
  char question[256];
  char options[4][64];
  char answer;
} Question;

// Array of questions
Question questions[] = {
  {
    "Which of the following is not a data type in C?",
    {"int", "float", "double", "string"},
    'd'
  },
  {
    "What is the output of the following C code?\nint a = 10;\na += 5;\nprintf(\"%d\", a);",
    {"5", "10", "15", "20"},
    'c'
  },
  {
    "Which of the following is a valid loop in C?",
    {"for (i = 0; i < n; i++)", "while (i < n)", "do { ... } while (i < n);", "all of the above"},
    'd'
  },
  {
    "What is the purpose of the 'break' statement in C?",
    {"To exit a loop", "To exit a switch statement", "To exit a function", "None of the above"},
    'a'
  },
  {
    "Which of the following is a pointer in C?",
    {"A variable that stores the address of another variable", "A variable that stores a value", "A variable that stores a string", "None of the above"},
    'a'
  }
};

// Function to print the questions and options
void printQuestions(Question questions[], int numQuestions) {
  for (int i = 0; i < numQuestions; i++) {
    printf("Question %d:\n", i + 1);
    printf("%s\n", questions[i].question);
    for (int j = 0; j < 4; j++) {
      printf("%c. %s\n", 'a' + j, questions[i].options[j]);
    }
    printf("\n");
  }
}

// Function to get the user's answers
char* getAnswers(int numQuestions) {
  char* answers = malloc(numQuestions * sizeof(char));
  for (int i = 0; i < numQuestions; i++) {
    printf("Enter your answer for question %d: ", i + 1);
    scanf(" %c", &answers[i]);
  }
  return answers;
}

// Function to check the user's answers
int checkAnswers(char* answers, Question questions[], int numQuestions) {
  int score = 0;
  for (int i = 0; i < numQuestions; i++) {
    if (answers[i] == questions[i].answer) {
      score++;
    }
  }
  return score;
}

// Function to print the results
void printResults(int score, int numQuestions) {
  printf("Your score is %d out of %d.\n", score, numQuestions);
  if (score >= (numQuestions * 0.75)) {
    printf("Congratulations! You passed the exam.\n");
  } else {
    printf("Sorry, you failed the exam.\n");
  }
}

int main() {
  int numQuestions = sizeof(questions) / sizeof(Question);
  printQuestions(questions, numQuestions);
  char* answers = getAnswers(numQuestions);
  int score = checkAnswers(answers, questions, numQuestions);
  printResults(score, numQuestions);
  free(answers);
  return 0;
}