//FormAI DATASET v1.0 Category: Math exercise ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed
    
    int num1, num2, operator, answer, user_answer, num_correct = 0;
    char operators[4] = {'+', '-', '*', '/'};
    
    printf("Welcome to the Math Exercise program!\n");
    printf("You will be presented with 10 C Math problems to solve.\n");
    printf("Let's get started!\n\n");
    
    for(int i=1; i<=10; i++) {
        num1 = rand() % 101; // generate random number between 0 and 100
        num2 = rand() % 101;
        operator = rand() % 4;
        printf("Question %d: %d %c %d = ", i, num1, operators[operator], num2);
        
        switch(operators[operator]) {
            case '+':
                answer = num1 + num2;
                break;
            case '-':
                answer = num1 - num2;
                break;
            case '*':
                answer = num1 * num2;
                break;
            case '/':
                answer = num1 / num2;
                break;
        }
        
        scanf("%d", &user_answer);
        
        if(user_answer == answer) {
            printf("Correct!\n");
            num_correct++; // increment correct answers
        } else {
            printf("Incorrect. The answer was %d\n", answer);
        }
    }
    
    printf("\nCongratulations! You have completed the Math Exercise program.\n");
    printf("You answered %d out of 10 questions correctly.\n", num_correct);
    
    return 0;
}