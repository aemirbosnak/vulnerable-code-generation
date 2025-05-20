//Gemma-7B DATASET v1.0 Category: Temperature Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, t_choice, f_choice, c_choice, num;
    float f_temp, c_temp;

    // Server
    if (fork() == 0)
    {
        printf("Enter your choice:\n1. Convert Fahrenheit to Celsius\n2. Convert Celsius to Fahrenheit\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the temperature in Fahrenheit:");
                scanf("%f", &f_temp);
                c_temp = (f_temp - 32) * 5 / 9;
                printf("The temperature in Celsius is: %.2f", c_temp);
                break;

            case 2:
                printf("Enter the temperature in Celsius:");
                scanf("%f", &c_temp);
                f_temp = (c_temp * 9 / 5) + 32;
                printf("The temperature in Fahrenheit is: %.2f", f_temp);
                break;

            default:
                printf("Invalid choice");
        }

        exit(0);
    }

    // Client
    else
    {
        printf("Waiting for the server...");
        scanf("Enter the server's choice:");
        t_choice = atoi(stdin);

        switch (t_choice)
        {
            case 1:
                printf("Enter the temperature in Fahrenheit:");
                scanf("%f", &f_temp);
                c_temp = (f_temp - 32) * 5 / 9;
                printf("The temperature in Celsius is: %.2f", c_temp);
                break;

            case 2:
                printf("Enter the temperature in Celsius:");
                scanf("%f", &c_temp);
                f_temp = (c_temp * 9 / 5) + 32;
                printf("The temperature in Fahrenheit is: %.2f", f_temp);
                break;

            default:
                printf("Invalid choice");
        }
    }

    return 0;
}