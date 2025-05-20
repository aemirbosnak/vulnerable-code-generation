//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4
#define QUESTIONS_FILE "questions.txt"
#define ANSWERS_FILE "answers.txt"
#define TIME_LIMIT 30

// Function to read questions from the file
void readQuestions(char **questions) {
  FILE *fp = fopen(QUESTIONS_FILE, "r");
  if (fp) {
    questions = (char *)malloc(MAX_QUESTIONS * sizeof(char *));
    int i = 0;
    while (!feof(fp) && i < MAX_QUESTIONS) {
      questions[i] = (char *)malloc(256);
      fscanf(fp, "%s", questions[i]);
      i++;
    }
    fclose(fp);
  }
}

// Function to read answers from the file
void readAnswers(char **answers) {
  FILE *fp = fopen(ANSWERS_FILE, "r");
  if (fp) {
    answers = (char *)malloc(MAX_QUESTIONS * sizeof(char *));
    int i = 0;
    while (!feof(fp) && i < MAX_QUESTIONS) {
      answers[i] = (char *)malloc(MAX_ANSWERS * sizeof(char));
      fscanf(fp, "%s", answers[i]);
      i++;
    }
    fclose(fp);
  }
}

// Function to start the examination
void startExamination(char **questions, char **answers) {
  time_t start_time = time(NULL);
  int i = 0;
  while (i < MAX_QUESTIONS && time(NULL) - start_time < TIME_LIMIT) {
    printf("%s", questions[i]);
    char answer[MAX_ANSWERS];
    scanf("%s", answer);
    if (strcmp(answer, answers[i]) == 0) {
      printf("Correct!\n");
    } else {
      printf("Incorrect. The answer is: %s\n", answers[i]);
    }
    i++;
  }
  time_t end_time = time(NULL);
  printf("Time elapsed: %d minutes", end_time - start_time);
}

int main() {
  char **questions = NULL;
  char **answers = NULL;

  readQuestions(questions);
  readAnswers(answers);

  startExamination(questions, answers);

  return 0;
}