//MISTRAL-7B DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 20
#define MIN_SIDE 1
#define MAX_SIDE 6
#define DICE_POOL_SIZE 100

// Paranoid function to seed random number generator
void seed_rng(void) {
  if (!time(NULL)) {
    fprintf(stderr, "Failed to get current time, using a static seed instead.\n");
    srand((unsigned)1);
  } else {
    srand(time(NULL));
  }
}

// Function to roll a dice
int roll_dice(int num_dice, int sides) {
  if (num_dice > MAX_DICE || sides < MIN_SIDE || sides > MAX_SIDE) {
    fprintf(stderr, "Invalid number of dice or sides!\n");
    exit(EXIT_FAILURE);
  }

  int dice_roll[num_dice];
  for (int i = 0; i < num_dice; i++) {
    dice_roll[i] = rand() % sides + 1;
  }

  return dice_roll;
}

// Function to print the dice rolls
void print_dice(int *dice, int num_dice) {
  if (num_dice > DICE_POOL_SIZE) {
    fprintf(stderr, "Too many dice to print!\n");
    exit(EXIT_FAILURE);
  }

  printf("Rolling %d dice with %d sides each:\n", num_dice, MIN_SIDE);
  for (int i = 0; i < num_dice; i++) {
    printf("Dice %d: %d\n", i + 1, dice[i]);
  }
}

int main(void) {
  seed_rng();

  int num_dice, sides;
  printf("Enter the number of dice: ");
  scanf("%d", &num_dice);
  printf("Enter the number of sides on each die: ");
  scanf("%d", &sides);

  if (num_dice <= 0 || sides <= 0) {
    fprintf(stderr, "Invalid input, please enter a positive number for dice and sides.\n");
    exit(EXIT_FAILURE);
  }

  int *dice_roll = calloc(num_dice, sizeof(int));

  if (dice_roll == NULL) {
    fprintf(stderr, "Failed to allocate memory for dice rolls.\n");
    exit(EXIT_FAILURE);
  }

  int *rolled_dice = roll_dice(num_dice, sides);

  if (rolled_dice == NULL) {
    free(dice_roll);
    fprintf(stderr, "Failed to roll dice.\n");
    exit(EXIT_FAILURE);
  }

  print_dice(rolled_dice, num_dice);

  free(rolled_dice);
  free(dice_roll);

  return EXIT_SUCCESS;
}