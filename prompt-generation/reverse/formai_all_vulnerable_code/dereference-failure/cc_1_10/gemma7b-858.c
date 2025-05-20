//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUESTIONS 10

typedef struct Question {
  char question[255];
  char answer[255];
  int marks;
  struct Question* next;
} Question;

void generateQuestion(Question** head) {
  *head = malloc(sizeof(Question));
  (*head)->marks = 1;
  strcpy((*head)->question, "What is the capital of France?");
  strcpy((*head)->answer, "Paris");

  Question* tail = *head;
  for (int i = 1; i < MAX_QUESTIONS; i++) {
    tail->next = malloc(sizeof(Question));
    tail = tail->next;
    tail->marks = 2;
    strcpy(tail->question, "Who invented the telephone?");
    strcpy(tail->answer, "Alexander Graham Bell");
  }
}

int main() {
  Question* head = NULL;
  generateQuestion(&head);

  // Start the examination
  printf("Welcome to the C Online Examination System!\n");
  printf("Please answer the following questions:\n");

  // Traverse the questions and ask for answers
  for (Question* current = head; current; current = current->next) {
    printf("%s\n", current->question);
    char answer[255];
    printf("Enter your answer: ");
    scanf("%s", answer);

    // Check if the answer is correct
    if (strcmp(answer, current->answer) == 0) {
      printf("Congratulations! You have earned %d marks for this question.\n", current->marks);
    } else {
      printf("Sorry, your answer is incorrect. The correct answer is: %s\n", current->answer);
    }
  }

  // End the examination
  printf("Thank you for completing the examination.\n");

  return 0;
}