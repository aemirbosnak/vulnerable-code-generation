//FormAI DATASET v1.0 Category: Math exercise ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QCOUNT 10
#define MAXQUESTIONS 25
#define MAXNAMELEN 20

struct Participant {
  char name[MAXNAMELEN];
  int score;
};

void generateQuestions(int questions[][2], int qCount);
int askMathQuestions(int questions[][2], int qCount);
void printResults(struct Participant* participants, int n);

int main() {
  int questions[MAXQUESTIONS][2];
  int qCount = QCOUNT, round = 1, i, numParticipants;

  printf("*** Welcome to the Math Quiz Game! ***\n");
  printf("How many participants? ");
  scanf("%d", &numParticipants);

  struct Participant participants[numParticipants];

  for (i = 0; i < numParticipants; i++) {
    printf("Enter name for participant %d: ", i + 1);
    scanf("%s", participants[i].name);
    participants[i].score = 0;
  }

  while (1) {
    printf("\nStarting round %d...\n", round++);
    generateQuestions(questions, qCount);
    for (i = 0; i < numParticipants; i++) {
      printf("\n%s's turn\n", participants[i].name);
      participants[i].score += askMathQuestions(questions, qCount);
    }
    printResults(participants, numParticipants);
    printf("\nDo you want to play another round (y/n)? ");
    char playAgain;
    scanf(" %c", &playAgain);
    if (playAgain == 'n' || playAgain == 'N') {
      printf("\nThanks for playing the Math Quiz Game!\n");
      break;
    }
  }

  return 0;
}

void generateQuestions(int questions[][2], int qCount) {
  srand(time(NULL));
  int i;
  for (i = 0; i < qCount; i++) {
    int op = rand() % 2;
    questions[i][0] = rand() % 100;
    questions[i][1] = rand() % 100;
    if (op == 0) {
      printf("%d) %d + %d = ?\n", i+1, questions[i][0], questions[i][1]);
    } else {
      printf("%d) %d - %d = ?\n", i+1, questions[i][0], questions[i][1]);
    }
  }
}

int askMathQuestions(int questions[][2], int qCount) {
  int i, answer, correct = 0;
  for (i = 0; i < qCount; i++) {
    printf("\nQuestion %d: ", i+1);
    scanf("%d", &answer);
    if (answer == (questions[i][0] + questions[i][1])) {
      printf("  Correct!\n");
      correct++;
    } else {
      printf("  Wrong answer\n");
    }
  }
  return correct;
}

void printResults(struct Participant* participants, int n) {
  printf("\n*** Results ***\n");
  int i, maxScore = 0;
  for (i = 0; i < n; i++) {
    printf("%s: %d\n", participants[i].name, participants[i].score);
    if (participants[i].score > maxScore) {
      maxScore = participants[i].score;
    }
  }
  printf("The winner(s):\n");
  for (i = 0; i < n; i++) {
    if (participants[i].score == maxScore) {
      printf("%s\n", participants[i].name);
    }
  }
}