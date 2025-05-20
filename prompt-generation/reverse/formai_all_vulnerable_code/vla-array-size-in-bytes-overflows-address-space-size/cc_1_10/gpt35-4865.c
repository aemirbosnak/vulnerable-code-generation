//FormAI DATASET v1.0 Category: Table Game ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // Initialize random number generator
  srand(time(NULL));
  
  // Set up game variables
  int num_players = 0;
  
  // Get number of players
  printf("How many players are there?\n");
  scanf("%d", &num_players);
  
  // Initialize player scores
  int scores[num_players];
  for (int i = 0; i < num_players; i++) {
    scores[i] = 0;
  }
  
  // Print game instructions
  printf("Welcome to the Cryptic Table Game!\n");
  printf("The objective of the game is to accumulate as many points as possible by guessing the correct number.\n");
  printf("Each player will take turns guessing a number between 1 and 100.\n");
  printf("Whoever is closest to the actual number will earn points equal to the difference between their guess and the actual number.\n");
  
  // Play the game
  int round = 1;
  while (round <= 5) { // Play 5 rounds
    // Generate random number for this round
    int correct_number = rand() % 100 + 1;
    printf("\nRound %d: The correct number is between 1 and 100.\n", round);
    
    // Loop through each player's turn
    for (int i = 0; i < num_players; i++) {
      // Get player's guess
      int guess = 0;
      printf("Player %d: Enter your guess.\n", i+1);
      scanf("%d", &guess);
      
      // Calculate difference between guess and correct number
      int difference = abs(correct_number - guess);
      
      // Add difference to player's score
      scores[i] += difference;
      
      // Print message letting player know whether their guess was too high, too low, or correct
      if (guess < correct_number) {
        printf("Your guess was too low.\n");
      }
      else if (guess > correct_number) {
        printf("Your guess was too high.\n");
      }
      else {
        printf("Your guess was correct!\n");
      }
    }
    
    // Print round scores
    printf("\nRound %d scores:\n", round);
    for (int i = 0; i < num_players; i++) {
      printf("Player %d: %d points\n", i+1, scores[i]);
    }
    
    // Increment round number
    round++;
  }
  
  // Determine winner and print final scores
  int winner = 0;
  for (int i = 1; i < num_players; i++) {
    if (scores[i] > scores[winner]) {
      winner = i;
    }
  }
  printf("\nPlayer %d is the winner with %d total points!\n", winner+1, scores[winner]);
  
  return 0;
}