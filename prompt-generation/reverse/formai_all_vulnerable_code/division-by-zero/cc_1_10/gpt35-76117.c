//FormAI DATASET v1.0 Category: Math exercise ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, operator, answer, userAnswer;
    char operators[4] = {'+', '-', '*', '/'};
    int correct = 0;
    int totalQuestions = 0;
    
    srand(time(NULL)); //initialize random number generator
    
    printf("Welcome to the Math Exercise program!\n");
    printf("You will be given a random arithmetic problem to solve.\n");
    printf("Please answer the question and the program will grade your response.\n");
    
    while(totalQuestions < 10) {
        a = rand() % 100; //generate random number a
        b = rand() % 100; //generate random number b
        operator = rand() % 4; //choose random operator
        
        printf("\nQuestion %d:\n", totalQuestions+1);
        printf("%d %c %d = ", a, operators[operator], b); //print problem
        
        switch(operator) { //execute arithmetic operation
            case 0:
                answer = a + b;
                break;
            case 1:
                answer = a - b;
                break;
            case 2:
                answer = a * b;
                break;
            case 3:
                answer = a / b;
                break;
        }
        
        scanf("%d", &userAnswer); //get user input
        
        if(userAnswer == answer) { //compare user answer to correct answer
            printf("Correct! Good job.\n");
            correct++;
        }
        else {
            printf("Incorrect. The correct answer is %d.\n", answer);
        }
        
        totalQuestions++;
    }
    
    printf("\nYou have completed the exercise.\n");
    printf("You answered %d out of 10 questions correctly!\n", correct);
    
    return 0;
}