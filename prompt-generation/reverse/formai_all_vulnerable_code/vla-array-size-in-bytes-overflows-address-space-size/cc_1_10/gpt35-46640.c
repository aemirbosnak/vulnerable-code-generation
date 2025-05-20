//FormAI DATASET v1.0 Category: Table Game ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // initialize variables
  int players, target, score = 0, roll, turnScore = 0, currentPlayer = 1, won = 0, invalid = 0;
  char input;

  // get number of players and target score from user
  printf("Welcome to the Dice Game!\n");
  printf("Enter number of players: ");
  scanf("%d", &players);
  printf("Enter target score: ");
  scanf("%d", &target);

  // initialize players' scores
  int playerScores[players];
  for (int i = 0; i < players; i++) {
    playerScores[i] = 0;
  }

  // seed the random number generator
  srand(time(NULL));

  // loop until a player has won the game
  while (!won) {

    // display current player's turn
    printf("\nPlayer %d's turn:\n", currentPlayer);

    // loop for each turn
    do {

      // roll the dice and display result
      roll = rand() % 6 + 1;
      printf("You rolled a %d\n", roll);

      // if roll is 1, end turn and reset turn score
      if (roll == 1) {
        turnScore = 0;
        printf("Turn over! You scored 0 points\n");
        break;
      }
      else {
        // add roll to turn score
        turnScore += roll;
      }

      // display turn score and ask player if they want to roll again or end turn
      printf("Turn score: %d\n", turnScore);
      printf("Roll again? (y/n): ");
      scanf(" %c", &input);

      // if player enters anything other than y or n, display error message and ask again
      while (input != 'y' && input != 'n') {
        printf("Invalid input! Enter y or n: ");
        scanf(" %c", &input);
        invalid = 1;
      }
      if (invalid) {
        invalid = 0;
        continue;
      }
    } while (input == 'y');

    // add turn score to player's total score
    score = playerScores[currentPlayer - 1];
    score += turnScore;
    playerScores[currentPlayer - 1] = score;

    // display player's total score
    printf("Total score: %d\n", score);

    // check if player has won the game
    if (score >= target) {
      printf("Congratulations! Player %d has won the game!\n", currentPlayer);
      won = 1;
      break;
    }

    // reset turn score and switch to next player's turn
    turnScore = 0;
    if (currentPlayer == players) {
      currentPlayer = 1;
    }
    else {
      currentPlayer++;
    }
  }

  return 0;
}