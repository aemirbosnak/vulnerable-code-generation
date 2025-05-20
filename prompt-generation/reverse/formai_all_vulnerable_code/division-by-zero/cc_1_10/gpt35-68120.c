//FormAI DATASET v1.0 Category: Math exercise ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void add(int a, int b);
void subtract(int a, int b);
void multiply(int a, int b);
void divide(int a, int b);

// main function
int main() {
    int choice;
    int num1, num2;
    srand(time(0)); // to generate random numbers

    printf("Welcome to Math Exercise Program!\n\n");
    printf("What would you like to do?\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("Please enter your choice (1-4): ");
    scanf("%d", &choice);

    // switch case depending on the user's choice
    switch (choice) {
        case 1:
            num1 = rand() % 100;
            num2 = rand() % 100;
            add(num1, num2);
            break;
        case 2:
            num1 = rand() % 100;
            num2 = rand() % 100;
            subtract(num1, num2);
            break;
        case 3:
            num1 = rand() % 10;
            num2 = rand() % 10;
            multiply(num1, num2);
            break;
        case 4:
            num1 = rand() % 100;
            num2 = rand() % 10;
            divide(num1, num2);
            break;
        default:
            printf("Invalid choice! Please enter a number between 1 and 4.\n");
            break;
    }

    return 0;
}

// function to perform addition
void add(int a, int b) {
    int answer;
    printf("What is %d + %d?\n", a, b);
    scanf("%d", &answer);

    if (answer == a + b) {
        printf("Correct! %d + %d = %d\n", a, b, answer);
    } else {
        printf("Sorry, the correct answer is %d. Keep practicing!\n", a + b);
    }
}

// function to perform subtraction
void subtract(int a, int b) {
    int answer;
    printf("What is %d - %d?\n", a, b);
    scanf("%d", &answer);

    if (answer == a - b) {
        printf("Correct! %d - %d = %d\n", a, b, answer);
    } else {
        printf("Sorry, the correct answer is %d. Keep practicing!\n", a - b);
    }
}

// function to perform multiplication
void multiply(int a, int b) {
    int answer;
    printf("What is %d * %d?\n", a, b);
    scanf("%d", &answer);

    if (answer == a * b) {
        printf("Correct! %d * %d = %d\n", a, b, answer);
    } else {
        printf("Sorry, the correct answer is %d. Keep practicing!\n", a * b);
    }
}

// function to perform division
void divide(int a, int b) {
    int answer;
    printf("What is %d / %d (rounded to the nearest integer)?\n", a, b);
    scanf("%d", &answer);

    if (answer == a / b) {
        printf("Correct! %d / %d = %d\n", a, b, answer);
    } else {
        printf("Sorry, the correct answer is %d. Keep practicing!\n", a / b);
    }
}