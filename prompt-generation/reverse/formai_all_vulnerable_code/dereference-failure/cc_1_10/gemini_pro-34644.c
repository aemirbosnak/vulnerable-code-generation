//GEMINI-pro DATASET v1.0 Category: Dice Roller ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DICE 100
#define MAX_SIDES 1000

struct die {
  int sides;
  int roll;
};

struct dice_bag {
  struct die dice[MAX_DICE];
  int num_dice;
};

void roll_dice(struct dice_bag *bag) {
  for (int i = 0; i < bag->num_dice; i++) {
    bag->dice[i].roll = rand() % bag->dice[i].sides + 1;
  }
}

int sum_dice(struct dice_bag *bag) {
  int sum = 0;
  for (int i = 0; i < bag->num_dice; i++) {
    sum += bag->dice[i].roll;
  }
  return sum;
}

void print_dice(struct dice_bag *bag) {
  for (int i = 0; i < bag->num_dice; i++) {
    printf("Die %d: %d\n", i + 1, bag->dice[i].roll);
  }
}

int main(int argc, char **argv) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <num_dice> <num_sides>\n", argv[0]);
    return 1;
  }

  int num_dice = atoi(argv[1]);
  int num_sides = atoi(argv[2]);

  if (num_dice <= 0 || num_dice > MAX_DICE) {
    fprintf(stderr, "Error: Invalid number of dice (%d)\n", num_dice);
    return 1;
  }

  if (num_sides <= 1 || num_sides > MAX_SIDES) {
    fprintf(stderr, "Error: Invalid number of sides (%d)\n", num_sides);
    return 1;
  }

  struct dice_bag bag;
  bag.num_dice = num_dice;

  for (int i = 0; i < num_dice; i++) {
    bag.dice[i].sides = num_sides;
  }

  srand(time(NULL));
  roll_dice(&bag);
  print_dice(&bag);
  printf("Total: %d\n", sum_dice(&bag));

  return 0;
}