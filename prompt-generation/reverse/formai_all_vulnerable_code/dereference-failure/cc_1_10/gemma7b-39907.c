//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
  char question[256];
  char answers[MAX_ANSWERS][256];
  int correctAnswer;
} Question;

Question questions[MAX_QUESTIONS] = {
  {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and operates a business", "b. A person who is good at math", "c. A person who is wealthy", "d. A person who is creative"}, 1},
  {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 2},
  {"What is the sound of one hand clapping?", {"a. Silence", "b. Hum", "c. Click", "d. Tick"}},
  {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and operates a business", "b. A person who is good at math", "c. A person who is wealthy", "d. A person who is creative"}, 1},
  {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 2},
  {"What is the sound of one hand clapping?", {"a. Silence", "b. Hum", "c. Click", "d. Tick"}},
  {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and operates a business", "b. A person who is good at math", "c. A person who is wealthy", "d. A person who is creative"}, 1},
  {"What is the capital of France?", {"a. Paris", "b. Rome", "c. Berlin", "d. Lyon"}, 2},
  {"What is the sound of one hand clapping?", {"a. Silence", "b. Hum", "c. Click", "d. Tick"}},
  {"What is the meaning of the word 'entrepreneur'?", {"a. A person who starts and operates a business", "b. A person who is good at math", "c. A person who is wealthy", "d. A person who is creative"}, 1}
};

int main() {
  int i, score = 0, currentQuestion = 0;
  char answer[MAX_ANSWERS];

  printf("Welcome to the C Online Examination System!\n");

  while (currentQuestion < MAX_QUESTIONS) {
    printf("Question %d: %s\n", currentQuestion + 1, questions[currentQuestion].question);

    for (i = 0; i < MAX_ANSWERS; i++) {
      printf("  Answer %d: %s\n", i + 1, questions[currentQuestion].answers[i]);
    }

    printf("Enter your answer: ");
    scanf("%s", answer);

    if (strcmp(answer, questions[currentQuestion].answers[questions[currentQuestion].correctAnswer]) == 0) {
      score++;
    }

    currentQuestion++;
  }

  printf("Your score is: %d out of %d\n", score, MAX_QUESTIONS);

  return 0;
}