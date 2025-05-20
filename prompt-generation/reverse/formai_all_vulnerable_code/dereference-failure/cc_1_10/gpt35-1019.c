//FormAI DATASET v1.0 Category: Periodic Table Quiz ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to print the periodic table with symbols and random atomic numbers
void printPeriodicTable(char symbols[][3], int numbers[]) {
    printf("\n=========PERIODIC TABLE=========\n\n");
    for (int i = 0; i < 9; i++) {
        printf("%s\t\t", symbols[i]);
    }
    printf("\n");
    for (int i = 0; i < 9; i++) {
        printf("%d\t\t", numbers[i]);
    }
    printf("\n");
}

// Function to generate random atomic numbers
void generateRandomNumbers(int numbers[]) {
    srand(time(NULL));
    for (int i = 0; i < 9; i++) {
        numbers[i] = rand() % 20 + 1;
    }
}

// Quiz function to ask user questions about the periodic table
void runQuiz(char symbols[][3], int numbers[]) {
    int score = 0;
    char answer[3];
    for (int i = 0; i < 9; i++) {
        printf("What is the atomic number of %s?\n", symbols[i]);
        scanf("%s", answer);
        if (atoi(answer) == numbers[i]) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Incorrect. The answer is %d.\n", numbers[i]);
        }
    }
    printf("You scored %d out of 9.\n", score);
    if (score == 9) {
        printf("Congratulations, you are a true chemistry nerd!\n");
    } else if (score >= 6) {
        printf("Not bad, you have some knowledge about the periodic table.\n");
    } else {
        printf("You need to study more.\n");
    }
}

int main() {
    char symbols[9][3] = {
        "H", "He", "Li", "Be", "B", "C", "N", "O", "F"
    };
    int numbers[9];
    
    // Generate and print random atomic numbers
    generateRandomNumbers(numbers);
    printPeriodicTable(symbols, numbers);
    
    char choice;
    printf("\nDo you want to take the periodic table quiz? (y/n)\n");
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        runQuiz(symbols, numbers);
    } else {
        printf("Okay, goodbye!\n");
    }
    
    return 0;
}