//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUESTIONS 10

typedef struct Question {
  char *question;
  int answer;
  struct Question *next;
} Question;

Question *head = NULL;

void addQuestion(char *question, int answer) {
  Question *newQuestion = malloc(sizeof(Question));
  newQuestion->question = strdup(question);
  newQuestion->answer = answer;
  newQuestion->next = NULL;

  if (head == NULL) {
    head = newQuestion;
  } else {
    head->next = newQuestion;
    head = newQuestion;
  }
}

void takeExam() {
  Question *currentQuestion = head;

  while (currentQuestion) {
    printf("%s\n", currentQuestion->question);
    int userAnswer = getchar();

    if (userAnswer == currentQuestion->answer) {
      printf("Correct!\n");
    } else {
      printf("Incorrect. The answer is: %d\n", currentQuestion->answer);
    }

    currentQuestion = currentQuestion->next;
  }

  printf("Congratulations! You have completed the exam.\n");
}

int main() {
  addQuestion("What is the meaning of life?", 42);
  addQuestion("What is the sound of one hand clapping?", 0);
  addQuestion("Who is the president of the United States?", 44);

  takeExam();

  return 0;
}