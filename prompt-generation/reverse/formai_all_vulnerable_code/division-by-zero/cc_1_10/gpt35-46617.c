//FormAI DATASET v1.0 Category: Math exercise ; Style: Alan Touring
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    
    srand(time(0)); //initialize random number generator
    
    int num1, num2, operator, answer, user_answer;
    char operators[4] = {'+','-','*','/'};
    int streak = 0; //user's current streak of correct answers
    int high_score = 0; //user's highest streak of correct answers
    
    printf("Welcome to the Math Exercise Program!\n");
    printf("----------------------------\n");
    printf("Instructions:\n");
    printf("Answer the following math problems using the correct operator (+ - * /):\n");
    
    while(1){ //loop to continually generate math problems
        
        num1 = rand()%101; //generate random numbers between 0 and 100
        num2 = rand()%101;
        operator = rand()%4; //generate random operator
        
        printf("\n%d %c %d = ", num1, operators[operator], num2);
        scanf("%d", &user_answer);
        
        if(operators[operator] == '+'){
            answer = num1 + num2;
        }
        else if(operators[operator] == '-'){
            answer = num1 - num2;
        }
        else if(operators[operator] == '*'){
            answer = num1 * num2;
        }
        else if(operators[operator] == '/'){
            answer = num1 / num2;
        }
        
        if(user_answer == answer){
            streak++; //increase user's streak of correct answers
            printf("Correct! Your current streak is %d\n", streak);
        }
        else{
            printf("Incorrect. Your streak of correct answers ended at %d\n", streak);
            if(streak > high_score){
                high_score = streak; //update user's high score if current streak is higher
            }
            streak = 0; //reset streak
        }
        
        printf("\nCurrent High Score: %d", high_score);
    }
    
    return 0;
}