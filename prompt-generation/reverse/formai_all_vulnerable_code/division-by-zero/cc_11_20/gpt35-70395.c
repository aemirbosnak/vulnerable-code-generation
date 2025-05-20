//FormAI DATASET v1.0 Category: Arithmetic ; Style: curious
#include<stdio.h>
#include<math.h>

int main()
{
   int num1, num2, sum, diff, prod, quo, rem, max, min, gcd, lcm, fact, i, j, num, count;
   float pi, powr;

   printf("Hello! I am your curious arithmetic bot. Let's do some calculations.\n\n");

   printf("Enter the first number:");
   scanf("%d", &num1);
   printf("Enter the second number:");
   scanf("%d", &num2);

   sum = num1 + num2;
   diff = num1 - num2;
   prod = num1 * num2;
   
   if (num2 != 0)
   {
       quo = num1 / num2;
       rem = num1 % num2;
   }
   
   max = (num1 > num2) ? num1 : num2;
   min = (num1 < num2) ? num1 : num2;

   if(num1 == 0 || num2 == 0)
   {
       gcd = max;
       lcm = 0;
   }
   else
   {
       for(i = 1; i <= max; i++)
       {
           if(num1 % i == 0 && num2 % i == 0)
           {
               gcd = i;
           }
       }
    
       lcm = (num1 * num2) / gcd;
   }
   
   printf("\n\n----------------------- Results -----------------------\n\n");

   printf("Sum: %d\n", sum);
   printf("Difference: %d\n", diff);
   printf("Product: %d\n", prod);
   if(num2 != 0)
   {
       printf("Quotient: %d\n", quo);
       printf("Remainder: %d\n", rem);
   }
   else
   {
       printf("Cannot divide by Zero\n");
   }
   
   printf("Maximum: %d\n", max);
   printf("Minimum: %d\n", min);
   printf("GCD: %d\n", gcd);
   printf("LCM: %d\n", lcm);

   printf("\n\n----------------------- Extra Calculations -----------------------\n\n");

   printf("Enter a number for factorial calculation:");
   scanf("%d", &num);

   if(num < 0)
   {
       printf("Invalid Input. Please Enter a positive integer\n");
   }
   else
   {
       fact = 1;
       for(i = 1; i <= num; i++)
       {
           fact *= i;
       }
       printf("Factorial of %d is %d\n", num, fact);
   }
    
   printf("Enter a number for prime check:");
   scanf("%d", &num);

   if(num <= 1)
   {
       printf("Invalid Input. Please Enter a number greater than one\n");
   }
   else
   {
       count = 0;
       for(i = 2; i <= sqrt(num); i++)
       {
           if(num % i == 0)
           {
               count++;
           }
       }

       if(count == 0)
       {
           printf("%d is a prime number\n", num);
       }
       else
       {
           printf("%d is not a prime number\n", num);
       }
   }

   printf("Enter a number for sin calculation:");
   scanf("%f", &pi);

   powr = (pi * 3.14159) / 180;

   printf("sin(%0.2f) = %f\n", pi, sin(powr));

   return 0;
}