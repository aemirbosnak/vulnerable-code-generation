//Falcon-180B DATASET v1.0 Category: Arithmetic ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

//function to calculate the sum of two integers
int sum(int a, int b){
    return a+b;
}

//recursive function to calculate the product of two integers
int product(int a, int b){
    if(a==0){
        return 0;
    }
    else{
        return a*b+product(a-1,b);
    }
}

//recursive function to calculate the factorial of a number
int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*factorial(n-1);
    }
}

//recursive function to calculate the power of a number
int power(int base, int exponent){
    if(exponent==0){
        return 1;
    }
    else{
        return base*power(base,exponent-1);
    }
}

//recursive function to calculate the greatest common divisor of two integers
int gcd(int a, int b){
    if(a==0){
        return b;
    }
    else{
        return gcd(b%a,a);
    }
}

//recursive function to calculate the least common multiple of two integers
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int main(){
    int num1, num2, choice;
    printf("Enter two integers:\n");
    scanf("%d %d",&num1,&num2);
    printf("1. Sum\n2. Product\n3. Factorial\n4. Power\n5. GCD\n6. LCM\n");
    printf("Enter your choice:\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Sum of %d and %d is %d\n",num1,num2,sum(num1,num2));
            break;
        case 2:
            printf("Product of %d and %d is %d\n",num1,num2,product(num1,num2));
            break;
        case 3:
            printf("Factorial of %d is %d\n",num1,factorial(num1));
            break;
        case 4:
            printf("Power of %d to %d is %d\n",num1,num2,power(num1,num2));
            break;
        case 5:
            printf("GCD of %d and %d is %d\n",num1,num2,gcd(num1,num2));
            break;
        case 6:
            printf("LCM of %d and %d is %d\n",num1,num2,lcm(num1,num2));
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}