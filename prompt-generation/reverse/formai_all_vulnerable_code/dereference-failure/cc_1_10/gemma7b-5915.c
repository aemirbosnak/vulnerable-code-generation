//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
  char *question;
  char **answers;
  int answerIndex;
} Question;

int main() {
  time_t start_time = time(NULL);
  Question questions[MAX_QUESTIONS] = {
    {"What is the meaning of the word 'entrepreneur'?",
      {"a. A dreamer", "b. A leader", "c. A business owner", "d. A manager"},
      2},
    {"Which scientist invented the theory of relativity?",
      {"a. Albert Einstein", "b. Isaac Newton", "c. Charles Darwin", "d. Galileo Galilei"},
      0},
    {"What is the capital of France?",
      {"a. Paris", "b. Rome", "c. Lyon", "d. Marseille"},
      1},
    {"Which planet is the largest?",
      {"a. Earth", "b. Mars", "c. Jupiter", "d. Saturn"},
      2},
    {"What is the sound of one hand clapping?",
      {"a. Silence", "b. Silence", "c. Silence", "d. Silence"},
      0}
  };

  int currentQuestionIndex = 0;
  int score = 0;

  while (currentQuestionIndex < MAX_QUESTIONS) {
    printf("Question: %s\n", questions[currentQuestionIndex].question);

    for (int i = 0; i < MAX_ANSWERS; i++) {
      printf("Answer: %s) %s\n", i + 1, questions[currentQuestionIndex].answers[i]);
    }

    int answerChoice = -1;
    printf("Enter your answer choice: ");
    scanf("%d", &answerChoice);

    if (answerChoice >= 1 && answerChoice <= MAX_ANSWERS) {
      if (questions[currentQuestionIndex].answerIndex == answerChoice - 1) {
        score++;
      }
      currentQuestionIndex++;
    } else {
      printf("Invalid answer choice.\n");
    }
  }

  time_t end_time = time(NULL);
  int timeTaken = end_time - start_time;

  printf("Your score: %d/%d\n", score, MAX_QUESTIONS);
  printf("Time taken: %d seconds\n", timeTaken);

  return 0;
}