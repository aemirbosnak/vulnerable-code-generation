//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void printWelcomeMessage() {
    printf("Welcome to the Adventure of Divider the Brave!\n");
    printf("Today, Divider will attempt to divide two numbers,**but beware** of the treacherous zero!\n");
}

void printFarewellMessage() {
    printf("Thank you for joining the Adventure of Divider the Brave.\n");
    printf("Until next time, may your numbers be ever in your favor!\n");
}

void checkDivision(int numerator, int denominator) {
    if (denominator == 0) {
        fprintf(stderr, "Oh no! Divider the Brave stumbled upon Zero: the treacherous villain!\n");
        fprintf(stderr, "Division by zero is not allowed! \n");
        fprintf(stderr, "Error number: %d. Error message: %s\n", errno, strerror(errno));
        exit(EXIT_FAILURE);
    }
}

double safeDivision(int numerator, int denominator) {
    checkDivision(numerator, denominator);
    return (double)numerator / (double)denominator;
}

void askForInput(int *numerator, int *denominator) {
    char input[MAX_INPUT_LENGTH];
    
    printf("Enter the numerator: ");
    fgets(input, sizeof(input), stdin);
    *numerator = atoi(input);

    printf("Enter the denominator: ");
    fgets(input, sizeof(input), stdin);
    *denominator = atoi(input);
}

int main() {
    int numerator, denominator;
    double result;

    printWelcomeMessage();

    while (1) {
        askForInput(&numerator, &denominator);
        result = safeDivision(numerator, denominator);
        printf("Divider the Brave triumphantly computes: %d / %d = %.2f!\n", numerator, denominator, result);
        
        char choice[MAX_INPUT_LENGTH];
        printf("Would you like to perform another division? (yes/no): ");
        fgets(choice, sizeof(choice), stdin);
        
        if (strncmp(choice, "no", 2) == 0) {
            printf("Divider the Brave returns home!\n");
            break;
        } else if (strncmp(choice, "yes", 3) != 0) {
            fprintf(stderr, "That choice is not recognized, but Divider will march on!\n");
        }
    }

    printFarewellMessage();
    return 0;
}