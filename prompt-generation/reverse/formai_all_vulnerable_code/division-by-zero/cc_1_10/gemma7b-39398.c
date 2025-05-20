//Gemma-7B DATASET v1.0 Category: Educational ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("CLS");
    printf("Welcome to the Crazy Calculator!");
    printf("\nPlease select an option:");
    printf("\n1. Addition");
    printf("\n2. Subtraction");
    printf("\n3. Multiplication");
    printf("\n4. Division");

    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            printf("Enter two numbers:");
            int num1, num2;
            scanf("%d %d", &num1, &num2);
            int result = num1 + num2;
            printf("The result is: %d", result);
            break;

        case 2:
            printf("Enter two numbers:");
            int num3, num4;
            scanf("%d %d", &num3, &num4);
            int result2 = num3 - num4;
            printf("The result is: %d", result2);
            break;

        case 3:
            printf("Enter two numbers:");
            int num5, num6;
            scanf("%d %d", &num5, &num6);
            int result3 = num5 * num6;
            printf("The result is: %d", result3);
            break;

        case 4:
            printf("Enter two numbers:");
            int num7, num8;
            scanf("%d %d", &num7, &num8);
            int result4 = num7 / num8;
            printf("The result is: %d", result4);
            break;

        default:
            printf("Invalid input!");
    }

    return 0;
}