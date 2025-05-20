//GPT-4o-mini DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcomeMessage() {
    printf("🎲🎉 Welcome to the Fun Dice Roller! 🎉🎲\n");
    printf("Let's roll some dice and have a blast!\n");
    printf("=========================================\n");
}

int rollDice(int sides) {
    return (rand() % sides) + 1; // Rolls a dice with given sides
}

void showResult(int result) {
    printf("\n🎈 You've rolled a: %d 🎈\n", result);
    if (result == 1) {
        printf("Oops! It's a lucky one! 🥲\n");
    } else if (result >= 2 && result <= 3) {
        printf("Not bad! You've got a low score! 💖\n");
    } else if (result >= 4 && result <= 5) {
        printf("Yay! That's a decent roll! 😃\n");
    } else {
        printf("Wow! What a roll! Perfecto! 🌟\n");
    }
}

void askPlayAgain() {
    char choice;
    printf("Would you like to roll again? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        main(); // Restart the program
    } else {
        printf("Thanks for playing! 🎈 Come back soon!\n");
    }
}

int main() {
    srand(time(NULL)); // Seed random number generator

    printWelcomeMessage();

    int diceCount, sides;
    printf("How many dice would you like to roll? ");
    scanf("%d", &diceCount);
    
    printf("How many sides does each die have? ");
    scanf("%d", &sides);
    
    printf("\nYou will be rolling %d dice with %d sides each!\n", diceCount, sides);
    
    int totalScore = 0;

    for (int i = 1; i <= diceCount; i++) {
        printf("\nRolling dice %d... ", i);
        int result = rollDice(sides);
        showResult(result);
        totalScore += result;
    }

    printf("\n🎊 Your total score is: %d 🎊\n", totalScore);

    if (totalScore <= diceCount) {
        printf("Keep practicing! You'll get better! 😊\n");
    } else if (totalScore <= diceCount * 3) {
        printf("You're doing great! 🌈\n");
    } else {
        printf("You're on fire! 🔥 Keep rocking! \n");
    }

    printf("=========================================\n");
    askPlayAgain();

    return 0;
}