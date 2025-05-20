//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int players, minProb, maxProb, probRange;
  int i, j, k, probCount, totalProbCount;
  float avgProb, playerAvgProb;
  srand(time(0));

  printf("Welcome to the Alien Invasion Probability Calculator!\n");
  printf("Enter the number of players: ");
  scanf("%d", &players);
  printf("Enter the minimum probability: ");
  scanf("%d", &minProb);
  printf("Enter the maximum probability: ");
  scanf("%d", &maxProb);
  
  probRange = maxProb - minProb + 1;

  int playerProb[players];

  printf("Calculating probabilities...\n");

  for (i = 0; i < players; i++) {
    playerProb[i] = (rand() % probRange) + minProb;
    printf("Player %d: %d%%\n", i+1, playerProb[i]);
  }

  totalProbCount = probRange * players;
  int probTable[probRange][players];

  for (i = 0; i < probRange; i++) {
    probCount = 0;
    for (j = 0; j < players; j++) {
      if (playerProb[j] == minProb + i) {
        probTable[i][j] = 1;
        probCount++;
      } else {
        probTable[i][j] = 0;
      }
    }

    printf("%d%%: ", minProb + i);
    for (k = 0; k < players; k++) {
      printf("%d ", probTable[i][k]);
    }
    printf("(%d)\n", probCount);
  }

  printf("Summary:\n");

  playerAvgProb = 0.0;
  for (i = 0; i < players; i++) {
    playerAvgProb += playerProb[i];
  }
  playerAvgProb /= players;
  printf("Average probability per player: %.2f%%\n", playerAvgProb);

  avgProb = 0.0;
  for (i = 0; i < probRange; i++) {
    probCount = 0;
    for (j = 0; j < players; j++) {
      if (probTable[i][j] == 1) {
        probCount++;
      }
    }
    avgProb += (float) probCount / players;
  }
  avgProb /= probRange;
  printf("Average number of players with given probability: %.2f\n", avgProb);

  return 0;
}