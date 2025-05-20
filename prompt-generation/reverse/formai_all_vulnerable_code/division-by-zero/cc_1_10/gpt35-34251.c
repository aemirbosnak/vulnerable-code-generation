//FormAI DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides) {
  return rand() % sides + 1;
}

void print_dice(int roll) {
  switch (roll) {
    case 1:
      printf("_________\n");
      printf("|       |\n");
      printf("|   *   |\n");
      printf("|       |\n");
      printf("---------\n");
      break;
    case 2:
      printf("_________\n");
      printf("|     * |\n");
      printf("|       |\n");
      printf("|*     *|\n");
      printf("---------\n");
      break;
    case 3:
      printf("_________\n");
      printf("|     * |\n");
      printf("|   *   |\n");
      printf("|*_____*|\n");
      printf("---------\n");
      break;
    case 4:
      printf("_________\n");
      printf("|*    * |\n");
      printf("|       |\n");
      printf("|*_____*|\n");
      printf("---------\n");
      break;
    case 5:
      printf("_________\n");
      printf("|*    * |\n");
      printf("|   *   |\n");
      printf("|*_____*|\n");
      printf("---------\n");
      break;
    case 6:
      printf("_________\n");
      printf("|*_____*|\n");
      printf("|*    * |\n");
      printf("|*_____*|\n");
      printf("---------\n");
      break;
  }
}

int main() {
  srand(time(0));
  int sides, num_rolls, i, roll;
  
  printf("Welcome to the Dice Roller!\n");
  printf("How many sides does your die have? ");
  scanf("%d", &sides);

  printf("How many times would you like to roll the die? ");
  scanf("%d", &num_rolls);
  
  for (i = 0; i < num_rolls; i++) {
    roll = roll_dice(sides);
    printf("Roll %d: ", i + 1);
    print_dice(roll);
  }
  
  printf("Thanks for using the Dice Roller!\n");
  
  return 0;
}