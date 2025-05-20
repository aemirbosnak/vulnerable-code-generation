//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the bingo card
#define CARD_SIZE 5

// Define the number of rows and columns in the bingo card
#define ROWS 5
#define COLS 5

// Define the maximum number of bingo cards
#define MAX_CARDS 10

// Define the maximum number of balls drawn
#define MAX_BALLS 75

// Define the bingo card
int bingoCard[ROWS][COLS];

// Define the array of drawn balls
int drawnBalls[MAX_BALLS];

// Define the number of drawn balls
int numDrawnBalls = 0;

// Define the number of cards won
int numCardsWon = 0;

// Generate a random bingo card
void generateCard(int card[ROWS][COLS]) {
  int i, j;
  
  // Initialize the card to all zeros
  for (i = 0; i < ROWS; i++) {
    for (j = 0; j < COLS; j++) {
      card[i][j] = 0;
    }
  }
  
  // Generate 25 random numbers for the card
  for (i = 0; i < 25; i++) {
    int num = (rand() % 75) + 1;
    
    // Make sure the number is not already in the card
    while (card[num / ROWS][num % COLS] != 0) {
      num = (rand() % 75) + 1;
    }
    
    // Add the number to the card
    card[num / ROWS][num % COLS] = num;
  }
}

// Print a bingo card
void printCard(int card[ROWS][COLS]) {
  int i, j;
  
  // Print the top of the card
  printf("   B  I  N  G  O\n");
  printf("  +---+---+---+---+---+\n");
  
  // Print the rows of the card
  for (i = 0; i < ROWS; i++) {
    printf("  | ");
    
    // Print the columns of the card
    for (j = 0; j < COLS; j++) {
      if (card[i][j] == 0) {
        printf("  ");
      } else {
        printf("%2d ", card[i][j]);
      }
    }
    
    // Print the end of the row
    printf(" |\n");
  }
  
  // Print the bottom of the card
  printf("  +---+---+---+---+---+\n");
}

// Draw a ball
int drawBall() {
  int ball;
  
  // Generate a random number between 1 and 75
  ball = (rand() % 75) + 1;
  
  // Return the ball
  return ball;
}

// Check if a card has won
int checkCard(int card[ROWS][COLS]) {
  int i, j;
  
  // Check the rows
  for (i = 0; i < ROWS; i++) {
    int count = 0;
    
    // Count the number of marked numbers in the row
    for (j = 0; j < COLS; j++) {
      if (card[i][j] == -1) {
        count++;
      }
    }
    
    // If all the numbers in the row are marked, the card has won
    if (count == COLS) {
      return 1;
    }
  }
  
  // Check the columns
  for (j = 0; j < COLS; j++) {
    int count = 0;
    
    // Count the number of marked numbers in the column
    for (i = 0; i < ROWS; i++) {
      if (card[i][j] == -1) {
        count++;
      }
    }
    
    // If all the numbers in the column are marked, the card has won
    if (count == ROWS) {
      return 1;
    }
  }
  
  // Check the diagonals
  int count1 = 0;
  int count2 = 0;
  
  // Count the number of marked numbers in the first diagonal
  for (i = 0; i < ROWS; i++) {
    if (card[i][i] == -1) {
      count1++;
    }
  }
  
  // Count the number of marked numbers in the second diagonal
  for (i = 0; i < ROWS; i++) {
    if (card[i][ROWS - i - 1] == -1) {
      count2++;
    }
  }
  
  // If all the numbers in either diagonal are marked, the card has won
  if (count1 == ROWS || count2 == ROWS) {
    return 1;
  }
  
  // The card has not won
  return 0;
}

// Play the game
void playGame() {
  int i, j;
  int ball;
  
  // Generate the bingo cards
  for (i = 0; i < MAX_CARDS; i++) {
    generateCard(bingoCard[i]);
  }
  
  // Draw balls until all the cards have won
  while (numCardsWon < MAX_CARDS) {
    // Draw a ball
    ball = drawBall();
    
    // Add the ball to the array of drawn balls
    drawnBalls[numDrawnBalls++] = ball;
    
    // Print the ball
    printf("Ball drawn: %d\n", ball);
    
    // Check each card for a win
    for (i = 0; i < MAX_CARDS; i++) {
      // Check if the card has won
      if (checkCard(bingoCard[i])) {
        // The card has won
        numCardsWon++;
        
        // Print the winning card
        printf("Card %d has won!\n", i + 1);
        printCard(bingoCard[i]);
      }
    }
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand(time(NULL));
  
  // Play the game
  playGame();
  
  return 0;
}