//FormAI DATASET v1.0 Category: Math exercise ; Style: energetic
#include<stdio.h>

int main() {
    int a,b,c;

    printf("Welcome to the Energizing Math Exercise Program!\n\n");

    printf("Enter the first number: ");
    scanf("%d",&a);

    printf("Enter the second number: ");
    scanf("%d",&b);

    printf("Enter the third number: ");
    scanf("%d",&c);

    printf("\n\n");

    printf("Let's get started!\n");
    printf("Question 1: What is %d times %d? \n",a,b);
    printf("Answer: ");
    int input1;
    scanf("%d",&input1);
    if(input1 == a*b) {
        printf("Correct! Great Job!\n\n");
    }
    else {
        printf("Oops! The correct answer is %d.\n\n",a*b);
    }

    printf("Question 2: What is %d divided by %d? \n",b,c);
    printf("Answer: ");
    int input2;
    scanf("%d",&input2);
    if(input2 == b/c) {
        printf("Correct! Well done!\n\n");
    }
    else {
        printf("Incorrect! The answer is %d.\n\n",b/c);
    }

    printf("Question 3: What is the remainder when %d is divided by %d? \n",a,c);
    printf("Answer: ");
    int input3;
    scanf("%d",&input3);
    if(input3 == a%c) {
        printf("Correct! Keep Going!\n\n");
    }
    else {
        printf("Wrong! The correct answer is %d.\n\n",a%c);
    }

    printf("Question 4: What is %d plus %d plus %d? \n",a,b,c);
    printf("Answer: ");
    int input4;
    scanf("%d",&input4);
    if(input4 == a+b+c) {
        printf("Spot on! You are amazing!\n\n");
    }
    else {
        printf("Sorry, the correct answer is %d.\n\n",a+b+c);
    }

    printf("That's the end of the program, congratulations on completing the Math Exercise! \n");
    return 0;
}