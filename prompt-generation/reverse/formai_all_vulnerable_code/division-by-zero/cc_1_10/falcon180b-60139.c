//Falcon-180B DATASET v1.0 Category: Math exercise ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function Prototypes
int randomNumber(int min, int max);
int sumOfDigits(int num);

int main()
{
    int num1, num2, sum;
    char choice;
    printf("Welcome to the Math Exercise Program!\n");
    printf("Please choose an exercise:\n");
    printf("1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Random Number\n");
    scanf("%c", &choice);
    switch(choice)
    {
        case '1':
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            sum = num1 + num2;
            printf("The sum of %d and %d is %d.\n", num1, num2, sum);
            break;
        case '2':
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            sum = num1 - num2;
            printf("The difference between %d and %d is %d.\n", num1, num2, sum);
            break;
        case '3':
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            sum = num1 * num2;
            printf("The product of %d and %d is %d.\n", num1, num2, sum);
            break;
        case '4':
            printf("Enter two numbers:\n");
            scanf("%d %d", &num1, &num2);
            if(num2 == 0)
            {
                printf("Cannot divide by zero!\n");
            }
            else
            {
                sum = num1 / num2;
                printf("The quotient of %d and %d is %d.\n", num1, num2, sum);
            }
            break;
        case '5':
            printf("Enter the minimum and maximum values:\n");
            scanf("%d %d", &num1, &num2);
            sum = randomNumber(num1, num2);
            printf("The sum of %d and %d is %d.\n", num1, num2, sum);
            break;
        default:
            printf("Invalid choice!\n");
    }
    return 0;
}

int randomNumber(int min, int max)
{
    int num;
    srand(time(NULL));
    num = rand() % (max - min + 1) + min;
    return num;
}

int sumOfDigits(int num)
{
    int sum = 0;
    while(num!= 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}