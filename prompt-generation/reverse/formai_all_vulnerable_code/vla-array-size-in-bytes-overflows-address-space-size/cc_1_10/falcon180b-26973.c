//Falcon-180B DATASET v1.0 Category: Recursive ; Style: optimized
#include<stdio.h>

//Function to calculate factorial of a number using recursion
long long int factorial(int n){
    if(n==0){
        return 1;
    }
    else{
        return(n*factorial(n-1));
    }
}

//Function to find the nth number in the Fibonacci series using recursion
long long int fibonacci(int n){
    if(n==1){
        return 0;
    }
    else if(n==2){
        return 1;
    }
    else{
        return(fibonacci(n-1)+fibonacci(n-2));
    }
}

//Function to find the sum of all even numbers in an array using recursion
long long int sumEven(int arr[],int n){
    if(n==0){
        return 0;
    }
    else if(arr[n]%2==0){
        return(arr[n]+sumEven(arr,n-1));
    }
    else{
        return sumEven(arr,n-1);
    }
}

//Function to find the nth prime number using recursion
int nthPrime(int n){
    int count=0;
    int i=2;
    while(count<n){
        if(isPrime(i)){
            count++;
        }
        i++;
    }
    return i-1;
}

//Function to check if a number is prime or not
int isPrime(int n){
    if(n<=1){
        return 0;
    }
    for(int i=2;i<=n/2;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}

int main(){
    int n,choice;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter your choice:\n1.Factorial\n2.Fibonacci\n3.Sum of even numbers\n4.Nth prime number\n");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Factorial of %d is %lld\n",n,factorial(n));
            break;
        case 2:
            printf("The %dth number in the Fibonacci series is %lld\n",n,fibonacci(n));
            break;
        case 3:
            printf("The sum of all even numbers in the array is %lld\n",sumEven(arr,n));
            break;
        case 4:
            printf("The %dth prime number is %d\n",n,nthPrime(n));
            break;
        default:
            printf("Invalid choice!");
    }
    return 0;
}