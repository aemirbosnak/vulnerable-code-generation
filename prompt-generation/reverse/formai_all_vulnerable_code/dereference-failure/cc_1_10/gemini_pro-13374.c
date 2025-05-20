//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random number between min and max (inclusive)
int random_number(int min, int max) {
  return rand() % (max - min + 1) + min;
}

// Function to shuffle an array of integers
void shuffle_array(int *array, int length) {
  for (int i = 0; i < length; i++) {
    int random_index = random_number(i, length - 1);
    int temp = array[i];
    array[i] = array[random_index];
    array[random_index] = temp;
  }
}

// Function to create a new game board
int *create_game_board(int size) {
  // Allocate memory for the game board
  int *game_board = malloc(sizeof(int) * size * size);
  if (game_board == NULL) {
    perror("Error allocating memory for game board");
    exit(1);
  }

  // Generate a list of unique numbers
  int *numbers = malloc(sizeof(int) * size * size);
  if (numbers == NULL) {
    perror("Error allocating memory for numbers");
    exit(1);
  }
  for (int i = 0; i < size * size; i++) {
    numbers[i] = i;
  }

  // Shuffle the numbers
  shuffle_array(numbers, size * size);

  // Copy the numbers to the game board
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      game_board[i * size + j] = numbers[i * size + j];
    }
  }

  // Free the memory allocated for the numbers
  free(numbers);

  return game_board;
}

// Function to print the game board
void print_game_board(int *game_board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      printf("%d ", game_board[i * size + j]);
    }
    printf("\n");
  }
}

// Function to get the user's input
int get_user_input(int size) {
  int input;
  while (1) {
    printf("Enter a number between 1 and %d: ", size * size);
    scanf("%d", &input);
    if (input >= 1 && input <= size * size) {
      return input;
    } else {
      printf("Invalid input. Please try again.\n");
    }
  }
}

// Function to check if the user has won the game
int check_win(int *game_board, int size) {
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (game_board[i * size + j] != i * size + j) {
        return 0;
      }
    }
  }
  return 1;
}

// Function to play the game
void play_game(int size) {
  // Create the game board
  int *game_board = create_game_board(size);

  // Print the game board
  print_game_board(game_board, size);

  // Get the user's input
  int input1 = get_user_input(size);
  int input2 = get_user_input(size);

  // Swap the two numbers on the game board
  int temp = game_board[input1 - 1];
  game_board[input1 - 1] = game_board[input2 - 1];
  game_board[input2 - 1] = temp;

  // Print the game board
  print_game_board(game_board, size);

  // Check if the user has won the game
  if (check_win(game_board, size)) {
    printf("Congratulations! You won the game.\n");
  } else {
    printf("Sorry, you lost the game.\n");
  }

  // Free the memory allocated for the game board
  free(game_board);
}

int main() {
  // Seed the random number generator
  srand(time(NULL));

  // Get the size of the game board from the user
  int size;
  while (1) {
    printf("Enter the size of the game board (between 2 and 10): ");
    scanf("%d", &size);
    if (size >= 2 && size <= 10) {
      break;
    } else {
      printf("Invalid input. Please try again.\n");
    }
  }

  // Play the game
  play_game(size);

  return 0;
}