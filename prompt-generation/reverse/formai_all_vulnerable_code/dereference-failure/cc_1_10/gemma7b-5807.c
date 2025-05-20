//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 2

typedef struct Question {
  char *question;
  char **answers;
  int answerIndex;
} Question;

void createQuestion(Question **questions, int index) {
  questions[index] = malloc(sizeof(Question));
  questions[index]->question = malloc(20 * sizeof(char));
  questions[index]->answers = malloc(MAX_ANSWERS * sizeof(char *));
  questions[index]->answerIndex = -1;
}

void addAnswer(Question *question, char *answer) {
  int i = 0;
  for (i = 0; i < MAX_ANSWERS; i++) {
    if (question->answers[i] == NULL) {
      question->answers[i] = malloc(20 * sizeof(char));
      strcpy(question->answers[i], answer);
      return;
    }
  }
  printf("Error: Maximum number of answers reached.\n");
}

int main() {
  Question **questions = malloc(MAX_QUESTIONS * sizeof(Question));
  int i = 0;

  for (i = 0; i < MAX_QUESTIONS; i++) {
    createQuestion(questions, i);
  }

  questions[0]->question = "What is the meaning of life?";
  addAnswer(questions[0], "To be happy");
  addAnswer(questions[0], "To be wealthy");

  questions[1]->question = "What is the sound of one hand clapping?";
  addAnswer(questions[1], "Silence");
  addAnswer(questions[1], "A symphony");

  // ... Add more questions and answers ...

  // Now, let's examine the answers
  for (i = 0; i < MAX_QUESTIONS; i++) {
    printf("%s: ", questions[i]->question);
    for (int j = 0; j < MAX_ANSWERS; j++) {
      printf("%s ", questions[i]->answers[j]);
    }
    printf("\n");
  }

  return 0;
}