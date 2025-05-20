//FormAI DATASET v1.0 Category: Math exercise ; Style: lively
// Welcome to the Math Funhouse!
// Get ready for some wacky arithmetic exercises!
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Setting up the randomizer
    srand(time(NULL));
    
    // The first challenge: multiplication mania!
    int num1 = rand() % 10; // Pick a random number from 0 to 9
    int num2 = rand() % 10;
    printf("What is %d multiplied by %d?\n", num1, num2);
    int answer1;
    scanf("%d", &answer1);
    if (answer1 == num1 * num2) {
        printf("Correct! For the next round...\n");
    } else {
        printf("Sorry, that's incorrect. The answer was %d. Moving on...\n", num1 * num2);
    }
    
    // The second challenge: division derby!
    int num3 = rand() % 10 + 1; // Pick a random non-zero number from 1 to 10
    int num4 = rand() % 10 + 1;
    printf("What is %d divided by %d?\n", num3 * num4, num4);
    int answer2;
    scanf("%d", &answer2);
    if (answer2 == num3) {
        printf("Correct! For the next round...\n");
    } else {
        printf("Sorry, that's incorrect. The answer was %d. Moving on...\n", num3);
    }
    
    // The third challenge: addition adventure!
    int num5 = rand() % 50; // Pick a random number from 0 to 49
    int num6 = rand() % 50;
    printf("What is %d plus %d?\n", num5, num6);
    int answer3;
    scanf("%d", &answer3);
    if (answer3 == num5 + num6) {
        printf("Correct! For the next round...\n");
    } else {
        printf("Sorry, that's incorrect. The answer was %d. Moving on...\n", num5 + num6);
    }
    
    // The final challenge: subtraction station!
    int num7 = rand() % 100; // Pick a random number from 0 to 99
    int num8 = rand() % num7; // Pick a random number from 0 to num7 - 1 (so answer is always non-negative)
    printf("What is %d minus %d?\n", num7, num8);
    int answer4;
    scanf("%d", &answer4);
    if (answer4 == num7 - num8) {
        printf("Congratulations! You beat the Math Funhouse!\n");
    } else {
        printf("Sorry, that's incorrect. The answer was %d. Better luck next time!\n", num7 - num8);
    }
    
    return 0;
}