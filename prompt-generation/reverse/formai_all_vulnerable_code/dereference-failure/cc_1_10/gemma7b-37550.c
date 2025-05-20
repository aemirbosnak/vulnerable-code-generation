//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CANDIDATES 10
#define MAX_QUESTIONS 20

typedef struct Candidate {
  char name[20];
  int score;
  struct Candidate* next;
} Candidate;

typedef struct Question {
  char question[200];
  char answer[20];
  struct Question* next;
} Question;

Candidate* createCandidate(char* name) {
  Candidate* candidate = (Candidate*)malloc(sizeof(Candidate));
  strcpy(candidate->name, name);
  candidate->score = 0;
  candidate->next = NULL;
  return candidate;
}

Question* createQuestion(char* question, char* answer) {
  Question* questionObj = (Question*)malloc(sizeof(Question));
  strcpy(questionObj->question, question);
  strcpy(questionObj->answer, answer);
  questionObj->next = NULL;
  return questionObj;
}

int main() {
  // Create a list of candidates
  Candidate* head = createCandidate("John Doe");
  head->next = createCandidate("Jane Doe");
  head->next->next = createCandidate("Peter Pan");

  // Create a list of questions
  Question* tail = createQuestion("What is the meaning of life?", "To be happy");
  tail->next = createQuestion("What is the capital of France?", "Paris");
  tail->next->next = createQuestion("Who wrote the novel Harry Potter?", "J.K. Rowling");

  // Start the examination
  int i, j;
  for (i = 0; i < MAX_QUESTIONS; i++) {
    // Display the question
    printf("%s\n", tail->question);

    // Get the candidate's answer
    char answer[20];
    scanf("%s", answer);

    // Check if the answer is correct
    if (strcmp(answer, tail->answer) == 0) {
      // Award points to the candidate
      head->score++;
    }

    // Move to the next question
    tail = tail->next;
  }

  // Print the final scores
  for (j = 0; j < MAX_CANDIDATES; j++) {
    printf("%s: %d\n", head->name, head->score);
    head = head->next;
  }

  return 0;
}