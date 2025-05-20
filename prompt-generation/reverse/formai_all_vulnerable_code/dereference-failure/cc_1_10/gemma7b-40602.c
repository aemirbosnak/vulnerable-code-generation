//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 10
#define MAX_ANSWERS 4

typedef struct Question {
  char *question;
  char **answers;
  int answer_index;
} Question;

Question questions[MAX_QUESTIONS];

void read_questions() {
  FILE *fp = fopen("questions.txt", "r");
  if (fp == NULL) {
    perror("Error reading questions file");
    exit(1);
  }

  int i = 0;
  while (fscanf(fp, "%[^\n]%*c", questions[i].question) != EOF) {
    questions[i].answers = malloc(MAX_ANSWERS * sizeof(char *));
    questions[i].answer_index = -1;

    for (int j = 0; j < MAX_ANSWERS; j++) {
      fscanf(fp, "%[^\n]%*c", questions[i].answers[j]);
    }

    i++;
  }

  fclose(fp);
}

void take_exam() {
  read_questions();

  int score = 0;
  for (int i = 0; i < MAX_QUESTIONS; i++) {
    printf("%s\n", questions[i].question);

    for (int j = 0; j < MAX_ANSWERS; j++) {
      printf("%d. %s\n", j + 1, questions[i].answers[j]);
    }

    int answer_choice = -1;
    printf("Enter your answer choice: ");
    scanf("%d", &answer_choice);

    if (answer_choice > 0 && answer_choice <= MAX_ANSWERS) {
      if (questions[i].answer_index == answer_choice - 1) {
        score++;
      }
    }
  }

  printf("Your score: %d/%d\n", score, MAX_QUESTIONS);
}

int main() {
  take_exam();

  return 0;
}