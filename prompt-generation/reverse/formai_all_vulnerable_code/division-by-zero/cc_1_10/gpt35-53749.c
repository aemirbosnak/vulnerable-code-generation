//FormAI DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number within a range
int generateRandomNum(int min, int max) {
    return ((rand() % (max - min + 1)) + min);
}

// function to perform arithmetic operation based on given operator
double performOperation(double num1, double num2, char operator) {
    double result;
    switch(operator) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            printf("Invalid/Unsupported Operator\n");
            result = 0.0;
    }
    return result;
}

int main() {
    int num1, num2, i;
    char operator;
    unsigned int seed;

    // get user input for minimum and maximum range for operand numbers
    int min_range, max_range;
    printf("Enter minimum range for operand numbers: ");
    scanf("%d", &min_range);
    printf("Enter maximum range for operand numbers: ");
    scanf("%d", &max_range);

    // get user input for number of math exercises to generate
    int num_exercise;
    printf("Enter number of math exercises to generate: ");
    scanf("%d", &num_exercise);

    // get user input for seed value for random number generator
    printf("Enter seed value for random number generator: ");
    scanf("%u", &seed);

    // initialize random number generator
    srand(seed);

    // generate and output math exercises
    for(i=1; i<=num_exercise; i++) {
        // generate random numbers within given range
        num1 = generateRandomNum(min_range, max_range);
        num2 = generateRandomNum(min_range, max_range);

        // generate random arithmetic operator
        operator = generateRandomNum(0, 3) == 0 ? '+' : generateRandomNum(0, 2) == 0 ? '-' : generateRandomNum(0, 1) == 0 ? '*' : '/';

        // output math exercise
        printf("%d. %d %c %d = ", i, num1, operator, num2);

        // get user input for answer
        double answer;
        scanf("%lf", &answer);

        // calculate and output result
        double result = performOperation(num1, num2, operator);
        if(answer == result) {
            printf("CORRECT\n");
        }
        else {
            printf("WRONG (Right answer is %.2lf)\n", result);
        }
    }

    return 0;
}