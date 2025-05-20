//Falcon-180B DATASET v1.0 Category: Dice Roller ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, sides, i, j;
    int diceArray[100];
    int sum = 0;
    float average;
    int max = 0, min = 100;
    int maxIndex = 0, minIndex = 0;
    int count = 0;
    int maxCount = 0;
    int minCount = 0;

    srand(time(NULL));

    printf("Enter the number of dice: ");
    scanf("%d", &numDice);

    printf("Enter the number of sides on each dice: ");
    scanf("%d", &sides);

    for (i = 0; i < numDice; i++) {
        diceArray[i] = rand() % sides + 1;
        sum += diceArray[i];
        if (diceArray[i] > max) {
            max = diceArray[i];
            maxIndex = i;
        }
        if (diceArray[i] < min) {
            min = diceArray[i];
            minIndex = i;
        }
        if (diceArray[i] == count) {
            count++;
        } else {
            count = 1;
        }
        if (diceArray[i] > maxCount) {
            maxCount = diceArray[i];
        }
        if (diceArray[i] < minCount) {
            minCount = diceArray[i];
        }
    }

    printf("The sum of the dice rolls is: %d\n", sum);
    printf("The average of the dice rolls is: %.2f\n", (float) sum / numDice);
    printf("The highest roll was: %d\n", max);
    printf("The lowest roll was: %d\n", min);
    printf("The most frequent roll was: %d\n", count);
    printf("The highest frequency was: %d\n", maxCount);
    printf("The lowest frequency was: %d\n", minCount);

    return 0;
}