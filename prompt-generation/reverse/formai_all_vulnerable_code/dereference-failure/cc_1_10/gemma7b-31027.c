//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXAM_QUESTIONS 10

typedef struct Question {
  char question[255];
  int answer_choice;
  struct Question* next;
} Question;

Question* create_question(char* question, int answer_choice, Question* next) {
  Question* new_question = malloc(sizeof(Question));
  strcpy(new_question->question, question);
  new_question->answer_choice = answer_choice;
  new_question->next = next;
  return new_question;
}

void take_exam(Question* questions) {
  printf("Welcome to the C Online Examination System!\n");

  for (Question* current_question = questions; current_question; current_question = current_question->next) {
    printf("Question: %s\n", current_question->question);

    for (int i = 0; i < current_question->answer_choice; i++) {
      printf("Answer Choice %d: %s\n", i + 1, current_question->question);
    }

    int answer_choice = -1;
    printf("Enter your answer choice number: ");
    scanf("%d", &answer_choice);

    if (answer_choice < 1 || answer_choice > current_question->answer_choice) {
      printf("Invalid answer choice. Please try again.\n");
      continue;
    }

    printf("Your answer is: %d\n", answer_choice);
  }

  printf("Thank you for taking the exam!\n");
}

int main() {
  Question* questions = create_question("What is the meaning of the word 'entrepreneur'?", 3, NULL);
  questions = create_question("What is the capital of France?", 2, questions);
  questions = create_question("Which programming language is known for its portability?", 1, questions);

  take_exam(questions);

  return 0;
}