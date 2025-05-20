//FormAI DATASET v1.0 Category: Math exercise ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random numbers between min and max
int generateRandomNumber(int min, int max) {
    int num = (rand() % (max - min + 1)) + min;
    return num;
}

int main() {
    srand(time(NULL)); // Set the seed for random number generator
    
    int option;
    printf("Welcome to the Math Exercise program!\n");
    printf("Choose an option from below:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n");
    scanf("%d", &option);
    
    int min, max, num1, num2, answer, userAnswer;
    float answerFloat, userAnswerFloat;
    switch(option) {
        case 1:
            printf("You chose Addition.\n");
            printf("Enter the minimum and maximum values for the numbers to be added:\n");
            scanf("%d %d", &min, &max);
            num1 = generateRandomNumber(min, max);
            num2 = generateRandomNumber(min, max);
            answer = num1 + num2;
            printf("What is the sum of %d and %d?\n", num1, num2);
            scanf("%d", &userAnswer);
            if(userAnswer == answer) {
                printf("Congratulations! Your answer is correct!\n");
            }
            else {
                printf("Oops! Your answer is incorrect. The correct answer is %d.\n", answer);
            }
            break;
        case 2:
            printf("You chose Subtraction.\n");
            printf("Enter the minimum and maximum values for the numbers to be subtracted:\n");
            scanf("%d %d", &min, &max);
            num1 = generateRandomNumber(min, max);
            num2 = generateRandomNumber(min, max);
            answer = num1 - num2;
            printf("What is the result of %d minus %d?\n", num1, num2);
            scanf("%d", &userAnswer);
            if(userAnswer == answer) {
                printf("Congratulations! Your answer is correct!\n");
            }
            else {
                printf("Oops! Your answer is incorrect. The correct answer is %d.\n", answer);
            }
            break;
        case 3:
            printf("You chose Multiplication.\n");
            printf("Enter the minimum and maximum values for the numbers to be multiplied:\n");
            scanf("%d %d", &min, &max);
            num1 = generateRandomNumber(min, max);
            num2 = generateRandomNumber(min, max);
            answer = num1 * num2;
            printf("What is the product of %d and %d?\n", num1, num2);
            scanf("%d", &userAnswer);
            if(userAnswer == answer) {
                printf("Congratulations! Your answer is correct!\n");
            }
            else {
                printf("Oops! Your answer is incorrect. The correct answer is %d.\n", answer);
            }
            break;
        case 4:
            printf("You chose Division.\n");
            printf("Enter the minimum and maximum values for the dividend:\n");
            scanf("%d %d", &min, &max);
            num1 = generateRandomNumber(min, max);
            printf("Enter the minimum and maximum values for the divisor:\n");
            scanf("%d %d", &min, &max);
            do {
                num2 = generateRandomNumber(min, max);
            } while(num2 == 0); // Ensure that the divisor is not 0
            answerFloat = (float)num1 / num2;
            printf("What is the quotient of %d divided by %d, rounded to 2 decimal places?\n", num1, num2);
            scanf("%f", &userAnswerFloat);
            if(userAnswerFloat == answerFloat) {
                printf("Congratulations! Your answer is correct!\n");
            }
            else {
                printf("Oops! Your answer is incorrect. The correct answer is %.2f.\n", answerFloat);
            }
            break;
        default:
            printf("Invalid option selected.\n");
    }
    
    return 0;
}